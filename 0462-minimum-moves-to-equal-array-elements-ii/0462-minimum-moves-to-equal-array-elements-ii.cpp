class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=size(nums) ;
        sort(nums.begin() , nums.end());
        int ans = 0 , md = 0 ;
        if(n&1) md = nums[n/2];
        else md = (nums[n/2] + nums[(n+1)/2]) / 2;
        for(auto c : nums) ans += abs(c - md);
        return ans ;
    }
};