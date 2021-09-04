public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr, arr+n);
        int ans = 0;
        for(int i = 0; i<n-2; i++){
            int k = i+2;
            for(int j = i+1; j<n-1; j++){
               while(k<n && arr[k] < arr[i] + arr[j]) k++;
               if(k > j) ans += k - 1 - j;
            }
        }
        return ans;
    }