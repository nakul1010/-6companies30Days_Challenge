/*Implement Atoi 
https://practice.geeksforgeeks.org/problems/implement-atoi/1/#
Or implement with num = num*10 + int(str[i]-'0') and check for conditions of minum plus atlast multiply by -1 if bool minus == true;
*/
int atoi(string str) 
{
    int n = str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]>='0' && str[i]<='9')
            continue;
        else if(str[0] == '-' || str[0] == '+')
            continue;
        else
            return -1;
    }
    return stoi(str);
}
