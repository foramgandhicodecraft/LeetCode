class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_size = 0;

        for (auto sentence:sentences){
            int size = 0;
            for (auto c:sentence){
                if (c == ' ')
                  size++;
            }
            size++;
            max_size = max(max_size, size);
        }

        return max_size;
    }
};