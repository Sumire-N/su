#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define I_BLOCK 0
#define O_BLOCK 1
#define T_BLOCK 2
#define S_BLOCK 3
#define Z_BLOCK 4
#define J_BLOCK 5
#define L_BLOCK 6
#define NONE    7
					
int falling_flg=0;
int element1_h,element1_w,element2_h,element2_w,element3_h,element3_w,element4_h,element4_w;
int height_f=0,width_f=0;
int NoMoveRight_flg=0;
int NoMoveLeft_flg=0;
int new_block=999;
int BlockStyle=0;
char key = 'n';
int NoRotate_flg=0;
int blockfound_count=0,blockunfound_count=0;
int floor_count=0,newcelling_count=0,newfloor_h,newcelling_h;
int height_v=0,width_v=0;

int stage[20][10]= {				{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{1,1,1,1,0,0,0,1,1,1}};
//Linux対応用関数
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

//画面表示--------------------------------------------------------------------
void DefineDynamicElement(void){//ブロックひとつひとつの■の座標を定義する、そしてブロックを消す
	int element_count=0;
	int height_g=0,width_g=0;
	
	for(height_g=0;height_g<20;height_g++)
	{
		for(width_g=0;width_g<10;width_g++)
		{
			if(stage[height_g][width_g]==2)
			{
				switch(element_count){
					case 0:
						element1_h=height_g;
						element1_w=width_g;
						stage[element1_h][element1_w]=0;
						element_count=element_count+1;
						break;
					case 1:
						element2_h=height_g;
						element2_w=width_g;
						stage[element2_h][element2_w]=0;
						element_count=element_count+1;
						break;
					case 2:
						element3_h=height_g;
						element3_w=width_g;
						stage[element3_h][element3_w]=0;
						element_count=element_count+1;
						break;
					case 3:
						element4_h=height_g;
						element4_w=width_g;
						stage[element4_h][element4_w]=0;
						element_count=element_count+1;
						break;
				}
			}
		}
	}
}

void DispStage(void){
	int width_i,height_i,i;
	int height_gameover=0;
	int gametryflg=1;
	//画面を真っ白にする
	system("clear");
	//天井
	//printf("□□□□□□□□□□□□");
	printf("_______________________\n");
	
	//ステージ
	for(height_i=0;height_i<20;height_i++)
	{
		printf("o");//左壁
		for(width_i=0;width_i<10;width_i++)
		{
			if(stage[height_i][width_i]==0) printf("  "); //ブロック無
			else if(stage[height_i][width_i]==1) printf("CO"); //ブロック有り
			else if(stage[height_i][width_i]==2) printf("CO"); //落下中ブロック
		}
		printf("o\n");//右壁
	}	
	//床
	printf("TTTTTTTTTTTTTTTTTTTTT\n");
	//printf("□□□□□□□□□□□□");
}


//キーボード入力処理-----------------------------------------------------------
void MoveRight(void){//ブロックを右に動かす、壁に当たったらめり込まないようにする
	
	DefineDynamicElement();
	if(stage[element1_h][element1_w+1]!=1 &&
		stage[element2_h][element2_w+1]!=1 &&
		stage[element3_h][element3_w+1]!=1 &&
		stage[element4_h][element4_w+1]!=1 &&
		element1_w!=9 &&
		element2_w!=9 &&
		element3_w!=9 &&
		element4_w!=9 )
	{
		//printf("入った");
		//printf("     %d",element2_w+1);
		//sleep(500);
		element1_w=element1_w+1;
		element2_w=element2_w+1;
		element3_w=element3_w+1;
		element4_w=element4_w+1;
		
		stage[element1_h][element1_w]=2;
		stage[element2_h][element2_w]=2;
		stage[element3_h][element3_w]=2;
		stage[element4_h][element4_w]=2;
	}
}

void MoveLeft(void){
	
	DefineDynamicElement();
	if(stage[element1_h][element1_w-1]!=1 &&
		stage[element2_h][element2_w-1]!=1 &&
		stage[element3_h][element3_w-1]!=1 &&
		stage[element4_h][element4_w-1]!=1 &&
		element1_w!=0 &&
		element2_w!=0 &&
		element3_w!=0 &&
		element4_w!=0 )
	{
		element1_w=element1_w-1;
		element2_w=element2_w-1;
		element3_w=element3_w-1;
		element4_w=element4_w-1;
		
		stage[element1_h][element1_w]=2;
		stage[element2_h][element2_w]=2;
		stage[element3_h][element3_w]=2;
		stage[element4_h][element4_w]=2;
	}
}
void NoRotate_LeftWall(void){//壁に面したら動かない
	int LeftWallFacedBlock_count=0;
	int MoveTimes=0;
	int FasedOneBrockCount=0;
	int FacedOneblock_height=0,FacedOneblock_width=0;
	
	
	if(new_block==T_BLOCK||new_block==L_BLOCK||new_block==J_BLOCK)
	{
		if(element1_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element2_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element3_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element4_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(LeftWallFacedBlock_count==3)
		{
			NoRotate_flg=1;
		}
		LeftWallFacedBlock_count=0;
		
		//１ブロックが横にあったとき壁蹴り・element4から順に回っているのは一番下の高さ座標が知りたいから
	
		if(stage[element1_h][element1_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element1_h;
			FacedOneblock_width=element1_w;
		}
		if(stage[element2_h][element2_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element2_h;
			FacedOneblock_width=element2_w;
		}
		if(stage[element3_h][element3_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element3_h;
			FacedOneblock_width=element3_w;
		}
		if(stage[element4_h][element4_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element4_h;
			FacedOneblock_width=element4_w;
		}
		if((FasedOneBrockCount==1||FasedOneBrockCount==2) && stage[FacedOneblock_height-1][FacedOneblock_width]==2 && stage[FacedOneblock_height-2][FacedOneblock_width]==2 )
		{
			NoRotate_flg=1;
			FasedOneBrockCount=0;
		}
	}
	
	else if(new_block==Z_BLOCK)
	{
		if(element1_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element2_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element3_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element4_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(LeftWallFacedBlock_count==2)
		{
			NoRotate_flg=1;
		}
		LeftWallFacedBlock_count=0;
		
		if(stage[element1_h][element1_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element1_h;
			FacedOneblock_width=element1_w;
		}
		if(stage[element2_h][element2_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element2_h;
			FacedOneblock_width=element2_w;
		}
		if(stage[element3_h][element3_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element3_h;
			FacedOneblock_width=element3_w;
		}
		if(stage[element4_h][element4_w-1]==1)
		{
			FasedOneBrockCount++;
			FacedOneblock_height=element4_h;
			FacedOneblock_width=element4_w;
		}
		if((FasedOneBrockCount==1||FasedOneBrockCount==2) && stage[FacedOneblock_height-1][FacedOneblock_width]==2 )
		{
			NoRotate_flg=1;
			FasedOneBrockCount=0;
		}
	}
	
	else if(new_block==I_BLOCK)
	{
		if(element1_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element2_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element3_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(element4_w==0)
		{
			LeftWallFacedBlock_count++;
		}
		if(LeftWallFacedBlock_count==4)
		{
					NoRotate_flg=1;

				LeftWallFacedBlock_count=0;
		}
		
		
		
		if(	stage[element1_h][element1_w+1]==1||
			stage[element2_h][element2_w+1]==1||
			stage[element3_h][element3_w+1]==1||
			stage[element4_h][element4_w+1]==1)
		{
			NoRotate_flg=1;
			LeftWallFacedBlock_count=0;
		}
	}
	

		if(element1_w==1)
		{
			LeftWallFacedBlock_count++;
		}
		if(element2_w==1)
		{
			LeftWallFacedBlock_count++;
		}
		if(element3_w==1)
		{
			LeftWallFacedBlock_count++;
		}
		if(element4_w==1)
		{
			LeftWallFacedBlock_count++;
		}
		if(LeftWallFacedBlock_count==4)
		{
			NoRotate_flg=1;
			LeftWallFacedBlock_count=0;
		}
}

void NoRotate_RightWall(void){//壁に面したら動かない
	int RightWallFacedBlock_count=0;
	int height_wk=0;
	
	if(new_block==T_BLOCK||new_block==L_BLOCK||new_block==J_BLOCK)
	{
		if(element1_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element2_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element3_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element4_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(RightWallFacedBlock_count==3)
		{
			NoRotate_flg=1;
		}
		RightWallFacedBlock_count=0;
		
		if(	stage[element1_h][element1_w+1]==1||
			stage[element2_h][element2_w+1]==1||
			stage[element3_h][element3_w+1]==1||
			stage[element4_h][element4_w+1]==1)
		{
			NoRotate_flg=1;
			RightWallFacedBlock_count=0;
		}
	}
	
	else if(new_block==S_BLOCK)
	{
		if(element1_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element2_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element3_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element4_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(RightWallFacedBlock_count==2)
		{
			MoveLeft();
		}
		RightWallFacedBlock_count=0;
		
		if(	stage[element1_h][element1_w+1]==1||
			stage[element2_h][element2_w+1]==1||
			stage[element3_h][element3_w+1]==1||
			stage[element4_h][element4_w+1]==1)
		{
			NoRotate_flg=1;
			RightWallFacedBlock_count=0;
		}
	}
	
	else if(new_block==I_BLOCK)
	{
		if(element1_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element2_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element3_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(element4_w==9)
		{
			RightWallFacedBlock_count++;
		}
		if(RightWallFacedBlock_count==4)
		{
			NoRotate_flg=1;
		}
		RightWallFacedBlock_count=0;
		
		
		if(	stage[element1_h][element1_w+1]==1||
			stage[element2_h][element2_w+1]==1||
			stage[element3_h][element3_w+1]==1||
			stage[element4_h][element4_w+1]==1)
		{
			NoRotate_flg=1;
			RightWallFacedBlock_count=0;
		}
	}
}

void Rotate_CW(void)
{
	NoRotate_flg=0;
	NoRotate_LeftWall();
	NoRotate_RightWall();
	if(NoRotate_flg==0)
	{
		if(new_block==T_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(stage[element1_h-1][element1_w+1]==0)
					{
						BlockStyle=4;
						stage[element1_h][element1_w]=0;
						stage[element1_h-1][element1_w+1]=2;
					}
					break;
					
				case 2:	
					if(stage[element1_h+1][element1_w+1]==0)
					{
						BlockStyle=1;
						//Serch_first2Block();
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w+1]=2;
					}
					break;
					
				case 3:
					if(stage[element1_h][element1_w-1]==0 &&
					stage[element1_h-1][element1_w]==0)
					{
						BlockStyle=2;			
					
						stage[element1_h+1][element1_w-1]=0;
						stage[element1_h+1][element1_w+1]=0;
						stage[element1_h][element1_w-1]=2;
						stage[element1_h-1][element1_w]=2;
					}
					break;
			
				case 4:
					if(stage[element1_h+2][element1_w-1]==0 &&
					stage[element1_h+2][element1_w+1]==0)
					{
						BlockStyle=3;
						//Serch_first2Block();
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w+1]=0;
						stage[element1_h+2][element1_w-1]=2;
						stage[element1_h+2][element1_w+1]=2;
					}
					break;
	
				}
		}
	
	
		else if(new_block==I_BLOCK)
		{
			switch(BlockStyle){
				DefineDynamicElement();
				case 1:
					if(	stage[element1_h-1][element1_w+2]==0 &&
						stage[element1_h+1][element1_w+2]==0 &&
						stage[element1_h+2][element1_w+2]==0 &&
						element1_h<17)//Iブロックが回転することで床にめり込まないようにするため
					{	
						BlockStyle=2;

						stage[element1_h][element1_w]=0;
						stage[element1_h][element1_w+1]=0;
						stage[element1_h][element1_w+3]=0;

						stage[element1_h-1][element1_w+2]=2;
						stage[element1_h+1][element1_w+2]=2;
						stage[element1_h+2][element1_w+2]=2;			
					}
				
					break;
				case 2:
				if(	stage[element1_h+1][element1_w-2]==0 &&
					stage[element1_h+1][element1_w-1]==0 &&
					stage[element1_h+1][element1_w+1]==0)
				{
					BlockStyle=1;
					stage[element1_h][element1_w]=0;
					stage[element1_h+2][element1_w]=0;
					stage[element1_h+3][element1_w]=0;
					stage[element1_h+1][element1_w-2]=2;
					stage[element1_h+1][element1_w-1]=2;
					stage[element1_h+1][element1_w+1]=2;
				}
				break;
			}
		}
		
		
		else if(new_block==L_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					
					if(stage[element1_h+1][element1_w+1]==0 &&
					stage[element1_h+2][element1_w-1]==0)
					{
						BlockStyle=4;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h+1][element1_w+1]=2;
						stage[element1_h+2][element1_w-1]=2;
					}
					break;
						
					
				case 2:
					if(	stage[element1_h-1][element1_w+1]==0 &&
						stage[element1_h+1][element1_w+1]==0 &&
						stage[element1_h+1][element1_w+2]==0)
					{
						BlockStyle=1;
					
						//Serch_first2Block();
						stage[element1_h][element1_w]=0;
						stage[element1_h][element1_w+2]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h-1][element1_w+1]=2;
						stage[element1_h+1][element1_w+1]=2;
						stage[element1_h+1][element1_w+2]=2;
					}
					break;

				case 3:
					if(	stage[element1_h+1][element1_w]==0 &&
						stage[element1_h+1][element1_w+2]==0 &&
						stage[element1_h+2][element1_w]==0)
						{
							BlockStyle=2;
							
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h][element1_w+1]=0;
							stage[element1_h+2][element1_w+1]=0;
							stage[element1_h+1][element1_w]=2;
							stage[element1_h+1][element1_w+2]=2;
							stage[element1_h+2][element1_w]=2;
						}
					break;
					
			case 4:
			
					if(	stage[element1_h-1][element1_w-2]==0 &&
						stage[element1_h-1][element1_w-1]==0 &&
						stage[element1_h][element1_w-1]==0)
						{
							BlockStyle=3;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h+1][element1_w-2]=0;
							stage[element1_h+1][element1_w+2]=0;
							stage[element1_h+1][element1_w]=0;
							stage[element1_h-1][element1_w-2]=2;
							stage[element1_h-1][element1_w-1]=2;
							stage[element1_h][element1_w-1]=2;
						}
					break;
			}
		}
	
	
	
		else if(new_block==J_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(	stage[element1_h+1][element1_w-1]==0 &&
						stage[element1_h+1][element1_w+1]==0 &&
						stage[element1_h+2][element1_w+1]==0)
						{
							BlockStyle=4;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h+2][element1_w-1]=0;
							stage[element1_h+2][element1_w]=0;
							stage[element1_h+1][element1_w-1]=2;
							stage[element1_h+1][element1_w+1]=2;
							stage[element1_h+2][element1_w+1]=2;
						}
					break;
					
				case 2:
					if(	stage[element1_h-1][element1_w+1]==0 &&
						stage[element1_h][element1_w+1]==0)
					{
						BlockStyle=1;
						//Serch_first2Block();
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w+2]=0;
						stage[element1_h-1][element1_w+1]=2;
						stage[element1_h][element1_w+1]=2;
					}
					break;
					
				case 3:
					if(	stage[element1_h+1][element1_w-1]==0 &&
						stage[element1_h+2][element1_w-1]==0 &&
						stage[element1_h+2][element1_w+1]==0)
						{
							BlockStyle=2;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h+1][element1_w]=0;
							stage[element1_h][element1_w+1]=0;
							stage[element1_h+1][element1_w-1]=2;
							stage[element1_h+2][element1_w-1]=2;
							stage[element1_h+2][element1_w+1]=2;
						}
					break;
			
				case 4:
					if(	stage[element1_h+1][element1_w+1]==0 &&
						stage[element1_h-1][element1_w+2]==0 &&
						stage[element1_h-1][element1_w+1]==0)
						{
							BlockStyle=3;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h][element1_w+2]=0;
							stage[element1_h+1][element1_w+2]=0;
							stage[element1_h+1][element1_w+1]=2;
							stage[element1_h-1][element1_w+2]=2;
							stage[element1_h-1][element1_w+1]=2;
						}
				break;
			}
		}
	
	
		else if(new_block==S_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(	stage[element1_h][element1_w-1]==0 &&
						stage[element1_h-1][element1_w-1]==0)
					{
						//printf("case１");
						//sleep(300);
						BlockStyle=2;
						stage[element1_h][element1_w+1]=0;
						stage[element1_h+1][element1_w-1]=0;
						stage[element1_h][element1_w-1]=2;
						stage[element1_h-1][element1_w-1]=2;
					}
					break;
				case 2:
					if(	stage[element1_h+1][element1_w+2]==0 &&
						stage[element1_h+2][element1_w]==0)
					{
						BlockStyle=1;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h+1][element1_w+2]=2;
						stage[element1_h+2][element1_w]=2;
					}
					break;
			}
		}

		else if(new_block==Z_BLOCK)
		{
			//WallKick();
			switch(BlockStyle){
				case 1:
					if(	stage[element1_h][element1_w+2]==0 &&
						stage[element1_h-1][element1_w+2]==0)
					{
						BlockStyle=2;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w+2]=0;
						stage[element1_h][element1_w+2]=2;
						stage[element1_h-1][element1_w+2]=2;
					}
					break;

				case 2:
					if(	stage[element1_h+2][element1_w]==0 &&
						stage[element1_h+1][element1_w-2]==0)
					{
						BlockStyle=1;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h+2][element1_w]=2;
						stage[element1_h+1][element1_w-2]=2;
					}
					break;
			}
		}
	}
}

