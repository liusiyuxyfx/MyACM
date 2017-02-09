/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月12日 星期二 14时35分22秒
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
const int MAXN=1e5+10;
//const int MINN=;
const int INF=0x3f3f3f3f;
int main()
{
  int time;
  int roada[MAXN];
  int roadb[MAXN];
  int T;
  cin>>T;
  while(T--){
    MEM(roada,0);
    MEM(roadb,0);
    int n,va,vb;
    cin>>n>>va>>vb;
    int flag=1;
    time=0;
    int t1=va,t2=vb;
    va%=n,vb%=n;
    while(flag){
      time++;
      va%=n;
      vb%=n;
      roada[va]++;
      roadb[vb]++;
      if((roada[va]&&roadb[va])||(roada[vb]&&roadb[vb])){
        cout<<time<<endl;
        flag=0;
      }
      va+=t1;
      va%=n;
      vb+=t2;
      vb%=n;
    }
  }
}


