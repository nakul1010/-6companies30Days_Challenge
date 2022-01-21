/*Find All Four Sum Numbers 
https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
*/
vector<vector<int> > fourSum(vector<int> &arr, int k) 
{
    unordered_set<string>s;
    vector< vector<int> >ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if(n==0)
        return ans;
    for(int i=0; i<n-3;i++)
    {
        for(int j=i+1; j<n-2;j++)
        {
            int low = j+1;
            int high = n-1;
            while(low<high)
            {
                int sum = arr[i] + arr[j] + arr[low] + arr[high];
                
                if(sum<k)
                    low++;
                else if(sum>k)
                    high--;
                else
                {
                    string str = to_string(arr[i])+to_string(arr[j])+to_string(arr[low])+
                                to_string(arr[high]);
                    
                    if(s.find(str)==s.end())
                    {
                        vector<int>vec;
                        vec.push_back(arr[i]);
                        vec.push_back(arr[j]);
                        vec.push_back(arr[low]);
                        vec.push_back(arr[high]);
                        ans.push_back(vec);    
                    }
                    low++,high--;
                    
                    s.insert(str);
                }
            }
        }
    }
    return ans;
}
