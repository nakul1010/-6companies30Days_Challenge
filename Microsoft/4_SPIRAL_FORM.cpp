/*Spiral Form
https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
*/
vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        vector<int>ans;
        
        int k=0,l=0,m=r,n=c;
        
        while(m>k && n>l)
        {
            for(int i=l;i<n;i++)
                ans.push_back(mat[k][i]);
            k++;
            
            for(int i=k;i<m;i++)
                ans.push_back(mat[i][n-1]);
            n--;
            
            if(m>k)
            {
                for(int i=n-1; i>=l; i--)
                    ans.push_back(mat[m-1][i]);
                m--;
            }
            if(n>l)
            {
                for(int i=m-1; i>=k; i--)
                    ans.push_back(mat[i][l]);
                l++;
            }
        }
        return ans;
    }
