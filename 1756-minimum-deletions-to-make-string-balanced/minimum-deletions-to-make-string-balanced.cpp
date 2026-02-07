class Solution {
public:
    int minimumDeletions(string s) {
        long long min_deletion = 0;
        long long count_b = 0;

        for (char c:s){
            if (c == 'a'){
                min_deletion = min(min_deletion+1, count_b);
            }
            else {
                count_b += 1;
            }
        }

        return (int)min_deletion;
    }
};