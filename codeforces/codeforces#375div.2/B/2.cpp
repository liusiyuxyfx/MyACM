/*************************************************************************
     File Name: 2.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 20时11分52秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char str[300];
int main(){
  int n;
  cin>>n;
  cin>>str;

  int flag=0,ans1=0,sum=0,ans2=0,sum1=0;
  for (int i=0; i<n; ++i){
    if (!flag&&str[i]=='_')continue;
    if ((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')){
      if (flag!=2){
      flag=1;
      sum++;
      }
      else {
        sum1++;
      }
    }
    else if (str[i]=='_'){
      if (flag!=2){
      flag=0;
      ans1=max(ans1,sum);
      //printf("%d\n",sum);
      sum=0;
      }
      else{
        if (sum1)ans2++,sum1=0;
      }
    }
    else if (str[i]=='('){
      flag=2;
      ans1=max(ans1,sum);
      sum=0;
    }
    else {
      flag=0;
      if (sum1)ans2++,sum1=0;
    }
  }
  ans1=max(ans1,sum);
  cout<<ans1<<" "<<ans2<<endl;
}
