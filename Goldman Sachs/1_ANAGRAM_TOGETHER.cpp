/*1 - Print Anagrams Together 
I3 -> TRIE Love babbar
https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
*/
#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& arr) 
    {
        unordered_map<string,int>mp;
        unordered_map<string,int>::iterator itr;
        
        int max_ = 0;
        int n = arr.size();
        int ans[n];
        
        for(int i=0;i<n;i++)
        {
            string curr = arr[i];
            sort(curr.begin(),curr.end());
            if(mp.find(curr)!=mp.end())
            {
                int get = mp[curr];
                ans[i] = get;
            }
            else
            {
                mp.insert(make_pair(curr,max_));
                ans[i] = max_;
                max_++;
            }
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<i<<" : "<<ans[i]<<endl;
        
        vector<vector<string> >vec;
        
        for(int find=0;find<max_;find++)
        {
            vector<string>v;
            for(int i=0;i<n;i++)
            {
                if(ans[i]==find)
                {
                    v.push_back(arr[i]);
                }
            }
            vec.push_back(v);
        }
        
        return vec;
    }
};

