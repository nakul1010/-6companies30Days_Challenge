/*
Longest Mountain
https://leetcode.com/problems/longest-mountain-in-array/
*/
#include<bits/stdc++.h>
using namespace std;


int longestMountain(int arr[],int n) 
{
    int store,ans=0;
    int up[n];
    int down[n];
    memset(up,0, sizeof(up));
    memset(down,0, sizeof(down));
    
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]>arr[i+1])
            down[i] = down[i+1]+1;
    }
    for(int i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1])
            up[i] = up[i-1]+1;
    }
    
    for(int i=0;i<n;i++)
    {
    	if(up[i]&&down[i])
        	ans = max(ans, (up[i]+down[i]+1));
    }
    return ans;
}
    
int main()
{
//	int arr[] = {2,1,4,7,3,2,5};//5
	int arr[] = {2,2,2};//0
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<longestMountain(arr,n);
	return 0;
}
