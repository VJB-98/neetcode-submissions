class Solution {
   public:
    int trap(vector<int>& height) {
        int size = height.size();
        int l = 0;
        int r=size-1;
        int lmax=0;
        int rmax=0;
        int res=0;

        while(l<r) {
            int water = min(lmax,rmax) - height[l];
            if (water>0) {
                res+=water;
            }
            water = min(lmax,rmax) - height[r];
            if (water>0) {
                res+=water;
            }            
            lmax=max(lmax, height[l]);
            rmax=max(rmax, height[r]);
            if (height[l]<=height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return res;
    }
};
