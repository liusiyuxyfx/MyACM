/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 20时09分16秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
const int N=2010;
int a[N],cnt[N],cnt2[N];

int main() {
  int n,m,i,j;
  scanf("%d %d",&n,&m);
  int tmp=n/m;
  printf("%d ",tmp);
  for (i=1; i<=n; ++i) {
    cin>>a[i];
    if (a[i]<=m) cnt[a[i]]++;
  }
  int ans=0;
  for (i=1; i<=m; ++i)
    if (cnt[i]<tmp) ans+=tmp-cnt[i];
  cout<<ans<<endl;
  for (i=j=1; i<=n; ++i) {
    if (a[i]>m) {
      for (; j<=m; ++j) {
        if (cnt[j]<tmp) {
          a[i]=j;
          cnt[j]++;
          break;
        }
      }
    } else if (cnt[a[i]]>tmp) {
      cnt[a[i]]--;
      for (; j<=m; ++j) {
        if (cnt[j]<tmp) {
          a[i]=j;
          cnt[j]++;
          break;
        }
      }
    }
    //cout<<a[i]<<" \n"[i==n];
    i==n? printf("%d\n",a[i]):printf("%d ",a[i]);
  }
}
