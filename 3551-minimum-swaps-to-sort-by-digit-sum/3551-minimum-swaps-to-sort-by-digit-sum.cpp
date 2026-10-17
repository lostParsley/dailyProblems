class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> tmp = nums ;
        auto getsum = [](int n1){
            int sm = 0 ;
            while(n1){
                sm += n1%10;
                n1 /= 10 ;
            }
            return sm ;
        };
        auto lambda = [getsum](int n1 , int n2){
            int s1 = getsum(n1) , s2 = getsum(n2);
            if(s1 != s2) return s1 < s2 ;
            return n1 < n2 ;
        };
        sort(tmp.begin() , tmp.end() , lambda);
        unordered_map<int , int> mp ;
        int n = size(nums) , ans = 0;
        for(int i = 0;i<n;i++){
            mp[nums[i]] = i ;
        }

        for(int i = 0;i<n;i++){
            if(mp[tmp[i]] != i){
                ans++;
                int j = mp[tmp[i]];

                swap(nums[i], nums[j]);

                mp[nums[j]] = j;
                mp[nums[i]] = i;
            }
        }
        return ans ;
    }
};