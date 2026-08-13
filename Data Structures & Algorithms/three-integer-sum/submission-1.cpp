class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_map<int, int> index;

        for (int i=0;i<nums.size();i++) {
            index[nums[i]] = i;
        }

        for (int i=0;i<nums.size();i++) {
            for (int j=i+1;j<nums.size();j++) {
                int sum = -1*(nums[i]+nums[j]);
                if (index.find(sum) != index.end() && index[sum] != i && index[sum] !=j) {
                    vector<int> triple = {nums[i], nums[j], sum};
                    sort(triple.begin(), triple.end());
                    res.insert(triple);
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
