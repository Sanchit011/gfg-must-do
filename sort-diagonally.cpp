public:
    void diagonalSort(vector<vector<int> >& mat, int n, int m) {
        // code here 
        vector<int> v;
        for (int row = 1; row < n; row++) {
            for (int j = 0, i = row; i < n && j < m; i++, j++) {
                v.push_back(mat[i][j]);
            }
            sort(v.rbegin(), v.rend(), greater<int>());
            int t = 0;
            for (int j = 0, i = row; i < n && j < m; i++, j++) {
                mat[i][j] = v[t++];
            }
            v.clear();
        }
        for (int col = 1; col < m; col++) {
            for (int j = col, i = 0; i < n && j < m; i++, j++) {
                v.push_back(mat[i][j]);
            }
            sort(v.rbegin(), v.rend());
            int t = 0;
            for (int j = col, i = 0; i < n && j < m; i++, j++) {
                mat[i][j] = v[t++];
            }
            v.clear();
        }
    }