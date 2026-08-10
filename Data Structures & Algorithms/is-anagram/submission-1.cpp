class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26);
        for (char ch : s) {
            alpha[ch-'a']++;
        }
        for (char ch : t) {
            alpha[ch-'a']--;
            if (alpha[ch-'a'] < 0) {
                return false;
            } 
        }
        for (int val : alpha) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
