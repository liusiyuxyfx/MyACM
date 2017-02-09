/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月20日 星期日 20时12分09秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=110;
const int MAXM=5010;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge {
  int u,v,cap,flow,nex;
  Edge() {}
  Edge (int u,int v, int cap,int flow,int nex):u(u),v(v),cap(cap),flow(flow),nex(nex) {}
}e[MAXM];

int top,head[MAXN];
int dis[MAXN],now[MAXN];

void init() {
  MEM(head,-1);
  top=0;
}

void Addedge(int u,int v,int cap) {
  e[top]=Edge(u,v,cap,0,head[u]);
  head[u]=top++;
  e[top]=Edge(v,u,0,0,head[v]);
  head[v]=top++;
}

bool bfs(int s,int t) {
  MEMINF(dis);
  dis[s]=0;
  queue<int>q;
  q.push(s);
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (int i=head[u]; ~i; i=e[i].nex) {
      int v=e[i].v;
      if (e[i].cap>e[i].flow&&dis[v]==INF) {
        dis[v]=dis[u]+1;
        q.push(v);
      }
    }
  }
  return dis[t]!=INF;
}

int dfs(int x,int t,int a) {
  if (x==t||a==0) 
    return a;
  int flow=0;
  int f;
  for (int &i=now[x]; ~i; i=e[i].nex) {
    if (i==INF)
      i=head[x];
    if (i==-1)
      break;
    int v=e[i].v;
    if (dis[v]==dis[x]+1&&(f=dfs(v,t,min(a,e[i].cap-e[i].flow)))>0) {
      flow+=f;
      a-=f;
      e[i].flow+=f;
      e[i^1].flow-=f;
      if (!a) break;
    }
  }
  return flow;
}
int dinic(int s,int t){
  int maxflow=0;
  while(bfs(s,t)) {
    MEMINF(now);
    maxflow+=dfs(s,t,INF);
  }
  return maxflow;
}

int from[MAXM],to[MAXM],w[MAXN];
int from2[MAXM],to2[MAXM],w2[MAXM];
int n,m,num,num2,a[MAXN];
int s,t;
int main () {
  int n,m;
  while(cin>>n>>m) {
    s=0;
    t=n+1;
    num=0,num2=0;
    for (int i=1; i<=n; ++i)
      scanf("%d",&a[i]);
    for (int i=1 ;i<=m; ++i) {
      int u,v,g,p;
      scanf("%d %d %d %d",&u,&v,&g,&p);
      if (p==0) {
        from[num]=u;
        to[num]=v;
        w[num]=-1;
        num++;
      }
      if (p>0) {
        from2[num2]=u;
        to2[num2]=v;
        w2[num2]=g;
        num2++;
      }
      if (p<0) {
        from[num]=u;
        to[num]=v;
        w[num++]=g;
      }
    }
    int mc=0,mf=0;
    for (int j=0; j<(1<<num2); ++j) {
      int ret=0;
      init();
      for (int i=0; i<num2; ++i) {
        if ((j>>i)&1) {
          Addedge(from2[i],to2[i],INF);
          ret+=w2[i];
        }
        else
          Addedge(from2[i],to2[i],1);
      }
      for (int i=0 ;i<num; ++i) {
        Addedge(from[i],to[i],INF);
        if (w[i]>0) Addedge(from[i],t,w[i]);
      }
      for (int i=1 ;i<=n; ++i) Addedge(s,i,a[i]);
      int pf=dinic(s,t),ps=ret;
      if (pf>mf)
        mf=pf,mc=ps;
      else if(pf==mf)
        mc=min(mc,ps);
    }
    if (mf==0)
      puts("Poor Heaven Empire");
    else printf("%d %d\n",mf,mc);
  }
}

