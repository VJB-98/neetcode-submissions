class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int window = s1.size();
        vector<int> freq(26);

        for (char ch : s1) {
            freq[ch - 'a']++;
        }

        vector<int> perm(26);
        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            perm[s2[r]-'a']++;
            while (r - l + 1 > window) {
                perm[s2[l]-'a']--;
                l++;
            }
            if (perm == freq) {
                return true;
            }
        }

        return false;
    }
};
