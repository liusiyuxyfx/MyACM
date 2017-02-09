/*************************************************************************
     File Name: CF748C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月04日 星期三 11时24分30秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char s[MAXN];

int main() {
  int T;
  int tot = 0;
  char lrf = '0', udf = '0';
  cin >> T >> s;
  for (int i = 0; i < T; ++i) {
    if (s[i] == 'L' && lrf == 'R' ||
        s[i] == 'R' && lrf == 'L' ||
        s[i] == 'U' && udf == 'D' ||
        s[i] == 'D' && udf == 'U')
      tot++, lrf = udf = '0';
    if (s[i] == 'L' || s[i] == 'R') lrf = s[i];
    else udf = s[i];
  }
  cout << ++tot <<endl;
}


