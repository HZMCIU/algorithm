### [Hat’s Words](https://vjudge.net/problem/HDU-1247)

### 题意

找出一个单词，其由单词表中的另外两个单词组成。

### 思路

字典树。在节点中加入`is_word`标记前面的单词能否组成一个单词。建完树，将单词暴力拆分，然后寻找拆分后的两个字符是否能够在字典树中找到。

```cpp
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5e4 + 10;
struct node
{
    node *next[26];
    bool is_word;
}*root;
char s[maxn][50];

node *build()
{
    node *k = new(node);
    memset(k->next, 0, sizeof(k->next));
    k->is_word = false;
    return k;
}
void insert(char *s)
{
    int len = strlen(s);
    node*r = root;
    for(int i = 0; i < len; i++)
    {
        int x = s[i] - 'a';
        if(r->next[x] == nullptr) r->next[x] = build();
        r = r->next[x];
    }
    r->is_word = true;
}
bool search(char *s)
{
    node *r = root;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int x = s[i] - 'a';
        if(r->next[x] == nullptr) return false;
        r = r->next[x];
    }
    return r->is_word;
}
int main()
{
    root = build();
    int n = 0;
    while(~scanf("%s", s[n])) n++;
    for(int i = 0; i < n; i++)
    {
        insert(s[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int len = strlen(s[i]);
        if(len == 1) continue;
        for(int j = 1; j < len; j++)
        {
            char a[50] = {0};
            char b[50] = {0};
            strncpy(a, s[i] + j, len - j);
            strncpy(b, s[i], j);
            if(search(a) && search(b))
            {
                puts(s[i]);
                break;
            }
        }
    }
    return 0;
}
```

