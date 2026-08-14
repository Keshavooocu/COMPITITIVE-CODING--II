class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left= 0;
        int ml=0; 

        for (int right = 0; right < s.length(); ++right) {
            char curr = s[right];
        
        if (mp.find(curr) != mp.end()) {
                left = max(left, mp[curr] + 1);
            }

            mp[curr] = right;
            ml = max(ml, right - left + 1);
        }
        return ml;
    }
};