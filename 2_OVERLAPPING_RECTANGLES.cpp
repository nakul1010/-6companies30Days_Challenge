/*2 - Overlapping rectangles 
https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
https://www.youtube.com/watch?v=UUjeqglXaSQ
*/
int doOverlap(int L1[], int R1[], int L2[], int R2[]) 
{
    int x1 = L1[0], y1=L1[1]; 
    int x2 = R1[0], y2=R1[1];
    
    
    int x3 = L2[0], y3=L2[1]; 
    int x4 = R2[0], y4=R2[1];
    
    if(x2>=x3 && y3>=y2 && x4>=x1 && y1>=y4)
        return 1;
    return 0;
    
}

