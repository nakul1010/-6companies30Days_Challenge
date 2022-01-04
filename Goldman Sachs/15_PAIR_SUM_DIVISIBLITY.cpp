/*15- Array Pair Sum Divisibility Problem 
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

IMP HELL POINTS
	- mod 0 keep diff
	- erase curr mod otherwise n=30 eg wrong
*/
#include<bits/stdc++.h>
using namespace std;

bool canPair(int arr[],int n,int k)
{
    int mod0=0;
    if(n%2==1)
        return false;
    if(k==1)
        return true;
	map<int,int>mp;
    map<int,int>::iterator itr;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]%k==0)
            mod0++;
        else
    		mp[arr[i]%k]++;
    //		arr[i] = arr[i]%k;
    }
    
    if(mod0%2!=0)
        return false;
    
//	 for(itr=mp.begin(); itr!=mp.end(); itr++)
//     {
//     	cout<<"key : "<<itr->first<<"   value : "<<itr->second<<endl;
//     }
    
    
    for(itr=mp.begin(); itr!=mp.end(); itr++)
    {
    	int curr_mod = itr->first;
    	int req_mod = k - curr_mod;
    	int times = itr->second;
    	
//    	cout<<"curr_mod : "<<curr_mod<<"    req_mod : "<<req_mod<<"    times : "<<times<<endl;
    	
		if(mp.find(req_mod)!=mp.end() && mp[req_mod]>=times)
    	{
    		mp[req_mod] = mp[req_mod] - times;
    		if(mp[req_mod]==0)
    			mp.erase(req_mod);
    	}
    	else
    	{
    		return false;
    	}
    	
    	mp.erase(curr_mod);
    }
    
    return true;
}

int main()
{
//	int arr[] = {13,11,9,3,7,1};//True
//	int k = 4;
	
//	int arr[] = {3,2,11,6,2,12};//False
//	int k = 12;
	
	
//	int arr[] = {14,10,1,1};//True
//	int k = 3;

//	int arr[] = {6,14,12,14};//True
//	int k = 2;
	
	int arr[]= { 8 ,11 ,14 ,13, 6, 11, 1, 4 ,2, 1, 1, 11, 2, 1, 2, 7, 14, 3, 1, 14, 3, 6, 12, 2, 9 ,5 ,11 ,3 ,1 ,3};
	int k =3;
	
//	int arr[] = {13,13,14,1};//True
//	int k = 2;
	
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	if(canPair(arr,n,k))
		cout<<"\nTrue";
	else
		cout<<"\nFalse";
		
	return 0;
}
