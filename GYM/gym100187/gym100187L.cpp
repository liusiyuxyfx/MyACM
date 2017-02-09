/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 12时22分56秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char s[MAXN];
int main() {
  int n;
  while(cin>>s) {
    n=strlen(s);
    for (int i=0; i<n/2; ++i) {
      s[i]=s[n-i-1];
     }
    printf("%s\n",s);
  }
}

