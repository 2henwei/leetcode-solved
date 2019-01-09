/**
 * 136. Single Number
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */

class Solution {
public:
    /* Hash Table */
	int singleNumber(vector<int>& nums) {
        map<int, int> check_table;
        for (size_t i = 0; i < nums.size(); i++) {
            int key = nums.at(i);
            if (check_table.find(key) != check_table.end()) {
                check_table.erase(key);
            } else {
                check_table[key] = 1;
            }
        }
        return check_table.begin()->first;
    }

	/* Bit Manipulation */
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            result ^= nums.at(i);
        }
        return result;
    }
};
