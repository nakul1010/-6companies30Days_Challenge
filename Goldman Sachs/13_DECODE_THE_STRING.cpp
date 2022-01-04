/*Decode the string 
https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
Recur
*/
#include<bits/stdc++.h>
using namespace std;
//________________________________________________________________________________________________________________________________________________
string Decode_String(string str,int n,int &i)//imp &i otherwise answer wrong
{
	string result;
	cout<<"i : "<<i<<endl;
	while(i<n && str[i]!=']')
	{
		if(isdigit(str[i]))
		{
			int number = 0;
			while(i<n && isdigit(str[i]))
			{
				number = (number*10) + (str[i]-'0');
				i++;
			}
			i++;//skip [
			string got = Decode_String(str,n,i);
			cout<<"number : "<<number<<"    got : "<<got<<endl;
			for(int j=0;j<number;j++)
				result = result + got;
			cout<<"result : "<<result<<endl;
			i++;
		}
		else
		{
			result = result + str[i];
			i++;
		}
	}
	return result;
}

//________________________________________________________________________________________________________________________________________________
int main()
{
	string str = "3[b2[ca]]";//bcacabcacabcaca
//	string str = "ab3[a2[bc]d]cd";//a bccd bccd
	
	int i=0;
	cout<<Decode_String(str,str.length(),i);
//	cout<<decodeString(str,i);
	return 0;
}
//________________________________________________________________________________________________________________________________________________
