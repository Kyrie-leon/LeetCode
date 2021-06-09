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

