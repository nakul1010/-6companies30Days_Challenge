/*First non-repeating character in a stream 
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
*/
string FirstNonRepeating(string str)
{
    queue<int>q;
    int arr[26] = {0};
    int n = str.size();
    for(int i=0; i<n; i++)
    {
        arr[(str[i]-'a')]++;
        
        if(arr[(str[i]-'a')] == 1)
            q.push(str[i]);
        
        while(q.empty()==false && arr[q.front()-'a']!=1)
            q.pop();
        
        if(q.empty())    
        {
            str[i] = '#';
          //  ans = ans + '#';
        }
            
        else
        {
            str[i] = q.front();//(char)q.front()
          //  ans = ans + (char)q.front();
        }
            
    }
    return str;
  //  return ans;
}

