/*************************************************************************
     File Name: SPOJKATHTHI.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 09时01分10秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int dp[MAXN][MAXN];
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m;
struct Node {
  int x;
  int y;
  int step;
}now,nex;

deque<Node>q;
void bfs() {
  dp[0][0]=0;
  now.x=0,now.y=0;
  now.step=0;
  q.push_front(now);
  while(!q.empty()) {
    now=q.front();
    q.pop_front();
    for (int i=0; i<4; ++i) {
      nex=now;
      nex.x+=dx[i];
      nex.y+=dy[i];
      if (nex.x<0||nex.x>=n||nex.y<0||nex.y>=m)continue;
      nex.step=1;
      if (mp[now.x][now.y]==mp[nex.x][nex.y]) nex.step=0;
      if (dp[now.x][now.y]+nex.step<dp[nex.x][nex.y]) {
        dp[nex.x][nex.y]=dp[now.x][now.y]+nex.step;
        nex.step==1? q.push_back(nex):q.push_front(nex);
      }
    }
  }
}


int main() {
  int T;
  cin>>T;
  while(T--) {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; ++i) scanf("%s",mp[i]);
    MEMINF(dp);
    MEM(vis,false);
    bfs();
    printf("%d\n",dp[n-1][m-1]);

  }
}

