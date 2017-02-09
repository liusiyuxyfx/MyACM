/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月19日 星期二 22时02分08秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define MAX(a,b) (a)>(b)?(a):(b);
#define MIN(a,b) (a)<(b)?(a):(b);
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
int main(){
  int dp[MAXN][3];
  int a[MAXN];
  int n;
  while(cin>>n){
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=2;j++)
    dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
      int temp=min(dp[i-1][1],dp[i-1][2]);
      dp[i][0]=1+min(dp[i-1][0],temp);
      if(a[i]>=2)
      dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
      if(a[i]&1)
      dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
    }
    int ans=min(dp[n][1],dp[n][2]);
    ans=min(dp[n][0],ans);
    cout<<ans<<endl;
  }
}

