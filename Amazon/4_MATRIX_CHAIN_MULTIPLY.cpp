/*
Brackets in Matrix Chain Multiplication 
https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/
60 b DP
*/
#include<bits/stdc++.h>
using namespace std;
//_______________________________________________________________________________________________________________________________________________________________
int matrix_chain_multiply(int arr[],int n)
{
	int dp[n-1][n-1];
	memset(dp,0,sizeof(dp));
	int n1 = n-1;//5
	
//	for(int i=0;i<n1;i++)
//	{
//		dp[i][i]=0;
//	}
//	for(int i=0;i<=3;i++)
//	{
//		dp[i][i+1] = arr[i]*arr[i+1]*arr[i+2];
//	}

	for(int g=0; g<n1; g++)//gap startegy
	{
		for(int i=0,j=g; j<n1; i++,j++)
		{
			if(g==0)
				dp[i][j] = 0;
			else if(g==1)
				dp[i][j] = arr[i]*arr[j]*arr[j+1];
			else
			{
				dp[i][j] = INT_MAX;
				for(int k=i;k<j;k++)//k=i an not zero remember
				{
					int left = dp[i][k];
					int right = dp[k+1][j];
					int n1 = arr[i] * arr[k+1] * arr[j+1];//multiplication cost
					int tc = left + right + n1;//left cost + right cost + mul cost
					dp[i][j] = min(dp[i][j],tc);
				}
			}
		}
	}
	

//	for(int i=0;i<n1;i++)
//	{
//		for(int j=0;j<n1;j++)
//		{
//			cout<<dp[i][j]<<"  ";
//		}
//		cout<<"\n";
//	}
	return dp[0][n-2];
}
//_______________________________________________________________________________________________________________________________________________________________
int main()
{
//	int arr[] = {10,20,30,40,50,60};
	int arr[] = {40, 20, 30, 10, 30};//2600
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"\n\nAns : "<<matrix_chain_multiply(arr,n);
	return 0;
}
//_______________________________________________________________________________________________________________________________________________________________
