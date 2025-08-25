class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>>graph(num);
        vector<int>indegree(num);
        int count = 0;
        vector<int>ans;

        if (pre.size() == 0){
            int k = num;
            while(k--){
                ans.push_back(k);
            }

            return ans;
        }

        for(auto itr:pre){
            indegree[itr[0]]++;
            graph[itr[1]].push_back(itr[0]);
        }

        queue<int>q;

        for (int i = 0; i < num; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            ans.push_back(q.front());
            count++;
            int node = q.front();
            q.pop();
            for (auto itr:graph[node]){
                indegree[itr]--;
                if (indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }

        if (count == num){
            return ans;
        } 

        vector<int>res;
        return res;
    }
};