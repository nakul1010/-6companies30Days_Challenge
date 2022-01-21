/*Minimum sum partition 
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
2d array didn't Work out*/
 int Partition(int arr[],int n,int total_sum,int sum, vector<vector<int>>&dp)
    {
        if(n==-1)    
        {
            return abs((total_sum-sum)-sum);
        }
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        int ans1 = Partition(arr,n-1,total_sum,sum,dp);
        int ans2 = Partition(arr,n-1,total_sum,arr[n]+sum,dp);
        return dp[n][sum] = min(ans1,ans2);
    }
    
	int minDifference(int arr[], int n)  
	{ 
	    int total_sum = 0;
	    for(int i=0;i<n;i++) total_sum+=arr[i];
	    
	    vector<vector<int>> dp(n+1, vector<int>(total_sum+1, -1));

	    return Partition(arr,n-1,total_sum,0,dp);
	}

