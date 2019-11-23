class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> hash;
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        vector<string> store;
        expand(digits, "" ,0, store, hash);
        return store;
    }
    
   void expand(string digits, string val, int index, vector<string> &store, map<char, string> hash_map) {
            string res;
            int vec_len = 0;
            if (index < digits.length()) {
            if (digits[index] == '7' || digits[index] == '9') {
                vec_len = 4;
            } else {
                vec_len = 3;
            }
            for (int i = 0; i < vec_len; i++) {
                res = val + hash_map[digits[index]][i];
                if (res.length() == digits.length()) {
                    store.push_back(res);
                }
                expand(digits, res ,index+1, store, hash_map);
            }
        }
    }
};