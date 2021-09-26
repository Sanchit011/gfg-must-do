int ternarySearch(int arr[], int n, int k) 
    { 
       // Your code here
       int low = 0;
       int hi = n-1;
       int mid1;
       int mid2;
       while(low<=hi){
           mid1 = low + (hi-low)/3;
           mid2  = low + ((hi-low)*2)/3;
           if(arr[mid1] == k || arr[mid2] == k) return 1;
           if(arr[mid1] > k){
               hi = mid1-1;
           }
           else if(arr[mid2] < k){
               low = mid2+1;
           }
           else{
               low = mid1+1;
               hi = mid2-1;
           }
       }
       return -1;
    }