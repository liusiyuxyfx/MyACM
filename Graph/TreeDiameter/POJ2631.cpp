
/*************************************************************************
     File Name: A.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月04日 星期五 21时29分59秒
************************************************************************/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e4+10;
const int MAXE=2e4+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge {
  int u, v, w, next;
}edge[MAXE];

int head[MAXN], dis[MAXN], top;

void Addedge(int u, int v, int w) {
  edge[top].u=u,edge[top].v=v,edge[top].w=w,edge[top].next=head[u],head[u]=top++;
}

int MAX(int a,int b) {
  return a > b ? a : b;
}
void Dfs(int u, int pre, int cur) {
  dis[u] += cur;
  for (int i = head[u]; i!=-1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == pre) continue;
    Dfs(v, u, cur + edge[i].w);
  }
  return;
}

int main() {
  int u,v,w,maxpos,ans=0;
  top=0;
  MEM(head,-1);
  MEM(dis,0);
  int cnt = 0;
  while (~scanf("%d %d %d", &u, &v, &w)) {
    Addedge(u, v, w);
    Addedge(v, u, w);
    cnt++;
  }
  Dfs(1, -1, 0);
  maxpos=0;
  for (int i=1; i <= cnt + 1; ++i) 
    if (ans < dis[i]) 
      ans = dis[i], maxpos = i;
  MEM(dis, 0);
  Dfs(maxpos, -1, 0);
  ans = 0;
  for (int i=1; i <= cnt + 1; ++i) ans = max(dis[i], ans);
  printf("%d\n", ans);
}

