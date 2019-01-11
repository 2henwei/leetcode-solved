class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            if (table.find(target - key) != table.end()) {
                return {table[target - key], i};
            } else {
                table[key] = i;
            }
        }
        return {};
    }
};
