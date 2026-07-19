class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string Ypart="";
        string Xpart="";
        string midPart="";

        for(char c : s){
            if(c==y){
                Ypart+=c;
            }
            else if(c==x){
                Xpart+=c;
            }
            else{
                midPart+=c;
            }
        }
        return Ypart + midPart + Xpart;
    }
};