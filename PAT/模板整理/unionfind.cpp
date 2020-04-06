const int maxn;
int par[maxn];
int rnk[maxn];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i, rnk[i] = 0;
}
void find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
void union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rnk[x] > rnk[y])
        x = y;
    else
        y = x;
    if (rnk[x] == rnk[y])
        rnk[y]++;
}