class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>stack;
        int n = asteroids.size();

        for (int i = 0; i < n; i++){
            
            if (!stack.empty() && asteroids[i] < 0 && stack.back() > 0){
                bool equal = false;
                while (!stack.empty() && stack.back() > 0){
                    if (stack.back() < abs(asteroids[i])){
                        stack.pop_back();
                    }
                    else if (stack.back() > abs(asteroids[i])){
                        //equal = true;
                        break;
                    }
                    else {
                        stack.pop_back();
                        equal = true;
                        break;
                    }
                }
                if (!equal && (stack.empty() || stack.back() < 0)){
                    stack.push_back(asteroids[i]);
                }
                continue;
            }
            stack.push_back(asteroids[i]);
            
        }

        return stack;
    }
};