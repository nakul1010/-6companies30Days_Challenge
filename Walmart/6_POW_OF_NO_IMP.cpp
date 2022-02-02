/*
Power Of Numbers 
https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/
*/

long long solve(int x,int n)//logn 
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    long long temp = solve(x,n/2)%mod;
    temp = (temp*temp)%mod;
    if(n%2==0)
        return (temp)%mod;
    else
        return  (temp*x)%mod;
}

long long power(int x,int n)
{
    return solve(x,n)%mod;
}
