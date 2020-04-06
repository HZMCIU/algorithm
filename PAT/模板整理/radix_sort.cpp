#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;

int a[maxn]={80,30,60,40,20,10,50,70};
int tmp[maxn];
int bucket[10];
int get_max(int len)
{
    int mx=a[0];
    for(int i=1;i<len;i++)
        if(a[i]>mx)
        mx=a[i];
    return mx;
}
int count_sort(int len,int exp)
{
    memset(bucket,0,sizeof(bucket));
    for(int i=0;i<len;i++)
        bucket[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        bucket[i]+=bucket[i-1];
    for(int i=len-1;i>=0;i--)
    {
        tmp[bucket[(a[i]/exp)%10]-1]=a[i];
        bucket[(a[i]/exp)%10]--;
    }
    for(int i=0;i<len;i++)
        a[i]=tmp[i];
}
int radix_sort(int len)
{
    int mx=get_max(len);
    for(int exp=1;mx/exp>0;exp*=10)
    {
        count_sort(len,exp);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    srand(time(0));
    int n=100;
    for(int i=0;i<n;i++)
        a[i]=rand()%20;
    radix_sort(n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
