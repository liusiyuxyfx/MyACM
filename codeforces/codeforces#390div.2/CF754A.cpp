/*************************************************************************
     File Name: CF754.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月12日 星期四 09时49分40秒
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
  int a[MAXN];
  int n ;
  scanf("%d" ,&n);
  int flag = -1;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] != 0 && flag == -1) flag = i; 
    sum += a[i];
  }
  if (flag == -1) {
    puts("NO");
    return 0;
  }
  if (sum != 0) {
    printf("YES\n1\n1 %d\n", n);
    return 0;
  }
  printf("YES\n2\n1 %d\n%d %d\n",flag + 1, flag + 2, n);
}
