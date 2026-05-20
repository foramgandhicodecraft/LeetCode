class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        map<int, int>m;
        int count = 0;
        vector<int>ans;

        for (int i = 0; i < n; i++){
            cout<<i<<endl;
            m[A[i]] += 1;
            m[B[i]] += 1;
            if (m[A[i]] > 1){
                count++;
                cout<<"count from A"<<count<<endl;
            }
            if ((m[B[i]] > 1) && (B[i] != A[i]) ){
                count++;
                cout<<"count from B"<<count<<endl;
            }

            ans.push_back(count);
        }

        return ans;
    }
};