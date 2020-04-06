const int maxn;
int bit[maxn];
int lowbit(int x)
{
    return x & -x;
}
int add(int x,int v)
{
    for (int i = x; i < maxn; i += lowbit(i))
    {
        bit += v;
    }
}
int sum(int x)
{
    int ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
    {
        ret += bit[i];
    }
    return ret;
}