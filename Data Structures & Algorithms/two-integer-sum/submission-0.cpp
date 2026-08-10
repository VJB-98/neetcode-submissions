class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res(2);
        for (int i=0;i<nums.size();i++) {
            int diff = target - nums[i];
            if (m.find(diff) != m.end()) {
                res[0] = m[diff];
                res[1] = i;
                return res;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};
