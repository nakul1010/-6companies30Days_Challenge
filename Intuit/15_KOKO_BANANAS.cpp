/*Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas/
*/
ool solve(vector<int>& arr,int n,int h,int mid)
{
    int cnt=0;
    for(int  i=0;i<n;i++)
    {
        if(arr[i]<=mid)
        {
            cnt++;
        }   
        else if(arr[i]%mid == 0)
        {
            cnt += arr[i]/mid;
        }
        else
        {
            cnt = cnt + (arr[i]/mid) + 1;
        }
    }
    if(cnt<=h)
        return true;
    return false;
}

int minEatingSpeed(vector<int>& arr, int h) 
{
    int  start=0,end=0,ans=INT_MAX,prev_mid=-1,mid,n;
    n=arr.size();
    for(int i=0;i<n;i++)
    {
        end = max(end,arr[i]);
        // end += arr[i];//overflow error
    }
    
    while(start<=end)//imp <=
    {
        mid = (start+end)/2;
        
        if(mid>0 && solve(arr,n,h,mid))
        {
            // cout<<"mid : "<<mid<<"   True";
            ans = min(ans,mid);
            end = mid-1;
        }
        else
        {
            // cout<<"mid : "<<mid<<"   False";
            start = mid+1;
        }
        if(prev_mid == mid)
            break;
        prev_mid=mid;
    }
    return ans;
}
