/*************************************************************************
     File Name: POJ2406.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月19日 星期六 10时23分18秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e6+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int Next[MAXN];
char s[MAXN];
int main() {
  while (~scanf("%s",s)) {
    if (s[0] == '.') break;
    MEM(Next, 0);
    int ilen = strlen(s);
    int lolp = 0;
    Next[1] = 0;
    for (int nocm = 2; nocm < ilen + 1 ; nocm ++) {
      while (lolp > 0 && s[lolp] != s[nocm - 1] ) 
        lolp = Next[lolp];
      if (s[lolp] == s[nocm-1]) 
        lolp++;
      Next[nocm] = lolp;
    }
    if (ilen % (ilen - Next[ilen]) == 0){
      printf("%d\n", ilen/(ilen - Next[ilen]));
    }
    else puts("1");
  }
}

  
  
