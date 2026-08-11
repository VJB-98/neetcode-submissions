class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        // auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
        //     return p1.second<p2.second;
        // };
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto &itr : freq) {
            pq.push({itr.second, itr.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        while(k>0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