void Rotate_CCW(void)
{
	NoRotate_flg=0;
	NoRotate_LeftWall();
	NoRotate_RightWall();
	if(NoRotate_flg==0)
	{
		if(new_block==T_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(stage[element1_h-1][element1_w+1]==0)
					{
						BlockStyle=2;
						stage[element1_h][element1_w+2]=0;
						stage[element1_h-1][element1_w+1]=2;
					}
					break;
					
				case 2:
					if(stage[element1_h+2][element1_w-1]==0 &&
						stage[element1_h+2][element1_w+1]==0)
					{
						BlockStyle=3;
						
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w-1]=0;
						stage[element1_h+2][element1_w-1]=2;
						stage[element1_h+2][element1_w+1]=2;
					}
					break;
			
				case 3:
					if(stage[element1_h-1][element1_w]==0 &&
						stage[element1_h][element1_w+1]==0)
					{
						BlockStyle=4;
					
						//Serch_first2Block();
						stage[element1_h+1][element1_w-1]=0;
						stage[element1_h+1][element1_w+1]=0;
						stage[element1_h-1][element1_w]=2;
						stage[element1_h][element1_w+1]=2;
					}
					break;	
							
						
				case 4:
			
					if(stage[element1_h+1][element1_w-1]==0)
					{
						BlockStyle=1;
						//Serch_first2Block();
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w-1]=2;
					}
					break;
							
				}
		}
	
	
		else if(new_block==I_BLOCK)
		{
			switch(BlockStyle){
				DefineDynamicElement();
				case 1:
				
				if(	stage[element1_h-1][element1_w+2]==0 &&
					stage[element1_h+1][element1_w+2]==0 &&
					stage[element1_h+2][element1_w+2]==0 &&
					element1_h<17)//Iブロックが回転することで床にめり込まないようにするため
				{	
					BlockStyle=2;
					stage[element1_h][element1_w]=0;
					stage[element1_h][element1_w+1]=0;
					stage[element1_h][element1_w+3]=0;
					stage[element1_h-1][element1_w+2]=2;
					stage[element1_h+1][element1_w+2]=2;
					stage[element1_h+2][element1_w+2]=2;
				}
				break;
			case 2:
				if(	stage[element1_h+1][element1_w-2]==0 &&
					stage[element1_h+1][element1_w-1]==0 &&
					stage[element1_h+1][element1_w+1]==0)
				{
					//DefineDynamicElement();
					BlockStyle=1;

					stage[element1_h][element1_w]=0;
					stage[element1_h+2][element1_w]=0;
					stage[element1_h+3][element1_w]=0;

					stage[element1_h+1][element1_w-2]=2;
					stage[element1_h+1][element1_w-1]=2;
					stage[element1_h+1][element1_w+1]=2;
				}
				break;
			}
		}
		
		
		else if(new_block==L_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(	stage[element1_h+1][element1_w-1]==0 &&
						stage[element1_h+1][element1_w+1]==0 &&
						stage[element1_h+2][element1_w-1]==0)
						{
							BlockStyle=2;
							
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h+2][element1_w]=0;
							stage[element1_h+2][element1_w+1]=0;
							stage[element1_h+1][element1_w-1]=2;
							stage[element1_h+1][element1_w+1]=2;
							stage[element1_h+2][element1_w-1]=2;
						}
						break;
						
					
				case 2:
					if(stage[element1_h-1][element1_w]==0 &&
						stage[element1_h-1][element1_w+1]==0 &&
						stage[element1_h+1][element1_w+1]==0)
						{
							BlockStyle=3;
							
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h][element1_w+2]=0;
							stage[element1_h+1][element1_w]=0;
							stage[element1_h-1][element1_w]=2;
							stage[element1_h-1][element1_w+1]=2;
							stage[element1_h+1][element1_w+1]=2;
						}
						break;
						
					
				case 3:
					
					if(stage[element1_h+1][element1_w+2]==0 &&
						stage[element1_h+2][element1_w]==0 &&
						stage[element1_h+2][element1_w+2]==0)
						{
							BlockStyle=4;
						
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h][element1_w+1]=0;
							stage[element1_h+1][element1_w+1]=0;
							stage[element1_h+1][element1_w+2]=2;
							stage[element1_h+2][element1_w]=2;
							stage[element1_h+2][element1_w+2]=2;
						}
						break;
			
			case 4:
				if(stage[element1_h-1][element1_w-1]==0 &&
					stage[element1_h][element1_w-1]==0)
				{
					BlockStyle=1;
					//Serch_first2Block();
					stage[element1_h][element1_w]=0;
					stage[element1_h+1][element1_w-2]=0;
					stage[element1_h+1][element1_w+2]=0;
					stage[element1_h-1][element1_w-1]=2;
					stage[element1_h][element1_w-1]=2;
				}
					break;
						
			}
		}
	
	
	
		else if(new_block==J_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(stage[element1_h+1][element1_w-1]==0 &&
					stage[element1_h+2][element1_w+1]==0)
					{
						BlockStyle=2;
						//Serch_first2Block();
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h+1][element1_w-1]=2;
						stage[element1_h+2][element1_w+1]=2;
					}
					break;
					
				case 2:
					if(	stage[element1_h-1][element1_w+1]==0 &&
						stage[element1_h-1][element1_w+2]==0 &&
						stage[element1_h][element1_w+1]==0)
						{
							BlockStyle=3;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h+1][element1_w]=0;
							stage[element1_h+1][element1_w+2]=0;
							stage[element1_h-1][element1_w+1]=2;
							stage[element1_h-1][element1_w+2]=2;
							stage[element1_h][element1_w+1]=2;
						}
						break;

				case 3:
					if(stage[element1_h+1][element1_w-1]==0 &&
						stage[element1_h+1][element1_w+1]==0 &&
						stage[element1_h+2][element1_w+1]==0)
						{
							BlockStyle=4;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h][element1_w+1]=0;
							stage[element1_h+2][element1_w]=0;
							stage[element1_h+1][element1_w-1]=2;
							stage[element1_h+1][element1_w+1]=2;
							stage[element1_h+2][element1_w+1]=2;
						}
						break;

				case 4:
					if(	stage[element1_h+1][element1_w]==0 &&
						stage[element1_h+1][element1_w+1]==0 &&
						stage[element1_h-1][element1_w+1]==0)
						{
							BlockStyle=1;
							//Serch_first2Block();
							stage[element1_h][element1_w]=0;
							stage[element1_h][element1_w+2]=0;
							stage[element1_h+1][element1_w+2]=0;
							stage[element1_h+1][element1_w]=2;
							stage[element1_h+1][element1_w+1]=2;
							stage[element1_h-1][element1_w+1]=2;
						}
					break;
			}
		}
	
	
		else if(new_block==S_BLOCK)
		{
				
			switch(BlockStyle){
				case 1:
					if(	stage[element1_h][element1_w-1]==0 &&
						stage[element1_h-1][element1_w-1]==0)
					{
						BlockStyle=2;
						stage[element1_h][element1_w+1]=0;
						stage[element1_h+1][element1_w-1]=0;
						stage[element1_h][element1_w-1]=2;
						stage[element1_h-1][element1_w-1]=2;
					}
					break;
				case 2:
					if(	stage[element1_h+1][element1_w+2]==0 &&
						stage[element1_h+2][element1_w]==0)
					{
						BlockStyle=1;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h+1][element1_w+2]=2;
						stage[element1_h+2][element1_w]=2;
					}
					break;
			}
		}
		else if(new_block==Z_BLOCK)
		{
			switch(BlockStyle){
				case 1:
					if(	stage[element1_h][element1_w+2]==0 &&
						stage[element1_h-1][element1_w+2]==0)
					{
						BlockStyle=2;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w+2]=0;
						stage[element1_h][element1_w+2]=2;
						stage[element1_h-1][element1_w+2]=2;
					}
					break;
				case 2:
					if(	stage[element1_h+2][element1_w]==0 &&
						stage[element1_h+1][element1_w-2]==0)
					{
						BlockStyle=1;
						stage[element1_h][element1_w]=0;
						stage[element1_h+1][element1_w]=0;
						stage[element1_h+2][element1_w]=2;
						stage[element1_h+1][element1_w-2]=2;
					}
					break;
			}
		}
	}
}



