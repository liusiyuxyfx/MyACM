/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年07月23日 星期六 20时17分41秒
************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define MAPIT(a,b) map<a,b>::iterator it;
#define VECIT(type) vector<type>::iterator it;
#define SETIT(type) set<type>::iterator it;
using namespace std;
typedef long long ll;
const int MAXN=1e2+10;
//const int MINN=;
const int INF=0x3f3f3f3f;
int main()
{
  char a[11000];
  bool b[10];
  int n,k;
  while(cin>>a>>k){
  MEM(b,0);
  for(int i=0;i<k;i++){
    int c;
    cin>>c;
    b[c]=1;
  }
  int len=strlen(a);
  int flag=0;
  for(int i=0;i<len;i++){
    if(b[a[i]-48]){
      flag=1;
      break;
    }
  }
    int flag2=1;
  char ans[100];
  int canfind;
  if(flag){
    int h=0;//代表这从这一位开始最大
    for(int i=0;i<len;i++){
      canfind=0;
      if(!h){
        if(b[a[i]-48]){
          h=1;
          for(int j=a[i]-48;j<10;j++)
          if(b[j]==0){ans[i]=j+48;canfind=1;break;}
        }
        else
        ans[i]=a[i];
      }
      else{
          for(int j=0;j<10;j++)
          if(b[j]==0){
            ans[i]=j+48;
            canfind=1;
            break;
          }
        }
      if(!canfind){
        h=0;
        int j;
        if(i!=0)j=0;
        else j=1;
        for(;j<10;j++)
        if(b[j]==0){
          ans[i]=j+48;
          break;
        }
      }

      if(flag2)
      if(i==len-1){
        h=1;
        if(strncmp(a,ans,len)>0){
        len++;
          flag2=0;
        }
      }
    }
    for(int i=0;i<len;i++)
    cout<<ans[i];
    puts("");
  }
  else
  cout<<a<<endl;
  }

}


      
