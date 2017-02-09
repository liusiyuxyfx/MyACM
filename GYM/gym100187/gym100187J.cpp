/*************************************************************************
     File Name: gym100187J.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月09日 星期日 13时19分55秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int top;
struct Edge{
  int u,v,nex;
}edge[MAXN];
int head[MAXN];
void Addedge(int u,int v) {
  edge[top].u=u,edge[top].v=v,edge[top].nex=head[u],head[u]=top++;
}

int n;
int a[MAXN];
bool vis[MAXN];
void bfs(int s) {
  queue<int>q;
  q.push(s);
  vis[s]=true;
  while(!q.empty()) {
    int u=q.front();
    q.pop();
    if (u==1) break;
    for (int i=head[u]; ~i; i=edge[i].nex) {
      int v=edge[i].v;
      if (vis[v]) continue;
      vis[v]=true;
      q.push(v);
    }
  }
  if (vis[1]) puts("YES");
  else puts("NO");
}

  
int main() {
  cin>>n;
  MEM(head,-1);
  for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
  int k;
  top=0;
  cin>>k;
  int x;
  for (int i=1; i<=k; ++i) 
    for (int j=1; j<=n; ++j) {
      scanf("%d",&x);
      Addedge(x,j);
  }   
  int s;
  cin>>s;
  for (int i=1; i<=n; ++i )
    if (s==a[i]) {
      s=i;
      break;
    }
  bfs(s);
}


      

  