void GetKeyboard(void){
	int stopflg=0;
	key = 'n';
	if(kbhit())key = getchar();
	if(falling_flg!=0)
	{
		switch(key){
			case 'd'://右にスライド
				MoveRight();
				break;
			case 'a'://左にスライド
				MoveLeft();
				break;
			case 'k'://cw:ClockWise
				Rotate_CCW();
				break;
			case 'j'://ccw:CounterClockWise
				Rotate_CW();
				break;
					}
	}
	while(kbhit())key = getchar();/////////////////////教えてもらった
}


//重力や消滅を計算----------------------------------------------------------------------
void ThrowBlock(void){//ブロック投入
	if(falling_flg==1)return;
	falling_flg=1;
	srand((int)time(0));
	new_block=(int)rand()%7;
	new_block=T_BLOCK;
	
	BlockStyle = 1;
	
	switch(new_block){
		case I_BLOCK:
			stage[0][3]=2;
			stage[0][4]=2;
			stage[0][5]=2;
			stage[0][6]=2;
			break;
		case O_BLOCK:
			stage[0][4]=2;
			stage[0][5]=2;
			stage[1][4]=2;
			stage[1][5]=2;
			break;
		case T_BLOCK:
			stage[0][4]=2;
			stage[0][5]=2;
			stage[0][6]=2;
			stage[1][5]=2;
			break;
		case L_BLOCK:
			stage[0][4]=2;
			stage[1][4]=2;
			stage[2][4]=2;
			stage[2][5]=2;
			break;
		case J_BLOCK:
			stage[0][5]=2;
			stage[1][5]=2;
			stage[2][5]=2;
			stage[2][4]=2;
			break;
		case S_BLOCK:
			stage[0][5]=2;
			stage[0][6]=2;
			stage[1][5]=2;
			stage[1][4]=2;
			break;
		case Z_BLOCK:
			stage[0][5]=2;
			stage[0][4]=2;
			stage[1][5]=2;
			stage[1][6]=2;
			break;
	}
}

