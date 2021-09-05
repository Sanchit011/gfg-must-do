public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);
        stack<long long> st;
        st.push(0);
        for(int i = 1; i<n; i++){
            int curr = arr[i];
            while(!st.empty() && curr <= arr[st.top()]) st.pop();
            if(st.empty()) left[i] = i;
            else left[i] =  i - 1 - st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            int curr = arr[i];
            while(!st.empty() && curr <= arr[st.top()]) st.pop();
            if(st.empty()) right[i] = n-1-i;
            else right[i] =  st.top() - 1 - i;
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long val = (right[i] + left[i] + 1)*arr[i];
            ans = max(ans, val);
        }
        return ans;
    }