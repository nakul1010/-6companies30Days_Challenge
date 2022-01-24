/*
Pots of Gold Game / Similar to Covid and Beds problem
https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/
*/
int dp[501][501];
int solve(vector<int>&arr,int first,int last)
{
    if(first==last)
        return arr[first];
    if(first>last)
        return 0;
    
    if(dp[first][last]!=-1)     
        return dp[first][last];
    
    int pick_first = arr[first] + 
                    min(solve(arr,first+2,last),solve(arr,first+1,last-1));
    
    int pick_last = arr[last]  +
                    min(solve(arr,first,last-2),solve(arr,first+1,last-1));
    
    
    return dp[first][last] = max(pick_last, pick_first);
}

int maxCoins(vector<int>&arr,int n)
{
    memset(dp,-1,sizeof(dp));
    return solve(arr,0,n-1);
}
