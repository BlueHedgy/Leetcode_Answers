class Solution {
public:
    void backtrack(string &s, string &temp, vector<string> &ans){
        if (temp.size() == s.size()){
            ans.push_back(temp);
            // return;
        }

        for (int i=0; i< s.size(); i++){
            if (temp.size()==0 || i>temp.size()-1){
                if (isalpha(s[i])){
                    temp.push_back(tolower(s[i]));
                    backtrack(s, temp, ans);
                    temp.pop_back();

                    temp.push_back(toupper(s[i]));
                    backtrack(s, temp, ans);
                    temp.pop_back();
                }
                else{
                    temp.push_back(s[i]);
                    backtrack(s, temp, ans);
                    temp.pop_back();

                }
            }     
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp;
        backtrack(s, temp, ans);
        return ans;
    }
};