/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月30日 星期五 22时40分52秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct node{
  string s;
  int len;
}no[MAXN];
bool cmp(node a,node b){
  return a.len<b.len;
}
char str[MAXN];
int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  for (int i=0; i<n; ++i){
    cin>>no[i].s;
    no[i].len=no[i].s.length();
  }
  sort(no,no+n,cmp);
  scanf("%s",str);
  int l=strlen(str),cnt=0,cnt1=0;
  for (int i=0; i<n; ++i){
    if (no[i].len<l)cnt++;
    else if (no[i].len==l)cnt1++;
  }
  int ans=cnt+1+cnt/k*5;
  int ans2=cnt1+cnt+(cnt1+cnt-1)/k*5;

  printf("%d %d\n",ans,ans2);
}
