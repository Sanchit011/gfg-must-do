public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n = x.size();
        int open1 = 0, open2 = 0, open3 = 0;
        int close1 = 0, clo;
        for(int i = 0; i<n; i++){
            if(x[i] == '(') open1++;
            if(x[i] == '[') open2++;
            if(x[i] == '{') open3++;
            if(x[i] == ')'){
                if(i>0 && (x[i-1] == '[' || x[i-1] == '{')) return false;
                open1--;
                if(open1<0) return false;
            }
            if(x[i] == ']'){
                if(i>0 && (x[i-1] == '(' || x[i-1] == '{')) return false;
                open2--;
                if(open2<0) return false;
            }
            if(x[i] == '}'){
                if(i>0 && (x[i-1] == '[' || x[i-1] == '(')) return false;
                open3--;
                if(open3<0) return false;
            }
        }
        if(open1 == 0 && open2 == 0 && open3 == 0) return true;
        return false;
    }