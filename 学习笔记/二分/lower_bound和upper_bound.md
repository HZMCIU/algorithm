**lower_bound(a,a+n,a[i])** 返回大于等于a[i]的第一个指针

**upper_bound(a,a+n,a[i])**返回大于a[i]的第一个指针

例如：

1 1 2 2 2 2 4 

`lower_bound(a,a+7,2)` 返回数组中`2 2 2 2` 最左边的一个数，所以叫做lower_bound

`upper_bound(a,a+7,2)` 返回数组中`2 2 2 2` 最右边的的右边一个数（4），所以叫做upper_bound

