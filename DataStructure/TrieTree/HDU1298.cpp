/*************************************************************************
     File Name: HDU1298.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年11月03日 星期四 19时25分03秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
char s[102];
char ans[102];
char sear[102];
int MAX=0;
int cnt[10] = {0,0,3,3,3,3,3,4,3,4};
int alph[10][4] = {{0}, {0}, {0,1,2}, {3,4,5}, {6,7,8}, {9,10,11},
                  {12,13,14}, {15,16,17,18}, {19,20,21}, {22,23,24,25}};
struct Trie {
  int pb;
  struct Trie* next[27];
  Trie() {
    pb = 0;
    for (int i = 0; i < 27; ++i) next[i] = NULL;
  }
} *root;

void Insert(char* s, int p) {
  Trie* u= root;
  for (int i=0,k; s[i]; ++i) {
    k = s[i] - 'a';
    if (u->next[k] == NULL) u->next[k] = new Trie();
    //if (u->next[k]!=NULL) printf("1 ");
    //else printf("0 ");
    u = u->next[k];
    u->pb += p;
  }
}

void Dfs(int pos,int len,Trie* u) {
  int k = s[pos] - '0';
  if (pos == len) {
    //printf("findone MAX=%d PB=%d string is %s\n",MAX,u->pb,sear);
    if (u->pb > MAX) {
      MAX = u->pb;
      sear[len] = '\0';
      //printf(" find:%s\n",sear);
      strcpy(ans, sear);
    }
    return;
  }
  //if (pos==0) {
  //      printf("root?=%d ",u==root?1:0);
  //      printf("id:%d\n",u->next[8]);
  //    }

 
  for (int i = 0; i < cnt[k]; ++i) {
    int cur = alph[k][i];
    //printf("now pos is %d cur is %d %c\n",pos,cur,cur+'a');
    if (u->next[cur] == NULL) {
      //printf("pos=%d u(%d)->next[%d]is passed\n",pos,u==root?1:0,cur);
      continue;
    }
    //printf("pos:%d cur:%d %c ",pos,cur,'a'+cur);
    sear[pos] = 'a'+cur;
    Dfs(pos+1, len, u->next[cur]);
  }
  return;
}

void Del (Trie *p) {
  for (int i = 0; i < 27; ++i) {
    if (p->next[i] != NULL) 
      Del(p->next[i]);
  }
  delete p;
}


int main () {
  int T, w, m, pb;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    root = new Trie();
    scanf("%d", &w);
    for (int i = 0; i < w; ++i) {
      scanf("%s %d", s, &pb);
      Insert(s, pb);
    }
    //printf("%d",root->next[8]);
    scanf("%d", &m);
   // puts("------------------");
    printf("Scenario #%d:\n", cas);
    for (int i = 0; i < m; ++i) {
      scanf("%s", s);
      int len = strlen(s);
      for (int j = 1; j < len; ++j) {
      //printf("len= %d\n",j);
        MAX = 0;
        Dfs(0, j, root);
        if (MAX) printf("%s\n", ans);
        else puts("MANUALLY");
      }
      puts("");
    }
    Del(root);
    puts("");
  }
}
