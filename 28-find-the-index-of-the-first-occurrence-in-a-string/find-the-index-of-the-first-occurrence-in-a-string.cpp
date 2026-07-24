class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();
        
        if (n > h) return -1;
        
        for (int i = 0; i <= h - n; ++i) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }
        
        return -1;
    }
};