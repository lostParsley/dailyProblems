class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n);
        int t = 0 ;
        vector<int> r(n);
        for(int i = n-1;i>=0;i--){
            while(t && nums[s[t-1]] >= nums[i]) t-- ;
            r[i] = t >0 ? s[t-1] : n ;
            s[t++] = i ;
        }
        vector<int> c(n , 0);
        map<int , int> p;
        long long ans = 0 ;
        for(int i = n-1;i>=0;i--){
            auto it = p.find(nums[i]);
            int nx = (it != p.end()) ? it->second : n ;
            if(nx < r[i]) c[i] = 1 + c[nx];
            p[nums[i]] = i ;
            ans += (long long)(r[i] - i - 1) - c[i];
        }
        return ans;
    }
};