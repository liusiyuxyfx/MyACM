/*************************************************************************
     File Name: CF746A.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月07日 星期六 09时29分09秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  b /= 2;
  c /= 4;
  int m = min (a, min(b, c));
  if (min(a, min(b, c)) == 0) puts("0");
  else printf("%d\n", 7 * m);
}
