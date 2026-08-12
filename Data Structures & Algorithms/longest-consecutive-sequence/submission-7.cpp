class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int n : nums) {
            int len = 1;
            if (s.find(n-1) == s.end()) {
                while(s.find(n + len) != s.end()) {
                    len++;
                }
            }
            res = max(res,len);
        }
        return res;
    }
};
