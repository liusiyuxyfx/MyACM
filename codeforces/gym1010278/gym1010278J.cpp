/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月12日 星期二 15时55分18秒
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
int mi[MAXN],shop[MAXN],dp[MAXN],level[MAXN];
int num;
void gemi()
{
  int i=1;
  num=1;
  mi[0]=1;
  while(i<1000000){
    i*=2;
    mi[num++]=i;
  //  printf("%d ",i);
  }
//  puts("");

}



void upgradelevel(int a,int j)
{
  int sum=0;
  for(int i=num-2;i>=0;i--)
  if(a%mi[i]==0){
    level[j]=i;
    break;
  }
}

int main()
{
  int T;
  gemi();
  //puts("num");
  //cout<<num<<endl;
  cin>>T;
  while(T--){
    int n;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>shop[i];
      upgradelevel(shop[i],i);
      dp[i]=level[i];
    }
    for(int i=2;i<=n;i++){
    for(int j=1;j<i;j++)
    if(shop[i]>shop[j])
    dp[i]=MAX(level[i]+dp[j],dp[i]);
    }
    for(int i=1;i<=n;i++)
    ans=MAX(ans,dp[i]);
    cout<<ans<<endl;
  }
}

