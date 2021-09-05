public:
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        stack<int> st;
        string ans = "";
        int n = s.size();
        unordered_map<char, int> mp;
        mp['+'] = 1;
        mp['-'] = 1;
        mp['*'] = 2;
        mp['/'] = 2;
        mp['^'] = 3;
        for(int i = 0; i<n; i++){
            char c = s[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                ans.push_back(c);
            }
            else if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                while(st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && mp[c] <= mp[st.top()]){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }