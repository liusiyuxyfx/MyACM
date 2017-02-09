/*************************************************************************
     File Name: POJ2752.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月19日 星期六 12时34分40秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=4e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int Next[MAXN];
char s[MAXN];
int ans[MAXN];
int main() {
  while (~scanf("%s", s)) {
    int len = strlen(s);
    int lolp = 0;
    MEM(Next, 0);
    for (int nocm = 2; nocm < len + 1; nocm++) {
      while (lolp > 0 && (s[lolp] != s[nocm - 1])) 
        lolp = Next[lolp];
      if (s[lolp] == s[nocm - 1]) 
        lolp++;
      Next[nocm] = lolp;
    }
    int tot = 0;
    lolp = len;
    ans[tot++] = Next[lolp];
    while(true) {
        lolp = Next[lolp];
        if(lolp == 0) break;
        ans[tot++] = lolp;
    }
    for (int i = tot-1; i > 0; --i) {
      printf("%d ",ans[i]);
    }
    printf("%d\n", len);
  }
}

