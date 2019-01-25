class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) 
            return 1;
        if (n == 2)
            return 2;
        
        int res1 = 1;
        int res2 = 2;
        int res;
        for (int i=3; i<=n; i++) {
            res = res1 + res2;
            res1 = res2;
            res2 = res;
        }
        return res;
    }
};
