/*************************************************************************
     File Name: CF749C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月05日 星期四 10时17分46秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
  int n;
  string s;
  cin >> n >> s;
  queue<int>D,R;
  for (int i = 0 ; i < n; ++i) {
    if (s[i] == 'D') D.push(i);
    else R.push(i);
  }
  int flag, d, r;
  while (true) {
    if (D.empty()) {flag = 0; break;}
    if (R.empty()) {flag = 1; break;}
    d = D.front(); D.pop();
    r = R.front(); R.pop();
    if (d < r) D.push(d + n);
    else R.push(r + n);
  }
  if (flag) puts("D");
  else puts("R");
}
