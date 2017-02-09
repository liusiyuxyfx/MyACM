/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月03日 星期六 12时24分42秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a))
#define MEMINF(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN=5e4+5;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int top;
int dis[MAXN],vis[MAXN],n,m,s,t;
struct Edge{
  int from,to,cap,next;
}edge[MAXN];
int head[MAXN];
void Addedge(int u,int v,int cap) {
  Edge *p=&edge[top];
  p->from=u,p->to=v,p->cap=cap,p->next=head[u],head[u]=top++;
}

bool bfs() {
  queue<int>q;
  MEM(dis,-1);
  dis[s]=0;
  q.push(s);
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (int i=head[u]; ~i; i=edge[i].next) {
      int v=edge[i].to;
      int c=edge[i].cap;
      if (c>0&&dis[v]<0) {
        dis[v]=dis[u]+1;
        q.push(v);
      }
    }
  }
  return dis[t]>0;
}

int Dinic_dfs(int a,int flow){
  if (a==t) return flow;
  int f=0,temp;
  for (int i=head[a]; ~i; i=edge[i].next) {
    int v=edge[i].to;
    int c=edge[i].cap;
    if (c>0&&dis[v]==dis[a]+1) {
      temp=Dinic_dfs(v,min(flow-f,c));
      if(temp==0) dis[v]=-1;
      else {
        f+=temp;
        edge[i].cap-=temp;
        edge[i^1].cap+=temp;
      }
    }
  }
 return f;
}

void Forward_dfs(int a) {
  vis[a]=1;
  for (int i=head[a]; ~i; i=edge[i].next) {
    if (edge[i].cap>0&&!vis[edge[i].to]) {
      vis[edge[i].to]=1;
      Forward_dfs(edge[i].to);
    }
  }
}

void Back_dfs(int a) {
  vis[a]=1;
  for (int i=head[a]; ~i; i=edge[i].next) {
    int flow;
    flow=edge[i^1].cap;
    if (flow>0 && !vis[edge[i].to]) {
       vis[edge[i].to]=1;
       Back_dfs(edge[i].to);
    }
  }
}

int main() {
  while(cin>>n>>m>>s>>t) {
    if (!n&&!m&&!s&&!t) break;
    MEM(head,-1);
    top=0;
    int u,v,c;
    for (int i=1; i<=m; ++i) {
      scanf("%d %d %d",&u,&v,&c);
      Addedge(u,v,c);
      Addedge(v,u,c);
    }
    while (bfs()) {
      while (true)
        if (!Dinic_dfs(s,INF)) break;
    }
    MEM(vis,0);
    Forward_dfs(s);
    Back_dfs(t);
    int ans=0;
    for (int i=1; i<=n; ++i) 
      if (vis[i]) ans++;
    if (ans==n) puts("UNIQUE");
    else puts("AMBIGUOUS");
  }
}
 
