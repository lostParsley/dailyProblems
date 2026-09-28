class Solution {
    set<vector<int>> st ;
    void rec(vector<int>& nums , int i , vector<int> cur){
        if(i >= size(nums)) {
            st.insert(cur);
            return ;
        } 
        rec(nums , i+1 , cur) ;
        
        cur.push_back(nums[i]);
        rec(nums , i+1 , cur) ;
        st.insert(cur);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur ;
        rec(nums , 0 , cur);
        vector<vector<int>> ans(st.begin() , st.end());
        return ans ;
    }
};