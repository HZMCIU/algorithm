## [Can you find it?](https://cn.vjudge.net/problem/HDU-2141)

#### 思路

先对两位数a，b求和，将结果保存在sum数组中，将数组排序，而枚举c[i]，使用二分查找判断s-c[i]是否存在于sum数组中，如果存在就成立

```cpp
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[550],b[550],c[550];
int sum[550*550+100];
int L,M,N,S;
int tot;
int bsearch(int n)
{
    int f=0;
    int l,r,mid;
    int ans;
    int t;
    for(int i=0;i<M;i++)     
    {
       //if(n-c[i]<0) continue;
       t=n-c[i];
       l=0,r=tot+1;
       while(l<=r)
       {
           mid=(r-l)/2+l;
           if(sum[mid]>t)
           {
               r=mid-1; 
           }
           else if(sum[mid]<t)
           {
               l=mid+1; 
           }
           else if(sum[mid]==t)
           {
                //printf("%d %d\n",sum[mid],c[i]);
                f=1;break;
           }
       }
    }
    return f;
}
int main()
{
    int cnt=0;
    while(~scanf("%d%d%d",&L,&N,&M))
    {
        for(int i=0;i<L;i++) scanf("%d",&a[i]);
        for(int i=0;i<N;i++) scanf("%d",&b[i]);
        for(int i=0;i<M;i++) scanf("%d",&c[i]);
        scanf("%d",&S);
        tot=0;
        for(int i=0;i<L;i++)//由于题目的内存限制，只能对两位数进行预处理(就是对两位数相加)
        {
            for(int  j=0;j<N;j++)
            {
                sum[tot++]=a[i]+b[j];
            }
        }
        sort(sum,sum+tot);
        sort(c,c+M);
        int t;
        printf("Case %d:\n",++cnt);
        for(int i=0;i<S;i++)
        {
            scanf("%d",&t);
            int res=bsearch(t);
            if(res) puts("YES");
            else puts("NO");
        }
    }
}


```

