/*
IPL 2021 - Match Day 2 - Sliding Window
https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#
*/
vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
{
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        while(dq.empty()==false && arr[i]>arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    
    for(int i=k; i<n; i++)
    {
        if(dq.front()==i-k)
            dq.pop_front();
        while(dq.empty()==false && arr[i]>arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    
    }
    return ans;
}
