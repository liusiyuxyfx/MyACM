/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月19日 星期二 20时59分06秒
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
const int MAXN=1e2+10;
//const int MINN=;
const int INF=0x3f3f3f3f;
const int maxn=200005;  
ll l[maxn];
ll r[maxn];
char s[maxn];
int main(){
  int n;
  while(cin>>n){
    cin>>s;
    for(int i=0;i<n;i++){
      cin>>l[i];
    }
    ll ans =INF;
    for(int i=0;i<n;i++){
      if(s[i]=='R'&&s[i+1]=='L')
      ans=min(ans,(l[i+1]-l[i])/2);
    }
    if(ans==INF)puts("-1");
    else
    cout<<ans<<endl;
  }
}

