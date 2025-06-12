class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>color(v);

        for(int i = 0; i < v; i++) color[i] = -1;

        for (int i = 0; i < v; i++){
            if (color[i] == -1){
            queue<int>q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()){
            int node = q.front();
            q.pop();

            for (auto itr:graph[node]){
                if (color[itr] == -1){
                    color[itr] = !color[node];
                    q.push(itr);
                }

                else if (color[itr] == color[node])
                  return false;
            }
            }
        }

        }

        
        return true;
    }
};