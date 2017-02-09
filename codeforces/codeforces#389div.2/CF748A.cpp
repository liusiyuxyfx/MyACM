/*************************************************************************
     File Name: CF748A.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月04日 星期三 09时48分19秒
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
  int n, m, k, x, y, t1, t2;
  cin >> n >> m >> k;
  t1 = k % (2 * m);
  t2 = k / (2 * m);
  if (t1 == 0) x = t2;
  else x = t2 + 1;
  y = (k - 2 * m * (x - 1) + 1)/2;
  if (k % 2 == 0) cout << x << " " << y << " R" << endl;
  else cout << x << " " << y << " L" << endl;
}

