/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月12日 星期五 16时15分53秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=2e6+5;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;


struct Edge{
  int to,cap,nex;
}e[MAXN];

int ecnt;
int s,t;
int cur[MAXN],dis[MAXN],head[MAXN];

void init(){
  MEM(head,-1);
  ecnt=0;
}

void Addedge(int u,int v,int cap){
  e[ecnt].to=v;
  e[ecnt].nex=head[u];
  e[ecnt].cap=cap;
  head[u]=ecnt++;
}

void Addedges(int u,int v,int w1,int w2){
  Addedge(u,v,w1);
  Addedge(v,u,w2);
}

bool bfs(){
  queue<int>q;
  q.push(s);
  MEMINF(dis);
  dis[s]=0;
  while(!q.empty()&&dis[t]==INF){
        int u=q.front();
        q.pop();
        for (int i=head[u]; ~i; i=e[i].nex) {
          Edge &p=e[i];
          if(p.cap>0&&dis[p.to]==INF){
            dis[p.to]=dis[u]+1;
            q.push(p.to);
          }
        }
  }
  return dis[t]<INF;
}

int dfs(int u,int maxflow){
  if (u==t) return maxflow;
  int res=0;
for(int i=cur[u]; ~i; i=e[i].nex){
Edge &p=e[i];
if(dis[p.to]==dis[u]+1&&p.cap>0){
  int flow=dfs(p.to,min(maxflow,p.cap));
      cur[u]=i;
      res+=flow;
      p.cap-=flow;
      maxflow-=flow;
      e[i^1].cap+=flow;
      if (!maxflow) return res;
      }
      }
      dis[u]=INF;
      return res;
}


int dinic(int s,int t){
int ans=0;
while(bfs()){
for (int i=s; i<=t; ++i)cur[i]=head[i];
ans+=dfs(s,INF);
}
return ans;
  }


int main(){
  int m,n;
  while(cin>>n>>m){
    init();
    s=0;
    t=n+1;
    for (int i=1; i<=n; ++i) {
      int a,b;
      scanf("%d %d",&a,&b);
      Addedges(s,i,a,0);
      Addedges(i,t,b,0);
    }
    while(m--){
      int u,v,w;
      scanf("%d %d %d",&u,&v,&w);
      Addedges(u,v,w,w);
    }
    printf("%d\n",dinic(s,t));
  }
}

