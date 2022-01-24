/*Partition Equal Subset Sum 
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/
    int dp[101][1001];
//________________________________________________________________________________________________________________________________________________________________
    bool partition(int arr[],int n,int sum)
    {
    	if(n<0 || sum<0)
    		return false;
    	if(sum==0)
    		return true;
    	
    	if(dp[n][sum]!=-1)
    	    return dp[n][sum];
    	    
    	bool incl = partition(arr,n-1,sum-arr[n]);
    	bool excl = partition(arr,n-1,sum);
    	
    	if(incl || excl)
    	{
    	    dp[n][sum] = 1;
    	    return true;
    	}
    		
    	else
    	{
    	    dp[n][sum] = 0;
    	    return false;
    	}
    		
    }
//________________________________________________________________________________________________________________________________________________________________
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
		for(int i=0;i<n;i++)
			sum+=arr[i];
    		
    	if(sum%2!=0)
    	{
    		return 0;
    	}
    	else
    	{
    	    memset(dp,-1,sizeof(dp));
    		sum = sum/2;
    		if(partition(arr,n-1,sum))	
    			return 1;
    		else	
    			return 0;
    	}
	    return 0;
    }
