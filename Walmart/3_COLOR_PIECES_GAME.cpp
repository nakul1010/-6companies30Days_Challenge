/*Remove Colored Pieces if Both Neighbors are the Same Color
https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
*/
bool winnerOfGame(string str) 
{
    int n = str.size();
    int cnt_a=0,cnt_b=0;
    for(int i=1; i<n-1; i++)
    {
        if(str[i]=='A'&&str[i+1]=='A'&&str[i-1]=='A')
            cnt_a++;
        if(str[i]=='B'&&str[i+1]=='B'&&str[i-1]=='B')
            cnt_b++;
    }
    if(cnt_a>cnt_b)
        return true;
    else
        return false;
}
