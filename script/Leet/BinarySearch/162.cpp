// Problem: https://leetcode.com/problems/find-peak-element/
// Date: 2021.09.20

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          
        int n = nums.size();
        int left = 0, right = n-1;

        while(left <= right){
            
            int middle = (left + right) / 2;
            
            if((middle == 0 || nums[middle] > nums[middle-1]) &&
               (middle == n-1 || nums[middle] > nums[middle+1])){
                return middle;
            }
            if(nums[middle+1] > nums[middle])
                left = middle + 1;
            else
                right = middle - 1;
            
        }
        return -1;
    }
};