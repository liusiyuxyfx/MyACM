/*************************************************************************
     File Name: CF685B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月10日 星期四 16时48分14秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=3e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Edge{
  int v;
  Edge* next;
} *head[MAXN],edge[MAXN<<1];

int pre[MAXN], top;
int size[MAXN], son[MAXN], ans[MAXN], balance[MAXN];
int n,m;
void Addedge(int u,int v) {
  Edge* p = &edge[top++];
  p->v = v, p->next = head[u], head[u] = p;
}

void DFS(int u) {
  size[u] = 1;
  int maxsize = 0;
  for (Edge* p = head[u]; p; p = p->next) {
    int v = p->v;
    DFS(v);
    size[u] += size[v];
    if (size[v] > maxsize) {
      maxsize = size[v];
      son[u] = v;
    }
  }
  if (size[u] == 1) {
    ans[u] = u;
    return;
  }
  int tmp = ans[son[u]];
  while ((size[u] - size[tmp]) * 2 > size[u]) {
    tmp = pre[tmp];
  }
  ans[u] = tmp;
}

int main() {
  scanf("%d %d", &n, &m);
  int v;
  top = 0;
  MEM(head, 0);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &v);
    Addedge(v, i);
    pre[i] = v;
  }
  DFS(1);
  while (m--) {
    scanf("%d",&v);
    printf("%d\n",ans[v]);
  }
}

