/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月12日 星期二 14时04分06秒
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
char a[1010],temp[4],b[5];
void exchange(int first,int second,int third)
{
  temp[0]=b[first];
  temp[1]=b[second];
  temp[2]=b[third];
  temp[3]='\0';
}
int judge()
{
  if(strstr(a,temp)!=NULL)return 1;
  return 0;
 }
int main()
{
  int T;
  cin>>T;
  while(T--){
  cin>>a>>b;
  if(strstr(a,b)!=NULL){puts("good");continue;}

  exchange(0,1,2);
   // puts(temp);
  if(judge()){puts("almost good");continue;}
  exchange(0,1,3);
   // puts(temp);
  if(judge()){puts("almost good");continue;}
  exchange(1,2,3);
   // puts(temp);
  if(judge()){puts("almost good");continue;}
  exchange(0,2,3);
   // puts(temp);
  if(judge()){puts("almost good");continue;}

  puts("none");
  }
}

