class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans(num , '0');

        for(int i = 0;i<num && sum >= 0;i++){
            for(int j = 9;j>=0;j--){
                if(j <= sum){
                    ans[i] = j + '0';
                    sum -= j ;
                    break;
                }
            }
        }
        if(sum != 0) return "";
        return ans;
    }
};