public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int ans;
    
    void merge(vector<long long>& arr, int left, int right, int end){
        vector<long long> temp;
        int i = left;
        int j = right;
        while(i<right && j<=end){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                ans += right - i;
                j++;
            }
        }
        if(i == right){
            while(j<=end){
                temp.push_back(arr[j]);
                j++;
            }
        }
        if(j == end+1){
            while(i<right){
                temp.push_back(arr[i]);
                i++;
            }
        }
        for(int k = left; k<=end; k++){
            arr[k] = temp[k-left];
        }
        return;
    }
    
    void mergeSort(vector<long long>& arr, int start, int end){
        if(start >= end) return;
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid+1, end);
        return;
    }
    
    long long int inversionCount(long long v[], long long n)
    {
        // Your Code Here
        vector<long long> arr(n);
        for(int i = 0; i<n; i++) arr[i] = v[i];
        ans = 0;
        mergeSort(arr, 0, n-1);
        return ans;
    }