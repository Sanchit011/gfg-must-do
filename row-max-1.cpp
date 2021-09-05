int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int col = m-1;
	    int ans = 0;
	    for(int i = 0; i<n; i++){
	        while(col >= 0 && arr[i][col] == 1){
	            col--;
	            ans = i;
	        }
	    }
	    if(col == m-1) return -1;
	    return ans;
	}