void PileUpBlock(void){//ブロックを積み上げるよ
	int MoveTimeBeforePileUp=0;
		DefineDynamicElement();
		stage[element1_h][element1_w]=2;
		stage[element2_h][element2_w]=2;
		stage[element3_h][element3_w]=2;
		stage[element4_h][element4_w]=2;

	if( 	stage[19][element1_w]==2 ||//床が下にあるとき
		stage[19][element2_w]==2 ||
		stage[19][element3_w]==2 ||
		stage[19][element4_w]==2)
	{
		stage[element1_h][element1_w]=1;
		stage[element2_h][element2_w]=1;
		stage[element3_h][element3_w]=1;
		stage[element4_h][element4_w]=1;
		
		falling_flg=0;
	} 
	if(	stage[element1_h+1][element1_w]==1 ||//下に積み上がったブロックがあるとき
		stage[element2_h+1][element2_w]==1 ||
		stage[element3_h+1][element3_w]==1 ||
		stage[element4_h+1][element4_w]==1 )
	{
		stage[element1_h][element1_w]=1;
		stage[element2_h][element2_w]=1;
		stage[element3_h][element3_w]=1;
		stage[element4_h][element4_w]=1;
		falling_flg=0;
	}
}

void VanishBlock(void){//ブロックを消す＆消した分のブロックを詰める
	/*int blockfound_count=0,blockunfound_count=0;
	int floor_count=0,newcelling_count=0,newfloor_h,newcelling_h;
	int height_v=0,width_v=0;*/
	
	for(height_v=19;height_v>0;height_v--)
	{
		blockfound_count=0;
		for(width_v=0;width_v<10;width_v++)
		{
			if(stage[height_v][width_v]==1)
			{
				blockfound_count++;
				if(blockfound_count==10)//下から一列ブロックがそろっているかどうかを探していって見つけたら消す
				{
					for(width_v=0;width_v<10;width_v++)
					{
						stage[height_v][width_v]=0;
					}
				}
			}
		}
	}
}

