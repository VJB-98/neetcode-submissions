class Solution {
    string encode_string(string s) {
        int size = s.size();
        string encoding;
        if (size < 10) {
            encoding = "00" + to_string(size);
        } else if (size < 100) {
            encoding = "0" + to_string(size);
        } else {
            encoding = to_string(size);
        }
        return encoding + s;
    }

    vector<string> decode_string(string s) {
        vector<string> res;
        for (int i = 0; i < s.size();) {
            int size = stoi(s.substr(i,3));
            string str = s.substr(i + 3, size);
            res.push_back(str);
            i += size + 3;
        }
        return res;
    }

   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (string s : strs) {
            res += encode_string(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.size() == 0) {
            return {};
        }
        return decode_string(s);
    }
};
