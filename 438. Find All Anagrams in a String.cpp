class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();

        if (s_len < p_len) return {};
        
        vector<int> p_freq(26,0);
        vector<int> window(26,0);
        vector<int> ans;

        for (int i=0; i<p_len; i++){
            p_freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        if (p_freq == window) ans.push_back(0);

        for (int i=p_len; i<s_len; i++){
            window[s[i - p_len] - 'a']--;
            window[s[i]         - 'a']++;
            if (p_freq == window) ans.push_back(i - p_len+1);
        }

        return ans;        
    }
};