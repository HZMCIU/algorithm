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
        ///�Ȱ�a[l]�е���ȡ������a[l]���г���
        int x=a[l];
        int i=l,j=r;
        while(i<j)
        {
            ///�ȴ��ں�벿�����ҵ�һ��С�ڵ���x����
            while(i<j&&a[j]>x)
                j--;
            ///�ǰ�벿�ֵĿ�λ��a[j]�ճ���
            a[i]=a[j];
            ///��ǰ�벿�����ҵ�һ������x����
            while(i<j&&a[i]<=x)
                i++;
            ///��x���a[j]����벿��
            a[j]=a[i];
        }
        ///������ȡ���������Ż�ȥ
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
