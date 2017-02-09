#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
const LL INF=0x3f3f3f3f3f3f3f3fll;
struct node {
  int x,y;
  LL step;
  int dir;
  int id;
};
int vis[MAXN];
typedef pair<int,int> PAIR;
LL ans[MAXN];
map<int,vector<pair<int,int> > >sz,sf;
void judge(node now) {
  int b;
  int flag=0;
  if (now.dir==1||now.dir==2) b=now.y-now.x;
  else b=now.x+now.y,flag=1;
  if (flag==1) {
    for (auto it :sf[b]) {
      int rx=it.first,id=it.second;
      ans[id]=min(ans[id],now.step+abs(now.x-rx));
    }
    sf.erase(b);
  }
  else {
    for (auto it : sz[b]) {
      int rx=it.first,id=it.second;
      ans[id]=min(ans[id],now.step+abs(now.x-rx));
    }
    sz.erase(b);
  }
}


int main() {
  int n,m,k;
  scanf("%d %d %d",&m,&n,&k);
  int x,y;
  for (int i=1; i<=k; ++i) {
    scanf("%d %d",&x,&y);
    swap(x,y);
    sz[y-x].push_back(PAIR(x,i));
    sf[y+x].push_back(PAIR(x,i));
  }
  MEMINF(ans);
  node now;
  now.x=0,now.y=0,now.dir=1,now.step=0;
  int mx,my;
  bool flag=false;
  int cnt=0;
  while (true) {
    node lim;
    if (now.dir==1) {
      int r=m-now.y,u=n-now.x;
      if (u<r) lim.dir=3,mx=u,my=u;
      else if(r<u)lim.dir=0,mx=r,my=r;
      else if (r==u) mx=my=r,flag=true;

    }
    else if(now.dir==0) {
      int l=now.y-0,u=n-now.x;
      if (l<u) mx=l,my=-l,lim.dir=1;
      else if(u<l)mx=u,my=-u,lim.dir=2;
      else mx=l,my=-l,flag=true;
    }
    else if(now.dir==2) {
      int d=now.x-0,l=now.y-0;
      if (l<d) mx=my=-l,lim.dir=3;
      else if(d<l)mx=my=-d,lim.dir=0;
      else mx=my=-d,flag=true;
    }
    else if(now.dir==3) {
      int r=m-now.y,d=now.x-0;
      if (r<d) mx=-r,my=r,lim.dir=2;
      else if(d<r)mx=-d,my=d,lim.dir=1;
      else mx=-d,my=d,flag=true;
    }
        lim.x=now.x+mx;
        lim.y=now.y+my;
        lim.step=now.step+abs(mx);
        judge(now);
        now=lim;
       if(now.x==0&&now.y==0) break;
       else if (now.x==0&&now.y==m) break;
       else if (now.x==n&&now.y==m) break;
       else if (now.x==n&&now.y==0) break;
  }
  for (int i=1; i<=k; ++i) {
    ans[i]==INF?puts("-1"):printf("%lld\n",ans[i]);
  }
}




