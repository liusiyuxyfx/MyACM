/*************************************************************************
     File Name: HDU1358.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月20日 星期日 16时28分39秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e6 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char s[MAXN];
int len;
int Next[MAXN];
void Get_next(){
  int lolp = 0;
  Next[1] = 0;
  for (int nocm = 2; nocm < len + 1; nocm++) {
    while (lolp > 0 &&(s[lolp] != s[nocm - 1])) 
      lolp = Next[lolp];
    if (s[lolp] == s[nocm - 1])
      lolp++;
    Next[nocm] = lolp;
  }
}
int main() {
  int cas = 0;
  while (true) {
    scanf("%d", &len);
    if (len == 0) break;
    scanf("%s", s);
    printf("Test case #%d\n",++cas);
    Get_next();
    int k;
    for (int i = 2; i <= len ;++i) {
      if (Next[i] == 0) 
        continue;
      k = i - Next[i];
      if (i % k == 0) 
        printf("%d %d\n", i, i/k);
    }
    puts("");
  }
}

