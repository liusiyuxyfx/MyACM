
/*************************************************************************
     File Name: UVA11573.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 21时03分54秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));

using namespace std;
typedef long long LL;
const int MAXN=1e3+10;
const int INF=0x3f3f3f3f;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

struct Node {
  int x,y;
}s,t,now,nex;

bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int n,m,k;
char mp[MAXN][MAXN];
void bfs() {
  deque<Node>q;
  q.push_front(s);
  dis[s.x][s.y]=0;
  while (!q.empty()) {
    now=q.front();
    q.pop_front();
    if (now.x==t.x&&now.y==t.y) break;
    if (vis[now.x][now.y]) continue;
    vis[now.x][now.y]=1;
    for (int i=0; i<8; ++i) {
      nex=now;
      nex.x+=dx[i];
      nex.y+=dy[i];
      if (nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
      int flag=0;
      if (mp[now.x][now.y]-'0'==i) flag=1;
      if (dis[now.x][now.y]+!flag<dis[nex.x][nex.y]) {
        dis[nex.x][nex.y]=dis[now.x][now.y]+!flag;
        if (flag) q.push_front(nex);
        else q.push_back(nex);
      }
    }
  }
}
int main() {
  cin>>n>>m;
  for (int i=1; i<=n; ++i)
   scanf("%s",mp[i]+1);
  cin>>k;
  for (int i=0; i<k; ++i) {
   scanf("%d %d %d %d",&s.x,&s.y,&t.x,&t.y);
   MEMINF(dis);
   MEM(vis,0);
   bfs(); 
   printf("%d\n",dis[t.x][t.y]);
  }
}

