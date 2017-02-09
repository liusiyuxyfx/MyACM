/*************************************************************************
     File Name: URAL1902.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年02月09日 星期四 13时30分40秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int ss[101];
int main() {
  int n, t, s;
  scanf("%d %d %d", &n, &t, &s);
  for (int i = 0; i < n; ++i) scanf("%d", ss+i);
  for (int i = 0; i < n; ++i) {
    int c = t - abs(s - ss[i]);
    double ans = (double) max(s, ss[i]) + c * 0.5;
    printf("%.6f\n", ans);
  }
}

