class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = (startIndex+1)%n; 
        int j = (startIndex-1+n)%n;
        int unitR = 1;
        int unitL = 1;
        bool found = false;
        int left, right;

        if (words[startIndex] == target){
            return 0;
        }

        // check right
        while (i != startIndex){
            if (words[i] ==  target){
                found = true;
                right = unitR;
                break;
            }
            unitR++;
            i = (i+1)%n;
        }

        if (found == false){
            return -1;
        }

        // check left
        while (j != startIndex){
            if (words[j] ==  target){
                left = unitL;
                break;
            }
            unitL++;
            j = (j-1+n)%n;
        }

        int distance = min(left, right);
        
        return distance;

    }
};