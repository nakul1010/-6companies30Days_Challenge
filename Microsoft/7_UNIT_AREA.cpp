/*
Unit Area of largest region of 1's 
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/
*/
int Max_Area(vector<vector<int>>& mat,vector<vector<int>>& visit,int i,int j,int n,int m)
{
    int row=n,col=m;
    if(i<0 || i>=row || j<0 || j>=col)
        return 0;
    if(visit[i][j]==1 || mat[i][j]==0)
        return 0;
    visit[i][j]=1;
    return 1 + Max_Area(mat,visit,i-1,j-1,n,m)
             + Max_Area(mat,visit,i-1,j,n,m)
             + Max_Area(mat,visit,i-1,j+1,n,m)
             
             + Max_Area(mat,visit,i,j-1,n,m)
             + Max_Area(mat,visit,i,j+1,n,m)
             
             + Max_Area(mat,visit,i+1,j-1,n,m)
             + Max_Area(mat,visit,i+1,j,n,m)
             + Max_Area(mat,visit,i+1,j+1,n,m);
}

int findMaxArea(vector<vector<int>>& mat) 
{
    
    int max_cnt=0,n=mat.size(), m=mat[0].size();
    vector<vector<int>>visit(n, vector<int>(m,0));
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visit[i][j]==0)
            {
               int cnt = Max_Area(mat,visit,i,j,n,m);
               max_cnt = max(max_cnt,cnt);
            }
        }
    }
    
    return max_cnt;
}
