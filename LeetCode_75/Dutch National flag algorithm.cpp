// 75. Sort Colors Dutch National flag algorithm Optimal solution

class Solution {
    void swap(int&a,int&b){
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size();
        while(mid<high){
            if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;low++;
            }
            else if(nums[mid]==2){
                high--;
                swap(nums[mid],nums[high]);
                
            }
        }

    }
};