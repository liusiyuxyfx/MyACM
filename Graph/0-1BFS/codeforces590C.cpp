/*************************************************************************
     File Name: codeforces590C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 22时33分31秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[4][MAXN][MAXN];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m;

struct Node {
  int x,y;
}now,nex;
void bfs(int num) {
  MEMINF(dis[num]);
  MEM(vis,0);
  deque<Node>q;
  Node s;
  for (int i=1 ; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      if (mp[i][j]==num+'0') {
        s.x=i;
        s.y=j;
        q.push_front(s);
        dis[num][i][j]=0;
      }
    }
  }
  while(!q.empty())  {
    now=q.front();
    q.pop_front();
    if (vis[now.x][now.y]) continue;
    vis[now.x][now.y]=true;
    for (int i=0; i<4; ++i) {
      nex=now;
      nex.x+=dx[i];
      nex.y+=dy[i];
      if (nex.x<1||nex.x>n||nex.y<1||nex.y>m||mp[nex.x][nex.y]=='#') continue;
      int step=0;
      if (mp[nex.x][nex.y]=='.') step=1;
      if (dis[num][nex.x][nex.y]>dis[num][now.x][now.y]+step){
        dis[num][nex.x][nex.y]=dis[num][now.x][now.y]+step;
        if (mp[now.x][now.y]=='.'||mp[nex.x][nex.y]=='.') q.push_back(nex);
        else q.push_front(nex);
      }
    }
  }
}



    
int main() {
  cin>>n>>m;
  for (int i=1; i<=n; ++i) 
    scanf("%s",mp[i]+1);
  MEMINF(dis);
  bfs(1);
  bfs(2);
  bfs(3);
  int ans=INF;
  /*
  for (int i=1; i<=3; ++i) {
    for (int j=1; j<=n; ++j) {
      for (int k=1; k<=m; ++k) {
        printf("%10d\t",dis[i][j][k]);
      }
      puts("");
    }
    puts("\n");
  }

  */
   for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      if (mp[i][j]=='#') continue;
      if (dis[1][i][j]==INF||dis[2][i][j]==INF||dis[3][i][j]==INF) continue;
      int flag=0;
        if (mp[i][j]=='.') flag=2;
      if (ans>dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-flag) {
        ans=dis[1][i][j]+dis[2][i][j]+dis[3][i][j]-flag;
      }
    }
  }
  if (ans==INF) puts("-1");
  else printf("%d\n",ans);
}



