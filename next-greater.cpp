public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> ans;
        for(int i = n-1; i>=0; i--){
            long long x = arr[i];
            while(!st.empty() && x > st.top()) st.pop();
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(x);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }