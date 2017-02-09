/*************************************************************************
     File Name: POJ1849.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月06日 星期日 09时34分43秒
************************************************************************/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5 +10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Edge {
  int v, w;
  Edge* next;
}edge[MAXN<<1], *head[MAXN];

int dis[MAXN];
int top;
void Addedge(int u, int v, int w) {
  Edge* p = &edge[top++];
  p->v = v, p->w = w, p->next = head[u], head[u] = p;
}

void Dfs(int u, int pre, int cur) {
  dis[u] += cur;
  for (Edge* p = head[u]; p; p = p->next) {
    int v = p->v;
    if (v == pre) continue;
    Dfs(v, u, cur + p->w);
  }
}

int main() {
  int M,S;
  while (~scanf("%d %d", &M, &S)) {
    int u, v, w;
    top = 0 ;
    MEM(head, 0);
    int sum=0;
    for (int i = 0; i < M - 1; ++i) {
      scanf("%d %d %d", &u, &v, &w);
      Addedge(u, v, w);
      Addedge(v, u, w);
      sum += w;
    }
    sum *= 2;
    int pos = 0, MAX = 0;
    MEM(dis, 0);
    Dfs(S , -1 , 0);
    for (int i = 1; i <= M; ++i) 
      if (dis[i] > MAX) 
        MAX = dis[i], pos = i;
    MEM(dis, 0);
    Dfs(pos, -1, 0);
    MAX = 0;
    for (int i = 1; i <= M; ++i) 
      MAX = max(dis[i], MAX);
    printf("%d\n", sum - MAX);
  }
}

