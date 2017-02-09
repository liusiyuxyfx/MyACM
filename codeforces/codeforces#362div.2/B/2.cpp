/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月15日 星期五 19时02分46秒
************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <deque>
#include <vector>
#include <map>
#include <list>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <utility>
#include <complex>
#include <numeric>
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
char a[500];
char pre[500];
char after[500];

void print (bool flag0pre,bool flag0af,int q,int p)
{
  if(flag0pre)cout<<'0';
  else{
    for(int i=0;i<q;i++)
    cout<<pre[i];
  }
  if(flag0af){puts("");return;}
  else{
    cout<<'.';
    for(int i=p-1;i>=0;i++)
    cout<<after[i];
    puts("");
  }
}

  

int main()
{
  while(cin>>a){
    int len=strlen(a);
    int deb,e;
    for(int i=0;i<len;i++){
      if(a[i]=='.')deb=i;
      if(a[i]=='e'){
        e=i;
        break;
      }
    }
    int sw=0;
    int temp=1;
    bool flag0pre=true;
    for(int i=len-1;i>=e;i--){
      if(a[i]=='e')break;
      sw+=(a [i]-48)*temp;
      temp*=10;
    }
   /**/ printf("sw=%d\n",sw);
    cout<<"deb="<<deb<<endl;
    int q=0;
    int flag=1;
    for(int i=0;i<=deb+sw;i++){
      if(!flag||a[i]=='e')
      if(a[i]=='e'){
        flag=0;
        if(flag0pre)break;
        else pre[q++]='0';
      }
      if(flag){
      if(a[i]=='.')continue;
      if(flag0pre){
        if(a[i]=='0')continue;
        else{
        pre[q++]=a[i];
          flag0pre=false;
          continue;
        }
      }
      pre[q++]=a[i];
    }
    }
    /***********testpre***********/
    printf("pre:");
    for(int i=0;i<q;i++)
    cout<<pre[i];
    puts("");
    /***************************/
    int p=0;
    bool flag0af=true;
    for(int i=e-1;i>=deb+sw+1;i--){
      if(flag0af){
        if(a[i]=='0')continue;
        else{
          after[p++]=a[i];
          flag0af=false;
          continue;
        }
      }
        after[p++]=a[i];
     }
     print(flag0pre,flag0af,q,p);
    puts("---------------");
  }
}

