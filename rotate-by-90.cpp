void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n = matrix.size();
    for(int layer = 0; layer < n/2; layer++){
        for(int i = layer; i<n-layer-1; i++){
            int x = matrix[layer][i];
            swap(matrix[layer][i], matrix[i][n-layer-1]);
            swap(matrix[i][n-layer-1], matrix[n-layer-1][n-1-i]);
            swap(matrix[n-layer-1][n-1-i], matrix[n-1-i][layer]);
            matrix[n-1-i][layer] = x;
        }
    }
    return;
}