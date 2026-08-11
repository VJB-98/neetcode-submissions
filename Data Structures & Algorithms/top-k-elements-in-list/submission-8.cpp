class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        vector<vector<int>> f(nums.size()+1);
        for (const auto& itr : freq) {
            f[itr.second].push_back(itr.first);
        }
        vector<int> res;
        
        for(int i=f.size()-1;i>=0;i--) {
            for (int n : f[i]) {
                res.push_back(n);
                if (res.size()==k) {
                    return res;
                }
            }
        }
        return res;
    }
};
