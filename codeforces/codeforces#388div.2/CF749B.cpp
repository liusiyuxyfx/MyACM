/*************************************************************************
     File Name: CF749B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月05日 星期四 09时35分21秒
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
  int x1, x2, x3, x4;
  int y1, y2, y3, y4;
  cin>> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cout << 3 <<endl;
  cout << x1 + x2 - x3 << " " << y1 + y2 - y3 << endl;
  cout << x1 + x3 - x2 << " " << y1 + y3 - y2 << endl;
  cout << x2 + x3 - x1 << " " << y2 + y3 - y1 << endl;
}

