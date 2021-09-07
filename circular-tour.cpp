public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int x = 0;
       int count = 0;
       for(int i = 0; i<2*n; i++){
           int index = i%n;
           x += p[index].petrol - p[index].distance;
           if(x < 0){
               x = 0;
               count = 0;
           }
           else{
               count++;
           }
           if(count == n) return i - n + 1;
       }
       return -1;
    }