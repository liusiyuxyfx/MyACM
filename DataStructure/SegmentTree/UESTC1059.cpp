/*************************************************************************
     File Name: UESTC1059.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月14日 星期一 08时50分32秒
************************************************************************/
#include <cstdio>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
#define lson root<<1
#define rson root<<1|1
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Node {
  int val = 0;
  int addMark = 0;
}node[MAXN<<2];

struct Operation{
  int l,r,add,x;
  int id;
}op[MAXN];

int sub_a[MAXN];
int size, optop, atop;
int getHash(int num) {
  return upper_bound(sub_a, sub_a + size, num) - sub_a;
}

void PushDown(int root) {
  if (node[root].addMark != 0){
    node[lson].addMark += node[root].addMark;
    node[rson].addMark += node[root].addMark;
    node[lson].val += node[root].addMark;
    node[rson].val += node[root].addMark;
    node[root].addMark = 0;
  }
}

void Update(int root, int nstart, int nend, int ustart, int uend, int add) {
  if (ustart > nend || uend < nstart) return;
  if (ustart <= nstart && uend >= nend) {
    node[root].addMark += add;
    node[root].val += add;
    return;
  }
  PushDown(root);
  int mid = (nstart + nend) >> 1;
  Update(lson , nstart, mid, ustart, uend, add);
  Update(rson, mid + 1, nend, ustart, uend, add);
}

int Query(int root ,int nstart, int nend, int target) {
  if (nstart == nend) return node[root].val;
  PushDown(root);
  int mid = (nstart + nend) >> 1;
  if (target <= mid )  return Query(lson, nstart, mid ,target);
  else if (target > mid) return Query(rson, mid + 1, nend, target);
}
int l, r, x;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i){
    scanf("%d", &op[i].id);
    if (op[i].id) {
      scanf("%d", &op[i].x);
      sub_a[atop++] = op[i].x;
    } else {
      scanf("%d %d %d", &op[i].l, &op[i].r, &op[i].add);
      sub_a[atop++] = op[i].l;
      sub_a[atop++] = op[i].r;
    }
  }
  //printf("atop = %d  ",atop);
  sort(sub_a,sub_a + atop);
  size = unique(sub_a, sub_a + atop) - sub_a;
  for (int i = 0; i < m; ++i) {
    //printf("operation %d: %c------",i, op[i] ? 'Q' : 'A');
    if (op[i].id) {
     // printf("Find x:%d and after hash become ",quop[qutop].x);
      int target = getHash(op[i].x);
      //printf("%d\n",target);
      printf("%d\n",Query(1, 1, size, target));
    } else {
      //printf("Update(%d,%d) and after hash become ",upop[uptop].l,upop[uptop].r);
      l = getHash(op[i].l);
      r = getHash(op[i].r);
      x = op[i].add;
      //printf("(%d,%d)\n",l,r);
      Update(1, 1, size, l, r, x);
    }
  }
}
