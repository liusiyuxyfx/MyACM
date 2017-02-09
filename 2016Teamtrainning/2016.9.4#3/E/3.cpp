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
vector <int> vec[MAXN];
vector <int> id[MAXN];
int dis[MAXN];
bool vis[MAXN];
bool use[MAXN];
struct Edge{
  int u,v,id;
  int nex;
}edge[MAXN<<2];
int head[MAXN];
int top;
void Addedge (int u,int v,int i) {
  vec[u].push_back(v);
  id[u].push_back(i);
  vec[v].push_back(u);
  id[v].push_back(i);
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
    int siz=vec[u].size();
    for (int i=0; i<siz; ++i) {
     // printf("Edge:%d->%d\n",u,edge[i].v);
      int v=vec[u][i];
      if (vis[v]==0) {
        vis[v]=1;
        dis[v]=dis[u]+1;
        q.push(v);
       // printf("dis[%d]=%d\n",v,dis[v]);
      }
      if (dis[v]==dis[u]+1) {
        //printf("use[%d]=1\n",edge[i].id);
        //printf("ans[%d],push_back(%d)\n",dis[u]+1,edge[i].id);
        ans[dis[u]+1].push_back(id[u][i]);
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
  for (int i=1; i<=M; ++i) {
    int u,v;
    scanf("%d %d",&u,&v);
    Addedge(u,v,i);
  }
  int cnt=bfs();
  cout<<cnt<<endl;
  for (int i=1; i<=cnt; ++i) {
    cout<<ans[i].size();
    for (auto j=0; j<ans[i].size(); ++j) {
      printf(" %d",ans[i][j]);
    }
    puts("");
  }
}

