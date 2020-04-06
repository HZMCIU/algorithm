#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+100;
typedef long long ll;
typedef pair<int,int> P;
///调整为大顶堆
void HeapAdjust(int a[],int s,int len)
{
    int p=s;
    for(int j=2*s+1;j<=len;j=j*2+1)
    {
        ///选择孩子中较大者换上去
        if(a[j]<a[j+1]&&j+1<=len)
            j++;
        if(a[p]>a[j])
            break;
        swap(a[p],a[j]);
        p=j;
    }
}
void HeapSort(int a[],int len)
{
    ///编号为len/2的节点有孩子，从底部开始调整
    ///len/2为最后一个孩子的父节点
    for(int i=len/2;i>=0;i--)
        HeapAdjust(a,i,len);
    for(int i=len;i>0;i--)
    {
        swap(a[0],a[i]);
        HeapAdjust(a,0,i-1);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int a[]={49,38,65,97,76,13,27,49};
    HeapSort(a,7);
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);
    return 0;
}

