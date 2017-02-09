/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月12日 星期二 13时45分09秒
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
char mp[MAXN][MAXN];
int main()
{
  int T;
  cin>>T;
  int R,C,I;
  int r1,c1,r2,c2;
  while(T--){
    cin>>R>>C>>I;
    for(int i=1;i<=R;i++)
    for(int j=1;j<=C;j++)
    mp[i][j]='.';
    while(I--){
      char color;
      cin>>r1>>c1>>r2>>c2>>color;
      for(int i=r1;i<=r2;i++)
      for(int j=c1;j<=c2;j++)
      mp[i][j]=color;
    }
    for(int i=1;i<=R;i++){
      for(int j=1;j<=C;j++)
      printf("%c",mp[i][j]);
     puts("");
    }
  }
}
