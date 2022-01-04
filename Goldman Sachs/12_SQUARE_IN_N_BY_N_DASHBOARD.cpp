/*12 - Squares in N*N Chessboard 
https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1
*/
long long squaresInChessBoard(long long n) 
{
    long long sqrs = 0;
   
    while(n!=0)
    {
        sqrs = sqrs + (n*n);
        n--;
    }
    
    return sqrs;
}
