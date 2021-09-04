public:
    int countTriplets(int arr[], int n, int l, int r) {
        // code here
        sort(arr, arr+n);
        int left = 0;
        int right = 0;
        int k;
        for(int i = 0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(k>j){
                if(arr[i] + arr[j] + arr[k] >= l){
                    k--;
                }
                else{
                    left += k-j;
                    j++;
                }
            }
        }
        for(int i = 0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(k>j){
                if(arr[i] + arr[j] + arr[k] > r){
                    k--;
                }
                else{
                    right += k-j;
                    j++;
                }
            }
        }
        int ans = right - left;
        return ans;
    }