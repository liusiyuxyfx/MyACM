/*************************************************************************
     File Name: CF282E.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月01日 星期二 16时19分32秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
LL pre[MAXN];
LL suf[MAXN];
LL a[MAXN];
int bit[60];
 const int MOD=1000000007;
struct Trie {
  struct Trie* next[2];
  Trie() {
    for (int i=0; i<2; ++i) next[i] = NULL;
  }
} *root;

void Insert(LL x) {
  MEM(bit, 0);
  int tot=0;
  while (x) {
    bit[tot++] = x & 1;
    x >>= 1;
  }
  Trie *u = root;
  for (int i = 50 ; i >= 0; --i) {
    int k = bit[i];
    if (u->next[k] == NULL) {
      u->next[k] = new Trie();
    }

    u = u->next[k];
  }
}

LL Search(LL x) {
  Trie *u = root;
  LL sum = 0,e;
  int tot=0;
  MEM(bit,0);
  while (x) {
    bit[tot++] = x & 1;
    x >>= 1;
  }
  for (int i = 50,k; i >= 0; --i) {
    k =bit[i];
    if (u->next[!k] != NULL) e=1;
    else e=0;
    sum += e ? (1LL << i) : 0;
    u = u->next[e? !k : k];
  }
  return sum;
}


     
int main () {
  int n;
  root = new Trie();
  scanf("%d", &n);
  pre[0] = suf[n+1] = 0;
  LL ans=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    pre[i] = pre[i-1] ^ a[i];
  }
  for (int i = n; i >= 1; --i) {
    suf[i] = suf[i+1] ^ a[i];
  }
  for (int i = 1; i <= n+1; ++i) {
    Insert(pre[i-1]);
    ans = max(ans, Search(suf[i]));
  }
  printf("%I64d\n",ans);
}

