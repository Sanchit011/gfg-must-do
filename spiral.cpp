public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int top = 0;
        int left = 0;
        int down = r-1;
        int right = c-1;
        while(top<=down && left<=right){
            for(int i = left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top > down || left > right) break;
            for(int i = top; i<=down; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top > down || left > right) break;
            for(int i = right; i>=left; i--){
                ans.push_back(matrix[down][i]);
            }
            down--;
            if(top > down || left > right) break;
            for(int i = down; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(top > down || left > right) break;
        }
        return ans;
    }