/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月30日 星期五 22时20分55秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

char s[MAXN];
int ans[MAXN];
int main(){
  int n,cnt=0;
  int flag;
  cin>>n;
  cin>>s;
  flag=1;
  for (int i=0; i<s[i]; ++i)
     if (s[i]=='B'){
       flag=i;
       break;
     }
  for (int i=flag; i<n; ++i)
      if (s[i]=='B') ans[cnt]++;
      else if (s[i]=='W'&&s[i+1]=='B') cnt++;

  if (ans[0]==0)
    puts("0");
  else{
  printf("%d\n",cnt+1);
  for (int i=0; i<=cnt; ++i)
    printf("%d ",ans[i]);
  puts("");
} 
}
