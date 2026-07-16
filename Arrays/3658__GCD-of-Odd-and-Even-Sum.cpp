class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven=n*(n+1);
        int sumOdd=n*n;
        int small=min(sumEven , sumOdd);
        for(int i=small ; i>1 ; i--){
            if((sumEven % i == 0) && sumOdd % i == 0){
                return i;
            }
        }
        return 1;
    }
};