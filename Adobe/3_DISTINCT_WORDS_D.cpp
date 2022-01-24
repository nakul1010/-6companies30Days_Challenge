/*Number of distict Words with k maximum contiguous vowels 
https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/#
*/

long long  dp[1001][1001], mod = 1000000007;
    
long long solve(int n,int cnt,int k)
{
    if(n==0)
        return 1;
    if(dp[n][cnt]!=-1)
        return dp[n][cnt]%mod;
    if(cnt==k)   
        return dp[n][cnt] = (21) * (solve(n-1,0,k)%mod) %mod;
    else
        return dp[n][cnt] = (
                            ((21) * (solve(n-1,0,k)%mod) %mod) + 
                            (5 * (solve(n-1,cnt+1,k)%mod) %mod)
                            %mod);
}

int kvowelwords(int N, int K) 
{
    memset(dp,-1,sizeof(dp));
    return solve(N,0,K)%mod;
}

