
/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月19日 星期三 18时12分48秒
************************************************************************/
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+5;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int t[MAXN];
int n;
int T;
int a[MAXN],b[MAXN];
bool solve() {
  bool flag=false;
  memcpy(t,a,sizeof a);
  for (int i=1; i<n; ++i) {
    if (t[i-1]>=t[i]) continue;
    if (flag) return false;
    if (!(i<2||i>1&&t[i-2]>=t[i]))
      t[i]=t[i-1];
    flag=true;
  }
  return true;
}


int main() {
  scanf("%d",&T);
  while (T--) {
    scanf("%d",&n);
    for (int i=0; i<n; ++i) {
      scanf("%d",&a[i]);
    }
    if (solve()) {
      puts("YES");
      continue;
    }
    reverse(a,a+n);
    if (solve()) puts("YES");
    else puts("NO");
  }
}




