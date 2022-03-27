class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int area=(j)*min(height[i],height[j]);
        int ans=area;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                i++;
            }
            else if(height[i]>height[j])
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
            
            area=(j-i)*min(height[i],height[j]);
            ans=max(ans,area);
        }
        
        return ans;
    }
};