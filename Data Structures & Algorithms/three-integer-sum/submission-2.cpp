class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_map<int, int> count;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]--;
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]--;
                int sum = -1 * (nums[i] + nums[j]);
                if (count[sum] > 0) {
                    res.insert({nums[i], nums[j], sum});
                }
            }
            for (int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
