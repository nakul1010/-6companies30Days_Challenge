/*
Next higher palindromic number using the same set of digits 
https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/
*/

string nextPermutation(int n, string arr)
{
	int index1=-1,index2=-1,i,j;
	
	for(i=n-1;i>0;i--)
	{
		if(arr[i]>arr[i-1])
			break;
	}
	if(i!=0)
	{
		for(j=n-1;j>=i;j--)	
		{
			if(arr[j]>arr[i-1])
			{
				break;
			}
		}
		swap(arr[j],arr[i-1]);
		
	    sort(arr.begin()+i,arr.end());//sort or reverse both works
	}
	return arr;
}
//____________________________________________________________________________________---
string nextPalin(string str)
{
    int n = str.length()        ;
    string first = "",final="",second="";
    for(int i=0; i<n/2; i++)
    {
        first = first + str[i];
    }
    
    // cout<<"first : "<<first<<endl;
    first = nextPermutation(first.length(),first);
    second = first;
    reverse(second.begin(),second.end());
    // cout<<"first : "<<first<<endl;
    
    if(n%2==0)
        final = first + second;
    else
        final = first + str[n/2] + second;
    
    if(final == str)
        return "-1";
    return final;
}
