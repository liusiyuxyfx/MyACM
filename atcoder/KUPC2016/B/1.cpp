/*
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月02日 星期日 12时20分40秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int MAX;
map<string,int> mp;
int main() {
  string c;
  MAX=0;
  int num[MAXN];
  int n,k;
  int left;
  MEM(num,0);
  scanf("%d %d",&n,&k);
  int flag=1;
  int cnt;
  cnt=n/k;
  left=n%k;
  int tmp;
  for (int i=0; i<n; ++i) {
    cin>>c;
    mp[c]++;
    if (mp[c]>1) {
      if (left!=0)left--;
      else cnt--;
    }


    if (flag) {
    num[c[0]-65]++;
    if (num[c[0]-65]>cnt){
      if (left!=0) left--;
      else cnt--;
    }
    }

  }

  if (cnt<=0) puts("0");
  else cout<<cnt<<endl;
}


