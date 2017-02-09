/*************************************************************************
     File Name: CF701E.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月10日 星期四 21时44分54秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Edge{
  int v;
  Edge* next;
} *head[MAXN],edge[MAXN<<1];

int top,n,k;
bool uni[MAXN];
void Addedge(int u, int v) {
  Edge* p = &edge[top++];
  p->v = v, p->next = head[u], head[u] = p;
}

int balance[MAXN];
int DFS(int u, int pre) {
  int size = uni[u]? 1:0;
  for (Edge* p = head[u]; p; p = p->next) {
    int v = p->v;
    if (v == pre) continue;
    int size_v = DFS(v, u);
    size += size_v;
    balance[u] = max(balance[u], size_v);
  }
  balance[u] = max(balance[u],2*k - size);
  return size;
}

LL ans;
void DFS2(int u,int pre, int len) {
  if (uni[u]) ans += len;
  for (Edge* p = head[u]; p; p = p->next) {
    int v = p->v;
    if (v == pre) continue;
    DFS2(v, u, len + 1);
  }
}

int main () {
  scanf("%d %d", &n, &k);
  MEM(head, 0);
  int u, v;
  for (int i = 0; i < 2 * k; ++i) {
    scanf("%d", &v);
    uni[v] = true;
  }
  for (int i = 1; i < n; ++i) {
   scanf("%d %d", &u, &v); 
   Addedge(u, v);
   Addedge(v, u);
  }
  DFS(1, 0);
  int minpos=0;
  balance[0] = INF;
  for (int i = 1; i <= n; ++i) {
    if (balance[minpos] > balance[i]) {
      minpos = i;
    }
  }
  DFS2(minpos, 0, 0);
  printf("%I64d\n",ans);
}

