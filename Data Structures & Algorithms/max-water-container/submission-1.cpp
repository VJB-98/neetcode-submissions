class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int size = heights.size();
        int l = 0;
        int r = size - 1;

        while (l < r) {
            area = max(area, (r - l) * min(heights[l], heights[r]));
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else if (l + 1 < r && r - 1 > l) {
                if (heights[l + 1] >= heights[r - 1]) {
                    r--;
                } else {
                    l++;
                }
            } else {
                l++;
            }
        }
        return area;
    }
};
