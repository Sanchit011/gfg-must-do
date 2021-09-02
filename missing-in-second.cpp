public:
	vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{ 
	    // Your code goes here
	    vector<long long> ans;
	    unordered_set<long long> st;
	    for(int i = 0; i<M; i++){
	        st.insert(B[i]);
	    }
	    for(int i = 0; i<N; i++){
	        if(st.find(A[i]) == st.end()) ans.push_back(A[i]);
	    }
	    return ans;
	} 