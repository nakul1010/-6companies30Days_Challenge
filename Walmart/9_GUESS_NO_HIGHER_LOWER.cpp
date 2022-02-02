/*Guess Number Higher or Lower II
https://leetcode.com/problems/guess-number-higher-or-lower-ii/

In this question we have to find the minimum amount of money required to win the game given some constraints. So this problem can easily be broken into 
subproblems. For each of the number between 1-n we will consider the case where this number is choosen by the player first and we will always consider this
 as a wrong choice. For example when n = 10 and the player guess the 1 as the first number then cost is 1 and again he have to choose from the range of 2-10.
  So to generalize this

1....... i........ n. Suppose i is any number between 1 to n. Then if player choose i as first number (which we will consider as wrong choice because we
want to consider the worst case to find our answer), then we will be left with two choice either our answer is in range (1..... i-1) or (i+1 ..... n).
So we have to consider max amoung these two cases. If this sounds confusing then see the explanation below for n= 3

Min of max
*/
int dp[201][201];

int solve(int low,int high)
{
    if(low>high) return -1;
    
    if(low==high) return 0;
    
    if(dp[low][high]!=-1) return dp[low][high];
    
    int pocket = INT_MAX;
    for(int dollar=low; dollar<=high; dollar++)
    {
        pocket = min(pocket, dollar + max(solve(low,dollar-1),solve(dollar+1,high) ));
    }
    return dp[low][high] = pocket;//from 1 -> 4 which will me min pivot
}

int getMoneyAmount(int n) 
{
    if(n==1)
        return 0;
    memset(dp,-1,sizeof(dp));
    return solve(1,n);
}
