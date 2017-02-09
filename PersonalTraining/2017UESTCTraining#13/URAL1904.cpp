/*************************************************************************
     File Name: URAL1904.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年02月09日 星期四 13时52分54秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int a[20];
int g[500000][2];
int k, m, n;
bool Deal(int t) {
  for (int i = 0; i < n; ++i) 
    t = abs (t - a[i]);
  return t <= 1;
}
int main() {
  while (~scanf("%d", &n)) {
    k = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int j;
    for (int i = -10000; i < 10000; ++i) {
      if (Deal(i)) {
        j = i + 1;
        while (Deal(j)) ++j;
        g[++k][0] = i;
        g[k][1] = j - 1;
        i = j;
      }
    }

    printf("%d\n", k);
    for (int i = 1; i <= k; ++i) {
      printf("%d %d\n", g[i][0],g[i][1]);
    }
  }
}

