/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月01日 星期六 22时24分02秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int a[105];
int main() {
  int n;
  while(cin>>n){
  for (int i=0; i<n; ++i) {
    scanf("%d",&a[i]);
  }
  getchar();
  char c;
  int cnt;
  int sum=0;
  for (int i=0; i<n; ++i) {
    cnt=0;
    while(true){
      c=getchar();
      if (c=='\n')break;
      if (c=='y'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        cnt++;
    }
    if (cnt==a[i])sum++;
  }
  if (sum==n) {
    puts("YES");
   }
  else puts("NO");
}
}

      

