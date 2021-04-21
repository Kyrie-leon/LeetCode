# 字符串常见面试题

# 1.找出字符串中第一个只出现一次的字符

## 输入描述:

```
输入几个非空字符串
```

## 输出描述:

```
输出第一个只出现一次的字符，如果不存在输出-1
```

示例1

## 输入

```
asdfasdfo
aabb
```

## 输出

```
o
-1
```

## 解题思路

两次遍历

第一次遍历，开辟一个可以容纳26个字母的数组用于计数每个字符出现的次数

第二次遍历，从左向右遍历只出现一次的字母并打印输出

时间复杂度是O(2n),空间复杂度是O(1)



```
#include<iostream>
#include<string>
using namespace std;
    
int main()
{
    string s;
    while(getline(cin,s))
    {
        int countArr[26] = {0};
        //第一次遍历计数
        string::iterator it = s.begin();
        while(it != s.end())
        {
            ++countArr[(*it-'a')];
            ++it;
        }
        //第二次遍历输出
        it = s.begin();
        int ret = 0;
        while(it != s.end())
        {
            if(countArr[(*it-'a')] == 1)
            {
                cout<<*it<<endl;
                ret = 1;
                break;
            }
            ++it;
        }
        if(ret == 0)
        {
            cout<<-1<<endl;
        }
    }

    return 0;
}
```

# 2. 字符串转为整数



## 题目描述

将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

## 输入描述:

```
输入一个字符串,包括数字字母符号,可以为空
```

## 返回值描述:

```
如果是合法的数值表达则返回该数字，否则返回0
```

示例1

## 输入

[复制](javascript:void(0);)

```
"+2147483647"
```

## 返回值

[复制](javascript:void(0);)

```
2147483647
```

示例2

## 输入

[复制](javascript:void(0);)

```
"1a33"
```

## 返回值

[复制](javascript:void(0);)

```
0
```

## 解题思路

1. 定义flag输出最后的结果是+还是-、先走一个位置判断正负值

2. 定义ret，迭代器it遍历string，如果是整数ret$\times$10+*it-‘0’,否则返回0
 > 注意：
>
   > 字符串可能为空因此需要判断是否为空
   >
   > 字符转为整数需要减去字符0，即-‘0’

```c
class Solution {
public:
    bool isNum(const char ch)
    {
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    int StrToInt(string str) {
        if(str.size() == 0)
            return 0;
        int flag = 1;
        int ret = 0;
        string::iterator it = str.begin();
        //先判断正负号
        if(*it == '-')
        {
            flag = -1;
            ++it;
        }
        if(*it == '+')
        {
            ++it;
        }
        while(it != str.end())
        {            
            if(isNum(*it))
            {
                ret *= 10;
                ret += *it-'0';
            }
            else
            {
                return 0;
            }
            ++it;
        }
        
        return ret*flag;
    }
};
```

 

# 3.字符串相加

## [415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)

给定两个字符串形式的非负整数 `num1` 和`num2` ，计算它们的和。

**提示：**

1. `num1` 和`num2` 的长度都小于 5100
2. `num1` 和`num2` 都只包含数字 `0-9`
3. `num1` 和`num2` 都不包含任何前导零
4. **你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式**

## 解题思路

先明确，字符转整数就是该字符减去‘0’

1.num1和num2倒着相加，先定义两个下标i1，i2指向num1和num2的最后一个下标

2.定义一个进位next初始化为0

3.遍历两个字符串，定义n1和n2为num1和num2下标位置的整数，定义sum为n1+

n2=next相加的结果,next为sum/10结果，即每次大于10进位就是1，小于10进位就是0

结果加到ret后面

4.结束后检查是否有进位，如果有进位就给ret后面再加字符1

5.相加后的结果ret是逆序的，因此需要逆置再返回

> 注意细节：
>
> i1和i2下标是从size-1开始
>
> i1和i2循环条件是逻辑或，加入三目运算符谁先遍历完谁置0
>
> ret循环体中的结果需要加字符'0'
>
> 遍历完判断进位是否为1，如果为1ret再追加字符1

