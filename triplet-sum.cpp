public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int x)
    {
        //Your Code Here
        sort(A, A+n);
        for(int i = 0; i<n; i++){
            int start = i+1;
            int end = n-1;
            while(end > start){
                if(A[i] + A[start] + A[end] > x){
                    end--;
                }
                else if(A[i] + A[start] + A[end] < x){
                    start++;
                }
                else return true;
            }
        }
        return false;
    }