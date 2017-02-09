/*************************************************************************
     File Name: HDU4825.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月02日 星期三 20时25分52秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Trie {
  struct Trie* next[2];
  Trie() {
    next[0]=next[1]=NULL;
  }
} *root;
void Insert(LL x) {
  Trie *u = root;
  for (int i =33; i >= 0; --i) {
    int k = x >> i & 1;
    if (u->next[k] == NULL) {
      u->next[k] = new Trie();
    }
    u = u->next[k];
  }
}

LL Search(LL x) {
  Trie *u = root;
  LL sum = 0;
  int e;
  for (int i = 33, k; i >= 0; --i) {
    k = x >> i & 1;
    //if (k) printf("1=%d\n",i);
    if (u->next[!k] != NULL) {
      sum |= !k? (1LL<<i) : 0;
      u = u->next[!k];
      //printf("pos=%d !k=%d\n",i,!k);
    }
    else {
      sum |= k? (1LL<<i) : 0;
      u = u->next[k];
    }

  }
  return sum;
}

void Del(Trie *p) {
  for (int i=0 ; i<2; ++i) {
    if (p->next[i] != NULL) Del(p->next[i]);
  }
  delete p;
}

int main () {
  int n,m;
  LL a;
  int T;
  while(~scanf("%d", &T)) {
    for (int cas = 1; cas <= T; ++cas) {
      root = new Trie();
      scanf("%d %d", &n,&m);
      for (int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        Insert(a);
      }
      printf("Case #%d:\n",cas);
      for (int i = 0; i < m; ++i) {
        scanf ("%lld", &a);
        //printf("Find %lld\n",a);
        printf("%lld\n",Search(a));
      }
      Del(root);
    }
  }
}

