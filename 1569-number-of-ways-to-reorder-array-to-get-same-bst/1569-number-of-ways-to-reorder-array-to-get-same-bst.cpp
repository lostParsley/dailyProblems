class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = size(nums) , mod = 1e9 + 7;
        vector<vector<long long>> pas(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i+1;j++) pas[i].push_back(1);
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<size(pas[i]);j++){
                if (i && j < i && j) pas[i][j] = (pas[i-1][j] + pas[i-1][j-1])%mod;
            }
        }
        auto rec = [&](auto&& self , vector<int>nums)-> long long{
            int m = size(nums);
            if(m < 3) return 1ll ;
            vector<int> lf , rt ;
            for(int i = 1;i<m;i++) if(nums[i] < nums[0]) lf.push_back(nums[i]);
            else rt.push_back(nums[i]);
            long long x  = self(self , lf) , y = self(self , rt);
            return (x%mod * y%mod * (pas[m-1][size(lf)])%mod)%mod;
        };
        return rec(rec , nums)-1;
    }
};