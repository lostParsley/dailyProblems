class Solution {
    set<int> st ;
    int rec(vector<int>&digits , int num , int len , vector<bool>&vis ){
        if(num > 0 && int(log10(num)) == 2){
            if(num%2 != 0) return 0 ;
            else {
                st.insert(num);
                return 1 ;
            } ;
        }
        // if(i >= size(digits)) return 0 ;
        int ans = 0 ;
        for(int j = 0;j<size(vis);j++){
            if(vis[j] || (len == 0 && digits[j] == 0)) continue ;

            vis[j] = 1 ;
            ans += rec(digits , num*10 + digits[j] , len + 1 , vis);
            vis[j] = 0 ;
        }
        
        return ans ;
    }
public:
    int totalNumbers(vector<int>& digits) {
        int n = size(digits);
        vector<bool> vis(n , 0);
        int ans = 0;
        // rec(digits , 0 , 0 , vis);
        vector<int> freq(10);
        for(auto a : digits){
            freq[a]++ ;
        }

            for(int i = 1;i<=9;i++){
                if(freq[i] == 0 ) continue ;
                freq[i]-- ;
                for(int j = 0;j<=9;j++){
                    if(freq[j] == 0 ) continue ;
                    freq[j]--;
                    for(int k = 0;k<=8;k+=2){
                        if(freq[k] > 0 ) ans++ ;
                    }
                    freq[j]++;
                }
                freq[i]++;
            }
        
        return ans ;
    }
};