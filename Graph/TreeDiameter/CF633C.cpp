/*************************************************************************
     File Name: CF633C.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月06日 星期日 19时28分12秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct Trie{
  int pos;
  struct Trie* next[26];
  Trie() {
    pos = 0;
    for (int i = 0; i < 26; ++i) next[i] = NULL;
  }
} *root;

char origin[MAXN][1010];
int top, Len, ans[MAXN];
char ss[MAXN];
void Insert (int pos) {
  Trie* u = root;
  int len = strlen(origin[pos]);
  for (int i = len-1, k; i >= 0; --i) {
    k = origin[pos][i] - 'a';
    if (origin[pos][i] <= 'Z') k = origin[pos][i] - 'A';
    if (u->next[k] == NULL) u->next[k] = new Trie();
    u = u->next[k];
  }
  u->pos = pos;
}

bool Find;

void Dfs(int u) {
  Trie* p = root;
  if (u == Len) {
    Find = true; 
    for (int i = 0; i < top; ++i) {
      printf("%s ", origin[ans[i]]);
    }
    return;
  }
  for (int i = u, k; i < Len; ++i) {
    k = ss[i] - 'a';
    if (p->next[k] == NULL) break;
    p = p->next[k];
    if (p->pos != 0) {
      ans[top++] = p->pos;
    if (!Find) Dfs(u + strlen(origin[p->pos]));
    else return;
    top--;
    }
  }
}

int main() {
  scanf("%d",&Len);
  scanf("%s", ss);
  root = new Trie();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) { 
    scanf("%s", origin[i]);
    Insert(i);
  }
  Dfs(0);
}

