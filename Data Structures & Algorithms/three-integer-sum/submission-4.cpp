class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> count;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int sum = -1 * (nums[i] + nums[j]);
                if (count[sum] > 0) {
                    res.push_back({nums[i], nums[j], sum});
                }
            }
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }

        return res;
    }
};
