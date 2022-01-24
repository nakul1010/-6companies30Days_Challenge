/*Longest Arithmetic Progression 
https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/
https://www.youtube.com/watch?v=Lm38EAoDc7c
*/
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestAP(int arr[], int n) 
{
    if(n<=2)
        return n;
    int max_length = 2;
    vector< unordered_map<int,int> >dp(n);//vec of map, [val][diff] = length
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int diff = arr[j]-arr[i];
            
            if(dp[i].find(diff)!=dp[i].end())
                dp[j][diff] = dp[i][diff] + 1;
            else
                dp[j][diff] = 2;
            max_length = max(max_length, dp[j][diff]);
        }
    }
    return max_length;
}

int main()
{
	int n = 5;
	vector< map< int, int > >vec(n);
	map<int,int>::iterator it;
	for(int i=0; i<n; i++)	
	{
		vec[i][i+0] = i+1;
		vec[i][i+1] = i+2;
		vec[i][i+2] = i+3;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<"\tvec of : "<<i<<endl;
		for(it=vec[i].begin(); it!=vec[i].end(); it++)
			cout<<it->first<<" : "<<it->second<<endl;
	}
	return 0;
}
