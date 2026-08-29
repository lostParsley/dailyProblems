class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = size(nums);
        vector<int> vec = nums;
        sort(vec.begin() ,vec.end());

        map<int , vector<int>> mp ;
        map<int , int> grp ;
        int group = 0 ;
        grp[vec[0]] = 0 ;
        mp[0].push_back(vec[0]);
        for(int i = 1;i<n;i++){
            if(abs(vec[i] - vec[i-1]) > limit)
                group++ ;
            mp[group].push_back(vec[i]);
            grp[vec[i]] = group;
        }

        for(int i = 0;i<n;i++){
            int gp = grp[nums[i]];
            nums[i] = *mp[gp].begin();
            mp[gp].erase(mp[gp].begin());
        }
        return nums;
    }
};