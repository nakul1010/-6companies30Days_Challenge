/*Leaders in an array 
https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/
*/
vector<int> leaders(int arr[], int n)
{
    vector<int>ans;
    stack<int>s;
    int i = n-1;
    while(i>=0)
    {
        while(s.empty()==false && arr[i]>=arr[s.top()])
            s.pop();
        
        if(s.empty())
            ans.push_back(arr[i]);
            
        s.push(i);
        i--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
