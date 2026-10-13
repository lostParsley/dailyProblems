class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0;i<size(nums);i++){
            if(nums[i] < 0) nums[i] *= -1;
        }
        sort(nums.rbegin() , nums.rend());
        for(int i = 0;i<(size(nums)+1)/2 ;i++){
            ans += nums[i] * nums[i];
        }
        for(int i=(size(nums)+1)/2 ;i<size(nums);i++){
            ans -= nums[i] * nums[i];
        }
        return ans;
    }
};