/*Stone Game
https://leetcode.com/problems/stone-game/
Similar to I7 Adobe
*/

int dp[501][501];

int Stone_Game(vector<int>&arr,int n,int s,int e)
{
    if(s>e)
        return 0;
    if(s==e)
        return arr[s];
    if(dp[s][e]!=-1)
        return dp[s][e];
    int pick_first = arr[s] + min(Stone_Game(arr,n,s+2,e) , Stone_Game(arr,n,s+1,e-1));
    int pick_last = arr[e] + min(Stone_Game(arr,n,s,e-2) , Stone_Game(arr,n,s+1,e-1));
    
    return dp[s][e] = max(pick_first,pick_last);
}

bool stoneGame(vector<int>& arr) 
{
    memset(dp,-1,sizeof(dp));
    int n = arr.size();
    int total_stones = 0;
    for(int i=0;i<n;i++)
        total_stones+=arr[i];
    
    int alice = Stone_Game(arr,n,0,n-1);
    int bob = total_stones - alice;
    if(alice>bob)
        return true;
    return false;
}
