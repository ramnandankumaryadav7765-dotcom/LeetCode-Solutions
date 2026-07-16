// Method-1
class Solution {
public:
    int tribonacci(int n) {
        
        int T0=0;
        int T1=1;
        int T2=1;

        if(n == 0)
            return 0;

        if(n == 1 || n==2)
        return 1;

        for(int i=3 ; i<=n ; i++){
            int ans=T0+T1+T2;
            T0=T1;
            T1=T2;
            T2 = ans;
        }
        return T2;
    }
};



//  Method-2 // But it give TLE , because(TC:3^n   --> Exponential)
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0)
            return 0;

        if(n == 1 || n == 2)
            return 1;

        return tribonacci(n-1)
             + tribonacci(n-2)
             + tribonacci(n-3);
    }
};