/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月04日 星期日 09时56分59秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
const double EPS=1e-16;
double r1,r2;
double F(double x){
  return 4.0*(r1*r1-x*x)*(r2*r2-x*x);
}
double  simpson(double l,double r){
  double mid=(l+r)/2;
  return (F(l)+F(r)+F(mid)*4)*(r-l)/6;
}
double asr(double l,double r,double eps,double A){
  double mid=(l+r)/2;
  double L=simpson(l,mid), R=simpson(mid,r);
  if (fabs(L+R-A)<=15*EPS)return L+R+(R+L-A)/15;
  return asr(l,mid,eps/2,L)+asr(mid,r,eps/2,R);
}
double asr(double l,double r,double eps){
  return asr(l,r,eps,simpson(l,r));
}
int main(){
  scanf("%lf%lf",&r1,&r2);
  printf("%f\n",asr(-min(r1,r2),min(r1,r2),EPS));
}
