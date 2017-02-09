/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月02日 星期日 13时10分13秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
map<string,int> mp;
int num[MAXN];
vector <string> vec;
int main() {
  int n,k;
  int N;
  string s;
  scanf("%d %d",&n,&k);
  N=n;
  for (int i=0; i<n; ++i) {
    cin>>s;
    if (mp[s]) {N--;continue;}
    else {mp[s]=1;
    vec.push_back(s);
    }
  }
  int cnt=N/k;
  int left=N%k;
  for (int i=0; i<vec.size(); ++i) {
    char c=vec[i][0];
    num[c-65]++;
    if (num[c-65]>cnt) {
      if (left!=0)left--;
      else cnt--;
    }
  }
  if (cnt<0) puts("0");
  else cout<<cnt<<endl;
}

