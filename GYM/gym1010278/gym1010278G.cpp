/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月12日 星期二 14时06分29秒
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
int main()
{
  int T;
  int h,w,n;
  cin>>T;
  while(T--){
    cin>>h>>w>>n;
    int t=2*w-2;
    int y=h%t;
    int x=h/t;
    if(y==0){
      if(n!=w)puts("No");
      else
      puts("Yes");
    }
    else if(y<=w){
      if(y!=n)
      puts("No");
      else
      puts("Yes");
    }
    else{
      if(w-(y-w)!=n)
      puts("No");
      else
      puts("Yes");
    }
  }
}

