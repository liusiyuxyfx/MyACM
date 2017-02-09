/*************************************************************************
     File Name: HDU3333.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月12日 星期六 12时54分53秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define lson root<<1
#define rson root<<1|1
using namespace std;
typedef long long LL;
const int MAXN=3e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Quer {
  int l,r,pos;
}quer[MAXN];
bool cmp (Quer a, Quer b) {
  return a.r < b.r;
}

LL sum[MAXN<<2];
LL a[MAXN];
LL ans[MAXN];

void Update(int root, int nstart, int nend, int target, int add) {
  if (nend < target || nstart > target) return;
  if (nstart == nend) {
    sum[root] += add;
    return;
  }
  int mid = (nstart + nend) >> 1;
  if (mid >= target) Update(lson, nstart, mid, target, add);
  if (mid < target) Update(rson, mid + 1, nend, target, add);
  sum[root] = sum[lson] + sum[rson];
}

LL Query(int root, int nstart, int nend,int qstart, int qend) {
  if (nstart >=qstart && nend <= qend) return sum[root];
  int mid = (nstart + nend) >> 1;
  LL ans = 0;
  if (qstart <= mid) ans += Query(lson, nstart, mid, qstart, qend);
  if (qend > mid) ans += Query(rson, mid + 1, nend, qstart, qend);
  return ans;
}

map <LL,int> mp;
int main() {
  int T;
  int Q,l,r;
  scanf("%d", &T);
  while (T--) {
    MEM(sum, 0);
    mp.clear();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
      scanf("%d %d", &quer[i].l, &quer[i].r);
      quer[i].pos = i;
    }
    int j = 1;
    sort(quer, quer + Q, cmp);
    for (int i = 0; i < Q; ++i) {
      for (; j <= quer[i].r; ++j) {
        if (mp[a[j]]!=0) Update(1, 1, n, mp[a[j]], -a[j]);
        mp[a[j]] = j;
        Update(1, 1, n, j, a[j]);
      }
      ans[quer[i].pos] = Query(1, 1, n, quer[i].l, quer[i].r);
    }
    for (int i = 0; i < Q; ++i) {
      printf("%lld\n", ans[i]);
    }
  }
}


      




