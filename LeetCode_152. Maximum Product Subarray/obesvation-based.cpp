#include <iostream>
#include <vector>
using namespace std;

//LeetCode 152. Maximum Product Subarray
//this is purlley done by me by ovservations and written by myself

//To remember
//1. input has zero also
//2. every possible testcases can be given with negative, positive, zero values

//observation
//1. 0 will break the array into multiple array which can be done individually
//2. in a smaller array(breaked due to zeros) if we have even negative than no problem because minus will cut minus
//3. if negative is odd then their is problem because we have exclude one negative value either from the start or from the end

// i am storing all the [first-index, last-index, whole_product, no_of_negative_values] of local array which is breaked due to presense of zeros
// then i am finding the product upto first negative value and product from last upto last negative value
// then i am checking which side should be include in the subarray

// the intiation is very clear for the problem but doing it in code maded the code long
// please dont use this code because a better logic is their. that is also doing the same but has very less line of codes
// i can work on this code and can reduce the no of line and can make this more simpler but the approach not perfect although it is almost same as perfect approach

// please look explantion.jpg for diagrams


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> data; //[first-index, last-index, whole_product, no_of_negative_values];
        int cur_product= 1;
        int last_zero = -1;
        int no_minus = 0;
        int no_zero = 0;

        for(int i=0; i<n; i++){  // traversing the whole nums to find all the local array breaked by zeros
            if(nums[i]==0){
                no_zero++;
                if(last_zero+1<=i-1)
                    data.push_back({last_zero+1, i-1, cur_product, no_minus});
                last_zero = i; cur_product = 1; no_minus=0;
                continue;
            }else if(nums[i]<0) no_minus++;
            cur_product*=nums[i];
        }
        if(nums[n-1]!=0)
            data.push_back({last_zero+1, n-1, cur_product, no_minus});

        for(int i=0; i<data.size(); i++){
            cout<<data[i][0]<<" "<<data[i][1]<<" "<<data[i][2]<<" "<<data[i][3]<<endl;
        }

        if(data.size()==0) return 0;

        int max_product=INT_MIN;
        if(data.size()>1 || no_zero>=1) max_product=0; // if we get any zero in the array then the max_product will change

        for(int i=0; i<data.size(); i++){
            if(data[i][0]>data[i][1]) continue;
            if(data[i][3]%2==0) max_product = max(max_product, data[i][2]);
            else{
                if(data[i][0]==data[i][1]) {
                    max_product = max(max_product, data[i][2]);
                    continue;
                }

                int front_value = 1,back_value=1,t=data[i][0]; 
                while(t<=data[i][1] && nums[t]>=0){
                    front_value*=nums[t];t++;
                }
                front_value*=nums[t];
                cout<<"front_value: "<<front_value<<endl;

                t=data[i][1]; 
                while(t>=data[i][0] && nums[t]>=0){
                    back_value*=nums[t];t--;
                }
                back_value*=nums[t];
                cout<<"back_value: "<<back_value<<endl;


                if(back_value>front_value) data[i][2]/=back_value;
                else data[i][2]/=front_value;

                max_product=max(data[i][2],max_product);
            }
        }

        return max_product;
    }
};

void testMaxProduct(vector<int>& nums) {
    Solution sol;
    int result = sol.maxProduct(nums);
    cout << "The maximum product is: " << result << endl;
}

int main(){
    vector<int> nums1 = {2,3,-2,4};
    testMaxProduct(nums1);

    // vector<int> nums2 = {-2,0,-1};
    // testMaxProduct(nums2);

    // vector<int> nums3 = {0,2};
    // testMaxProduct(nums3);

    // vector<int> nums4 = {0,2,0};
    // testMaxProduct(nums4);
}