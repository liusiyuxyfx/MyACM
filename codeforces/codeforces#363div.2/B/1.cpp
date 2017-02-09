/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月19日 星期二 21时57分10秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define MAX(a,b) (a)>(b)?(a):(b);
#define MIN(a,b) (a)<(b)?(a):(b)
#define APS(a) (a)>0?(a):-(a)
#define FL(s,n,a) fill(s,s+n,a);
#define MAPIT(a,b) map<a,b>::iterator it;
#define VECIT(type) vector<type>::iterator it;
#define SETIT(type) set<type>::iterator it;
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
//const int MINN=;
const int INF=0x3f3f3f3f;
bool judge (int &x)
{
  if(!x)x++;
}

int main(){
  int n,m,x1,x2,y1,y2;
  char mp[MAXN][MAXN];
  cin>>n>>m;
  int i,j;
  for(i=1;i<=n;i++)
  scanf("%s",mp[i]+1);
  x1=x2=y1=y2=0;
  bool flag1=true;
  bool flag2=true;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++)
      if(mp[i][j]=='*'){
        x1=i;y2=j;
        break;
      }
      if(x1)break;
  }
  if(i>n&&j>m){
    puts("YES");
    puts("1 1");
  }
  for(i=x1+1;i<=n&&flag1;i++)
  for(j=1;j<=m;j++)
  if(mp[i][j]=='*'&&!y1)y1=j;
  else
  if(mp[i][j]=='*'&&y1!=j){
    flag1=false;break;
  }
  
  for(i=1;i<=m&&flag2;i++){
    if(i==y2)
    continue;
    for(j=1;j<=n;j++)
    if(mp[j][i]=='*'&&!x2)x2=j;
    else if(mp[j][i]=='*'&&x2!=j){
      flag2=false;
      break;
    }
  }
  judge(x1);
  judge(x2);
  judge(y1);
  judge(y2);
  if(flag1)printf("YES\n%d %d",x1,y1);
  else if(flag2)printf("YES\n%d %d",x2,y2);
  else puts("NO");
}



