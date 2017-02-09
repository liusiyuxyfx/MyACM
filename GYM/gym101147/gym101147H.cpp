/*************************************************************************
     File Name: 3.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月03日 星期二 16时45分57秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=12;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int resc[MAXN][MAXN][MAXN];
int host[MAXN][MAXN][MAXN];

void INIT() {
  MEM(host,0);
  MEM(resc,0);
}

void Resc() {
 for (int F = 10; F >= 1 ; --F)
   for (int Y = 1; Y <= 10 ; ++Y)
     for (int X = 1; X <= 10; ++X){
       resc[F][Y][X] = max(resc[F+1][Y][X], resc[F][Y-1][X]);
       resc[F][Y][X] = max(resc[F][Y][X], resc[F][Y][X-1]);
       resc[F][Y][X] += host[F][Y][X];
     }
}

int main() {
  freopen("commandos.in","r",stdin);
  int T;
  int n, f, y, x, num;
  scanf("%d", &T);
  while (T--) {
    INIT();
    scanf("%d", &n);
    for (int i = 0 ; i < n; ++i) {
      scanf("%d %d %d %d", &f, &y, &x, &num);
     host[f][y][x]=num;
    }
    Resc();
    printf("%d\n", resc[1][10][10]);
  }
}

    
