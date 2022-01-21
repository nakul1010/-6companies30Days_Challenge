/*Minimum steps to destination 
https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
*/

    int dp[10001][10001];
    int Min_Steps(int start,int &dest,int i,int steps)
    {
        if(dest==start)
            return steps;
        if(abs(start) > dest)
            return INT_MAX;
        if(dp[i][abs(start)]!=-1)
            return dp[i][abs(start)];
            
        int pos = Min_Steps(start+i,dest,i+1,steps+1);
        int neg = Min_Steps(start-i,dest,i+1,steps+1);
        
        return dp[i][abs(start)] = min(pos,neg);
    }
    
    int minSteps(int D)
    {
        memset(dp,-1,sizeof(dp));
        int i = 1, start = 0, dest = D, steps = 0;
        return Min_Steps(start,dest,i,steps);
        // return steps;
    }
