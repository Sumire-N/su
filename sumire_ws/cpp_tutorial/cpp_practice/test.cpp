/*#include <iostream>
int main(void){
  std::cout << "hello wolrd" << std::endl;
  return 0;
  }*/

/*#include <iostream>
using namespace std;

const int MAX_NAME = 16;

class Student{
public:
  char name[MAX_NAME +1];
  int scoreJapanese;
  int scoreMath;
  int scoreEnglish;

  void Show();
nn};

void Student::Show(){
  cout << "名前:"<< name << endl
       << "国語:"<< scoreJapanese<<"点"
    ",数学:"<<scoreMath<<"点"
    ",英語:"<<scoreEnglish<<"点"<<endl;
  
}

int main(){
  Student student[]={
    {"赤井孝",73,98,86,},
    {"笹井大輔",64,45,40,},
    {"吉田叶",76,78,69,},
  };


int size=sizeof student/sizeof *student;

for(int i=0;i<size;i++){
  student[i].Show();
 }
 }*/

/*#include <iostream>
#include<string.h>

class hito
{
private:
  char setname[40];
  int age;
public:
  void setname(char*ss);
  void setage(int tosi);
  void disp();
};

void hito::setname(char*ss){
  strcpy(name,ss)
};

void hito::setage(int tosi){
  if(tosi<0) age=0; else age=tosi;
}

void hito::disp(){
  cout << "名前:"<< name << endl;
  cout <<"年齢:" << age << endl;
  
}


void main(){
  hito yamada;

  yamada.setname("山田一郎");
  yamada.setage("30");
  yamada.disp();

}*/

/*person person1;
person1.m_height=170;
person1.m_weight=60;

void print(constPerson&psn)
{

}*/


/*#include<iostream>
using namespace std;
class Tashizann{
private:
  float a,b;
  float wa;
public:
  void SetA(float);
  void SetB(float);
  void Keisan(void);
  float Wa(void);
};

void Tashizann::SetA(float x){
  a=x;
}

void Tashizann::SetB(float y){
  b=y;
}

void Tashizann::Keisan(void){
  wa=a+b;
}

float Tashizann::Wa(void){
  return(wa);
}

int main(void){
  Tashizann p;

  p.SetA(1000);
  p.SetB(2000);
  p.Keisan();

  cout << "wa=" << p.Wa() << endl;
  
  
  // getchar();
  return 0;
}*/

/*#include<iostream>

class Total{
private:
  long n;
  long sum;
public:
  void SetN(void);
  long Sum(void);
  void Keisan(void);
};

void Total::SetN(long m)
{
  n=m;
}

void Total::Keisan(void){
  for(n=0;n;)
}*/


/*#include<iostream>

void main(){
  char line[512];
  cout << "なんか入力して終了はCTRL+Zを押して"<< endl;

  while(cin.getline(line,sizeof(line)))
    cout << line << endl
}*/


/*#include <iostream>
using namespace std;

class Integer{
public:
  int m_value;

  Integer();
  Integer(int num);
  void Show();
  
  
};

Integer::Integer(){
  m_value=0;
}

Integer::Integer(int num){
  m_value=num;
}

void Integer::Show(){
  cout << m_value << endl;
}

int main(){
  Integer a;
  Integer b(100);
  Integer c(40);

  a.Show();
  b.Show();
  c.Show();
  }*/



/*#include <iostream>
#include <cstdlib>
using namespace std;

const int INTARRAY_SIZE=100;

class IntArray{
public:
  IntArray();
  int Get(int i);
  void Set(int i,int value);
private:
  void CheckIndex(int i);
  int m_arrey[INTARRY_SIZE];
  
    
};


int Array::Get(int i){
  CheckIndex(i);
  return m_array[i];
}

int Array::Set(int i,int value){
  CheckIndex(i);
  m_array[i]=value;
}

int Array::CheckIndex(int i){
  if(i<=0 && i<INTARRAY_SIZE){
    cout << "インデックスは正常です" << endl;
  }
  else{
    cout <<"インデックスは不正です" << endl;
    <<"値:"<< i << endl;
    exit(EXIT_FAILURE);
  }
  }*/

/*class Total{
private:
  long n;
  long sum;
public:
  void SetN(void);
  long Sum(void);
  void keisan(void);
};

void Total::SetN(long m ){
  n=m;
}

void Total::Keisan(void){
  sum=0;
  for(i=0;i<=n;i++){
    sum+=i;
  }
}


void Total::Sum(){
  return(sum);
}

int main(void){
  Total a;
  long n;

  cout <<"input-->";cin << n;

  a.SetN(n);
  a.Keisan();

  cout <<"sum=" << a.Sum() <<endl;

  return 0;
  }*/

/*#include <iostream>
using namespace std;

int main(){
  int a=0;
  a+=2;
  cout << "a += 2 -> a=" << a << endl;
  ++a;
  cout << "++a  -> a="  << a << endl;

  a = a*5+2;

  cout << "a=a*5+2 -> a="  <<a<<endl;

  
  }*/


/*#include<iostream>
#include<string>
using namespace std;

int main()
{
  int tosi;
  string name;
  cout <<" こんにちは。私はコンピュータです。"<<endl;
  cout <<"あなたの名前を入力してください。"<<endl;
  cin >> name;
  cout << name <<"さん。よろしく。"<<endl;
  cout << "失礼ですが、お年はいくつですか？"<<endl;
  cin >> tosi;
  cout << "なるほど。" <<tosi <<"歳ですか。" <<endl;
  cout << "私はもうすぐ1歳のマシンです" << endl;
  }*/

#include <iostream>
#include<string>
using namespace std;

class Inu
{
private:
  string name;
public:
  Inu(string s){
    name = s;
  }
  void naku(){
    cout << "ワン！俺は" << name <<"だ！" << endl;
    
  }
};

int main(){
  Inu poti("ポチ");
  Inu wannko("わんこ");
  cout << "鳴きます！" << endl;

  poti.naku();
  wannko.naku();
}
