/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月15日 星期五 01时33分21秒
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
  ll t,s,x;
  while(cin>>t>>s>>x){
    ll sum=x-t;
    if(sum<0){
      cout<<"NO"<<endl;
      continue;
    }
    if(sum<s){
      if(sum!=0)
      cout<<"NO"<<endl;
      else
      cout<<"YES"<<endl;
    }
    else
      if(sum%s==1||sum%s==0)
      cout<<"YES"<<endl;
  }
}


