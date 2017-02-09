/*************************************************************************
     File Name: CF747B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月06日 星期五 10时31分28秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
string s;
int n;
int main() {
  while (cin >> n) {
    cin >> s;
    int ca, cg, cc, ct, cq, tot;
    ca = cg = cc = ct = cq = 0;
    tot = s.length();
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'A') ca++;
      if (s[i] == 'G') cg++;
      if (s[i] == 'C') cc++;
      if (s[i] == 'T') ct++;
      if (s[i] == '?') cq++;
    }
    int avr = tot / 4;
    if (ca > avr || cg > avr || ct > avr || cc > avr || tot % 4) {
      cout << "===" <<endl;
      continue;
    }
    int aa, ag, ac, at;
    aa = avr - ca;
    ag = avr - cg;
    ac = avr - cc;
    at = avr - ct;
    for (int i = 0; i < tot; ++i) {
      if (s[i] == '?') {
        if (aa) s[i] = 'A', aa--;
        else if (ac) s[i] = 'C', ac--;
        else if (ag) s[i] = 'G', ag--;
        else if (at) s[i] = 'T', at--;
      }
    }
    cout << s << endl;
  }
}


