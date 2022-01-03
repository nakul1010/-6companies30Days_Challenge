/*Count the subarrays having product less than k 
https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

imp tc
4 8
55 100 33 61

o/p if abs used
start : 1    end : 0    product : 1
start : 2    end : 1    product : 1
start : 3    end : 2    product : 1
start : 4    end : 3    product : 1
cnt = 8

2ptr appraoch
*/

int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) 
{
    long long product = 1,cnt = 0,start=0,end=0;
    
    while(end<n)
    {
        product = product * arr[end];
        while(product>=k)
        {
            // product /= arr[start++];
            product = product / arr[start];
            start++;
        }
        // cnt += end-start+1;
        
        // cout<<"start : "<<start<<"    end : "<<end<<"    product : "<<product<<endl;
        // cnt = cnt + abs(end-start)+1;//wrong for tc in dev-c++
        
        cnt += end-start + 1;
        end++;
    }
    // cout<<endl;
    return cnt;
}
