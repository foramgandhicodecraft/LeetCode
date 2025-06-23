class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string token;
        vector<int>v1;
        vector<int>v2;

        while (getline(ss1, token, '.')){
            v1.push_back(stoi(token)); // stoi will remove leading zeroes
        }

        while (getline(ss2, token, '.')){
            v2.push_back(stoi(token));
        }

        int size = max(v1.size(), v2.size());
        
        for (int i = 0; i < size; i++){
            int num1 = i < v1.size()? v1[i] : 0;
            int num2 = i < v2.size()? v2[i] : 0;

            if (num1 > num2)  return 1;

            else if (num1 < num2)  return -1;
        }

        return 0;
    }
};