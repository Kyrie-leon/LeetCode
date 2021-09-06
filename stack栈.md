# 匹配问题

#### [1047. 删除字符串中的所有相邻重复项](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/)

难度简单281

给出由小写字母组成的字符串 `S`，**重复项删除操作**会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

**示例：**

```
输入："abbaca"
输出："ca"
```





### 思路：栈+reverse

栈为空就将字符入栈

栈不为空两种情况：

- 栈顶和数组中元素相同出栈同时指针后移
- 不相同就入栈



```c++
class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        stack<char> st;
        for(auto& e:s)
        {
            if(st.empty() || st.top() != e){
                st.push(e);
            }
            else{
                    st.pop();
            }
        }

        while(!st.empty())
        {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```



### 有效括号

#### 解题思路：

1. 栈：左括号入栈，碰见右括号让左括号出栈。细节：栈为空需要判断

```c++
//1
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n < 2)
			return false;
		stack<char> s;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == '(')
			{
				s.push(A[i]);
			}
			else if (A[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
					return false;
			}
			else
			{
				return false;
			}
		}
		if (s.empty())
			return true;
		return false;
	}
};
```

## 问题描述：用两个栈实现队列
[剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)


用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 `appendTail` 和 `deleteHead` ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，`deleteHead` 操作返回 -1 )

 

**示例 1：**

```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```

**示例 2：**

```
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

**提示：**

- `1 <= values <= 10000`
- `最多会对 appendTail、deleteHead 进行 10000 次调用`

### 解题思路
- 使用两个栈s1和s2来维护队列
- s1只负责插入，队头就被压入了栈底
- s2只负责删除，将s1的数据出栈压入到s2，s2入栈顺序恰好是队列的顺序
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/ac05b05086c5a88c31a65ef40efffcae.gif#pic_center)
### 代码

```cpp
class CQueue {
public:
    CQueue() {
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        //s2为空就将s1的数据全部导入s2
        if(s2.size() <= 0)
        {
            while(!s1.empty())
            {
                int value = s1.top();
                s1.pop();
                s2.push(value);
            }
        }
        //如果s2仍未空，则说明s1也为空，队列中没有数据
        if(s2.empty())
            return -1;
        int value = s2.top();
        s2.pop();

        return value;
    }
private:
    stack<int> s1;  //s1插入
    stack<int> s2;  //s2删除
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

```
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

private:
    stack<int> stack1;    //ru
    stack<int> stack2;    //chu
};
```

