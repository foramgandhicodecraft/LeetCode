class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1)
          return 1;

        unordered_map<int, int>m;
        int left = 0;
        m[fruits[left]]++;
        int right = 1;
        int max_len = INT_MIN;

        while (right <= fruits.size()-1){

            if (m.find(fruits[right]) == m.end() && m.size() == 2){
                while (m.size() != 1){
                    m[fruits[left]]--;
                    if (m[fruits[left]] == 0){
                        m.erase(fruits[left]);
                    }

                    left++;
                }
            }

            m[fruits[right]]++;

            max_len = max(max_len, right-left+1);

            right++;
        }

        return max_len;
    }
};