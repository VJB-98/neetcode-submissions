class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int size = height.size();

        left[0]=0;
        int lmax=height[0];
        for (int i=1;i<height.size();i++) {
            left[i]=lmax;
            lmax=max(lmax,height[i]);
        }

        int rmax=height[size-1];
        right[size-1]=0;
        for (int i=size-2;i>=0;i--) {
            right[i]=rmax;
            rmax=max(rmax,height[i]);
        }

        int sum=0;
        for(int i=0;i<size;i++) {
            int water = min(left[i],right[i])-height[i];
            if(water>0) {
                sum+=water;
            }
        }

        return sum;
    }
};
