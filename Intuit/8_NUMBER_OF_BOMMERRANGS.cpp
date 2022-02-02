/*447. Number of Boomerangs
https://leetcode.com/problems/number-of-boomerangs/
d = sqrt(( y2 –  y1)² + ( x1 –  x2)²)
*/
#include<bits/stdc++.h>
using namespace std; 


bool check(int i,int j,int k)
{
    if(i==j || i==k || j==k)
        return false;
    return true;
}

int numberOfBoomerangs_TLE(vector<vector<int>>& arr)//TLE
{
    int n = arr.size() ,cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(check(i,j,k))
                {
                     int dist1 = ((arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])) + 
                                 ((arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]))  ;
                    
                     int dist2 = ((arr[i][0] - arr[k][0]) * (arr[i][0] - arr[k][0])) + 
                                 ((arr[i][1] - arr[k][1]) * (arr[i][1] - arr[k][1]))  ;
                
                     if(dist1 == dist2)
                        cnt++;
                }
            }
        }
    }
    return cnt;
}
    
int numberOfBoomerangs(vector<vector<int>>& arr) 
{
    int n = arr.size() ,cnt = 0;
    unordered_map<int,int>mp;
    unordered_map<int,int>::iterator it;
    if(n==1)
        return cnt;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                continue;
            
            int distance = ((arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])) + 
                     ((arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]))  ;
            mp[distance]++;    
        }
        // cout<<i<<endl;
	    for(it=mp.begin(); it!=mp.end(); it++)
	    {
	        int distance = it->first;
	        int curr_cnt = it->second;
	        // cout<<"distance : "<<distance<<"     curr_cnt : "<<curr_cnt<<endl;
	        cnt += curr_cnt * (curr_cnt-1);
	    }
        mp.clear();//very_imp 
    }
    
    return cnt;
}
int main()
{
	
	return 0;
}
