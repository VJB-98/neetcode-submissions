class Solution {
   public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;
        for (int i=0;i<height.size();i++) {
            while(!s.empty() && height[s.top()] <= height[i]) {
                int mid = height[s.top()];
                s.pop();
                if (!s.empty()) {
                    int left = height[s.top()];
                    int right = height[i];
                    int h = min(left, right) - mid;
                    int w = i - s.top() - 1;
                    res += h*w;
                }
            }
            s.push(i);
        }

        return res;
    }
};
