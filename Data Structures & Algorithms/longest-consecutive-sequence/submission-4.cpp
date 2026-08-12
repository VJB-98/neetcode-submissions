class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_map<int, int> index;
        vector<bool> vis(nums.size(), false);

        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;
        }

        int res = 1;
        for (int n : nums) {
            int len = 1;
            int temp = n;
            vis[index[n]] = true;
            while (index.find(temp - 1) != index.end() && !vis[index[temp - 1]]) {
                len++;
                temp--;
                vis[index[temp]] = true;
            }
            temp=n;
            while (index.find(temp + 1) != index.end() && !vis[index[temp + 1]]) {
                len++;
                temp++;
                vis[index[temp]] = true;
            }
            if (len > res) {
                res = len;
            }
        }

        return res;
    }
};
