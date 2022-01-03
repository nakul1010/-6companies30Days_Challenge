/*11 - Find Missing And Repeating 
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
*/
int *findTwoElement(int *arr, int n) 
{
    int *store = new int[2];
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.empty()==false && s.find(arr[i])!=s.end())
        {
            store[0] = arr[i];
        }
        s.insert(arr[i]);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(s.find(i)==s.end())
        {
            store[1] = i;
            break;
        }
    }
    return store;
}
