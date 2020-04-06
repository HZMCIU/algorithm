https://cn.vjudge.net/problem/CodeForces-680C

## Bear and Prime 100

### 题意

**奇特点： **系统内部生成一个数字（未知），自己构造一个数据输入，系统根据程序的输入，返回一个字符串（"yes","no"），然后根据系统返回的值来判断，这个这个数据是否为素数。

### 思路

将[2-200]中的素数全部枚举出来，如果这个数字可以被两个以上的素数整除，那么这个数是合数。但是会忽略4,9,25,49这几个数，所以这几个数字需要另外判断，如果未知数x能够被4,9,25,49,这几个数中的任意一个整除那么，这个未知数x就是合数。

```cpp
#include <bits/stdc++.h>
using  namespace  std;
int num[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
int main()
{
    int cnt=0;
    int f=0;
    for(int i=0;i<15;i++) 
    {
        printf("%d\n",num[i]);
        fflush(stdout);
        char s[6];
        cin >> s;
        if(s[0]=='y') cnt++;
    }
    for(int i=15;i<19;i++)
    {
        printf("%d\n",num[i]);
        fflush(stdout);
        char s[6];
        cin >> s;
        if(s[0]=='y') f=1;
    }
    if(f||cnt>=2) 
    {
         puts("composite");
         fflush(stdout);
    }
    else 
    {
         puts("prime");
         fflush(stdout);
    }
}

```

