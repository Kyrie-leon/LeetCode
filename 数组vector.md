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

#### [137. 只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/)

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

**说明：**

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**

```
输入: [2,2,3,2]
输出: 3
```

**示例 2:**

```
输入: [0,1,0,1,0,1,99]
输出: 99
```

## 解题思路

![](https://gitee.com/Kyrie-leon/blog-image/raw/master/C++/20210409093546.png)

```c
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                sum += (nums[j] >> i) & 1;
            }
            //还原
            ret ^= (sum % 3) << i;
        }

        return ret;
    }
};
```



#### [260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)

难度中等387

给定一个整数数组 `nums`，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 **任意顺序** 返回答案。

 

**进阶：**你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

 

**示例 1：**

```
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
```

**示例 2：**

```
输入：nums = [-1,0]
输出：[-1,0]
```

**示例 3：**

```
输入：nums = [0,1]
输出：[1,0]
```

## 解题思路

1. 全部两两异或得出异或结果xorRet
2. 查看异或结果为1的位divFlag
3. 将divFlag为1的数字划为group1，其余的为group2
4. 对两个组异或，最终结果就是答案

```c
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorRet = 0;
        for(auto num:nums)
        {
            xorRet ^= num;
        }

        int divFlag = 0;
        for(; divFlag < 32; ++divFlag)
        {
            if((xorRet >> divFlag) & 1 == 1)
            {
                break;
            }
        }
        
        int ret1 = 0, ret2 = 0;
        for(auto num:nums)
        {
            if((num>>divFlag) & 1 == 1)
            {
                ret1 ^=num;
            }
            else
            {
                ret2 ^=num;
            }
        }
       
        return {ret1, ret2};
    }
};
```



# 2.杨辉三角



#### [118. 杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)

难度简单471

给定一个非负整数 *numRows，*生成杨辉三角的前 *numRows* 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

**示例:**

```c
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

1. 先创建数组vv，然后填充

```c
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
 
        for(size_t i = 0; i < vv.size(); ++i)
        {
            vv[i].resize(i+1, 0);
            vv[i][0] = 1;
            vv[i][vv[i].size()-1] = 1;
        }

        for(size_t i = 0; i < vv.size(); ++i)
        {
            for(size_t j = 0; j < vv[i].size(); ++j)
            {
                if(vv[i][j] == 0)
                {
                    vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
                }
            }
        }

        return vv;
        
    }
};
```



# 3. 数组中出现次数超过一半的数字



## 题目描述



 [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

 [剑指 Offer 39. 数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/)

[牛客数组中出现次数超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tab=answerKey)

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

示例1

## 输入

[复制](javascript:void(0);)

```
[1,2,3,2,2,2,5,4,2]
```

## 返回值

[复制](javascript:void(0);)

```
2
```

## 解题思路

投票法，对于给定的数组定义两个变量，一个condidate用于记录当前位置元素的数据，一个count用于记录当前位置元素出现的次数，这个题目可以看作是士兵打仗一命换一命，只要你的人数超过一半就可以活到最后

```c
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int condidate = -1;
        int count = 0;
        for(auto e:numbers)
        {
            if(condidate == e)
            {
                count++;
            }
            else if(--count < 0)
            {
                condidate = e;
                count = 1;
            }
        }
        if(count > 0)
        {
            count = 0;
            for(auto e:numbers)
            {
                if(condidate == e)
                    count++;
            }
            if(count > (numbers.size()/2))
                return condidate;
        }
        
        return 0;
    }
};
```

# 4.删除有序数组中的重复项

[26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

难度简单1942

给你一个有序数组 `nums` ，请你**[ 原地](http://baike.baidu.com/item/原地算法)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组** 并在使用 O(1) 额外空间的条件下完成。

示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

## 解题思路

双指针法，初始化prev指向下标0，cur指向下标1，只要cur和prev指向的值相等就移动cur，直到cur指向的值不等于prev，先移动prev，再就将cur指向的值赋给prev，最后移动cur

细节：

1. 先排除数组为0和1的情况
2. cur边界问题
3. 返回值不能是prev，pre所指的只是下标需要加1

![](https://gitee.com/Kyrie-leon/blog-image/raw/master/Leetcode//20210408090749.png)

代码

```c
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return 1;

        int prev = 0;
        int cur = 1;
        while(cur < size)
        {
            if(nums[prev] != nums[cur])
            {
                nums[++prev] = nums[cur++];
            }
            else
            {
                cur++;
            }
                
        }

        return prev+1;
    }
};
```

