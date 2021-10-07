// Problem: https://leetcode.com/problems/3sum/
// Date: 2021.09.21

class Solution {
private:
    vector<int> visit;
    bool chk;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp(3, -999999);
        
        // 배열의 크기가 3 이하일 경우 정답 없음
        if(nums.size() < 3) return ans;
        
        // 오름차순 정렬
        sort(&nums[0], &nums[nums.size()]);
        
        // 첫 번째 원소 선정
        for(int i=0; i<nums.size()-2; i++){
            
            // 중복 방지
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            // target을 만족하는 두 번째, 세 번째 원소 선정
            int left = i+1, right = nums.size()-1;
            int target = 0 - nums[i];
            while(left < right){
                if(nums[left] + nums[right] > target)
                    right--;
                else if(nums[left] + nums[right] < target)
                    left++;
                else{
                    // 중복 방지
                    if(tmp[0] != nums[i] || tmp[1] != nums[left]){
                        // 조건에 맞는 원소 찾았을 시 ans에 push
                        tmp[0] = nums[i], tmp[1] = nums[left], tmp[2] = nums[right];
                        ans.push_back(tmp);                        
                    }
                    left++, right--;
                }
            }
        }
        return ans;
    }
};