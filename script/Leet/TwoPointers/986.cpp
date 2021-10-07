// Problem: https://leetcode.com/problems/interval-list-intersections/
// Date: 2021.09.25

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> intersec;        
        int cur1 = 0, cur2 = 0;
        
        while(cur1 < firstList.size() && cur2 < secondList.size()){
            
            int start = max(firstList[cur1][0], secondList[cur2][0]);
            int end = min(firstList[cur1][1], secondList[cur2][1]);
            
            if(start <= end) intersec.push_back({start, end});
            (end == firstList[cur1][1]) ? cur1++ : cur2++;
            
        }
        
        return intersec;
    }
};