class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        vector<vector<int>> stack;

        for (int i = temperatures.size()-1; i >= 0; i--){
            while (stack.size()>0 && temperatures[i] >= stack[stack.size()-1][0]){
                stack.pop_back();
            }

            if (stack.size() == 0){
                ans[i] = 0;
                stack.push_back({temperatures[i],i});
                continue;
            }

            ans[i] = stack[stack.size()-1][1] - i;
            stack.push_back({temperatures[i],i});
            
        }

        return ans;
    }
};