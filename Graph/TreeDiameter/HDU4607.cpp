/*************************************************************************
     File Name: HDU4607.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月06日 星期日 14时40分57秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;

struct Edge {
  int v;
  Edge* next;
} *head[MAXN], edge[MAXN << 1];

int top;
int maxdis,maxpos;

void Addedge(int u,int v) {
  Edge* p = &edge[top++];
  p->v = v; p->next = head[u]; head[u] = p;
}

void Dfs(int u, int pre, int dis) {
  if (dis > maxdis) {
    maxdis = dis;
    maxpos = u;
  }
  for (Edge *p = head[u]; p; p = p->next) {
    int v= p->v;
    if (v == pre) continue;
    Dfs(v, u, dis + 1);
  }
}

int main() {
  int T;
  scanf("%d",&T);
  while (T--) {
    top = 0;
    MEM(head, 0);
    int n,k,q;
    scanf("%d %d",&n, &q);
    int u, v;
    for (int i = 1; i < n; ++i) {
      scanf("%d %d", &u, &v);
      Addedge(u, v);
      Addedge(v, u);
    }

    maxpos = maxdis = -1;
    Dfs(1, -1, 1);
    int temp = maxpos;
    maxpos = maxdis = -1;
    Dfs(temp, -1, 0);
    for (int i=1; i<=q; ++i) {
      scanf("%d", &k);
      int ans;
      if (k <= maxdis) ans=k-1;
      else ans = maxdis + (k - maxdis -1) * 2;
      printf("%d\n", ans);
    }
  }
}

