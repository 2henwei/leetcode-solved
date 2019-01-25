class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nz = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nz = nz + 1;
                swap(nums[i], nums[nz]);
            }   
        }
    }
};