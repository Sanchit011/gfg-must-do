public:
  
    long long int minPainters(int arr[], int n, long long int val){
        long long int count = 1;
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum > val){
                count++;
                sum = arr[i];
                if(sum > val) return INT_MAX;
            }
        }
        return count;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long int low = 1;
        long long int hi = 0;
        for(int i = 0; i<n; i++) hi += arr[i];
        long long int mid;
        long long int ans = hi;
        while(low <= hi){
            mid = low + (hi-low)/2;
            if(minPainters(arr, n, mid) <= k){
                ans = mid;
                hi = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }