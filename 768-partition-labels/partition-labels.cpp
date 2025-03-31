class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>length;
        int alpha[26];

        // hash map can also be used
        // for better space optimization i.e o(1) use array eith 26 places since only small letters are allowed

        // take an array for storing the last occurence of each alphabet in the string
        for (int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++){

            end = max(end, alpha[s[i] - 'a']);
            if (i == end){
                length.push_back(end-start+1);
                start = i+1;
            }
            
        }
        return length;
    }
};