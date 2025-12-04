class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        // int collision = 0;
        // for (int i = 1; i < n; i++){
        //     if (directions[i] == 'L' && directions[i-1] == 'R'){
        //         collision += 2;
        //         directions[i] = 'S';
        //         directions[i-1] = 'S';
        //     } else if ((directions[i] == 'L' && directions[i-1] == 'S') || (directions[i] == 'S' && directions[i-1] == 'R')){
        //         collision += 1;
        //         directions[i] = 'S';
        //         directions[i-1] = 'S';
        //     }
        // }

        // return collision;

        int i = 0;
        int ll = 0;
        int tr = 0;
        int count = 0;

        while (i < n && directions[i] == 'L'){
            ll += 1;
            i++;
        }

        i = n-1;
        while (i >= 0 && directions[i] == 'R'){
            tr += 1;
            i--;
        }

        for (int i = 0; i < n; i++){
            if (directions[i] != 'S'){
                count += 1;
            }
        }

        int total = count - ll - tr;

        return total;

    }
};