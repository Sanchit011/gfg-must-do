public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int R = matrix.size();
        int C = matrix[0].size();
        unordered_set <int> rows, cols;
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                if(matrix[i][j] == 1){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                if(rows.find(i) != rows.end() || cols.find(j) != cols.end()){
                    matrix[i][j] = 1;
                }
            }
        }
        return;
    }