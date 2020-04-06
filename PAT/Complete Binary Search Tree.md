### [Complete Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568)

**将二叉搜索树的元素排序，得到中序序列。又因为题目给定这个二叉搜索树是满二叉树，所以可直接用中序遍历的方法建树（优先填充左边的节点）**

```cpp
void build(node *&root,int rt)
{
    if(rt>n)
        return ;
    root=(node*)malloc(sizeof(node));
    root->left=root->right=nullptr;
    build(root->left,rt<<1);
    root->val=arr[cnt++];
    build(root->right,rt<<1|1);
}
```

