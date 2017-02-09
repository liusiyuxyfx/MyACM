/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 19时30分34秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

string s;

int main() {
  int n;
  cin>>n;
  cin>>s;
  int MAX_len=0;
  int inside=0;
  int uf=0;
  int pf=0;
  bool in=false;
  int cnt=0;
  for (int i=0; i<n; ++i) {
    if (((i==0&&s[i]!='(')||s[i-1]=='(')&&s[i]!='_') uf=1;
    if (s[i]=='(') {
      cnt=0;
      in=true;
      continue;
    }
    if (s[i]==')') {
      if (s[i-1]!='_') {
        uf=0;
        inside++;
      }

      in=false;
      continue;

    }

    if (in) {
      if (s[i]=='_') {
        if (s[i-1]=='_') continue;
        if (uf==0) {
          uf=1;
          continue;
        }
        if (uf==1) {
          uf=0;
          inside++;
          continue;
        }
      }
    }
    else {
      if (s[i]=='_') {
        if (s[i-1]=='_')continue;
        if (uf==0) {
          uf=1;
          cnt=0;
          continue;
        }
        if (uf==1) {
          uf=0;
          //printf("%d",cnt);
          MAX_len=max(MAX_len,cnt);
          //printf("\n");
          continue;
        }
        
      }
      else {
        //printf("%c",s[i]);
        cnt++;
      }
    }
  }
  printf("%d %d\n",MAX_len,inside);
}

          




  
