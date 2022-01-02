/*4 - Run Length Encoding 
https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
*/

string encode(string str)
{
    int n = str.length();
    string ans = "";
    
    int curr_cnt = 0;
    char curr_char = str[0];
    for(int i=0;i<n;i++)
    {
        if(str[i]==curr_char)
        {
            curr_cnt++;
        }
        else
        {
            ans += curr_char + to_string(curr_cnt);
            curr_char = str[i];
            curr_cnt = 1;
        }
    }
    ans += curr_char + to_string(curr_cnt);
    return ans;
}     
 
