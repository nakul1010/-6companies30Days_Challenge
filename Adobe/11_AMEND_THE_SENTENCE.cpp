/*
Amend The Sentence 
https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1
*/
string amendSentence (string str)
{
    string ans = "", token= "";
    token = str[0];
    int n = str.length();
    
    for(int i=1;i<n;i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            ans = ans + token + ' ';
            token = str[i];
        }
        else
        { 
            token += str[i];
        }
    }
    if(token.empty()==false)
    {    
        ans = ans + token + ' ';
    }
    ans.pop_back();
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);//not is lower

    return ans;
}
