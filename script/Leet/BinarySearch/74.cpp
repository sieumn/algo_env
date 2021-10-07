// Problem: https://leetcode.com/problems/search-a-2d-matrix/
// Date: 2021.09.17

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                
        int r = matrix.size();
        int c = matrix[0].size();
        if(r == 0 || c == 0) return false;
        
        int first = 0, last = r*c - 1;
        
        while(first <= last){
            int middle = (first + last) / 2;
            int cur = matrix[middle/c][middle%c];
            
            if(cur > target)
                last = middle - 1;
            else if(cur < target)
                first = middle + 1;
            else{
                return true;
            }
        }
        
        return false;
    }    
};