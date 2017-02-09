/*************************************************************************
     File Name: gym100625J.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月10日 星期一 22时33分18秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset((a),0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e2+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int n,m;
char mp[MAXN][MAXN];
int dis[500][MAXN][MAXN];
struct node {
  int x,y;
}s;
vector<node>res;
vector<node>pris;

bool vis[MAXN][MAXN];
void bfs(int num) {
  MEM(vis,false);
  deque<node>q;
  q.push_front(s);
  dis[num][s.x][s.y]=0;
  if (mp[s.x][s.y]=='#') dis[num][s.x][s.y]=1;
  while (!q.empty()) {
    node now=q.front();
    q.pop_front();
    if (vis[now.x][now.y]) continue;
    vis[now.x][now.y]=true;
    for (int i=0; i<4; ++i) {
      node nex=now;
      nex.x+=dx[i];
      nex.y+=dy[i];
      if (nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
      if (mp[nex.x][nex.y]=='*') continue;
      int flag=0;
      if (mp[nex.x][nex.y]=='#') flag=1;
      if (dis[num][nex.x][nex.y]>dis[num][now.x][now.y]+flag) {
        dis[num][nex.x][nex.y]=dis[num][now.x][now.y]+flag;
        if (flag) q.push_back(nex);
        else q.push_front(nex);
      }
    }
  }
}


int main () {
  int T;
  cin>>T;
  while (T--) {
    pris.clear();
    res.clear();
    MEMINF(dis);
    cin>>n>>m;
   node temp;
   int cnt=0;
    for (int i=1; i<=n; ++i) {
      scanf("%s",mp[i]+1);
      for (int j=1; j<=m; ++j) {
        temp.x=i,temp.y=j;
        if (mp[i][j]=='$') pris.push_back(temp);
        if (mp[i][j]!='*'&&(i==1||i==n||j==1||j==m))res.push_back(temp);
      }
    }
    
    for (int i=0; i<pris.size(); i++) {
      s=pris[i];
      bfs(i);
      cnt++;
    }
    for (int i=0; i<res.size(); ++i) {
      s=res[i];
      bfs(i+2);
      cnt++;
    }
    int ans=INF;
    /*
    for (int i=0; i<cnt; ++i) {
      for (int j=1; j<=n; ++j) {
        for (int k=1; k<=m; ++k) {
          if (dis[i][j][k]==INF) printf("INF  ");
          else printf("%3d  ",dis[i][j][k]);
        }
        puts("");
      }
      puts("\n");
    }
    */
    for (int i=2; i<cnt; ++i) {
      for (int j=1; j<=n; ++j) {
        for (int k=1; k<=m; ++k) {
          if (mp[j][k]=='*')continue;
          if (dis[0][j][k]==INF||dis[1][j][k]==INF||dis[i][j][k]==INF) continue;
          int flag=0;
          if (mp[j][k]=='#') flag=2;
          ans=min(ans,dis[0][j][k]+dis[1][j][k]+dis[i][j][k]-flag);
        }
      }
    }
    printf("%d\n",ans);
  }
}
