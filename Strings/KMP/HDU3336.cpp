/*************************************************************************
     File Name: HDU3336.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月20日 星期日 09时19分20秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=10007;
char s[MAXN];
int len,T;
int Next[MAXN];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &len);
    scanf("%s", s);
    int lolp = 0;
    for (int nocm = 2; nocm < len + 1; ++nocm) {
      while (lolp > 0 && (s[lolp] != s[nocm-1])) 
        lolp = Next[lolp];
      if (s[lolp] == s[nocm - 1])
        lolp++;
      Next[nocm] = lolp;
    }
    int ans = 0;
    for (int i = 0 ; i < len + 1; ++i) 
      if (Next[i] + 1!= Next[i+1]) 
        ans += Next[i];
    ans += len + Next[len+1];
    printf("%d\n",ans % MOD);
  }
}
  
