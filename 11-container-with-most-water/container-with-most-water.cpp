class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area;
        int area, heights, width;
        while (left < right){
            width = right - left;
            heights = min(height[left], height[right]);
            area = heights * width;
            max_area = max(max_area, area);
            if (height[left] > height[right])
               right--;
            else
               left++;
        }

        return max_area;
    }
};