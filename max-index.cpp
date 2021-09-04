public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        int ans = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i = 1; i<n; i++){
            left[i] = min(left[i-1], arr[i]);
        }
        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1], arr[i]);
        }
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            if(left[i] > right[j]){
                i++;
            }
            else{
                ans = max(ans, j-i);
                j++;
            }
        }
        return ans;
    }