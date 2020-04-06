unsigned int elfhash(char *str)
{
    unsigned int hash = 0;
    unsigned int x = 0;
    while (*str)
    {
        hash = (hash << 4) + *str;//hash<<4Òª¼ÓÉÏÀ¨ºÅ
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= x >> 24;
            hash &= ~x;
        }
        str++
    }
    return hash & 0x7FFFFFFF;
}
