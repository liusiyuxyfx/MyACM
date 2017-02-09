/*************************************************************************
     File Name: CF745B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月13日 星期五 10时04分42秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN=500 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
  char mp[MAXN][MAXN];
  int n,m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", mp[i]);
  }
  int left, right, top, bot;
  bool fl, fr, ft ,fb;
  bool flag = false;
  fl = fr = ft = fb =false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <m; ++j) {
      if (mp[i][j] == 'X' && !fl && !ft) {
        left = j, top = i;
        fl = ft = true;
      }
     if (ft && i == top) 
       if (mp[i][j] == 'X' && mp[i][j+1] != 'X') 
         fr = true, right = j;
     if (ft && mp[i][j] == 'X' && mp[i+1][j] !='X')
       fb = true, bot = i;
     if (mp[i][j] == 'X') {
       if (fl && j < left ||
           fr && j > right || 
           fb && i > bot) {
         flag = true;
         break;
       }
     }
    }
  }
  for (int i = top; i <= bot; ++i) 
    for (int j = left; j <= right; ++j)
      if (mp[i][j] == '.') {
        flag = true;
        break;
      }
  if (flag) puts("NO");
  else puts("YES");
}

