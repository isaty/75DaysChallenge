class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       
        int n=cardPoints.size(),score=0;
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            left[i+1]+=left[i]+cardPoints[i];
            right[n-i-1]+=right[n-i]+cardPoints[n-i-1];
        }
        
        if(k==n)
          return left[n];
        
       for(int i=0;i<=k;i++)
       {
          score=max(score,left[i]+right[n-k+i]);
       } 
        
        return score;
    }
};