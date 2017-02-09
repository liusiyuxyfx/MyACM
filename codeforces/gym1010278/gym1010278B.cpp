/**********************************************************************
File Name: 1.cpp
ID: Liusiyu
BLOG: http://blog.csdn.net/r_o_j
LANG: C++ 
Mail: 779532360@qq.com 
Created Time: 2016年07月12日 星期二 13时09分20秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <deque>
#include <vector>
#include <map>
#include <list>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <utility>
#include <complex>
#include <numeric>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define MAX(a,b) (a)>(b)?(a):(b);
#define MIN(a,b) (a)<(b)?(a):(b)
#define APS(a) (a)>0?(a):-(a)
#define FL(s,n,a) fill(s,s+n,a);
#define MAPIT(a,b) map<a,b>::iterator it;
#define VECIT(type) vector<type>::iterator it;
#define SETIT(type) set<type>::iterator it;
using namespace std;
typedef long long ll;
const int MAXN=1e2+10;
//const int MINN=;
const int INF=0x3f3f3f3f;
char a[110],b[110];
int main()
{
  int T;
  int flag;
  cin>>T;
  while(T--){
    flag=1;
    cin>>a>>b;
    int lena=strlen(a);
    int lenb=strlen(b);
    if(lena!=lenb){
      puts("No");
      continue;
    }
    for(int i=0;i<lena;i++){
      if(a[i]>='A'&&a[i]<='Z')
      a[i]+=32;
      if(b[i]>='A'&&b[i]<='Z')
      b[i]+=32;
      if(a[i]=='p')
      a[i]='b';
      if(b[i]=='p')
      b[i]='b';
      if(a[i]=='i')
      a[i]='e';
      if(b[i]=='i')
      b[i]='e';
      if(a[i]!=b[i]){
        flag=0;
       // printf("%c %c",a[i],b[i]);
        break;
      }
    }
    if(flag)puts("Yes");
    else puts("No");
  }
}

