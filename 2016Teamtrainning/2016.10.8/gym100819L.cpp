/*************************************************************************
     File Name: gym100819L.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月08日 星期六 13时19分33秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+5;
double ans[MAXN],p[MAXN],r[MAXN],sm[MAXN],w;
int n;
double get(int x) {
  return log(1.0+x/w);
}
int main() {
  scanf("%d %lf",&n,&w);
  string s[MAXN];
  double  temp=0;
  for (int i=0; i<n; ++i) cin>>s[i]>>p[i]>>r[i];
  for (int i=0; i<n; ++i) if (s[i]=="safe") sm[i]=temp,temp=r[i]; else sm[i]=temp;
  for (int i=n-1; i>=0; i--) ans[i]=max(ans[i+1],get(r[i]))*p[i]+(1.0-p[i])*get(sm[i]);
  printf("$%.2lf\n",(exp(ans[0])-1.0)*w);
}
