public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int left = 0;
        int right = n-1;
        int ans;
        while(left <= right){
            if(M[left][right] == 1) {
                left++;
                ans = right;
            }
            else {
                right--;
                ans = left;
            }
        }
        for(int i = 0; i<n; i++){
            if(i != ans && M[i][ans] == 0) return -1;
            if(i != ans && M[ans][i] == 1) return -1;
        }
        return ans;
    }