class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        if (s.length() == 2 && s[0] != s[1]) {
            return 2;
        }
        int start_ptr = 0;
        int end_ptr = 1;
        map<char, int> map;
        map[s[start_ptr]] = 1;

        int res = 0;
        while (end_ptr < s.length()) {
            if (map.find(s[end_ptr]) == map.end()) {
                map[s[end_ptr]] = 1;
                res = max(res, end_ptr - start_ptr + 1);                   
                end_ptr++;
            } else {
                map.erase(s[start_ptr]);
                start_ptr++;
                map[s[start_ptr]] = 1;
                if (start_ptr == end_ptr) {
                    end_ptr = start_ptr+1;
                }
            }
        }
        if (res == 0) {
            res++;
        }
        return res;
    }
};