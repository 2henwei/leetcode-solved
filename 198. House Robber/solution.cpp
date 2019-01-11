class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> value(nums.size(), 0);

        if (nums.size() < 1) return 0;
        if (nums.size() < 2) return nums[0];

        value[0] = nums[0];
        value[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            value[i] = max(value[i - 1], value[i - 2] + nums[i]);
        }
        return value[nums.size() - 1];
    }
};
