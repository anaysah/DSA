class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max=nums[0];
        for(int i=0;i<size; i++){
            int sum=0;
            for (int j=i;j<size; j++){
                sum+=nums[j];
                if(sum>max) max=sum;
            }
        }
        return max;
    }
};