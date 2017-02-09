/*************************************************************************
     File Name: gym101147E.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月03日 星期二 16时09分58秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
vector <int> pre[MAXN];
int ans[MAXN];

void BFS(int n) {
  queue <int> q;
  q.push(n);
  ans[n] = 0;
  int u ,v;
  while(!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = 0; i < pre[u].size(); ++i) {
      v = pre[u][i];
      //cout << "u =" <<u << " v= "<<v<<endl;
      if (ans[v] == INF) {
        //cout << "change "<< v<< endl;
        ans[v] = ans[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  freopen("jumping.in","r",stdin);
  int T, n, di;
  scanf("%d", &T);
  while(T--) {
    scanf("%d",&n);
    MEMINF(ans);
    for (int i = 0; i <= n; ++i) pre[i].clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &di);
      if (di + i <= n) pre[di + i].push_back(i);
      if (i - di > 0) pre[i - di].push_back(i);
    }
    BFS(n);
    for (int i = 1; i <= n; ++i) 
      if (ans[i] == INF) puts("-1");
      else printf("%d\n", ans[i]);
  }
}

