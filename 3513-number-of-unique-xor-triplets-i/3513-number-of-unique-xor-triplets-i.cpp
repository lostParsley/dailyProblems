class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int i = 0 , msb = 0  , tmp = nums.size();
        while(tmp){
            if(tmp%2 == 1) msb = i ;
            i++;
            tmp /= 2 ;
        }
        if(size(nums) <= 2) return nums.size() ;
        return (1 << (msb + 1));
    }
};