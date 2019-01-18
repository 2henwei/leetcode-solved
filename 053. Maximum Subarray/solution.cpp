class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int submax[nums.size()];
        submax[0] = nums[0];
        int max_num = submax[0];
        for(int i=1; i<nums.size(); i++) {
            submax[i] = nums[i] + (submax[i-1] > 0 ? submax[i-1] : 0);
            max_num = max(max_num, submax[i]);
        }
        return max_num;
    }
};
