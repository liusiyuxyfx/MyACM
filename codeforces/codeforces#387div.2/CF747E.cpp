/*************************************************************************
     File Name: 747E.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2017年01月09日 星期一 12时08分36秒
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
using namespace std;
typedef long long LL;
const int MAXN=1e6 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
string pat, pal, num;
vector< vector<string> > mp(MAXN);
stack<int> st;
int main()
{
  bool flag = 0;
  int maxi = 0;
  cin >> pat;
  for(int i = 0 ; i < pat.size(); ++i) {
    if(pat[i] == ',') {
        if (!flag) {
            while (!st.empty() && st.top() == 0)
              st.pop();
            mp[int(st.size())].push_back(pal);
            maxi = max(maxi,int(st.size()));
            if(!st.empty())
              --st.top();
            flag = 1;
          }
        else {
          st.push(stoi(num));
          flag = 0;
        }
        num = "";
        pal = "";
      }
    else {
      if(!flag)
        pal+=pat[i];
      else
        num+=pat[i];	  
    }
  }
  cout << maxi+1 << endl;
  for(int i = 0 ;i < maxi+1 ; ++i)
    {
      for(int j = 0 ; j < mp[i].size() ; ++j)
  	cout << mp[i][j] << endl;
      cout << endl;
    }
  return 0;
}
