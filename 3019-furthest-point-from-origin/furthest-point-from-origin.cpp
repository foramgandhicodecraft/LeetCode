class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int distance = 0;
        int slash_count = 0;

        for (auto ch:moves){
            if (ch == '_'){
                slash_count++;
            }
            else if (ch == 'L'){
                distance--;
            }
            else if (ch == 'R'){
                distance++;
            }
        }

        if (distance < 0){
            distance -= slash_count;
        }
        else if (distance > 0){
            distance += slash_count;
        }
        else if (distance == 0){
            distance = slash_count;
        }

        return abs(distance);
    }
};