/*************************************************************************
     File Name: CF754B.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月12日 星期四 10时04分11秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char mp[5][5];
int dx[][2] = {{-1,-2},{-1,-2},{-1,-2},{0,0},{0,0},{1,2},{1,2},{1,2},{-1,1},{-1,1},{-1,1},{0,0}};
int dy[][2] = {{-1,-2},{0,0},{1,2},{-1,-2},{1,2},{-1,-2},{0,0},{1,2},{-1,1},{0,0},{1,-1},{-1,1}};
bool check(int x, int y) {
  for (int i = 0; i <12; ++i) 
    if (mp[x+dx[i][0]][y+dy[i][0]] == 'x' && mp[x+dx[i][1]][y+dy[i][1]] == 'x') return true;
    return false;
}

int main() {
  for (int i = 0; i < 4; ++i) 
    scanf("%s", mp[i]);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mp[i][j] == '.') {
        if (check(i,j)) {
          puts("YES");
          return 0;
        }
      }
    }
  }
  puts("NO");
}
