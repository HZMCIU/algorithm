#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;

int a[maxn]={80,30,60,40,20,10,50,70};
int tmp[maxn];
void merge(int l,int m,int r)
{
    int i=l,j=m+1;
    int cnt=l;
    while(i<=m&&j<=r)
    {
        if(a[i]<=a[j])
            tmp[cnt++]=a[i++];
        else
            tmp[cnt++]=a[j++];
    }
    ///将剩余的点全部加入到数组中
    while(i<=m)
        tmp[cnt++]=a[i++];
    while(j<=r)
        tmp[cnt++]=a[j++];
    for(int k=l;k<=r;k++)
        a[k]=tmp[k];
}
void merge_sort_up2down(int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)>>1;
        merge_sort_up2down(l,mid);
        merge_sort_up2down(mid+1,r);
        merge(l,mid,r);
    }
}
void merge_groups(int gap,int len)
{
    int i;
    for(i=0;i+2*gap-1<len;i+=2*gap)
    {
        merge(i,i+gap-1,i+2*gap-1);
    }
    ///将最后一个长度未达到len的数组段，合并到前一个长度为len的数组段中
    if(i+gap-1<len-1)
    {
        merge(i,i+gap-1,len-1);
    }
}
void merge_sort_down2up(int l,int r)
{
    int len=r-l+1;
    for(int i=1;i<len;i*=2)
    {
        merge_groups(i,len);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    srand(time(0));
    int n=30;
    for(int i=0;i<n;i++)
        a[i]=rand()%10;
    merge_sort_up2down(0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
