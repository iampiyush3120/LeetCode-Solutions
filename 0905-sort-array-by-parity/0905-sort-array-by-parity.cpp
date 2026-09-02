class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left=0;
        int right=nums.size()-1;

        while(left<right){
            //left ko tab tak aage badho jab tak even mil rha hai
            while(left<right && nums[left]%2==0){
               left++;
            }
             //right ko jabtak piche lao jab tak odd na mil jaye
             while(left<right && nums[right]%2!=0){
                right--;
             }
             //left par odd right par even
             swap(nums[left],nums[right]);
        }
        return nums;
        
    }
};