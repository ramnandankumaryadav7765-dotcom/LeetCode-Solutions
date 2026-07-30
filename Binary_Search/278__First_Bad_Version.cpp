// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


// METHOD-1
// It is good but give it ("Time Limit Exceeds(TLE)")
class Solution {
public:
    int firstBadVersion(int n) {
        for(int version=1 ; version<=n ; version++){
            if(isBadVersion(version)){
                return version;
            }
        }
        return -1;
    }
};



//  METHOD-2
class Solution {
public:
    int firstBadVersion(int n) {

        long long left = 1;
        long long right = n;

        while(left < right){

            long long mid = left + (right - left)/2;

            if(isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};