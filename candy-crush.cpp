public:
    string Reduced_String(int k,string s){
        // Your code goes here
        vector<pair<char, int>> st;
        int n = s.size();
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(st.size() == 0 || st.back().first != c){
                st.push_back({c, 1});
            }
            else{
                st.back().second++;
            }
            if(st.back().second == k) st.pop_back();
        }
        string ans = "";
        reverse(st.begin(), st.end());
        while(st.size() > 0){
            for(int i = 0; i<st.back().second; i++){
                ans.push_back(st.back().first);
            }
            st.pop_back();
        }
        return ans;
    }