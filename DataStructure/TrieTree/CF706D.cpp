/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月06日 星期日 13时52分11秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef int LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

typedef struct Trietag {
  int cnt;
  struct Trietag* next[3];
} Trie;

const int MAXM=3e6+10;

Trie memory[MAXM], *root;
int top = 0;
Trie* Create () {
  Trie* p = &memory[top++];
  p->cnt = 0;
  p->next[0] = NULL;
  p->next[1] = NULL;
  return p;
}

void Insert(LL s) {
  Trie* p =root;
  for (int i = 31, k; i>=0; --i) {
    k = s >> i & 1;
    if (p->next[k] == NULL) p->next[k] = Create();
    p = p->next[k];
    ++p->cnt ;
  }
}

LL Search(LL s) {
  Trie* p = root;
  LL sum = 0;
  for (int i = 31,k; i>=0; --i) {
    k = s >> i & 1;
    if (p->next[!k] == NULL) {
      p = p->next[k];
    }
    else {
      if (p->next[!k]->cnt == 0) {
        p = p->next[k];
      } else {
        sum |= (1LL << i);
        p = p->next[!k];
      }
    }
  }
  return sum;
}

void Del(LL s) {
  Trie *p = root;
  for (int i = 31, k; i>=0; --i) {
    k = s >> i & 1;
    if (p->next[k] == NULL) return;
    p = p->next[k];
    p->cnt --;
  }
}

char c[10];
int main() {
  int n;
  scanf("%d",&n);
  LL x;
  root = Create();
  Insert(0);
  while (n--) {
    scanf("%s %d", c, &x);
    if (c[0] == '+') Insert(x);
    else if (c[0] == '-') Del(x);
    else printf("%d\n",Search(x));
  }
}
