/*************************************************************************
     File Name: gym100819M.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月08日 星期六 12时41分57秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
  LL n;
  string s[30];
  LL a[30];
  cin>>n;
  LL k,sum=0;
  for (LL i=0; i<n; ++i) {
    cin>>s[i];
    scanf("%lld",&a[i]);
  }
  bool flag;
  for (LL i=1; i<=100; ++i) {
    flag=true;
    k=i;
    for (LL j=0; j<n; ++j) {

      if (s[j]=="DIVIDE") {
        if (k%a[j]!=0) {
          flag=false;
          break;
        }
        else k/=a[j];
      }

      else if (s[j]=="SUBTRACT") {
        if (k-a[j]<0) {
          flag=false;
          break;
        }
        else k-=a[j];
      }

      else if (s[j]=="ADD") k+=a[j];

      else k*=a[j];
    }
    if (!flag) sum++;
  }
  printf("%lld\n",sum);
}


