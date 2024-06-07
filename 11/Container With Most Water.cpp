class Solution {
public:
    int maxArea(vector<int>& height) {
        int l;
        int w;
        int i=0;
        int n=height.size();
        int j=n-1;
        int maxi=0;
        for(i=0;i<=j-1;i++){
            for(j=n-1;j>i;j--){
                l=min(height[i],height[j]);
                w=j-i;
                
            }
            maxi=max((l*w),maxi);
            
        }
        return maxi;
    }
};