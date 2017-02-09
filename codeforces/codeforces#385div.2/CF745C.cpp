/*************************************************************************
     File Name: CF745C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月14日 星期六 09时27分15秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN=1010;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int fa[MAXN];
int flag[MAXN];
int home[MAXN];
int sum[MAXN];

int find(int x) {
  if(x != fa[x]) {
    return fa[x] = find(fa[x]);
  }
  return x;
}

void Union(int fx, int fy) {
  fx = find(fx);
  fy = find(fy);
  if (fx != fy) {
    fa[fy] = fx;
    sum[fx] += sum[fy];
    flag[fx] += flag[fy];
  }
} 

int Total(int x) {
  return x * (x - 1) / 2;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    sum[i] = 1;
    flag[i] = 0;
  }

  for (int i = 0; i < k; ++i) {
    scanf("%d", &home[i]);
    flag[home[i]] = 1;
  }
  int u, v;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &u, &v);
    Union(u, v);
  }
  int suml = 0;
  int sumul = 0;
  int ans = 0;
  int maxnum = 0;
  for (int x = 1; x <= n; ++x) {
    if (x != fa[x]) continue;
    if (!flag[x]) sumul += sum[x];
    else {
      maxnum = max(sum[x], maxnum);
      ans += Total(sum[x]);
    }
  }
  ans += Total(sumul + maxnum) - Total(maxnum) - m;
  printf("%d\n", ans);
}

