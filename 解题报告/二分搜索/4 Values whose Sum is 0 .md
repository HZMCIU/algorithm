##  [4 Values whose Sum is 0](https://cn.vjudge.net/problem/POJ-2785)         

#### 思路

将a和b相加到sum1中，c和d相加到sum2中，而后对sum2的元素进行排序。而后对sum1中的每个数字在sum2

中查找是否存在和sum1相反的数，**如果存在那么由这个点，向左右两端延伸，找出所有满足条件的点**

```cpp
#include <cstdio>
#include <algorithm>
using namespace std;
int a[4010],b[4010],c[4010],d[4010];
int sum1[4010*4010],sum2[4010*4010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    int t=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           	//将a和b的和加到sum1中，c和d和加入sum2中
            sum1[t]=a[i]+b[j];
            sum2[t]=c[i]+d[j];
            t++;
        }
    }
    //printf("%d\n",t);
    //for(int i=0;i<t;i++) printf("%d ",sum1[i]);
    //puts("");
    //for(int i=0;i<t;i++) printf("%d ",sum2[i]);
    //puts("");
    sort(sum2,sum2+t);
    //for(int i=0;i<t;i++) printf("%d ",sum2[i]);
    int cnt=0;
    for(int  i=0;i<t;i++)
    {
        int k=0-sum1[i];
        int l=0,r=t+2,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(sum2[mid]>k)
            {
                r=mid-1;
            }
            else if(sum2[mid]<k)
            {
                l=mid+1;
            }
            else if(sum2[mid]==k)
            {
                cnt++;
                int i=mid+1;
              	//向左右两端延伸，求出符合条件的点
                while(i<t&&sum2[i]==k)  cnt++,i++;
                i=mid-1;
                while(i>=0&&sum2[i]==k) cnt++,i--;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

```



