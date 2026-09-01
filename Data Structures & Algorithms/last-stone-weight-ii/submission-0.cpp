class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        sort(stones.begin(), stones.end());
        for(int i:stones)sum+= i;
        int target=0;
        if(sum%2 ==0) target = sum/2;
        else target= (sum+1)/2;

        bitset<10001> dp;
        dp[0]=1;

        for(int i:stones){
            if(i>target) break;
            dp |= dp<<i;
        }
        
        for(int i=target;i>=0;i--){
            if(dp[i]==1){
                int res= abs( sum - 2*i);
                return res;
            }
        }

        return 0;
    }
};