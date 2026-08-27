class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();

        int curr_min=nums[0];
        int min_sum=nums[0];

        int curr_max = nums[0];
        int max_sum = nums[0];
        int total=nums[0];

        for(int i=1;i<n;i++){
            curr_min= min(nums[i],curr_min +nums[i]);
            min_sum =min(min_sum,curr_min);
            
            curr_max= max(nums[i],curr_max +nums[i]);
            max_sum =max(max_sum,curr_max);

            total+=nums[i];
        }
        
        if(max_sum <0 ) return max_sum;
        return max(total-min_sum,max_sum);
        
    }
};