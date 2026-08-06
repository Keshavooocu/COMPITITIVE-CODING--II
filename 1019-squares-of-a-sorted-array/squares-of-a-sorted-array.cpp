class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
            int right = 0;
        while (right < n && nums[right] < 0) {
            ++right;
        }
        int left = right - 1; 
        
        int pos = 0; 

        while (left >= 0 && right < n) {
            if (abs(nums[left]) < abs(nums[right])) {
                result[pos++] = nums[left] * nums[left];
                --left;
            } else {
                result[pos++] = nums[right] * nums[right];
                ++right;
            }
        }

        while (left >= 0) {
            result[pos++] = nums[left] * nums[left];
            --left;
        }
        while (right < n) {
            result[pos++] = nums[right] * nums[right];
            ++right;
        }

        return result;
        
    }
};