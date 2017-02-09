/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 14时09分21秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int n;
map<int,int>mp;
multiset<LL> ms;
LL sum[MAXN];
int main(){
  scanf("%d",&n);
  sum[0]=0;
  int a;
  for (int i=1; i<=n; ++i) {
    scanf("%d",&a);
    sum[i]=sum[i-1]+(LL)a;
  }
  mp[0]=n;
  ms.insert(-sum[n]+sum[0]);
  int c;
  for (int i=1; i<=n; ++i) {
    scanf("%d",&c);
    auto ite=mp.lower_bound(c);
    ite--;
    int l=ite->first;
    int r=ite->second;
    mp.erase(ite);
    
    ms.erase(ms.find(sum[l]-sum[r]));
    if (l<c-1) {
      ms.insert(sum[l]-sum[c-1]);
      //printf("%lld",sum[l]-sum[c-1]);
      mp[l]=c-1;
    }
    if (c<r) {
      ms.insert(sum[c]-sum[r]);
      mp[c]=r;
    }
    if(i!=n) printf("%I64d\n",-*ms.begin());
    else puts("0");
  }
}


    


