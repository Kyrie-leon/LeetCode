## [349. 两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/)

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //1.先用set去重
        set<int> set1;
        for(auto &e1 : nums1)
        {
            set1.insert(e1);
        }
        set<int> set2;
        for(auto &e2 : nums2)
        {
            set2.insert(e2);
        }

        //2.输出交集
       vector<int> ret;
        for(auto& e1 : set1)
        {
            if(set2.find(e1) != set2.end())
            {
                ret.push_back(e1);
            }
        }
        return ret;
    }
};

```

## [350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)

给定两个数组，编写一个函数来计算它们的交集。

 

**示例 1：**

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
```

**示例 2:**

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
```

 

**说明：**

- 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
- 我们可以不考虑输出结果的顺序。

### 思路

1. 哈希

由于同一个数字在两个数组中都可能出现多次，因此需要用哈希表存储每个数字出现的次数。对于一个数字，其在交集中出现的次数等于该数字在两个数组中出现次数的最小值。

首先遍历第一个数组，并在哈希表中记录第一个数组中的每个数字以及对应出现的次数，然后遍历第二个数组，对于第二个数组中的每个数字，如果在哈希表中存在这个数字，则将该数字添加到答案，并减少哈希表中该数字出现的次数。

为了降低空间复杂度，首先遍历较短的数组并在哈希表中记录每个数字以及对应出现的次数，然后遍历较长的数组得到交集。

![](https://assets.leetcode-cn.com/solution-static/350/350_fig1.gif)

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //哈希表统计较小数组中每个数字出现的次数
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> map1;
        for(auto& e : nums1)
        {
            map1[e]++;
        }

        vector<int> ret;
        for(auto& e : nums2)
        {
            auto it = map1.find(e);
            if(it != map1.end() && it->second != 0)
            {
                ret.push_back(e);
                it->second--;
            }
        }
        return ret;
    }
};
```

2. 排序+双指针

https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/shu-ju-jie-gou-he-suan-fa-shuang-zhi-zhe-zkp0/

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //对两个数组先排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        //双指针遍历数组
        vector<int> ret;
        int i1 = 0, i2 = 0;
        while(i1 < nums1.size() && i2 < nums2.size())
        {
            if(nums1[i1] == nums2[i2])
            {
                ret.push_back(nums1[i1]);
                ++i1, ++i2;
            }
            else if(nums1[i1] < nums2[i2])
            {
                ++i1;
            }
            else
            {
                ++i2;
            }
        }
        
        return ret;
    }
};
```



## [961. 重复 N 次的元素](https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/)

```c++
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;  //求出n 
        unordered_map<int,int> count_map;   //计数数组
        for(auto &e: nums)
        {
            count_map[e]++;
        }
        
        //找出n
        for(auto &e: count_map)
        {
            if(e.second == n)
                return e.first;
        }
        return -1;
        

    }
};
```

## [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0)
            return -1;
        int letterArr[26] = {0};
        int i = 0;
        for(; i < s.size(); ++i)
        {
            ++letterArr[(s[i]-'a')];
        }

        for(i =0; i < s.size(); ++i)
        {
            if(letterArr[(s[i]-'a')] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
```

## [884. 两句话中的不常见单词](https://leetcode-cn.com/problems/uncommon-words-from-two-sentences/)

给定两个句子 `A` 和 `B` 。 （*句子*是一串由空格分隔的单词。每个*单词*仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是*不常见的*。

返回所有不常用单词的列表。

您可以按任何顺序返回列表。

**示例 1：**

```
输入：A = "this apple is sweet", B = "this apple is sour"
输出：["sweet","sour"]
```

**示例 2：**

```
输入：A = "apple apple", B = "banana"
输出：["banana"]
```

```c++
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> countMap;    //哈希表计数单词出现次数
        string s;
        s = s1 + " " + s2;  //两句话拼接成一句话并当作输入流
        istringstream words(s);
        string temp;
        while(words >> temp)
        {
            countMap[temp]++;   //计数每一个单词
        }
        vector<string> ret;
        for(auto& e: countMap)
        {
            if(e.second == 1)
                ret.push_back(e.first); //统计出每一个出现一次的单词
        }
        return ret;
    }
};
```

# [217. 存在重复元素](https://leetcode-cn.com/problems/contains-duplicate/)

难度简单402

给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 `true` 。如果数组中每个元素都不相同，则返回 `false` 。

 

**示例 1:**

```
输入: [1,2,3,1]
输出: true
```

**示例 2:**

```
输入: [1,2,3,4]
输出: false
```

**示例 3:**

```
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
```

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        //第一遍遍历统计出现的次数
        for(auto& n : nums)
        {
            countMap[n]++;
        }
        //第二遍遍历，有次数大于1的返回true
        for(auto& e : countMap)
        {
            if(e.second > 1)
                return true;
        }
        return false;
    }
};c
```

# **NC61** **两数之和**

描述

给出一个整数数组，请在数组中找出两个加起来等于目标值的数，

你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的

假设给出的数组中只存在唯一解

例如：

给出的数组为 {20, 70, 110, 150},目标值为90
输出 index1=1, index2=2

## 思路：哈希

哈希表中存元素值和下标值，遍历数组中的每一个数字，并和target求差值

- 如果能找到返回哈希表中的下标值和数组下标值
- 没找到就插入这个元素到哈希表

```c++
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> uMap;
        vector<int> ret;
        size_t i = 0;
        for(; i < numbers.size(); ++i)
        {
            int tmp = target -numbers[i];
            if(uMap.count(tmp))
            {
                ret.push_back(uMap[tmp]+1);
                ret.push_back(i+1);
                break;
            }
            else
                uMap[numbers[i]] = i;
        }
        
        return ret;
    }
};
```

# [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

## 思路1：

首先定义一个map存储数组中的元素，没存储一个就将将该元素bool值置为true

1. 遍历数组中的元素并存入map中
2. 如果这个元素bool值为true说明重复，直接返回元素
3. 否则将该值存map中并置true

时间空间复杂度均为O(N)

```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> nMap;
        for(auto& n: nums)
        {
            if(nMap[n])
                return n;
            nMap[n] = true;
        }
        return -1;
    }
};
```

## 思路2：

原地置换

数组的下标用i表示

数组的第i个元素的值nums[i]

如果想让数组的第i个元素的值nums[i]在数组下标nums[i]的位置：nums[i] == nums[nums[i]]

1. 遍历数组nums
2. 如果数组nums的第i个数字的值nums[i]和数组下标刚好对应继续遍历
3. 如果数字在对应下标的位置说明重复直接返回
4. 都不是直接将数字交换对应下标的地方去

```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size())
        {
            //1.数字在对应下标数组位置i++
            if(nums[i] == i)
            {
                i++;
                continue;
            }
            //2.数字在对应下标位置说明重复
            if(nums[i] == nums[nums[i]])
            {
                return nums[i];
            }
            std::swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
```

#

