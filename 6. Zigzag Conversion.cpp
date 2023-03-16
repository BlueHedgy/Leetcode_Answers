class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2 || s.size() < numRows) return s; 

        int dir=1, count=0;
        vector<string> ans_set(numRows);
        string ans;

        for (int i=0; i<s.size(); i++){
            if (count == numRows-1) dir = -1;
            else if (count == 0 ) dir = 1;
            ans_set[count] += s[i];

            count += dir;  
        }
        
        for (int j=0; j< ans_set.size(); j++) ans += ans_set[j];
        return ans;
    }
};  