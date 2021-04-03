# 1. 只出现一次的数字

#### [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

难度简单1785

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

**说明：**

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**

```
输入: [2,2,1]
输出: 1
```

**示例 2:**

```
输入: [4,1,2,1,2]
输出: 4
```

## 解题思路：

两两异或，最后出现一次的数字就被找出来了

## 代码

```c
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(size_t i = 0; i < nums.size(); ++i)
        {
            ret = ret^nums[i];
        }

        return ret;
    }
};
```

# 2.杨辉三角

#### [118. 杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)

难度简单471

给定一个非负整数 *numRows，*生成杨辉三角的前 *numRows* 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

**示例:**

```
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

## 解题思路