```c
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int next = 0;   //进位
        int sum = 0;
        int i1 = num1.size() - 1, i2 = num2.size() - 1;
        //遍历
        while(i1 >= 0 || i2 >= 0)
        {   
            int n1 = i1 >= 0 ? num1[i1] - '0' : 0; 
            int n2 = i2 >= 0 ? num2[i2] - '0' : 0;
            sum = n1 + n2 + next;
            next = sum/10; 
            ret += sum%10 + '0';
            --i1;
            --i2;
        }
       
        if(next == 1)
            ret += '1';

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

# 字符串相乘

## [43. 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)

难度中等595

给定两个以字符串形式表示的非负整数 `num1` 和 `num2`，返回 `num1` 和 `num2` 的乘积，它们的乘积也表示为字符串形式。

**示例 1:**

```
输入: num1 = "2", num2 = "3"
输出: "6"
```

**示例 2:**

```
输入: num1 = "123", num2 = "456"
输出: "56088"
```

## 解题思路

[本体思路]:https://leetcode-cn.com/problems/multiply-strings/solution/gao-pin-mian-shi-xi-lie-zi-fu-chuan-cheng-fa-by-la/





#  4. 反转字符串

## [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

难度简单371

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `char[]` 的形式给出。

不要给另外的数组分配额外的空间，你必须**[原地](https://baike.baidu.com/item/原地算法)修改输入数组**、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 [ASCII](https://baike.baidu.com/item/ASCII) 码表中的可打印字符。

 

**示例 1：**

```
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```

**示例 2：**

```
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```

## 解题思路

双指针交换



```c
class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin = 0, end = s.size() - 1;
        while(begin < end)
        {
            swap(s[begin],s[end]);
            ++begin;
            --end;
        }
    }
};
```

## [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

难度简单118

给定一个字符串 `s` 和一个整数 `k`，你需要对从字符串开头算起的每隔 `2k` 个字符的前 `k` 个字符进行反转。

- 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
- 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。

 

**示例:**

```c
输入: s = "abcdefg", k = 2
输出: "bacdfeg"
```

## 解题思路

题目读起来非常难懂，似乎是英文直译过来的，其实就是将字符串的每2k个字符分成一个块，将这一个块内的前k个字符逆置，对于分的最后一个2k字符块，如果少于k个就全部翻转

思路理清后，直接实现即可，定义cur指针每次走2k个位置，在2k的字符区间内，使用双指针逆置，left为cur，right为left+k-1，这里需要注意有可能区间字符少于left+k-1

```c
class Solution {
public:
    string reverseStr(string s, int k) {
        int cur = 0;
        int len = s.size();
        while(cur < len)
        {
            int left = cur;
            int right = min(left + k - 1, len - 1);
            while(left < right)
            {
                swap(s[left++], s[right--]);
            }
            cur += 2*k;
        }
        return s;
    }
};
```



## [557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

难度简单280

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

**示例：**

```c
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
```

## 解题思路

使用快慢指针

1. 定义快指针fast和慢指针low，快指针先走遇到空格字符或者字符串结尾就停下来，这时候快指针指向的位置就是空格字符的位置或者字符串结束标识符'\0'，快指针用于切割字符串
2. 定义一个单词右指针，起始位置为fast-1
3. 交换慢指针low和right指针所指内容
4. 交换结束后，fast指向下一个位置，即空格字符后的位置或者‘\0’后的位置，low也等于fast位置

![](https://gitee.com/Kyrie-leon/blog-image/raw/master/LeetCode//20210329104209.png)

```c
class Solution {
public:
    string reverseWords(string s) {
        int low = 0, fast = 0;
        while(fast < s.size())
        {
            while(fast < s.size() && s[fast] != ' ')
            {
                ++fast;
            }
            int right = fast - 1;
            while(low < right)
            {
                swap(s[low], s[right]);
                ++low;
                --right;
            }
            low = fast += 1;
        }
        return s;
    }
};
```



# 5. 验证回文字符串

## [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

难度简单354

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

**说明：**本题中，我们将空字符串定义为有效的回文串。

**示例 1:**

```
输入: "A man, a plan, a canal: Panama"
输出: true
```

**示例 2:**

```
输入: "race a car"
输出: false
```

## 解题思路

双指针遍历比较，第一遍先将字符串中所有字符串转为小写，第二遍比较

注意细节：

双指针边界。left<right



```c
class Solution {
public:
    bool isLetter(char ch)
    {
        if((ch >= 'a' && ch <= 'z')
        || (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        if(s.size() == 0)
            return false;
        int begin = 0, end = s.size() - 1;
        //第一遍遍历将字符串转为小写
        for(; begin < s.size(); ++begin)
        {
            if(isupper(s[begin]))
            {
                s[begin] += 32;
            }
        }

        //第二遍判断
        begin = 0;
        while(begin < end)
        {
            while(begin < end && !isLetter(s[begin]))
                ++begin;
            while(begin < end && !isLetter(s[end]))
                --end;
            if(s[begin] != s[end])
                return false;
            ++begin;
            --end;
        }

        return true;
    }
};
```

day3每日一题编程题1

思路：

定一个vector里面存放每个字串的长度，起始位置和结束位置，最后找到最长的长度然后输出即可

```c++
#include<iostream>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

bool IsNum(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

int main()
{
	string s;
	vector<int> ret;    //存放长度和下标
	int j = 0;    //vector下标
	int len = 0;
	int begin = 0;
	int end = 0;
	cin >> s;
	//第一遍查找最长的数组
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (IsNum(s[i]))
		{
			begin = i;
			while (IsNum(s[i]))
			{
				i++;
			}
			end = i;
			ret.push_back(end - begin);
			ret.push_back(begin);
			ret.push_back(end);
		}
	}
	
	//第二遍查找最大值
	int max = 0;
	int index = 0;
	for(int i = 0; i < ret.size(); i+=3)
	{
		if (max < ret[i])
		{
			max = ret[i];
			index = i;
		}
		
	}

	for(int i = ret[index+1]; i < ret[index+2]; ++i)
	{
	cout<<s[i];
	}
	cout<<endl;
	
	return 0;
}
```

