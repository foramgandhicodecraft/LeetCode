class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        int j = 0;
        int n = players.size();
        int count = 0;

        while (i < n && j < trainers.size()){
            while (j < trainers.size() && players[i] > trainers[j]){
                j++;
            }
           
           if (j < trainers.size() && players[i] <= trainers[j]){
            count++;
            i++;
            j++;
           }

        }

        return count;
    }
};