class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n =score.size();
        
        vector<pair<int,int>> sorted_scores(n);

        for (int i = 0; i < n; ++i) {
            sorted_scores[i] = {score[i], i};
        }

        sort(sorted_scores.rbegin(), sorted_scores.rend());

        vector<string> ans(n);

        for (int r = 1; r <= n; ++r) {
            int i = sorted_scores[r - 1].second;

            if(r ==1) {
                ans[i] = "Gold Medal";
            } else if(r ==2) {
                ans[i] = "Silver Medal";
            } else if(r ==3) {
                ans[i] = "Bronze Medal";
            } else{
                ans[i] = to_string(r);  }
        }
        return ans;
    }
};