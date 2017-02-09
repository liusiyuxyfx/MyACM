/*************************************************************************
     File Name: cF747A.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月06日 星期五 10时22分13秒
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
  int n;
  while (~scanf("%d", &n)) {
    int k = sqrt(n);
    for(int i = k; i <= n; ++k) {
      if (n % k == 0) {
        int a = n / k;
        if (a > k)
        swap(a, k);
        printf("%d %d\n",a,k );
        break;
      }
    }
  }
}

