/*************************************************************************
     File Name: CF745A.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月13日 星期五 09时48分33秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

string s;
map <string, int> mp;
int main() {
  cin >> s;
  int sum = 0;
  int len = s.length();
  s+=s;
  for (int i = 0; i < len; ++i) {
    string t;
    for (int j = 0; j < len;++j) {
      t += s[i+j];
    }
    if (!mp[t]) {
      mp[t] = 1 , sum ++;
    }
  }
  cout << sum << endl;
}


