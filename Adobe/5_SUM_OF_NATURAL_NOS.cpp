/*
Express as sum of power of natural numbers 
https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
*/
long long dp[1001][1001] , mod = 1000000007;

long long countWaysUtil(int x, int n, int num)
{
    long long val = (x - pow(num, n));
    if (val == 0)
        return 1;
    if (val < 0)
        return 0;
    
    if(dp[num][val]!=-1)
        return dp[num][val]%mod;
    return dp[num][val] = (countWaysUtil(val, n, num + 1)%mod +
           countWaysUtil(x, n, num + 1)%mod)%mod;
}

int numOfWays(int n, int x)
{
    memset(dp,-1,sizeof(dp));
    return countWaysUtil(n, x, 1)%mod;
}
