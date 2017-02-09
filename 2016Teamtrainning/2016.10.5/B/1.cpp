/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月05日 星期三 12时30分02秒
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
  int T,n;
  cin>>T;
  string s;
  for (int cas=1; cas<=T; ++cas) {
    printf("Case %d: ",cas);
    scanf("%d",&n);
    cin>>s;
    int cnta=0;
    int cntb=0;
    int cntw=0;
    int cntt=0;
    for (int i=0; i<s.length(); ++i) 
      if (s[i]=='A') cnta++;
      else if (s[i]=='B') cntb++;
      else if (s[i]=='W') cntw++;
      else if (s[i]=='T') cntt++;
    
    if (cnta==n) puts("ABANDONED");
    else if(cnta+cntb==n) puts("BANGLAWASH");
    else if (cnta+cntw==n) puts("WHITEWASH");
    else if (cntb>cntw) printf("BANGLADESH %d - %d\n",cntb,cntw);
    else if (cntb==cntw) printf("DRAW %d %d\n",cntb,cntt);
    else printf("WWW %d - %d\n",cntw,cntb);
  }}


    
