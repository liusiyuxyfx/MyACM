/************************************************************************
     File Name: CF752E.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月09日 星期一 15时36分32秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
const int MAXN=1e6;
const int MAXMM=1e7;
long long f[MAXMM+5];
int a[MAXN+50];
int n,MAX=0;
long long k;
int main()
{
    scanf("%d %lld",&n,&k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      MAX = max(MAX,a[i]);
      ++f[a[i]];
    }
    for (int i = MAX; i >= 2; --i)
        if (i&1) {
          f[i/2] += f[i];
          f[i/2+1] += f[i];
        }
        else f[i/2] += f[i]*2LL;
    for (int i = MAX-1; i >= 1; --i) 
      f[i] = f[i+1] + f[i];
    f[MAX+1] = 0;
    int l = 1,r = MAX,mid;
    while (l<r) {
        mid = (l+r+1) >> 1;
        if (f[mid] - f[min(2*mid - 1, MAX + 1)] >= k)
          l = mid;
        else r = mid-1;
    }
    if (f[l] - f[min(2*l, MAX+1)] < k) 
      printf("-1");
    else printf("%d\n",l);
    return 0;
}
