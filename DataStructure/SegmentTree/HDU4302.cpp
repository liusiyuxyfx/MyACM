/*************************************************************************
     File Name: HDU4302.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月13日 星期日 20时57分55秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
#define Max(a,b) (a) > (b) ? (a) : (b)
#define Min(a,b) (a) < (b) ? (a) : (b)
#define lson root<<1
#define rson root<<1|1
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int cakes[MAXN<<2];

void PushUp(int root) {
  cakes[root] = cakes[lson] + cakes[rson];
}
void Update(int root, int nstart, int nend, int target, int add) {
  if (nend < target || nstart > target) return;
  if (nstart == nend) {
    cakes[root] += add;
    //printf("cakes[%d] changet to %d\n", root, cakes[root]);
    return;
  }
  int mid = (nstart + nend) >> 1;
  if (target <= mid) Update(lson, nstart, mid, target, add);
  if (target > mid) Update(rson, mid + 1, nend, target, add);
  PushUp(root);
}

int Query(int root, int nstart, int nend, int qstart,int qend,int left) {
  if (nstart > qend || qstart >nend || !cakes[root]) return -1;
  if (nstart == nend) {
    if (cakes[root]) return nstart;
  }
  int mid = (nstart + nend) >> 1;
  int ans;
  if (left) {
    ans = Query(rson, mid + 1, nend, qstart, qend, left);
    if (ans == -1) ans = Query(lson, nstart, mid, qstart, qend, left);
  } else {
    ans = Query(lson, nstart, mid, qstart, qend, left);
    if (ans == -1) ans = Query(rson, mid + 1, nend, qstart, qend, left);
  }
  return ans;
}

int main() {
  int T, op, pos, target, dir, len, eat;
  LL ans;
  int n, m;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    //printf("Case %d: \n",cas);
    scanf("%d %d", &n, &m);
    MEM(cakes, 0);
    ans = pos = 0;
    dir = 1;
    int cnt = 0;
    while (m--) {
      scanf("%d", &op);
      //printf("op %d is %s **********************\n",++cnt, (op? "Q" : "A"));
      if (op) {
        int l = Query(1, 0, n, 0, pos, 1);
        int r = Query(1, 0 ,n, pos, n, 0);
        int ll = pos - l;
        int rr = r - pos;
       // printf("Find l = %d , r = %d  rr=%d, ll=%d\n",l ,r,rr, ll);
        if (l == -1 && r == -1) {
          len = 0, eat = 0;
        } else if (l == -1 && r != -1) {
          //puts("Move to right");
          dir = 1, len = rr, pos = r, eat = 1;
        } else if (l != -1 && r == -1) {
          dir = 0, len = ll, pos = l, eat = 1;
          //puts("Move to left");
        } else if (ll < rr) {
          dir = 0, len = ll, pos = l, eat = 1;
        } else if (ll > rr) {
          dir = 1, len = rr ,pos = r, eat = 1;
        } else if (rr == ll) {
          if (dir) {
            len = rr, pos = r;
          } else {
            len = ll, pos = l;
          }
          eat = 1;
        }
        //printf("len = %d, pos = %d ,dir = %d\n", len, pos, dir);
        ans += len;
        if (eat) Update(1, 0, n, pos, -1);
      } else {
       scanf("%d", &target);
       Update(1, 0, n, target, 1);
      }
    }
    printf("Case %d: ",cas);
    printf("%lld\n",ans);
  }
}

        


