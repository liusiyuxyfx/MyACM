/*************************************************************************
     File Name: CF746D.cpp
     ID: Liusyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月07日 星期六 10时49分16秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,szeof(a));
#define MEMINF(a) memset(a,0x3f,szeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e6 +10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
  char s[MAXN];
  int n,k,a,b;
  cin >> n >> k >> a >> b;
    int flag = 0;
  if (a == 0 && b == 0) {
    cout << "NO" <<endl;
    return 0;
  } else if ( a == 0 || b == 0) {
    int maxx = max(a, b);
    if (k >= maxx) 
      for (int i = 0; i < n; ++i) {
        if (a) s[i] = 'G';
        else s[i] ='B';
      }
    else {
      cout << "NO" <<endl;
      return 0;
    }
  } else if (a == b) {
    if (k < 1) {
      puts("NO");
      return 0;
    }
    s[0] = 'G';
    for (int i = 1; i < n; ++i) { 
      if (s[i-1] == 'G') s[i] = 'B';
      else s[i] = 'G';
    }
  }
  else {
    if (a > b) flag = 0;
    else flag =1;
    bool can = 1;
    int minn = min(a,b);
    int maxx = max(a,b);
    minn++;
    int c = maxx / minn;
    int d = maxx % minn;
    if (d && c + 1 > k) can = 0;
    if (!d && c > k) can = 0;
    if (!can) {
      cout << "NO" <<endl;
      return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
     if (!flag) {
       cnt++;
       s[i] = 'G';
       if (cnt == c) {
         if (d) {
           s[i+1] = 'G';
           s[i+2] = 'B';
           d--;
           i += 2;
         } else {
           s[i+1] = 'B';
           i++;
         }
         cnt = 0;
       }
     } else {
       cnt ++;
       s[i] = 'B';
       if (cnt == c) {
         if (d) {
           s[i+1] = 'B';
           s[i+2] = 'G';
           d--;
           i += 2;
         } else {
           s[i+1] = 'G';
           i++;
         }
         cnt = 0;
       }
     }
    }
  }
    s[n] = '\0';
     cout << s <<endl;
}

      

      

