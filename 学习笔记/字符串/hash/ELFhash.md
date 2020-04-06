ELFHash 的核心思想在于`影响`

将字符串映射为一个整数

```cpp
unsigned int ELFhash(char *str)
{
    unsigned int h = 0;
    unsigned int x;
    while(*str)
    {
        h = (h << 4) + *str++;//hash左移4位，把当前字符ASCII存入hash低四位。
        x = h & 0xF0000000L;//取出最高4位
        if(x)//如果最高4位不等于0，那么说明字符多余7个。现在正在处理第8个字符。现在取出最高4位，给下一个字符腾出空间，同时用这四个位来影响5-8位
        {
            h ^= x>>24;//用最高4位影响5-8位，杂糅
            h &= ~x;//清空高四位 
        }
    }
  //返回一个符号位为0的数，即丢弃最高位，以免函数外产生影响。(我们可以考虑，如果只有字符，符号位不可能为负)
    return h & 0x7FFFFFFF;
}
```

