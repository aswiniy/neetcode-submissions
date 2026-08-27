class Solution {
    public boolean hasDuplicate(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            int num = nums[i];
            if(map.containsKey(num))
            {
                return true;
            }
            map.put(num, 1);
        }
        return false;
    }
}