class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> encodingVsAnagram;

        for (string s : strs) {
            vector<int> count(26, 0);
            for (char ch : s) {
                count[ch - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i=1;i<26;i++) {
                key += "," + to_string(count[i]);
            }
            // if (encodingVsAnagram.find(count) != encodingVsAnagram.end()) {
                encodingVsAnagram[key].push_back(s);
            // } else {
                // encodingVsAnagram[count] = {s};
            // }
        }

        for (auto itr : encodingVsAnagram) {
            res.push_back(itr.second);
        }
        return res;
    }
};
