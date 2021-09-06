public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i<n; i++){
            char c = s[i];
            while(!st.empty() && st.top() > c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k--){
            st.pop();
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size() > 1 && ans[ans.size() - 1] == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }