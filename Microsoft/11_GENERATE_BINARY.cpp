/*
Generate Binary Numbers 
https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/#
*/

//___________________________________________________________________________________________________________________________________________________________
//BRUT FORCE TC:nlogn
string get_binary(int n)//logn
{
    string str = "";
    while(n)
    {
        str = to_string(n%2) + str;
        n = n/2;
    }
    return str;
}

vector<string> generate(int n)
{
	vector<string>ans;
	for(int i=1; i<=n; i++)//n
	{
	    string str = get_binary(i);
	    ans.push_back(str);
	}	
	return ans;
}
//___________________________________________________________________________________________________________________________________________________________

vector<string> generate(int n)
{
	vector<string>ans;
	queue<string>q;
	q.push("1");
	for(int i=1; i<=n; i++)
	{
	    string str = q.front();
	    q.pop();
	    ans.push_back(str);
	    
	    q.push(str + "0");
	    q.push(str + "1");
	}
	
	return ans;
}

