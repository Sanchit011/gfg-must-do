public:
    //Function to find minimum number of pages.
    long long int minStudents(int arr[], int n, long long int val){
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
  
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m > n) return -1;
        long long int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        long long int low = 1;
        long long int hi = sum;
        long long int ans = hi;
        long long int mid;
        while(low <= hi){
            mid = low + (hi-low)/2;
            if(minStudents(arr, n, mid) <= m){
                ans = mid;
                hi = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }