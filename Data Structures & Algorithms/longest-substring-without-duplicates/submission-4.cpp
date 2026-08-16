class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int size = s.size();
        int longest = 0;
        int current = 0;
        int start = 0;

        for (int i = 0; i < size; i++) {
            if (index.find(s[i]) == index.end()) {
                current++;
            } else {
                start = max(start, index[s[i]] + 1);
                current = i - start + 1;
            }
            longest = max(longest, current);
            index[s[i]] = i;
        }

        return longest;
    }
};
