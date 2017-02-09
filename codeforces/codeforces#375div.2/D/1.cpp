/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 20时13分51秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=4000;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int n,m,k;
char mp[MAXN][MAXN];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int top;
struct node {
  int x,y;
};
bool bfs_vis[MAXN][MAXN];
bool dfs_vis[MAXN][MAXN];
bool cmp(node a,node b) {
  return a.x<b.x;
}

int dfscnt;
vector<node>que;
queue<node>q;
vector<node> vec[MAXN];
bool flag;
void dfs(node u) {
  dfscnt++;
  vec[top].push_back(u);
  dfs_vis[u.x][u.y]=1;
  if (u.x==1||u.x==n||u.y==1||u.y==m) flag=false;
  //printf("dfscnt:%d\n-------",dfscnt);
  for (int i=0; i<4; ++i) {
    node v=u;
    v.x+=dx[i];
    v.y+=dy[i];
    if (dfs_vis[v.x][v.y])continue;
    if (mp[v.x][v.y]!='.') continue;
    //printf("%d %d\n",v.x,v.y);
    if (v.x==1||v.x==n||v.y==1||v.y==m) flag=false;
    dfs(v);
  }
}

void bfs(){
  node u;
  u.x=1,u.y=1;
  q.push(u);
  bfs_vis[1][1]=1;
  MEM(bfs_vis,0);
  while(!q.empty()) {
    node no=q.front();
    q.pop();
    //printf("m %c %d\n",mp[4][3],!dfs_vis[4][3]);
    if (mp[no.x][no.y]=='.'&&!dfs_vis[no.x][no.y]) {
      flag=true;
      //puts("-----");
      dfs(no);
      if (flag) {
       //printf("no:%d %d\n",no.x,no.y);
        //puts("*****");
        node lal;
        lal.x=vec[top].size();
        lal.y=top;
        que.push_back(lal);
        top++;
      }
      else {
        vec[top].clear();
      }
    }
    for (int i=0; i<4; ++i) {
      node v=no;
      v.x+=dx[i];
      v.y+=dy[i];
      if (bfs_vis[v.x][v.y])continue;
      if (v.x<1||v.x>n||v.y<1||v.y>m) continue;
      q.push(v);
      bfs_vis[v.x][v.y]=1;
    }
  }
}
      
int main() {
  scanf("%d %d %d",&n,&m,&k);
  top=0;
  for (int i=1; i<=n; ++i) {
    scanf("%s",mp[i]+1);
  }

  bfs();
  //printf("MAP%ld\n",que.size());
  int sum=0;
  sort(que.begin(),que.end(),cmp);
  for (auto i=0; i<top-k; ++i) {
    sum+=que[i].x;
    int num=que[i].y;
    for (int it=0;it<vec[num].size(); ++it) {
      int x=vec[num][it].x;
      int y=vec[num][it].y;
     mp[x][y]='*';
    }
  }

  printf("%d\n",sum);
  for (int i=1; i<=n; ++i) 
   puts(mp[i]+1);

}


