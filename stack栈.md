# day7 

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

