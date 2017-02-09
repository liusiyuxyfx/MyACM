/*************************************************************************
     File Name: CF746B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月07日 星期六 09时35分00秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2005;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

int main() {
  char a[MAXN];
  char b[MAXN];
  int n;
  scanf("%d %s", &n, a);
  int flag = 0;
  if (n % 2) flag = 1;
  int l = n / 2;
  int r = n / 2 + 1;
  l--;
  r--;
  for (int i = 0; i < n; ++i) {
    if (flag) {
      b[r] = a[i];
      r++;
      flag = 0;
    } else {
      b[l] = a[i];
      l--;
      flag = 1;
    }
  }
  b[n]='\0';
  puts(b);
}
