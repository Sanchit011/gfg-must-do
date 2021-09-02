int Search(vector<int> arr, int k) {
    //code here
    int low = 0;
    int hi = arr.size() - 1;
    int mid;
    while(low <= hi){
        mid = low + (hi-low)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] >= arr[low]){
            if(arr[mid]>k && arr[low]<=k) hi = mid-1;
            else low = mid+1;
        }
        else{
            if(arr[mid]<k && arr[hi]>=k) low = mid+1;
            else hi = mid-1;
        }
    }
    return -1;
}