class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        // BUG FIX: Size must be mx + 1 to safely access index mx
        // Made long long to avoid overflow when calculating pairs later
        vector<long long> freq(mx + 1, 0); 

        for (int v : nums) {
            // BUG FIX: changed i*i < v to i*i <= v to include exact square roots
            for (int i = 1; i * i <= v; i++) {
                if (v % i == 0) {
                    freq[i]++;
                    // BUG FIX: changed n/i to v/i
                    if (v / i != i) freq[v / i]++; 
                }
            }
        }
        
        vector<long long> fsum(mx + 1, 0);
        for (int i = mx; i >= 1; i--) {
            fsum[i] = freq[i] * (freq[i] - 1) / 2;
            // BUG FIX: changed j < mx to j <= mx
            for (int j = 2 * i; j <= mx; j += i) {
                fsum[i] -= fsum[j];
            }
        }

        vector<long long> sm(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            // BUG FIX: Proper running prefix sum
            sm[i] = sm[i - 1] + fsum[i];
        }

        vector<int> ans;
        for (long long v : queries) {
            int l = 1, h = mx, tmp = 0;
            while (l <= h) {
                int m = l + (h - l) / 2;
                if (sm[m] > v) {
                    tmp = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};