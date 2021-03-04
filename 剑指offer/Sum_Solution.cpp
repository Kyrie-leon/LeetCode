class Sum{
public:
    explicit Sum()
    {
        _ret += _i;
        ++_i;
    }
    static int GetRet()
    {
        return _ret;
    }
    
    static void ReSet()
    {
        _i = 1;
        _ret = 0;
    }
private:
    static int _i;
    static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum::ReSet();
        Sum arr[n];
        
        return Sum::GetRet();
    }
};