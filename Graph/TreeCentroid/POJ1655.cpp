/*************************************************************************
     File Name: POJ1655.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月08日 星期二 20时41分09秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e4 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Edge {
  int v;
  Edge* next;
} *head[MAXN], edge[MAXN << 1];

int top, n, balance[MAXN];
void Addedge(int u, int v) {
  Edge* p = &edge[top++];
  p->v = v, p->next = head[u], head[u] = p;
}

int DFS(int u, int pre) {
  int size = 1;
  for (Edge* p = head[u]; p; p = p->next) {
    int v = p->v;
    if (v == pre) continue;
    int size_v = DFS(v, u);
    size += size_v;
    balance[u] = max(balance[u], size_v);
  }
  balance[u] = max(balance[u], n - size);
  return size;
}

int main() {
  int T, u, v;
  scanf("%d", &T);
  while (T--) {
    MEM(head, 0);
    MEM(balance, 0);
    top = 0;
    scanf("%d", &n);
    for (int i = 0; i < n - 1;++i) {
      scanf("%d %d", &u, &v);
      Addedge(u, v);
      Addedge(v, u);
    }
    DFS(1, -1);
    int minpos = 0;
    balance[0] = INF;
    for (int i = 1; i <= n; ++i) 
      if (balance[i] < balance[minpos])
       minpos = i;
    printf("%d %d\n",minpos, balance[minpos]);
  }
}

