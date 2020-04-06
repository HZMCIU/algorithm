#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> P;

int na[maxn],nb[maxn];
string add(string a,string b)
{
    memset(na,0,sizeof(na));
    memset(nb,0,sizeof(nb));
    int len1=a.length();
    int len2=b.length();
    int len=max(len1,len2);
    for(int i=0,j=len1-1;i<len1;i++,j--)
        na[j]=a[i]-'0';
    for(int i=0,j=len2-1;i<len2;i++,j--)
        nb[j]=b[i]-'0';
    int c=0;
    for(int i=0;i<len;i++)
    {
        na[i]+=nb[i]+c;
        c=0;
        if(na[i]>10)
            na[i]%=10,c=1;
    }
    if(c)
        na[len++]=1;
    string ret;
    for(int i=len-1;i>=0;i--)
        ret+='0'+na[i];
    return ret;
}
string sub(string a,string b)
{
    memset(na,0,sizeof(na));
    memset(nb,0,sizeof(nb));
    int len1=a.length();
    int len2=b.length();
    int len=max(len1,len2);
    bool neg=false;
    if(len1<len2)
        neg=true;
    else if(a<b)
        neg=true;
    ///如果a<b的话，那么交换a,b,交换的同时也要交换len1和len2
    if(neg)
    {
        swap(a,b);
        swap(len1,len2);
    }
    for(int i=0,j=len1-1;i<len1;i++,j--)
        na[i]=a[j]-'0';
    for(int i=0,j=len2-1;i<len2;i++,j--)
        nb[i]=b[j]-'0';
    for(int i=0;i<len;i++)
    {
        if(na[i]<0||na[i]<nb[i])
            na[i]+=10,na[i+1]-=1;
        na[i]-=nb[i];
    }
    string ret;
    if(neg)
        ret+='-';
    ///去除前导零
    while(na[len]==0&&len>0)
        len--;
    for(int i=len;i>=0;i--)
        ret+=na[i]+'0';
    return ret;
}
int main()
{
//    freopen("in.txt", "r", stdin);
    string a,b;
    cin>>a>>b;
    cout << sub(a,b);
    return 0;
}
