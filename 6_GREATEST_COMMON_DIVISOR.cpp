/*6)Greatest Common Divisor of Strings
https://leetcode.com/problems/greatest-common-divisor-of-strings/
For string array : https://www.geeksforgeeks.org/program-to-find-greatest-common-divisor-gcd-of-n-strings/
*/
#include<bits/stdc++.h>
using namespace std;
//__________________________________________________________________________________________________________________________________________________________
string gcdOfStrings(string str1, string str2) 
{
	if(str1.length() < str2.length())//keep str1 highest for last else
		return gcdOfStrings(str2,str1);
	
	else if(str1.find(str2) != 0)// If str1 is not the concatenation of str2
        return "";
    
    else if(str2=="")//GCD string found
    	return str1;

    else//Cut off the common prefix part of str1 & then recur
    	return gcdOfStrings(str1.substr(str2.length()), str2);
}
//__________________________________________________________________________________________________________________________________________________________
int main()
{
//	string str1 = "ABCABC", str2 = "ABC";//ABC
	string str1 = "ABABAB", str2 = "ABAB";//AB
//	string str1 = "LEET", str2 = "CODE";//""

//	string str1 = "nakul", str2 = "bcd";//AB
	
	cout<<str1.substr(str2.length());//from n2 till end
//	cout<<gcdOfStrings(str1,str2);
	return 0;
}
//__________________________________________________________________________________________________________________________________________________________
