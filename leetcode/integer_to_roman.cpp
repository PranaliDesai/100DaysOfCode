class Solution {
public:
    string intToRoman(int num) {
        // Converting this to a an array
        map<int, string> map;
        map[1] = "I";
        map[5] = "V";
        map[10] = "X";
        map[50] = "L";
        map[100] = "C";
        map[500] = "D";
        map[1000] = "M";
        string result = "";
        int multiplier = 1;
        int x = num;
        vector<int> rem_vec;
        vector<int> multi;
        int rem;
        while (x != 0) {
            rem = x%10;
            if (rem > 5 && rem != 9) {
                rem_vec.push_back(rem%5);
                rem_vec.push_back(5);
                multi.push_back(multiplier);
                multi.push_back(multiplier);
            } else {
                rem_vec.push_back(rem);
                multi.push_back(multiplier);
            }
            multiplier *=10;
            x = x/10;
        }
        for (int i = rem_vec.size() - 1; i > -1; i--) {
            if (rem_vec[i] == 4 || rem_vec[i] == 9) {
                result += map[multi[i]] + map[(rem_vec[i]+1)*multi[i]];
            } 
            else if (rem_vec[i] < 5 && rem_vec[i] != 4) {
                int digit_count = rem_vec[i];
                while (digit_count > 0) {
                    result += map[multi[i]];
                    digit_count--;
                }
            }
            else if  (rem_vec[i] == 5) {
                result += map[5*multi[i]];
            }
            else if (rem_vec[i] > 5 && rem_vec[i] != 9) {

                int digit_count_new = rem_vec[i];
                while (digit_count_new > 0) {
                    result += map[multi[i]];
                    digit_count_new--;
                }
                result += map[5*multi[i]];

            }

        }
        return result;
    }
    
    
};