/*Stickler Thief 
https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/#
*/
int dp[10001];
int stickler_thief(int arr[],int i)
{
    if(i<0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int gain = arr[i] + stickler_thief(arr,i-2);
    int skip = stickler_thief(arr,i-1);
    return dp[i] = max(gain,skip);
}
//Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n)
{
    memset(dp,-1,sizeof(dp));
    return stickler_thief(arr,n-1);
}
