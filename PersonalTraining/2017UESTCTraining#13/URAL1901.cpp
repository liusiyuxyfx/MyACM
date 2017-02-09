/*************************************************************************
     File Name: URAL1901.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年02月09日 星期四 13时38分04秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+ 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int a[MAXN];
vector <int> ans;
int main() {
  int n, s;
  while (~scanf("%d %d", &n, &s)) {
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    if (n == 1) {
      printf("1\n%d\n", a[0]);
      continue;
    }
    sort(a, a + n);
    ans.clear();
    int cnt = 0;
    for (int i = 0, j = n - 1; i <= j; ) {
      if ( i == j) {
        ans.push_back(a[i]);
        cnt ++;
        break;
      }
      if (a[i] + a[j] <= s) {
        ans.push_back(a[i]);
        ++i;
        ans.push_back(a[i]);
        ++i, ++cnt;
      } else {
        ans.push_back(a[i]);
        ++i, ++cnt;
        ans.push_back(a[j]);
        --j, ++cnt;
      }
    }
    printf("%d\n", cnt);
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); ++i) {
        printf(" %d", ans[i]);
    }
    puts("");
  }
}




