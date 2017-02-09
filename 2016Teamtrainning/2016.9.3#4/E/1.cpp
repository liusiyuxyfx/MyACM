/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月03日 星期六 12时26分05秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int MOD=1000000007;

int main() {
  int n,i,x,sum;
  while (~scanf("%d",&n)) {
    sum=0;
    for (i=1; i<=n; ++i) {
      scanf("%d",&x);
      sum+=x;
    }
    printf("%d\n",max(sum,0));
  }
}
