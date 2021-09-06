# 并查集

## 实现

思路：

1. 初始化一个vector里面都用-1表示，同一集合只有一个根节点用-1表示，有多少个子节点就给—1加几

代码：

```c++
class UnionFindSet{
public:
    //构造函数开辟n个大小空间用-1表示
    UnionFindSet(int n)
    {
        _ufs.resize(n, -1);
    }
    //合并两个子集，自己不能和自己合并
    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);

        //
        if(root1 != root2)
        {
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
        }

    }
	//合并子集要让父节点合并，因此找一个父节点
    int FindRoot(int x)
    {
        assert(x < _ufs.size());
        while(_ufs[x] >= 0)
        {
            x = _ufs[x];
        }
        return x;
    }
	//返回根节点个数
    size_t SetSize()
    {
        size_t size = 0;
        for(int i = 0; i < _ufs.size(); ++i)
        {
            if(_ufs[i] < 0)
                ++size;
        }

        return size;
    }
private:
    vector<int> _ufs;
};
```

## [剑指 Offer II 116. 朋友圈](https://leetcode-cn.com/problems/bLyHh0/)

难度中等10

一个班上有 `n` 个同学，其中一些彼此是朋友，另一些不是。朋友关系是可以传递的，如果 a 与 `b` 直接是朋友，且 `b` 与 `c` 是直接朋友，那么 `a` 与 `c` 就是间接朋友。

定义 **朋友圈** 就是一组直接或者间接朋友的同学集合。

给定一个 `n x n` 的矩阵 `isConnected` 表示班上的朋友关系，其中 `isConnected[i][j] = 1` 表示第 `i` 个同学和第 `j` 个同学是直接朋友，而 `isConnected[i][j] = 0` 表示二人不是直接朋友。

返回矩阵中 **朋友圈**的数量。

思路：

将有相同朋友的组成一个集合最后返回集合中根节点个数即可

```c++
class UnionFindSet{
public:
    UnionFindSet(int n)
    {
        _ufs.resize(n, -1);
    }
    
    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);

        //
        if(root1 != root2)
        {
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
        }

    }

    int FindRoot(int x)
    {
        assert(x < _ufs.size());
        while(_ufs[x] >= 0)
        {
            x = _ufs[x];
        }
        return x;
    }

    size_t SetSize()
    {
        size_t size = 0;
        for(int i = 0; i < _ufs.size(); ++i)
        {
            if(_ufs[i] < 0)
                ++size;
        }

        return size;
    }
private:
    vector<int> _ufs;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFindSet ufs(isConnected.size());
        for(int i =0; i < isConnected.size(); ++i)
        {
            for(int j = 0; j < isConnected.size(); ++j)
            {
                if(isConnected[i][j] == 1)
                    ufs.Union(i, j);
            }
        }

        return ufs.SetSize();
    }
};
```



## [990. 等式方程的可满足性](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/)

难度中等191

给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 `equations[i]` 的长度为 `4`，并采用两种不同的形式之一：`"a==b"` 或 `"a!=b"`。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 `true`，否则返回 `false`。 

```
class UnionSet{
public:
    UnionSet(int n)
    {
        _ufs.resize(n,-1);
    }

    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);

        if(root1 != root2)
        {
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
        }
    }

    int FindRoot(int x)
    {
        assert(x < _ufs.size());
        while(_ufs[x] >= 0)
        {
            x = _ufs[x];
        }
        
        return x;
    }

private:
    vector<int> _ufs;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionSet ufs(26);
        //第一遍将相等的值放到一个集合
        for(int i = 0; i < equations.size(); ++i)
        {
            if(equations[i][1] == '=')
            {
                ufs.Union(equations[i][0]-'a', equations[i][3]-'a');
            }
        }
        //第二遍不等的值是否与逻辑相悖
        for(int i = 0; i < equations.size(); ++i)
        {
            if(equations[i][1] == '!')
            {
                if(ufs.FindRoot(equations[i][0]-'a') == ufs.FindRoot(equations[i][3]-'a'))
                    return false;
            }
        }

        return true;
    }
};
```

