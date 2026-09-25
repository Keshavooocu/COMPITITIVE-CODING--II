class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char t : tasks){
            freq[t - 'A']++;
        }

        int mfreq = 0;
        for (int f : freq) {
            mfreq = max(mfreq, f); }

        int mmax = 0;
        for (int f : freq) {
            if (f == mfreq) {
                mmax++;
            }
        }

        int part_count = mfreq - 1;
        int part_len = n + 1;
        int min_slots = part_count * part_len + mmax;

        return max((int)tasks.size(), min_slots);
    }
};