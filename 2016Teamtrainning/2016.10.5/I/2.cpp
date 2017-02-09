/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月05日 星期三 15时18分18秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=205;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
typedef pair<int,int> PAIR;
vector<PAIR  >num;
vector<int>limit;
bool cmp (PAIR a,PAIR b) {
  if (a.second==b.second) return a.first<b.first;
  return a.second<b.second;
}

int main() {
  int T;
  int n;
  cin>>T;
  for (int cas=1; cas<=T; ++cas) {
    printf("Case %d: ",cas);
    num.clear();
    limit.clear();
    int u,v;
    cin>>n;
    for (int i=0; i<n; ++i) {
      scanf("%d %d",&u,&v);
      num.push_back(make_pair(u,v));
    }
    sort(num.begin(),num.end(),cmp);
    /*for (int i=0; i<num.size(); ++i) {
      printf("%d %d\n",num[i].first,num[i].second);
    }*/

    for (auto ni=num.begin(); ni!=num.end(); ni++) {
      auto find=lower_bound(limit.begin(),limit.end(),ni->first+1);
      if (find==limit.end()) limit.push_back(ni->first);
      else {
        *find=ni->first;
      }
    }
    cout<<(int)limit.size()<<endl;
  }
}

        
