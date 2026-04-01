class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long currMass = mass;
        int n = asteroids.size();

        if (n == 1){
            if (mass >= asteroids[0]){
                return true;
            } else {
                return false;
            }
        }

        for (int i = 0; i < n; i++){
            if (currMass < asteroids[i]){
                return false;
            }
            currMass += asteroids[i];
        }

        return true;
    }
};