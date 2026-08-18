class Solution {
    bool compare(unordered_map<char, int>& orig_freq, unordered_map<char, int>& exp_freq) {
        for (const auto& itr : orig_freq) {
            int key = itr.first;
            if (orig_freq[key] > exp_freq[key]) {
                return false;
            }
        }
        return true;
    }

   public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> orig_freq;
        unordered_map<char, int> exp_freq;

        for (char ch : t) {
            orig_freq[ch]++;
        }

        int l = 0;
        string res = "";

        for (int r = 0; r < s.size(); r++) {
            exp_freq[s[r]]++;
            if (compare(orig_freq, exp_freq)) {
                while (orig_freq.find(s[l]) == orig_freq.end() ||
                       exp_freq[s[l]] - 1 >= orig_freq[s[l]]) {
                    exp_freq[s[l]]--;
                    l++;
                }
                if (res.size()==0 || res.size() > r - l + 1) {
                    res = s.substr(l, r - l + 1);
                    // cout << res << endl;
                }
            }
        }

        return res;
    }
};
