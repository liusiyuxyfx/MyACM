/*************************************************************************
     File Name: Cf746C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月07日 星期六 10时20分35秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int ans2, cnt;
int s, x1, x2, t1, t2, p, d, cd;
void car() {
  while (true) {
    if (p == x1) cnt = 1;
    if (cnt && p == x2) return;
    if (p == s) cd = -1;
    if (p == 0) cd = 1;
    if (cd == -1) p--;
    else p++;
    ans2 += t1;
  }
}

int main() {
  while (~scanf("%d %d %d %d %d %d %d", &s, &x1, &x2, &t1, &t2, &p, &d)) {
    ans2 = cnt = 0;
    int ans1 = abs(x2 - x1) * t2;
    if (t1 >= t2) printf("%d\n", ans1);
    else {
      cd = d;
      car();
      printf("%d\n", min(ans1, ans2));
    }
  }
}
