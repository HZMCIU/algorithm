#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;

int a[maxn]={49,38,65,97,76,13,27,49};

void quick_sort(int l,int r)
{
    if(l<r)
    {
        ///先把a[l]中的数取出来，a[l]空闲出来
        int x=a[l];
        int i=l,j=r;
        while(i<j)
        {
            ///先从在后半部分中找到一个小于等于x的数
            while(i<j&&a[j]>x)
                j--;
            ///填补前半部分的空位，a[j]空出来
            a[i]=a[j];
            ///在前半部分中找到一个大于x的数
            while(i<j&&a[i]<=x)
                i++;
            ///将x填补在a[j]，后半部分
            a[j]=a[i];
        }
        ///将最先取出来的数放回去
        a[i]=x;
        quick_sort(l,i-1);
        quick_sort(i+1,r);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    quick_sort(0,7);
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);
    return 0;
}
