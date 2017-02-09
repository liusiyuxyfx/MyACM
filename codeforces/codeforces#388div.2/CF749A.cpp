/*************************************************************************
     File Name: CF749A.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月05日 星期四 09时20分09秒
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
  int sum, num;
  cin >> sum;
  num = sum / 2 - 1;
  printf("%d\n",num + 1);
  for (int i = 0; i < num; ++i) 
    printf("2 ");
  printf("%d\n", sum - num * 2);
}

