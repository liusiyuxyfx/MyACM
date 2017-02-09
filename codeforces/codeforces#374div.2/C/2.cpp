/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 18时57分09秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int N,M,T;
struct Edge{
  int u,v,c,nex;
}edge[MAXM];
int head[MAXN];
int path[MAXN][MAXN];
int dp[MAXN][MAXN];
int top;
void Addedge(int u,int v,int c) {
  edge[top].u=u;
  edge[top].v=v;
  edge[top].c=c;
  edge[top].nex=head[u];
  head[u]=top++;
}
void init(){
  MEM(vis,0);
  MEM(dp,INF);
  top=0;
}
void DP_work() {
  fill(dp,T+1,sizeof dp);
  dp[1][1]=0;
  for (int i=2; i<=n; ++i) {
    for (int j=0; j<top; ++j) {
      int u=edge[j].u,v=edge[j].v,c=edge[j].c;
      if (dp[u][i-1]+c<dp[v][i]) {
        dp[v][i]=dp[i-1][u]+c;
        path[v][i]=u;
      }
    }
    if (dp[i]
  }

  if (dp
int main() {
  cin>>N>>M>>T;
  int u,v,c;
  top=0;
  init();
  for (int i=0; i<=m; ++i){
    scanf("%d  %d  %d",&u,&v,&c);
    Addedge(u,v,c);
  }
  DP_work();
