/*Subarray with given sum 
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
*/
vector<int> subarraySum(int arr[], int n, long long s)
{
    vector<int>ans;
    long long sum = 0; 
    int low=0,high=0;
    
    while(high<n)
    {
        sum += arr[high];
        while(sum > s)
        {
            sum -= arr[low];
            low++;
        }
        if(sum == s)
        {
            ans.push_back(low+1);
            ans.push_back(high+1);
            break;
        }
        high++;
    }
    
    if(ans.size()==0 && sum == s)
    {
        ans.push_back(low+1);
        ans.push_back(high+1);
    }
    if(ans.size()==0)
        ans.push_back(-1);
    return ans;
}
