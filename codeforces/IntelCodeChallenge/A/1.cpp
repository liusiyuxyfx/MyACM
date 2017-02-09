/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月01日 星期六 21时18分52秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

char s[10];
int main(){
  int n,x,y;
 
  while(~scanf("%d",&n)){
  cin>>s;
  sscanf(s,"%d:%d",&x,&y);
  if (n==12) {
    int x1=x/10;
    int x2=x%10;
    int y1=y/10;
    int y2=y%10;
    if (x1==1&&x2>2){
      x1=0;
    }
    else if (x1>1&&x2!=0) {
      x1=0;
    }
    else if (x1>1&&x2==0) {
      x1=1;
    }
    else if (x1==0&&x2==0) {
      x1=1;
    }

      if (y1>5) y1=0;
    x=x1*10+x2;
    y=y1*10+y2;
  }
  else
     if (n==24) {
       int x1=x/10;
       int x2=x%10;
       int y1=y/10;
       int y2=y%10;
       if (x1>2) {
         x1=0;
       }else if (x1==2&&x2>3) {
         x2=0;
       }
       if (y1>5) y1=0;
  x=x1*10+x2;
  y=y1*10+y2;
     }
  printf("%02d:%02d\n",x,y);
}
}
