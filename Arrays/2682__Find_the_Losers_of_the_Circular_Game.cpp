class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        int current=0;
        int turn=1;

        vector<bool>visited(n , false);
        visited[0]=true;
        while(true){
            current = (current + turn *k) %n;
            if(visited[current]){
                break;
            }
            visited[current] = true;
            turn++;
        }

        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};