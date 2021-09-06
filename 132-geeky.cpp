public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		vector<int> mn(n, 1000000);
		for(int i = 1; i<n; i++){
		    mn[i] = min(mn[i-1], arr[i-1]);
		}
		stack<int> st;
		st.push(0);
		for(int i = 1; i<n; i++){
		    while(!st.empty() && arr[st.top()] <= arr[i]){
		        st.pop();
		    }
		    if(!st.empty()){
		        int val = mn[st.top()];
		        if(val < arr[i]) return true;
		    }
		    st.push(i);
		}
		return false;
	}