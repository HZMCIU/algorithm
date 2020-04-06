//假设此时区间为1-n且1必定可行
//二分答案：
int l=1,r=n+1;
while(l+1<r)
{
    int mid=l+(r-l)/2;
    if(judge(mid)) l=mid;
    else r=m;
}
//在这个方法中，l已知保存着可行值，已知为不可行值
//mid = l + (r-l);之所以写成这样而不是mid = (l+r)/2;是为了防止溢出,
//并且具有更好的通用性(如果l和r是迭代器或者指针, 第一种就不行了, 因为迭代器或指针是不能相加的)
//方法1：
//同样可以推广到查找值当中
//查询区间为[l,r)
int bsearch(int *a, int l, int r, int key)
{
    int mid;
    while(l<r)                           //和上面不一样了
    {
        mid = l + (r-l)/2;
        if(a[mid] < key) l = mid+1;     //注意这里和上面不一样了
        else if(a[mid] == key) return mid;
        else  r = mid;
    }
    return -1;
}
//我就算怎么改变l，r，都让查询区间是[l,r)


//方法2：
//查询区间是[l,r];
int bsearch(int *a, int l, int r, int key)
{
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] < key) l = mid + 1;
        else if (a[mid] == key) return mid;
        else r = mid - 1;
    }
    return -1;
}
//和上面一样，我就算怎么改变l，r，都让查询区间是[l,r]






//提炼精度：
//写法1:(推荐)
double l=,r=;
for(int i=0;i<60;i++)
{
    double mid=(l+r)/2;
    if(judge(mid)) l=mid;
    else r=mid;
}
//写法2：(不推荐)
while(r-l<eps)//其中eps是所需要的精度
{
    double mid = (l+r)/2;
    if(judge(mid)) l=mid;
    else r=mid;
}
