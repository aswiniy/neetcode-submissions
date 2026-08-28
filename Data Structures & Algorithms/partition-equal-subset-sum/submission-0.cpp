class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n= nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;

        for(int i=0;i<n;i++){
          sum+=nums[i];
        }
        
        if(sum %2==1) return false;
        int target = sum/2;

        vector<int> sums(target+1);

        sums[0]=1;
        
        int right=0;

        for(int i:nums){
            bool check=true;
            if(i>target) break;
            for(int j=right;j>=0;j--){
                if(j+i > target) continue;
                if(sums[j]==1){
                    if(j+i == target)return true;
                    if(check){
                        right = j+i;
                        check = false;
                    }
                    sums[j+i]=1;
                }
            }
        }
        
        return false;
    }
};