void PlugBlock(void){

	for(height_v=19;height_v>0;height_v--)
	{
		newcelling_count=0;
		blockunfound_count=0;
		for(width_v=0;width_v<10;width_v++)
		{
			if(stage[height_v][width_v]!=0) continue;
			//{
			blockunfound_count++;
			if(blockunfound_count==10)continue;//ブロックが一列なかったら、その列を床にする（次に積もらせる部分）
			//{
				if(height_v==19)//ブロックが一つも積まれておらず、床がstageの床になる場合
				{
					newfloor_h=height_v;
				}
				else
				{//すでに積もった１ブロックが床になる場合
					floor_count++;
					if(floor_count==1)//下から数えて初めてブロックがなかった部分を床にする
					{
						newfloor_h=height_v;
					}
				}
		}
		for(width_v=0;width_v<10;width_v++)//続けて天井を探す
		{
			if(stage[height_v-1][width_v]==1) continue;//床を見つけた一つ上の列から１ブロックがある場所を探す
			//{
			newcelling_count++;
			if(newcelling_count==1) continue;//ひとつでも１ブロックを見つけたらその列を天井とする
			//{
			newcelling_h=height_v-1;
			for(width_v=0;width_v<10;width_v++)
			{
				stage[newfloor_h][width_v]=stage[newcelling_h][width_v];//天井のブロックを床のブロックにコピペする
				stage[newcelling_h][width_v]=0;//天井のブロックは消す
			}
			floor_count=0;
			//}
			//}
		}
				
			//}
			//}
		//}
		if(newcelling_count==1)//天井を見つけたら、再度床と天井を探すためにheight_vを初期化する
		{
			height_v=19;
		}
	}
}

