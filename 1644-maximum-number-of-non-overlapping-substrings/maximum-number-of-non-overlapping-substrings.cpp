class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // mantain the first and last occurence of each charater in string
        vector<int>first(26,-1);
        vector<int>last(26,-1);

        for (int i = 0; i < s.size(); i++){
            if (first[s[i] - 'a'] == -1){
                //first[s[i] - 'a'].push_back(i);  USED FOR VECTORS OF VECTORS
                first[s[i] - 'a'] = i;
            }

            last[s[i] - 'a'] = i;
        }

        // generate valid substrings
        vector<pair<int, int>>substrings;

        for (int i = 0; i < 26; i++){
            if (first[i] == -1) continue;

            int start = first[i];
            int end = last[i];
            bool valid = true;
            int j = start;

            while (j <= end){
                if (first[s[j] - 'a'] < start){
                    valid = false;
                    break;
                }

                end = max(end, last[s[j] - 'a']);
                j++;

            }

            if (valid){
                    substrings.push_back({start, end});
            }
        }
        
        // find the non overlapping intervals
        // sort the substrings by their end positions
        sort(substrings.begin(), substrings.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.second < b.second; // sort by end position
        });

        int endLimit = -1;
        vector<string>result;

        for (auto interval:substrings){
            int start = interval.first;
            int end = interval.second;

            if (start > endLimit){
                result.push_back(s.substr(start, end-start+1));
                endLimit = interval.second;
            }

        }

        return result;
    }
};