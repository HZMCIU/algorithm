## Removing Columns

https://cn.vjudge.net/problem/CodeForces-496C

### 总结

1. 使用**cin**来读入二维字符数组比**scanf**更加方便，不会出现由于回车键，使用无法将字符数组完全读入内存中情况
2. 使用**f**数组来标志每两行之间的关系（通过**数组来记录两个状态之间的关系**，可以使得前面的计算结果能够保留下来，为后面的计算作为计算依据，这种技巧已经是我第二次遇到了，https://cn.vjudge.net/problem/POJ-3276）

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[200][200];
int f[200];
bool del[200];
int main()
{
    scanf("%d%d",&n,&m);
  	//char ch; 若要使用 scanf 先要定义一个char临时变量
    for(int  i=0;i<n;i++)
    {
        for(int  j=0;j<m;j++)
        {
            cin >> s[i][j];
            //scanf("%c",&s[i][j]); 这样写会把换行符也读入，导致错误
          
            //正确的写法，但是麻烦，先将字符读入临时变量中，可以知道换行符都是在j=0的时候被读取的，所以
            //当读取的字符为换行符的时候要将j-=1，来抵消j++的作用
          	//scanf("%c",&ch); 
            //if(ch=='\n') j-=1;
            //else s[i][j]=ch;
        }
    }
    int cnt=0;
    bool flag=1;
    for(int  j=0;j<m;j++)
    {
        flag=1;
        for(int  i=0;i<n-1;i++)
        {
            if(s[i][j]>s[i+1][j]&&f[i]==0) {cnt++;flag=0;break;}
        }
        if(flag)
        for(int  i=0;i<n-1;i++) 
        {
            if(s[i][j]<s[i+1][j]) f[i]=1;
        }
    }
    
    printf("%d\n",cnt);
}
```

