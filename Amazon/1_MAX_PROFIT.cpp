/*
Maximum Profit DP
https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
*/
int max_profit(int arr[],int n,int k)
{
	int dp[k+1][n]; 
	memset(dp,0,sizeof(dp));
	int ans= 0;
	
	for(int i=1;i<=k;i++)
	{
		for(int j=1; j<n; j++)
		{
			int completed = dp[i][j-1];
			int max_ = 0;
			for(int l=0;l<j;l++)
			{
				int diff = (arr[j] - arr[l]) + dp[i-1][l];
				max_ = max(max_,diff);
			}
			dp[i][j] = max(max_,completed);
			ans = max(ans,dp[i][j]);
		}
	}
	return ans;
}
int maxProfit(int k, int n, int arr[])
{
    return max_profit(arr,n,k);
}
