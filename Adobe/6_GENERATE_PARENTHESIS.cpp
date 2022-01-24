/*
Generate Parentheses 
https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/
*/

vector<string>ans;

bool ispar(string &str)
{   
    stack<char>s;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else
        {
            if(s.empty())
                return false;
            char t = s.top();
            if(str[i]=='}'&&t=='{' || str[i]==')'&&t=='(' || str[i]==']'&&t=='[')
                s.pop();
            else
                return false;
        }
    }
    if(s.empty()==true)
        return true;
    return false;
}


void Generate(string &str,int open,int close)
{
    if(open==0 && close==0)
    {
        if(ispar(str))
            ans.push_back(str);
        return;
    }
    if(open>0)
    {
        string temp = str + "(";
        Generate(temp,open-1,close);
    }
    if(close>open)
    {
        string temp = str + ")";
        Generate(temp,open,close-1);
    }
}

vector<string> AllParenthesis(int n) 
{
    
    string str = "(";
    int open = n-1,close = n;
    Generate(str,open,close);
    return ans;
}
