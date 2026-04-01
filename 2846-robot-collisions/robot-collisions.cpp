class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // if all same direction, return helath array
        int n = positions.size();
        
        map<int, int>index;
        for (int i = 0; i < n; i++){
            index[positions[i]] = i;
        }

        sort(positions.begin(), positions.end());

        vector<int>stack;
        stack.push_back(positions[0]);

        for (int i = 1; i < n; i++){
            // positions->index->string direction and top of stack
            while (!stack.empty() &&
       directions[index[stack.back()]] == 'R' &&
       directions[index[positions[i]]] == 'L') {

    int topPos = stack.back();
    int topIdx = index[topPos];
    int currIdx = index[positions[i]];

    if (healths[currIdx] < healths[topIdx]) {
        healths[topIdx]--;
        index.erase(positions[i]);
        break;
    }
    else if (healths[currIdx] > healths[topIdx]) {
        healths[currIdx]--;
        index.erase(topPos);
        stack.pop_back();
    }
    else {
        index.erase(positions[i]);
        index.erase(topPos);
        stack.pop_back();
        break;
    }
}

if (index.count(positions[i])) {
    stack.push_back(positions[i]);
}
            
        }

        vector<int> ans(n, -1);

for (auto &p : index) {
    ans[p.second] = healths[p.second];
}

vector<int> finalAns;
for (int i = 0; i < n; i++) {
    if (ans[i] != -1) {
        finalAns.push_back(ans[i]);
    }
}
return finalAns;

    }
};