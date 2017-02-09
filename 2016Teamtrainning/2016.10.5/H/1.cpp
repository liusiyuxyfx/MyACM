/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月05日 星期三 22时07分35秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=50000;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int s[MAXN],p;
int main() {
  int Test;
  int n,m;
  int cnt;
  LL ans;
  cin>>Test;
  for (int cas=1; cas<=Test; ++cas) {
    ans=0;
    map<int,int>mp;
    cin>>n>>m;
    for (int i=0; i<n; ++i) scanf("%d",&s[i]);
    for (int i=0; i<m; ++i) scanf("%d",&p),mp[p]++;
    cnt=(int)mp.size();
    for (int i=0; i<n; ++i) {
      if (mp[s[i]]==1) cnt--;
      else if (mp[s[i]]==0) cnt++;
      mp[s[i]]--;
      if (i-m>=0) {
        if (mp[s[i-m]]==0) cnt++;
        else if (mp[s[i-m]]==-1) cnt--;
        mp[s[i-m]]++;
      }
      if (cnt==0) {
        LL pos=i-m+2;
        ans+=pos*pos;
      }
    }
    cout<<ans<<endl;
  }
}

    

   

