class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq ;
        while(n){
            pq.push(n%10);
            n /= 10;
        }
        int x = pq.top();
        pq.pop();
        return x * (pq.top());
    }
};