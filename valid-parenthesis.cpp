public:
    int maxLength(string s){
        // code here
        stack<int> st;
        int n = s.size();
        int ans = 0;
        st.push(-1);
        for(int i = 0; i<n; i++){
            if(s[i] == '(') st.push(i);
            else {
                if(!st.empty()){
                    st.pop();
                }
                if(!st.empty()){
                    ans = max(ans, i - st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return ans;
    }