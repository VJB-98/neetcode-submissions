class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> alpha(26);
        for (int i = 0; i < s.size(); i++) {
            alpha[s[i]-'a']++;
            alpha[t[i]-'a']--;
        }

        for (int val : alpha) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
