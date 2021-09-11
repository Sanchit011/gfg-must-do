public:
    string nextPalin(string s) { 
        //complete the function here
        int n = s.size();
        if(n == 1 || n == 2) return "-1";
        int mid = n/2;
        for(int gap = 2; mid - gap >= 0; gap++){
            int index = mid - gap;
            int start = n - index - 1;
            int x = upper_bound(s.begin() + ((n+1)/2) ,s.begin() + start, s[index]) - s.begin();
            if(x != start){
                swap(s[x], s[start]);
                swap(s[index], s[n-1-x]);
                sort(s.begin()+index+1, s.begin()+mid);
                sort(s.begin()+((n+1)/2), s.begin()+start);
                reverse(s.begin()+((n+1)/2), s.begin()+start);
                return s;
            }
        }
        return "-1";
    }