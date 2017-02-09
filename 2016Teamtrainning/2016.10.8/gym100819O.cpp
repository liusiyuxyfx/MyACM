/*************************************************************************
     File Name: gym100819O.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月08日 星期六 12时13分18秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=505;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int m,n;
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

struct Node {
  int x,y;
  int step;
};
int ans;

bool bfs() {
  queue<Node>q;
  Node s;
  s.x=1,s.y=1,s.step=0;
  q.push(s);
  vis[1][1]=true;
  int jump;
  while (!q.empty()) {
    Node u=q.front();
    q.pop();
    if (u.x==n&&u.y==m) {
      ans=u.step;
      return true;
    }
    vis[u.x][u.y]=true;
    jump=mp[u.x][u.y]-'0';
    Node v;
    for (int i=0; i<4; ++i) {
      v=u;
      v.x+=dx[i]*jump;
      v.y+=dy[i]*jump;
      v.step++;
      if(vis[v.x][v.y]) continue;
      if(v.x<1||v.x>n||v.y<1||v.y>m) continue;
      vis[v.x][v.y]=true;
      q.push(v);
    }
  }
  return false;
}
  


int main() {
  cin>>n>>m;
  for (int i=1; i<=n; ++i) scanf("%s",mp[i]+1);
  MEM(vis,false);
  if(bfs()) printf("%d\n",ans);
  else puts("IMPOSSIBLE");
}
