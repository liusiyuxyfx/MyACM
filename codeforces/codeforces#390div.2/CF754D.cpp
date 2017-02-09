/*************************************************************************
     File Name: CF754D.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月12日 星期四 10时45分49秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=3e5 +10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Node {
  int id;
  int l, r;
  bool operator <(const Node &a) const {
    return r > a.r;
  }
} no[MAXN],ne;
bool cmp (Node a, Node b) {
  return a.l < b.l;
}

int main() {
  int n, k;
  scanf("%d %d" , &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &no[i].l, &no[i].r);
    no[i].id = i;
  }
  sort(no, no + n, cmp);
  /*for (int i = 0 ;i < n; ++i) {
    printf("%d %d\n", no[i].l, no[i].r);
  }*/
  priority_queue<Node> q;
  int len = 0, ansl, ansr;
  for (int i = 0; i < n; ++i) {
    q.push(no[i]);
    if (q.size() > k) {
      q.pop();
    }
    if (q.size() < k) continue;
    ne = q.top();
    //printf("topnode:id = %d r = %d\n",ne.id, ne.r);
    if (ne.r - no[i].l + 1 > len) {
      len = ne.r - no[i].l + 1;
      ansl = no[i].l;
      ansr = ne.r;
    }
  }
  if (len != 0) {
    printf("%d\n", len);
    for (int i = 0; i < n; ++i) {
      if (no[i].l <= ansl && no[i].r >= ansr) {
        k--;
        printf("%d ", no[i].id + 1);
        if (!k) break;
      }
    }
  } else  {
    puts("0");
    for (int i = 0; i < k; ++i) {
      printf("%d ", i + 1);
    }
    puts("");
  }
}
