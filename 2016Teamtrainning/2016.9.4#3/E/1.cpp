/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月04日 星期日 09时55分48秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=400;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int N,M,S,T;
vector <int> ans[MAXN];
int dis[MAXN];
bool vis[MAXN];
bool use[MAXN];
struct Edge{
  int u,v,id;
  int nex;
}edge[MAXN<<2];
int head[MAXN];
int top;
void Addedge (int u,int v,int id) {
  edge[top].v=v;
  edge[top].id=id;
  edge[top].nex=head[u];
  head[u]=top++;
}

int bfs() {
  queue<int>q;
  MEM(dis,0);
  MEM(vis,false);
  MEM(use,0);
  q.push(S);
  vis[S]=1;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    int D=dis[u]+1;
    for (int  i=head[u]; ~i; i=edge[i].nex) {
     // printf("Edge:%d->%d\n",u,edge[i].v);
      int v=edge[i].v;
      if (vis[v]==0) {
        vis[v]=1;
        dis[v]=D;
        q.push(v);
       // printf("dis[%d]=%d\n",v,dis[v]);
      }
      if (dis[v]==D) {
        //printf("use[%d]=1\n",edge[i].id);
        //printf("ans[%d],push_back(%d)\n",dis[u]+1,edge[i].id);
        ans[D].push_back(edge[i].id);
      }
    }
  }
  //printf("T:%d ",T);
  //printf("dis[T]=%d\n",dis[T]);
  return dis[T];
}

  
int main() {
  cin>>N>>M>>S>>T;
  MEM(head,-1);
  for (int i=1; i<=N; ++i) ans[i].clear();
  for (int i=1; i<=M; ++i) {
    int u,v;
    scanf("%d %d",&u,&v);
    Addedge(u,v,i);
    Addedge(v,u,i);
  }
  int cnt=bfs();
  cout<<cnt<<endl;
  for (int i=1; i<=cnt; ++i) {
    cout<<ans[i].size();
    for (int j=ans[i].size()-1; j>=0; --j) {
      printf(" %d",ans[i][j]);
    }
    puts("");
  }
}

