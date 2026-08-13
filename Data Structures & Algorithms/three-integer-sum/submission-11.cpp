class Solution {
    void two_sum(int l, int r, vector<int>& nums, int target, vector<vector<int>>& res) {
        while (l < r) {
            if (nums[l] + nums[r] == target) {
                res.push_back({-1 * target, nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
            } else if (nums[l] + nums[r] < target) {
                l++;
            } else {
                r--;
            }
        }
    }

   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -1 * nums[i];
            two_sum(i + 1, nums.size() - 1, nums, target, res);
        }
        return res;
    }
};

//[-2,-2,0,0,2]
//[-4,-1,-1,0,1,2]