class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> buf(2, INT_MAX);
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > buf[1])
                return true;
            else if (nums[i] <= buf[0])
                buf[0] = nums[i];
            else
                buf[1] = nums[i];
        }
        return false;
    }
};