### [Language of FatMouse ](https://vjudge.net/problem/ZOJ-1109)

### 题意

给出两个字符串$a,b$ ，$a$是英文，$b$是老鼠国的语言，两者相对应。后面有$q$个查询，问一个查询中老鼠过的语言是否存在相对应的英文。

### 思路

对$b$建一个字典树，在每个节点中存一个`str`字符数组来映射相应的$b$。

`sscanf(tmp,"%s%s",s,t);`来将原来的字符重新存入`s,t`以此来去除换行和空格。

```cpp
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6;
int tot = 1;
struct node
{
    node *next[26];
    char s[20];
}*root;
char s[20];
char t[20];
char tmp[50];
node *build()
{
    node *k = new(node);
    memset(k->next, 0, sizeof(k->next));
    return k;
}
void insert()
{
    int len = strlen(t);
    node *r = root;
    for(int i = 0; i < len; i++)
    {
        int x = t[i] - 'a';
        if(r->next[x] == NULL) r->next[x] = build();
        r = r->next[x];
    }
    memcpy(r->s, s, sizeof(s));
}
void find()
{
    int len = strlen(s);
    node *r = root;
    for(int i = 0; i < len; i++)
    {
        int x = s[i] - 'a';
        if(r->next[x] == NULL)
        {
            printf("eh\n");
            return ;
        }
        r = r->next[x];
    }
    printf("%s\n", r->s);
}
int main()
{
    root = build();
    while(fgets(tmp, 50, stdin) && tmp[0] != '\n')
    {
        sscanf(tmp, "%s%s", s, t);
        insert();
    }
    while(~scanf("%s", s))
    {
        find();
    }
    return 0;
}

```

