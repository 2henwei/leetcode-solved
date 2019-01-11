class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel(J.begin(), J.end());

        size_t count = 0;
        for (size_t i = 0; i < S.size(); i++) {
            if (jewel.count(S[i])) {
                ++count;
            }
        }
        return count;
    }
};
