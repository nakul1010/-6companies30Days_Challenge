/*Total Decoding Messages 
https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/
*/
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int dp[10001];
int recur_ways(string &str,int n,int index) 
{
    if(index==n)
    {
        return  1;
    }
    
    if(dp[index]!=-1)
        return dp[index];
        
    int curr_cnt = 0;
    for(int i=index; i<n&&i<index+2; i++)//3 digit number will be greater than 26
    {
        int curr_no = stoi(str.substr(index, abs(index-i)+1));   
        if(curr_no<=26 && curr_no!=0)
        {
            curr_cnt = (curr_cnt + (recur_ways(str,n,index+abs(index-i)+1)%mod))%mod;
        }
        else
            break;
    }
    return dp[index] = curr_cnt%mod;
}

int CountWays(string str)
{
    memset(dp,-1,sizeof(dp));
    return (recur_ways(str,str.length(),0))%mod;
}

int main()
{
	cout<<CountWays("123");
	return 0;
}
