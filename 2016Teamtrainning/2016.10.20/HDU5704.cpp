/*************************************************************************
     File Name: HDU5704.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月20日 星期四 19时01分34秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
  int T;
  scanf("%d",&T);
  while (T--) {
    int n;
    scanf("%d",&n);
    int sum=0;
    int a[110];
    for (int i=0; i<n-1; ++i) {
      scanf("%d",&a[i]);
      sum+=a[i];
    }
    int ans=2*sum/(3*n-2);
    printf("%d ",ans);
    printf("%.2lf\n",1.0/(double)(count(a,a+n-1,ans)+1));
  }
}

