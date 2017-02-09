/*************************************************************************
     File Name: HDU1247.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月02日 星期三 18时14分21秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=5e4+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char s[MAXN][100];
typedef struct TrieTag{
  bool word;
  struct TrieTag* next[26];
}Trie;

const int MAXM=1e6;
Trie memory[MAXM],*root;
int top=0;

Trie* Create() {
  Trie *p = &memory[top++];
  p->word = false;
  for (int i = 0; i < 26; ++i) p->next[i]=NULL;
  return p;
}

void Insert(char* s) {
  Trie* p = root;
  for (int i = 0,k; s[i]; ++i) {
    k=s[i]-'a';
    if (p->next[k] == NULL) p->next[k] = Create();
    p = p->next[k];
  }
  p->word = true;
}

bool Search(char* s) {
  if (root == NULL) return 0;
  Trie *p =root;
  for (int i = 0, k; s[i]; ++i) {
    k = s[i] - 'a';
    if (p->next[k] == NULL) return 0;
    p = p->next[k];
  }
  return p->word;
}

char temp[100];
int main() {
  root = Create();
  int cnt = 0;
  while(~scanf("%s",s[cnt])) {
    Insert(s[cnt]);
    cnt++;
  }
  for (int i = 0; i <= cnt; ++i) {
    int len = strlen(s[i]);
    //printf("now is %s\n",s[i]);
    for (int j = 0 ; j <len ; ++j) {
      MEM(temp,0);
      strncpy(temp, s[i], j);
      //printf("find:%s\n",temp);
      if (Search(temp) && Search(s[i]+j)) {
          printf("%s\n",s[i]);
          break;
      }
    }
  }
}

