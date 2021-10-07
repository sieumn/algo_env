// Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Date: 2021.09.17

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        

        vector<int> index = {-1, -1};
        
        if(nums.size()==0) return index;
        
        if(nums[0]==target)
            index[0] = 0;
        else
            searchLR(nums, 0, nums.size()-1, target, index, 0);
                
        if(nums[nums.size()-1]==target)
            index[1] = nums.size()-1;
        else
            searchLR(nums, 0, nums.size()-1, target, index, 1);
        
        return index;
    }
    
    //변경한 함수 (searchLeft + searchRight)
    static void searchLR(vector<int>& nums, int first, int last, int target, vector<int>& index, int mode){

        if(first > last) return;
        
        else if(first == last){
            if(nums[first] == target) index[mode] = first;
            return;
        }
        
        int middle = (first + last) / 2;
        
        if(nums[middle] < target)
            searchLR(nums, middle+1, last, target, index, mode);
        
        else if(nums[middle] > target)
            searchLR(nums, first, middle-1, target, index, mode);
        
        // target을 찾았을 때만 mode값 활용
        else{
            if(mode==0 && nums[middle-1] == target)
                searchLR(nums, first, middle-1, target, index, mode);
            else if(mode==1 && nums[middle+1] == target)
                searchLR(nums, middle+1, last, target, index, mode);
            else{
                index[mode] = middle;
            }
        }

    }
};