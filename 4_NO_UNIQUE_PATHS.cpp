/*Number of Unique Paths 
https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/
*/
int dp[16][16];
int solve(int n,int m,int x,int y,int &ans)
{
    if(x==n && y==m)
    {
        return 1;
    }
    if(x>n || y>m || x<0 || y<0)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    return dp[x][y] = solve(n,m,x+1,y,ans) + solve(n,m,x,y+1,ans);
}
//Function to find total number of unique paths.
int NumberOfPath(int n, int m)
{
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    return solve(n,m,1,1,ans);
}
