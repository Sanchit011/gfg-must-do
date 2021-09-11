public:
        int isValid(string s) {
            // code here
            int n = s.size();
            for(int i = 0; i<n; i++){
                if(s[i] == '.' || (s[i] >= '0' && s[i] <='9')){
                    continue;
                }
                return 0;
            }
            if(s[n-1] == '.') return 0;
            int i = 0;
            string str;
            int count = 0;
            while(i<n){
                str = "";
                while(i<n && s[i] != '.'){
                    str += s[i];
                    i++;
                }
                if(str.size() == 0 || str.size() > 3) return 0;
                if(str.size() > 1 && str[0] == '0') return 0;
                if(str.size() == 3 && str[0] > '2') return 0;
                if(str.size() == 3 && str[0] == '2' && str[1] > '5') return 0;
                if(str.size() == 3 && str[0] == '2' && str[1] == '5' && str[2] > '5') return 0;
                i++;
                count++;
            }
            if(count != 4) return 0;
            return 1;
        }