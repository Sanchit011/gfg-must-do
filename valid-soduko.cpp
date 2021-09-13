public:
    int isValid(vector<vector<int>> mat){
        // code here
        int n = mat.size();
        unordered_set<int> st;
        for(int i = 0; i<n; i++){
            st.clear();
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0) continue;
                if(st.find(mat[i][j]) != st.end()) return 0;
                st.insert(mat[i][j]);
            }
        }
        for(int j = 0; j<n; j++){
            st.clear();
            for(int i = 0; i<n; i++){
                if(mat[i][j] == 0) continue;
                if(st.find(mat[i][j]) != st.end()) return 0;
                st.insert(mat[i][j]);
            }
        }
        for(int count = 0; count < 9; count++){
            st.clear();
            for(int i = (count/3)*3; i<((count/3)*3) + 3; i++){
                for(int j = (count%3)*3; j<((count%3)*3)+3; j++){
                    if(mat[i][j] == 0) continue;
                    if(st.find(mat[i][j]) != st.end()) return 0;
                    st.insert(mat[i][j]);
                }
            }
        }
        return 1;
    }