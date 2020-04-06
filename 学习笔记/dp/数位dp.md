[讲解](http://blog.csdn.net/wust_zzwh/article/details/52100392)

**数位dp的枚举方式**：控制上界，从高位到低位逐次枚举。当高位达到限制时，枚举下一位有限制。当高位没有达到限制时，枚举下一位，即从0-9逐一枚举。

例如：枚举3位数，上界是213。当百位枚举到0，1时，百位没有达到限制，所以枚举个位的时候没有限制，即个位从0-9逐一枚举。当百位枚举到2时，百位达到了限制，个位也有了限制，只能枚举0，1。

```cpp
int up;
up = limit?a[pos]:9;//数组a存储了上界的每一位数，limit为上一位是否达到了限制，num为该位能够枚举的最大值
for(int i=0;i<=up;i++)
{
    //操作
}

```

**数位dp模板**

```cpp
int a[20]//存储数位
int dp[20][state] //记忆化搜索
//pos数位的位置,lead前导零,limit数位上界限制
int dfs(int pos,/*状态变量*/,bool lead,bool limit)
{
    if(pos==-1) return 1;//到达最后一位,结束搜索。返回1，表示这个数是符合题目要求的条件的
    if(!limit&&!lead&&dp[pos][state]!=-1) return dp[pos][state];//记忆化搜索,但是必须是没有前导零，以及上一位没有限制
    int up=limit?a[pos]:9;//确定上界
    int ans=0;
    for(int i=0;i<=up;i++)
    {
        //操作,过滤掉不符合题意的状态
        ans+=dfs(pos-1,/*状态转移*/,lead&&i==0,limit&&i==a[pos]);//上一位有前导零，并且这一位也是0，那么前导零就是1，如果上一位达到了上限，并且这一位也达到了上线，那么下一个状态的limit就是1
    }
    if(!limit&&!lead) dp[pos][state]=ans;//记录结果
    return ans;
}
int solve(int x)
{
    int pos=0;
    //分解数位
    memset(dp,-1,sizeof(dp));
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,/**/,1,1);//刚开始lead为1,limit也为1
}
int main()
{
    int l,r;
    while(~scanf("%d%d",&l,&r))
    {
        printf("%d\n",solve(r)-solve(l-1));
    }
    return 0;
}
```

记忆化搜索条件中加入了`!limit` ,这是因为如果不采用限制的话，那么dp\[pos]\[state]记录的值并不适合所有的情况。

例如：求在\[1-210]不含两个连续11的数的个数。11，111，211，112都是不合法的。

dp\[pos][pre]:第pos位，前一位是pre的个数。

如果不采用限制的话。假设百位枚举0，十位枚举1，那么dp\[0][1]=9(因为11是不合法的)。那么在百位枚举2，十位枚举1时，如果直接进行记忆化搜索，那么结果时错误的。因为dp\[0][1]=1(只有10，这一个状态)。

记忆化搜索的时候采用数位上界限制，以及前导零的作用就是为了让dp的状态一致。

**数位dp常用的优化**

1. `memset(dp,-1,sizeof(dp))`放在多组测试数据外。约束条件与每个数的自身有关系，输入对这些不会有影响。
2. ​