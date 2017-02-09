/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月03日 星期六 14时07分08秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int N=805;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
struct node{
  int x,y;
}s,t;
char mp[N][N];
int vis[N][N];
int mx[]={0,1,0,-1},my[]={1,0,-1,0};
int dir,n,m,step;
queue<node> q;

bool solve(int i) {
  if (i<0) return 0;
  //cout<<"\ni="<<i<<endl;
  //cout<<"dir="<<dir<<endl;
  t.x=s.x+mx[i];
  t.y=s.y+my[i];
  //cout<<"t.x="<<t.x<<" t.y="<<t.y<<endl;
  if (t.x<0 || t.x>=2*n-1 || t.y<0 || t.y>=2*m-1)
    return 0;
  if (mp[t.x][t.y]!='-' && mp[t.x][t.y]!='|')
    return 0;
  t.x+=mx[i];
  t.y+=my[i];
  if (t.x<0 || t.x>=2*n-1 || t.y<0 || t.y>=2*m-1)
    return 0;
  //cout<<"vis["<<t.x<<"]["<<t.y<<"]="<<vis[t.x][t.y]<<endl;
  //cout<<"step="<<step<<endl;
  if (vis[t.x][t.y]!=step) return 0;
  //cout<<"\ni="<<i<<" dir="<<dir<<endl;
  if (dir==-1) {
    if (i) puts("N");
    else puts("E");
  } else if (dir==i) printf("F");
  else if ((i+1)%4==dir) printf("L");
  else printf("R");
  dir=i;
  q.push(t);
  return 1;
}

int main() {
  int i,j;
  while (~scanf("%d%d",&n,&m)) {
    getchar();
    for (i=0; i<2*n-1; ++i) {
      gets(mp[i]);
      //for (j=0; j<2*m-1; ++j)
        //cout<<mp[i][j];
      //puts("");
    }
    MEM(vis,0);
    s.x=0,s.y=2*m-2;
    vis[s.x][s.y]=1;
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty()) {
      s=q.front();
      q.pop();
      for (i=0; i<4; ++i) {
        t.x=s.x+mx[i];
        t.y=s.y+my[i];
        if (t.x<0 || t.x>2*n-2 || t.y<0 || t.y>2*m-2)
          continue;
        //cout<<"----t.x="<<t.x<<" t.y="<<t.y<<endl;
        //cout<<mp[t.x][t.y]<<endl;
        if (mp[t.x][t.y]!='-' && mp[t.x][t.y]!='|') continue;
        t.x+=mx[i];
        t.y+=my[i];
        if (t.x<0 || t.x>2*n-2 || t.y<0 || t.y>2*m-2)
          continue;
        if (vis[t.x][t.y]) continue;
        vis[t.x][t.y]=vis[s.x][s.y]+1;
        //cout<<"vis["<<t.x<<"]["<<t.y<<"]="<<vis[t.x][t.y]<<endl;
        q.push(t);
      }
    }
    //cout<<"-----"<<endl;
    s.x=2*n-2,s.y=0;
    step=vis[s.x][s.y];
    //cout<<"step="<<step<<endl;
    while (!q.empty()) q.pop();
    q.push(s);
    dir=-1;
    while (!q.empty()) {
      //cout<<"s.x="<<s.x<<" s.y="<<s.y<<endl;
      s=q.front();
      q.pop();
      step--;
      bool flag=solve(dir);
      for (i=0; i<4 && !flag; ++i)
        flag=solve(i);
    }
    puts("");
  }
}
