class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white_count = 0; 
        //count number of whites in window of size k
        for (int i = 0; i < k; i++){
            if (blocks[i] == 'W')
              white_count++;
        }
        int minimum_count = white_count;

        for (int i = k; i < blocks.size(); i++){
            if (blocks[i - k] == 'W')
              white_count--;
            if (blocks[i] == 'W')
              white_count++;
            minimum_count = min(minimum_count, white_count);
        }

        return minimum_count;
    }
};