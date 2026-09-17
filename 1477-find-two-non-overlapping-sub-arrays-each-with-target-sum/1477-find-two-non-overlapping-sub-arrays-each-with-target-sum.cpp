class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int j = 0, n = size(arr), sm = 0, mn = 1e9;
        vector<int> pre(n, 1e9), suf(n, 1e9);
        for (int i = 0; i < n; i++) {

            sm += arr[i];

            while (j <= i && sm > target) {
                sm -= arr[j];
                j++;
            }

            if (sm == target) {
                mn = min(mn, i - j + 1);
            }

            pre[i] = mn;
        }

        j = n - 1;
        mn = 1e9;
        sm = 0;

        for (int i = n - 1; i >= 0; i--) {

            sm += arr[i];

            while (j >= i && sm > target) {
                sm -= arr[j];
                j--;
            }

            if (sm == target) {
                mn = min(mn, j - i + 1);
            }

            suf[i] = mn;
        }

        int ans = 1e9;

        for (int i = 0; i < n - 1; i++) {
            if (pre[i] != 1e9 && suf[i + 1] != 1e9)
                ans = min(ans, pre[i] + suf[i + 1]);
        }

        if (ans == 1e9) return -1;
        return ans;
    }
};