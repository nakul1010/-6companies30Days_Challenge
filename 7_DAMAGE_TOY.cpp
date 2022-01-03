/*7 - Kid that gets the damaged toy
https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1

n=2403 , m=20802, k=826 op=2403
n=1 , m=1, k=1 op=1
n=5 , m=2, k=1 op=2
n=5 , m=8, k=2 op=4
*/
int findPosition(int n , int m , int k) 
{
    while(m>n)
    {
        m = m-n;
    }
    m--;
    // cout<<(m+k)<<endl;
    if((m+k)%n==0)
        return n;
    return (m+k)%n;
}
