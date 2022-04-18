class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int mx=0;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();
    
            if(st.empty())
                left[i]=-1;
            else
                left[i]=st.top();
            st.push(i);
        }
        
    
        stack<int>st1;    
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty() && heights[i]<=heights[st1.top()])
                st1.pop();
            
            if(st1.empty())
                right[i]=n;
            else
                right[i]=st1.top();
            
            st1.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            int area=heights[i]*(right[i]-left[i]-1);
            mx=max(mx,area);
        }
         
        return mx;
    }
};