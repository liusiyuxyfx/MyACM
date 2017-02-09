/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月20日 星期六 21时02分57秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main(){
  int n,m;
  cin>>n>>m;
  char c;
  bool flag=false;
  int cnt=0;
  while(true){
    c=getchar();
    if (cnt==n*m) break;
    if(c==' '||c=='\n')continue;
    putchar(c);
    if(c=='Y'||c=='M'||c=='C'){
      cnt++;
      flag=true;
      break;
    }
  }

  if(flag) puts("#Color");
  else puts("#Black&White");
}

