/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年08月18日 星期四 06时30分24秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1050;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;

struct Edge{
  int to,cap,next;
}e[MAXN*MAXN];
int head[MAXN],dis[MAXN],vis[MAXN],work[MAXN];
int src,t,cnt;

void Addedge(int u,int v,int cap) {
  e[cnt].to=v;e[cnt].cap=cap;e[cnt].next=head[u],head[u]=cnt++;
  e[cnt].to=u,e[cnt].cap=0,e[cnt].next=head[v],head[v]=cnt++;
}

bool bfs(){
  queue<int>q;
  for (int i=0; i<=t; ++i) dis[i]=-1;
  dis[src]=0;
  q.push(src);
  while(!q.empty()) {
    int u=q.front();
    q.pop();
    for (int i=head[u]; ~i; i=e[i].next) {
      Edge &p=e[i];
      if (p.cap>0&&dis[p.to]==-1) {
        dis[p.to]=dis[u]+1;
        q.push(p.to);
      }
    }
  }
  return dis[t]>=0;
}

int dfs(int a,int flow) {
  vis[a]=1;
  int f;
  if (a==t) return flow;
  for (int i=work[a]; i!=-1; i=e[i].next) {
    Edge &p=e[i];
    if (p.cap>0&&dis[p.to]==dis[a]+1&&!vis[p.to]) {
      if ((f=dfs(p.to,min(e[i].cap,flow)))>0) {
        e[i].cap-=f;
        e[i^1].cap+=f;
      return f;
      }
    }
  }
  return 0;
}


int dinic(){
  int i,ans=0,flow;
  while(bfs()) {
    for (int i=0; i<=t; ++i) {
      work[i]=head[i];
    }
    while(1) {
      for (int i=0; i<=t; ++i) {
        vis[i]=0;
      }

      flow=dfs(src,INF);
      if (flow==0) break;
      ans+=flow;
    }
  }
  return ans;
}

int main(){
  int n,m;
  int val[1024];
  while (cin>>n>>m) {
    MEM(val,0);
    int tmp,sum;
    for (int i=1; i<=n; ++i) {
      sum=0;
      for (int j=1; j<=m; ++j) {
        scanf("%d",&tmp);
        sum=sum*2+tmp;
      }
      val[sum]++;
    }
    cnt=0;
    MEM(head,-1);
    t=1035;
    for (int i=1 ;i<=1024; ++i) {
      Addedge(0,i,val[i-1]);
    }
    for (int i=1025;i<1025+m; ++i) {
      scanf("%d",&tmp);
      Addedge(i,1035,tmp);
    }
    for (int i=1; i<=1024; ++i) {
      tmp=i-1;
      for (int j=1025+m-1;j>=1025; --j) {
        if (tmp%2) Addedge(i,j,INF);
        tmp/=2;
      }
    }
    if (dinic()==n) puts("YES");
    else puts("NO");
  }

}


