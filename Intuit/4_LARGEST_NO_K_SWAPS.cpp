/*Largest number in K swaps 
https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
*/

void max_no_after_swaps(string str,int n,int i,int k,string &max)
{
	if(k==0)
	{
		return;
	}
	for(;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(str[j]>str[i])
			{
				swap(str[i],str[j]);
				if (str.compare(max) > 0 ) //A value > 0 : if *this is longer than str or, first character that doesn't match is greater, grater than max
                    max = str;
				max_no_after_swaps(str,n,i+1,k-1,max);
				swap(str[i],str[j]);//imp 
			}
		}
	}
}
string findMaximumNum(string str, int k)
{
    string max = str;//for same no
    max_no_after_swaps(str,str.length(),0,k,max);
    return max;
}
