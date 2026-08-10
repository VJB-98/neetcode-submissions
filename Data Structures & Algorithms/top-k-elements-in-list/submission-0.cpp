class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second<p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int>::iterator itr;
        for (itr = freq.begin(); itr != freq.end(); itr++) {
            pq.push({itr->first, itr->second});
        }

        vector<int> res;
        while(k>0) {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};
