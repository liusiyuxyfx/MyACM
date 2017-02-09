#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=510;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
bool vis[MAXN];
char s[MAXN][MAXN<<2];
int main() {
  int ans,T,n;
  cin>>T;
  for (int cas=1; cas<=T; ++cas) {
    ans=-1;
    scanf("%d",&n);
    getchar();
    for (int i=1; i<=n; ++i) scanf("%s",s[i]);
    MEM(vis,true);
    for (int i=1; i<n; ++i) {
      for (int j=i+1; j<=n; ++j) 
        if (vis[j]) {
          if (strstr(s[j],s[i])) break;
          else vis[j]=false,ans=max(ans,j);
      } 
    }
    printf("Case #%d: %d\n",cas,ans);
  }
}

