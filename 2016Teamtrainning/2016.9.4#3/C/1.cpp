/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年09月04日 星期日 13时03分56秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define pb push_back
using namespace std;
typedef long long LL;
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int a[N],b[N];
vector<pair<int,int>> v;

int main() {
  int n,m,i,x;
  scanf("%d%d",&n,&m);
  while (m--) {
    scanf("%d",&x);
    a[x]++;
    if (a[0]>2) a[1]++,a[0]-=2;
    //cout<<"a[0]="<<a[0]<<endl;
    //cout<<"b[0]="<<b[0]<<endl;
    int pre=a[0];
    for (i=1; i<n-1; ++i) {
      if (a[i]>2) a[i+1]++,a[i]-=2;
      if (a[i]==2 && pre==2){
        a[i-1]=0;
        a[i]=1;
        a[i+1]++;
      }
      //cout<<"a["<<i<<"]="<<a[i]<<endl;
      pre=a[i];
    }
    int cnt=0;
    for (i=0; i<n; ++i)
      if (a[i]!=b[i]) cnt++,v.pb(make_pair(i,a[i]));
    printf("%d",cnt);
    for (i=0; i<cnt; ++i)
      printf(" %d %d",v[i].first,v[i].second);
    v.clear();
    puts("");
    for (i=0; i<n; ++i) b[i]=a[i];
  }
}
