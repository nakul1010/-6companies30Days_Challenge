/*Sorted subsequence of size 3 
https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/
*/
vector<int> find3Numbers(vector<int> arr, int n) 
{
    stack<int>s;
    vector<int>ans;
    
    for(int i=n-1; i>=0; i--)
    {
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        s.push(arr[i]);
        if(s.size()>=3)
            break;
    }
    if(s.size()>=3)
    {
        while(ans.size()!=3)
        {
            ans.push_back(s.top());
            s.pop();
        }
    }
    return ans;
}
