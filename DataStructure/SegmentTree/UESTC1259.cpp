/*************************************************************************
     File Name: UESTC1259.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月14日 星期一 17时12分39秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
#define lson root<<1
#define rson root<<1|1
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Node {
  int val, changemark;
  bitset <101> bs;
}node[MAXN<<2];
int N, M;
char s[MAXN];

void PushUp(int root) {
  node[root].bs = node[lson].bs | node[rson].bs;
}

void PushDown(int root) {
  if (node[root].changemark != 0) {
    node[lson].bs.reset();
    node[rson].bs.reset();
    node[lson].bs.set(node[root].changemark-1);
    node[rson].bs.set(node[root].changemark-1);
     //printf("node[%d]and node[%d] 's bs change to\n",lson,rson);
     //cout<<node[lson].bs<<endl;
    node[lson].changemark = node[root].changemark;
    node[rson].changemark = node[root].changemark;
    node[root].changemark = 0;
  }
}
void BuildTree(int root, int nstart, int nend) {
  if (nstart == nend) {
    int x;
    scanf("%d",&x);
    node[root].bs.reset();
    node[root].bs.set(x-1);
    node[root].changemark = 0;
    return;
  }
  int mid = (nstart + nend) >> 1;
  BuildTree(lson, nstart, mid);
  BuildTree(rson, mid + 1, nend);
  PushUp(root);
}

void Update(int root, int nstart, int nend, int ustart, int uend, int x) {
  if (ustart > nend || uend < nstart) return;
  if (ustart <= nstart && nend <= uend) {
    node[root].bs.reset();
    node[root].bs.set(x-1);
    //printf("node[%d]'s bs change to\n",root);
     //cout<<node[root].bs<<endl;
    node[root].changemark = x;
    return;
  }
  PushDown(root);
  int mid = (nstart + nend) >> 1;
  if (ustart <= mid) Update(lson, nstart, mid, ustart, uend, x);
  if (mid < uend) Update(rson, mid + 1, nend, ustart, uend, x);
  PushUp(root);
}

bitset<101> Query(int root, int nstart, int nend, int qstart, int qend) {
  if (qstart <= nstart && nend <= qend) {
      return node[root].bs;
  }
  PushDown(root);
  bitset<101>ans;
  int mid = (nstart + nend) >> 1;
  if (qstart <= mid) ans |= Query(lson, nstart, mid ,qstart, qend);
  if (qend > mid) ans |= Query(rson, mid + 1, nend, qstart, qend);
  return ans;
}

int main() {
  scanf("%d %d", &N, &M);
  BuildTree(1, 1, N);
  int T;
  scanf("%d", &T);
  int l ,r, x;
  bitset<101>ans;
  while (T--) {
    scanf("%s", s);
    if (s[0] == 'Q') {
      scanf("%d %d", &l, &r);
      ans = Query(1, 1, N, l, r);
      printf("%d\n", (int)ans.count());
    } else {
      scanf("%d %d %d", &l, &r, &x);
      Update(1, 1, N, l, r, x);
    }
  }
}


