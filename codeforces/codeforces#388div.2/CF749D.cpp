/*************************************************************************
     File Name: CF749D.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月05日 星期四 10时52分42秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

map<int,int>maxbid;
map<int,int>afop;
set<int> bids[MAXN];
int k, fx, smax;
int x;
int qry[MAXN];
void Deal() {
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d" ,&x);
    qry[i] = x;
    if (maxbid[x]) afop.erase(maxbid[x]);
  }
  
  fx = smax = 0;
  auto it = afop.end();
  if (afop.size() == 0) return;
  else if (afop.size() == 1) fx = (--it)->second;
  else {
    fx = (--it)->second;
    smax = (--it)->first;
  }
}


int main() {
  int n, val, q;
  scanf("%d", &n);
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &x, &val);
    maxbid[x] = val;
    bids[x].insert(val);
  }
  
  scanf("%d", &q);
  for (int i = 1; i <= n; ++i) 
    if (maxbid[i]) afop[maxbid[i]] = i;
  while (q--) {
    for (int i = 0; i < k; ++i) 
      if (maxbid[qry[i]]) afop[maxbid[qry[i]]] = qry[i];
    Deal();
    if (!fx) {
      puts("0 0");
      continue;
    }
    if (!smax) {
      printf("%d %d\n", fx, *(bids[fx].begin()));
      continue;
    }
    printf("%d %d\n", fx, *bids[fx].upper_bound(smax));
  }
}

