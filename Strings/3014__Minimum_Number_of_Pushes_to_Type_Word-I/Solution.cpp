class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8){
            return n;
        }
        else if(n>8 && n<=16){
            return (n-8)*2+8;
        }
        else if(n>16 && n<=24){
            return (n-16)*3+24;
        }
        else if(n>24 && n<=26){
            return (n-24)*4+48;
        }
        return -1;
    }
};

//  So we can absorbe something here , In this All characters are unique

// And in this solution , we dont use any loop , or any data structure so the TIME COMPLEXITY:- O(1) & SPACE COMPLEXITY :- O(1).