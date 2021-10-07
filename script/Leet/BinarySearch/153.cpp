// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Date: 2021.09.20

class Solution {
private:
    int left, right;
    int min;
public:
    int findMin(vector<int>& nums) {
        left = 0, right = nums.size()-1;
        min = nums[0];
        
        while(left <= right){

            //원소가 하나일 경우 min 없데이트
            if(left == right){
                if(nums[left] < min) min = nums[left];
                break;
            }
            
            // middle 값 선정 후 min 업데이트
            int middle = (left + right) / 2;
            if(nums[middle] < min) min = nums[middle];
            
            // middle을 기준으로 좌우의 오름차순 여부 판단
            // 좌우 모두 오름차순일 경우 가장 left 값이 min
            if(nums[left] <= nums[middle] && nums[middle] <= nums[right]){
                if(nums[left] < min) min = nums[left];                
                break;
            }
            // 한 방향만 오름차순일 경우 오름차순이 아닌 방향에 min 위치
            else if(nums[left] <= nums[middle])
                left = middle+1;
            else
                right = middle-1; 
        }
        
        return min;
    }
};