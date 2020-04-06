[博客](https://kb.cnblogs.com/page/176818/)

[博客](http://blog.csdn.net/fx677588/article/details/53406327)

[博客](http://blog.csdn.net/hyjoker/article/details/51190726)

[博客](https://www.cnblogs.com/zhangtianq/p/5839909.html)



对于暴力匹配，主串和模式串发生失配的时候，主串的字符指针i会移动到i+1的位置，模式串的字符指针会移动到j=0的位置。假设主串的长度是n，模式串的长度是m那么复杂度就是$O(n*m)$

对于kmp模式匹配， 当主串和模式串发生失配的时候，主串指针i不移动，模式串指针j不用回到j=0的位置，而是根据<b style="background-color:yellow">移动的位数=已经匹配的位数-对应部分的匹配权值}</b>(next[j])(j是最后一位匹配的字符所在的位置)`来回溯指针j，继续匹配。那么复杂度就是$O(n+m)$



[博客](https://www.cnblogs.com/cherryljr/p/6519748.html)

```cpp
int getnext(int len)
{
    next[0]=-1;
    int j;
    for(int i=1;i<len;i++)
    {
        j=next[i-1];
        while(pat[j+1]!=pat[i]&&j>=0) //如果不匹配，利用前面记录的信息，进行回溯，寻找长度更小的前后缀
            j=next[j];
        if(pat[j+1]==pat[i])
            next[i]=j+1;
        else
            //实在找不到匹配字符了，那么next的值就设为-1
            next[i]=-1;
    }
    return 0;
}

int kmp(int slen,int plen)
{
    int s_i=0,p_i=0;
    while(s_i<slen&&p_i<plen)
    {
        if(pat[p_i]==sur[s_i])
        {
            s_i++;
            p_i++;
        }
        else
        {
            if(p_i==0)
                //如果模式串都到第0位，还是失配，那么只能主串指针向前移动了
                s_i++;
            else
                //如果失配了，将模式串中的指针移动
                p_i=next[p_i-1]+1;
        }
    }
    return p_i==plen?(s_i-plen+1):-1;
}
```

