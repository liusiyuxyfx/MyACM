/*************************************************************************
     File Name: CF747D.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月06日 星期五 11时40分16秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int n, k;
int a[MAXN];
int len[MAXN];
int main() {
  while (~scanf("%d %d", &n, &k)) {
    int tmp = k;
        a[0] = 0;
    int tot = -1;
    int sum = 0;
    int flag = 0;
    int h = 0;
    for (int i = 1; i <=n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] >= 0) {
        if (a[i-1] < 0) sum++;
        if (flag) len[tot]++;
      } else {
        k--;
        flag = 1;
        if (a[i-1] >= 0) tot++,sum++;
      }
    }
    if (k == tmp) {
      puts("0"); //特判全为零上的情况
      continue;
    }
    if (k < 0) {
        puts("-1");
        continue;
    }

    if (a[n] >= 0) tot++, h = -1;//最后一个时段为零上时，把该时段放到最后判断
        sort(len, len + tot + h);
    for (int i = 0 ; i < tot + h; ++i) 
      if (k >= len[i]) k -= len[i], sum-=2;
      else break;
    if (h == -1 && k >= len[tot-1]) sum--;//最后个时段为零上时的情况
    printf("%d\n", sum);
  }
}



          
