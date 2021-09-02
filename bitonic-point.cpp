public:
	int findMaximum(int arr[], int n) {
	    // code here
	    int low = 0;
	    int hi = n-1;
	    int mid;
	    int ans = 0;
	    if(n == 1) return arr[0];
	    if(n == 2) return max(arr[0], arr[1]);
	    if(n == 3) return max({arr[0], arr[1], arr[2]});
	    while(low <= hi){
	        mid = low + (hi-low)/2;
	        ans = max(ans, arr[mid]);
	        if(arr[mid] > arr[mid-1]){
	            low = mid+1;
	        }
	        else if(arr[mid] > arr[mid+1]){
	            hi = mid-1;
	        }
	        else break;
	    }
	    return ans;
	}