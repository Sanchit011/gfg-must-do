int search(int A[], int n){
	    //code
	    if(n == 1) return A[0];
	    int start = 0;
	    int end = n-1;
	    int mid;
	    while(start <= end){
	        mid = (start + end)/2;
	        if(A[mid] != A[mid+1] && mid == 0) return A[mid];
	        if(A[mid] != A[mid-1] && mid == n-1) return A[mid];
	        if(A[mid] != A[mid+1] && A[mid] != A[mid-1]) return A[mid];
	        else if(A[mid] == A[mid-1] && mid%2 == 1){
	            start = mid+1;
	        }
	        else if(A[mid] == A[mid+1] && mid%2 == 0){
	            start = mid+1;
	        }
	        else end = mid - 1;
	    }
	    return -1;
	}