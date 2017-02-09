/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月04日 星期二 15时41分40秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int MAXM=MAXN*MAXN;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int inde[MAXN];
int outde[MAXN];
int deg[MAXN];
bool vis[MAXN][MAXN];
struct MaxFlow{
    int head[MAXN];
    struct Edge{
        int u,v,nex,cap,flow;
    }edge[MAXM];
    int tot,s,t,n,m;
    int dis[MAXN];
    int cur[MAXN];
    void init(int n,int m){
        this->s=0;
        this->t=n+1;
        this->n=n;
        this->m=m;
        MEM(head,-1);
        tot=0;
    }
    void Addedge(int u,int v,int w) {
        edge[tot].v=v,edge[tot].cap=w,edge[tot].flow=0,edge[tot].nex=head[u],head[u]=tot++;
        edge[tot].v=u,edge[tot].cap=0,edge[tot].flow=0,edge[tot].nex=head[v],head[v]=tot++;
    }
    bool bfs() {
        MEM(dis,-1);
        queue<int>q;
        dis[s]=0;
        q.push(s);
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for (int i=head[u]; ~i; i=edge[i].nex) {
                int v=edge[i].v;
                if (edge[i].cap>edge[i].flow&&dis[v]==-1) {
                    q.push(v);
                    dis[v]=dis[u]+1;
                }
            }
        }
        return dis[t]!=-1;
    }
    int dfs(int u,int delta) {
        if (u==t||delta==0)
            return delta;
            int ret=0;
            int aug;
            for(int &i=cur[u]; ~i; i=edge[i].nex) {
                int v=edge[i].v;
                if (dis[v]==dis[u]+1&&(aug=dfs(v,min(edge[i].cap-edge[i].flow,delta)))>0) {
                    edge[i].flow+=aug;
                    edge[i^1].flow-=aug;
                    delta-=aug;
                    ret+=aug;
                    if (delta==0) break;
                }
            }
            return ret;
    }
    void dinic() {
        int ret=0;
        while(bfs()) {
            memcpy(cur,head,sizeof head);
            ret+=dfs(s,INF);
            //cout<<ret<<endl;
        }
        cout<<ret<<endl;
     }
}nima;
int b[MAXN];
int main() {
  int Test;
  int sum=0;
  cin>>Test;
  while (Test--) {
    int n,m;
    scanf("%d %d",&n,&m);
    int u,v;
    MEM(vis,0);
    MEM(inde,0);
    MEM(deg,0);
    MEM(outde,0);
    nima.init(n,m);
    for (int i=0; i<m; ++i) {
      scanf("%d %d",&u,&v);
      nima.Addedge(u,v,1);
      outde[u]++;
      inde[v]++;
      deg[u]++;
      deg[v]++;
     // printf("Addedge(%d %d)\n",u,v);

    }
    //puts("-----");
    int pre=0;
    int ans=n;
    /*for (int i=1; i<=n; ++i) {
      if (deg[i]%2) {
        if (!pre) pre=i;
        else {
          nima.Addedge(pre,i,1),outde[pre]++,inde[i]++;
          printf("Addedge(%d %d)\n",pre,i);
          pre=i;
        }
        ans--;
      }
    }*/
    int g=0;
   
	for (int i = 1; i <= n; ++i)
	{
		if (abs(inde[i] - outde[i]) % 2 == 1)b[++g] = i;
	}
        //puts("-----");
	for (int i = 1; i <= g; i += 2)
	{
		nima.Addedge(b[i], b[i + 1], 1);
		++outde[b[i]];
		++inde[b[i + 1]];
                //printf("Addedge(%d %d)\n",b[i],b[i+1]);
	}


    /*for (int i=1 ;i<=n; ++i) {
      printf("deg[%d]=%d outde=%d inde=%d\n",i,deg[i],outde[i],inde[i]);
    }*/

    for (int i=1 ;i<=n; ++i) {
      int x=abs(outde[i]-inde[i])/2;
      if (inde[i]>outde[i]) {
        nima.Addedge(i,nima.t,x);
      // printf("Add:%d T=%d\n",i,x);
        sum+=x;
      }
      else if (inde[i]<outde[i]) {
        nima.Addedge(nima.s,i,x);
       //printf("ADD:S %d=%d\n",i,x);
      }
    }
    nima.dinic();
    /*for (int i=0; i<nima.tot; ++i) {
      printf("i:%d i^1:%d u:%d v:%d cap:%d flow:%d\n",i,i^1,nima.edge[i^1].v,nima.edge[i].v,nima.edge[i].cap,nima.edge[i].flow);
    }*/

    printf("%d\n",n-g);
    for (int i=0; i<m*2; i+=2) {
      int from=nima.edge[i].v;
      int to=nima.edge[i^1].v;
      if (nima.edge[i].cap==1) printf("%d %d\n",from,to);
      else printf("%d %d\n",to,from);
    }
  }
}




