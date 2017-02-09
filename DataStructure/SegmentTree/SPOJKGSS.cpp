/*************************************************************************
     File Name: SPOJKGSS.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月12日 星期六 11时43分50秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define lson root<<1
#define rson root<<1|1
using namespace std;
typedef long long LL;
const int MAXN=1e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Node {
  int val1,val2;
}node[MAXN<<2];

void PushUp(int root) {
  node[root].val1 = max(node[lson].val1, node[rson].val1);
  node[root].val2 = max(min(node[lson].val1, node[rson].val1),
                        max(node[lson].val2, node[rson].val2));
  //printf("   pushup : node[%d].val1= %d node[%d].val2 = %d\n",root, node[root].val1, root, node[root].val2);
}

void BuildTree(int root, int istart, int iend) {
  if(istart == iend) {
    int a;
    scanf("%d", &a);
    node[root].val1 = a;
    node[root].val2 = 0;
  }
  else {
    int mid = (istart + iend) >> 1;
    BuildTree(lson, istart, mid);
    BuildTree(rson, mid + 1, iend);
    PushUp(root);
  }
}

void Update(int root, int nstart, int nend, int target, int change) {
  //printf("Update to root %d\n",root);
  if(target < nstart || target > nend) return;
  if(nstart == nend) {
    node[root].val1 = change;
    node[root].val2 = 0;
    //printf("  change node[%d].val1(%d) to %d\n",root,node[root].val1,change);
    return;
  }
  int mid = (nstart + nend) >> 1;
  Update(lson, nstart, mid, target, change);
  Update(rson, mid + 1, nend, target ,change);
  PushUp(root);
}
int ans1, ans2;
void Query(int root, int nstart, int nend, int qstart, int qend) {
  //printf("Query to root %d:\n", root);
  if (nstart >= qstart && nend <= qend) {
    int tmp = ans1;
    ans1 = max(ans1, node[root].val1);
    ans2 = max(min(tmp, node[root].val1),
               max(ans2, node[root].val2));
    //printf("   find ans1= %d ans2= %d\n",ans1, ans2);
    return;
  }
  int mid = (nstart + nend) >> 1;
  if (qstart <= mid) Query(lson, nstart, mid, qstart, qend);
  if (qend > mid) Query(rson, mid + 1, nend, qstart, qend);
}

char s[2];
int main () {
  int n;
  scanf("%d", &n);
  BuildTree(1, 1, n);
  int T;
  scanf("%d", &T);
  int i,j;
  while (T--) {
    //puts("Test++");
    scanf("%s %d %d", s, &i, &j);
    ans1 = ans2 =0;
    if (s[0] == 'Q') {
      Query(1, 1, n, i, j);
      printf("%d\n", ans1 + ans2);
    }
    else {
      Update(1, 1, n, i, j);
    }
  }
}


