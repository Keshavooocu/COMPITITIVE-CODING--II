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

        for (int rank = 1; rank <= n; ++rank) {
            int original_index = sorted_scores[rank - 1].second;

            if(rank ==1) {
                ans[original_index] = "Gold Medal";
            } else if(rank ==2) {
                ans[original_index] = "Silver Medal";
            } else if(rank ==3) {
                ans[original_index] = "Bronze Medal";
            } else{
                ans[original_index] = to_string(rank);  }
        }
        return ans;
    }
};