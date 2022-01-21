/*Stock span problem 
next greater element on left : https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/
Stock span problem : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
https://www.youtube.com/watch?v=kCAMWbTCO1c
*/
vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n,0);
        stack<int>s;
        int i=0;
        
        while(i<n)
        {
            while(s.empty()==false && price[i]>=price[s.top()])
                s.pop();
            if(s.empty()==false)
            {
                ans[i] = (i - s.top());
            }
            else
            {
                ans[i] = i+1;
            }
            
            s.push(i);
            i++;
        }
        
        
        return ans;
    }
