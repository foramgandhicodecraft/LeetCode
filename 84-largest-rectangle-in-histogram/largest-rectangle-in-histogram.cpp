class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //left smallest
        vector<pair<int,int>>left;
        vector<int>left_smallest(n); 
        for (int i = 0; i < heights.size(); i++){
          while (left.size() != 0 && heights[i] <= left.back().second){
              left.pop_back();
            }
          if (left.size() == 0){
            left_smallest[i] = 0;
          }else{
          left_smallest[i] = left.back().first + 1;
          }
          left.push_back({i, heights[i]});
        }

        //right smallest
        vector<pair<int,int>>right;
        vector<int>right_smallest(n); 
        for (int i = heights.size()-1; i >= 0; i--){
          while (right.size() != 0 && heights[i] <= right.back().second){
              right.pop_back();
            }
          if (right.size() == 0){
            right_smallest[i] = heights.size() - 1;
          }else{
          right_smallest[i] = right.back().first - 1;
          }
          right.push_back({i, heights[i]});
        }

        int width,area;
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++){
            width = right_smallest[i] - left_smallest[i] + 1;
            area = width * heights[i];
            max_area = max(max_area,area);
        }

        return max_area;
    }
};