// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Date: 2021.09.17

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int index = -1;
        int left = 0, right = nums.size()-1;
    
        if(nums.size() == 0) return index;
        
        while(left <= right){

            int middle = (left + right) / 2;
            
            if(nums[middle] == target){
                return middle;
            }
            if(nums[middle] > target){
                if(nums[left] > target && nums[middle] > nums[right])
                    left = middle + 1;
                else                
                    right = middle - 1;
            }
            else if(nums[middle] < target){
                if(nums[right] < target && nums[left] > nums[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
        }
        
        return index;        
    }

};