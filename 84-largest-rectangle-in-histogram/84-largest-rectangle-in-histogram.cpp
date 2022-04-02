class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
                left[i]=-1;
            else
                left[i]=st.top();
            
            st.push(i);
        }
        
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && heights[st2.top()]>=heights[i])
            {
                st2.pop();
            }
            if(st2.empty())
                right[i]=n;
            else
                right[i]=st2.top();
            
            st2.push(i);
        }
        // cout<<right[n-1];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            // cout<<left[i]<<" "<<right[i]<<"\n";
            int l=heights[left[i]+1];
            int r=heights[right[i]-1];
            
            int temp=min(heights[i],min(l,r))*(right[i]-left[i]-1);
            ans=max(temp,ans); 
            
        }
        return ans;
    }
};