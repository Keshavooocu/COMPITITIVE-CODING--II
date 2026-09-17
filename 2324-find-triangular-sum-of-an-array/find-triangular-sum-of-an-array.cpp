class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        for(int size = n ; size>1; size--){
            for(int i=0; i<size-1;i++){
                int x = nums[i] + nums[i+1];
                nums[i] = x % 10;
            }
        }
        return nums[0];
    }
};