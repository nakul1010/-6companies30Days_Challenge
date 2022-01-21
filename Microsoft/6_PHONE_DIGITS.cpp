/*Possible Words From Phone Digits 
https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
*/
void find_combination(vector<char> keypad[], int input[],int n,string str,vector<string> &ans)
{
	if(n==-1)
	{
	   // cout<<str<<" , ";
	    ans.push_back(str);
		return;
	}
	
	int digit = input[n];
	int len = keypad[digit].size();
	
	for(int i=0;i<len;i++)
	{
		find_combination(keypad, input, n-1 , keypad[digit][i]+str, ans);//if ulta not work str+keypad[digit][i]
	}
}
//Function to find list of all words possible by pressing given numbers.
vector<string> possibleWords(int input[], int n)
{
    vector<string> ans;
	vector<char> keypad[] =
    {
        {}, {},        // 0 and 1 digit don't have any characters associated
        { 'a', 'b', 'c' },//2
        { 'd', 'e', 'f' },//3
        { 'g', 'h', 'i' },//4
        { 'j', 'k', 'l' },//5
        { 'm', 'n', 'o' },//6
        { 'p', 'q', 'r', 's'},//7
        { 't', 'u', 'v' },//8
        { 'w', 'x', 'y', 'z'}//9
    };
 
 	string str = "";
 	find_combination(keypad, input, n-1 , str,ans);
 	sort(ans.begin(),ans.end());
 	return ans;
}
