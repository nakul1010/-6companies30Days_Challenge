/*Winner of an election 
https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/
*/
 
vector<string> winner(string arr[],int n)//nlogn
{
    vector<string>ans;
    
    map<string,int>mp;
    map<string,int>::iterator it;
    
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    
    int max_votes = -1;
    for(it=mp.begin(); it!=mp.end(); it++)
        max_votes = max(max_votes, it->second);
    
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second == max_votes)
        {
            ans.push_back(it->first);
            ans.push_back(to_string(it->second));
            break;
        } 
    }
    return ans;
}	
