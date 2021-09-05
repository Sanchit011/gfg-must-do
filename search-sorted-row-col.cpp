class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        int row = 0;
        while(row < n && matrix[row][0] <= x) row++;
        if(row == 0) return false;
        row--;
        int col = 0;
        while(col < m){
            if(matrix[row][col] == x) return true;
            else if(matrix[row][col] > x) return false;
            col++;
        }
        return false;
    }
};