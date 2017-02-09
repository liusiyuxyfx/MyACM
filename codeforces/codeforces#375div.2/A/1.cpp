/*************************************************************************
     File Name: 1.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: 2016年10月03日 星期一 19时47分50秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int x1,x2,x3,MAXX,MINX;
      scanf("%d%d%d",&x1,&x2,&x3);
        MAXX=max(x1,max(x2,x3));
          MINX=min(x1,min(x2,x3));
            printf("%d\n",MAXX-MINX);
}

