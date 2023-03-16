class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_len = s1.size();
        int s2_len = s2.size();

        if (s1_len > s2_len) return false;

        vector<int> s1_freq(26,0);
        vector<int> window(26,0);

        // First window checking
        for (int i=0; i<s1_len; i++){
            s1_freq[s1[i]- 'a']++;  // s1_freq[corresponding index of letter due to ascii number assignement for characters]
            window[s2[i] - 'a']++;
        }

        if (s1_freq == window) return true;

        for (int i=s1_len; i<s2_len; i++){
            window[s2[i-s1_len] - 'a']--;       // exclude char before the sliding window -> reduce frequency in window of said char
            window[s2[i]        - 'a']++;

            if (s1_freq == window) return true;
        }
        return false;
    }
};