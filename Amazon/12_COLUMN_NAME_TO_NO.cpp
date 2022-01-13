/*Column name from a given column number 
https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#
I1 & I2 --> Amazon Math
*/
string colName (long long int n)
    {
        string str = "";
        
        while(n>0)
        {
            int rem = n%26;
            
            // cout<<n<<" : "<<rem<<" : "<<char((rem-1) + 'A')<<endl;
            if(rem==0)
            {
                str = 'Z'+str;
                n--;
            }
            else
                str = char((rem-1) + 'A') + str;
            n = n/26;
        }
        
        return str;
    }
