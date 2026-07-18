// Time complexity for this approach :- O(n logn) , because sort() built function take O(n logn) time complexity
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};



/*
//  Using Frequency Counting Approach : Time Complexity : O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freqOfS(26, 0);
        vector<int> freqOfT(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freqOfS[s[i] - 'a']++;
            freqOfT[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freqOfS[i] != freqOfT[i]) {
                return false;
            }
        }

        return true;
    }
};

*/

// In this if strings have mixed Letters (Upper case & Lower Case) then first we convert all into lower case . So we use --->>  s[i] = tolower(s[i]);