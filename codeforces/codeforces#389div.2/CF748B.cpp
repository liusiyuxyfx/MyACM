/*************************************************************************
     File Name: CF748B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月04日 星期三 10时50分00秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e3+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

char s1[MAXN];
char s2[MAXN];
char ans[MAXN];
int par[MAXN];

int main() {
  scanf("%s %s", s1, s2);
  MEM(par,-1);
  int tot = 0;
  int len = strlen(s1);
  for (int i = 0 ; i < len; ++i) {
    if (par[s1[i] - 'a'] == -1 && par[s2[i] - 'a'] == -1) {
      if (s1[i] != s2[i]) ans[tot++] = s1[i];
      par[s1[i] - 'a'] = s2[i] - 'a';
      par[s2[i] - 'a'] = s1[i] - 'a';
    } else if (par[s1[i] - 'a'] != s2[i] - 'a' || par[s2[i] - 'a'] != s1[i] - 'a'){
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", tot);
  for (int i = 0 ; i < tot; ++i) {
    printf("%c %c\n",ans[i], par[ans[i] - 'a'] + 'a');
  }
}


