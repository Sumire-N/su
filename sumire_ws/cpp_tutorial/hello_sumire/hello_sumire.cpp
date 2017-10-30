#include <stdio.h>
int main(void){
int a,b,c,d;
 for(a=0;a<5;a++)
{
 for(b=0;b<4-a;b++)
  {
    printf(" ");
  } 
 for(c=0;c<a;c++)
  {
    printf("*");
  }
 for(d=0;d<a+1;d++)
  {
    printf("*");
  }
  printf("\n");
}

  return 0;
}
