long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    if(x == 1) return 1;
    if(x == 2 || x == 3) return 1;
    if(x == 4) return 2;
    long long int low = 1;
    long long int hi = x/2;
    long long int mid;
    long long ans = 1;;
    while(low <= hi){
        mid = low + (hi - low)/2;
        if(mid*mid == x){
            ans = mid;
            break;
        }
        if(mid*mid < x){
            low = mid+1;
            ans = mid;
        }
        else{
            hi = mid-1;
        }
    }
    return ans;
}