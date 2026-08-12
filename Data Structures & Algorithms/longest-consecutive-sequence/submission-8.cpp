class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> umap;
        int res = 0;

        for (int n : nums) {
            if (!umap[n]) {
                umap[n] = umap[n-1] + umap[n+1] + 1;
                umap[n - umap[n-1]] = umap[n];
                umap[n + umap[n+1]] = umap[n];
                res = max(res, umap[n]);
            }
        }
        return res;
    }
};