void FallBlock(void){
	DefineDynamicElement();//ブロックを落とす

	if(falling_flg==0)return;
	
	element1_h=element1_h+1;
	element2_h=element2_h+1;
	element3_h=element3_h+1;
	element4_h=element4_h+1;
	
	stage[element1_h][element1_w]=2;
	stage[element2_h][element2_w]=2;
	stage[element3_h][element3_w]=2;
	stage[element4_h][element4_w]=2;
}

void CalcEnvironment(void){
	ThrowBlock();
	PileUpBlock();//ブロックを積み上げる
	FallBlock();
	VanishBlock();//ブロックを消す＆消した分を詰める
	PlugBlock();
}

void DispGameOver(void){//ゲームオーバーとリトライ
	key='n';
	int height=0,width=0;
	int height_gameover=0;
	int GameOver_flg=0;
	
	for(height_gameover=0;height_gameover<10;height_gameover++)//stageの一番上までブロックが詰まったか確認
	{
		if(stage[0][height_gameover]==1)
		{
			system("clear");
			printf("\n\n\n                          GAME OVER !!\n\n");//gameoverを表示
			printf("\n\n              ざんねん！リトライするときは　r　キーを押してね！\n\n\n\n\n\n\n\n");
			GameOver_flg=1;
		}
	}

	if(GameOver_flg==1)
	{			
		while(key !='r')//r キーでリトライできるようにする
		{
			if(kbhit())key = getchar();
		}
	
		system("clear");
	
		for(height=0;height<20;height++)//stageに積もっているブロックをすべて消去する
		{
			for(width=0;width<10;width++)
			{
				if(stage[height][width]==1)
				{
					stage[height][width]=0;
				}
			}
		}
	}		
}


int main(void)
{
	while(1){
		GetKeyboard();//キーボード入力処理
		CalcEnvironment();//重力とか消えるとかの処理
		DispStage();//ステージの表示（しばらく変えない！）
		sleep(1);//プログラムを止める時間（50ms）
		DispGameOver();
		}
	return 0;
}
