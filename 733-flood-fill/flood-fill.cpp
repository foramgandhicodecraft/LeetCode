class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int m = image.size();
        int n = image[0].size();
        set<pair<int, int>>visited;

        while (!q.empty()){
            int left = q.front().first;
            int right = q.front().second;
            visited.insert({left, right});
            q.pop();

            if (left-1 >= 0 && image[left-1][right] == initial){
                if (visited.find({left-1, right}) == visited.end()){
                    image[left-1][right] = color;
                    q.push({left-1, right});
                }
                
            }

            if (left+1 < m && image[left+1][right] == initial){
                if (visited.find({left+1, right}) == visited.end()){
                    image[left+1][right] = color;
                    q.push({left+1, right});
                }
                
            }

            if (right-1 >= 0 && image[left][right-1] == initial){
                if (visited.find({left, right-1}) == visited.end()){
                    image[left][right-1] = color;
                    q.push({left, right-1});
                }
                
            }

            if (right+1 < n && image[left][right+1] == initial){
                if (visited.find({left, right+1}) == visited.end()){
                    image[left][right+1] = color;
                    q.push({left, right+1});
                }
                
            }
        }

        return image;
    }
};