class Solution {
    set<vector<int>> st ;
    
    void rec(vector<int>& c , int i , vector<int>cur , int sm , int target){
        if(i == size(c)){
            if(sm == target) st.insert(cur);
            return; 
        }
        if(sm > target) return ;
        rec(c , i+1 , cur , sm , target);
        cur.push_back(c[i]);
        rec(c , i+1 , cur , sm + c[i] , target) ; 
        // cur.push_back(c[i]);
        rec(c , i , cur , sm + c[i] , target );
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        sort(c.begin() ,c.end());
        vector<int> cur ;
        rec(c , 0 , cur , 0 , target);
         vector<vector<int>> ans(st.begin() , st.end());
         return ans;
    }
};