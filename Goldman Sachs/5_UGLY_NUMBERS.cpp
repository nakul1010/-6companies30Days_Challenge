/*5- Ugly Numbers
https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
*/
ull getNthUglyNo(int n) 
{
    set<long long>s;
    set<long long>::iterator itr;
    s.insert(1);
    long long ele1,ele2,ele3;
    while(n!=1)
    {
        itr = s.begin();
        ele1 = (*itr) * 2;
        ele2 = (*itr) * 3;
        ele3 = (*itr) * 5;
        s.erase(itr);
        
        s.insert(ele1);
        s.insert(ele2);
        s.insert(ele3);
        n--;
    }
    return *s.begin();
}
