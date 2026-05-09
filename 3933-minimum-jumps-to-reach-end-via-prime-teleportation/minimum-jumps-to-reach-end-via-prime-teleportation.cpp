class Solution {
public:
    vector<bool>isPrime;
    void sieve(int max_element){
        isPrime.resize(max_element+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= sqrt(max_element); i++){
            if (isPrime[i]){
                for (int j = i*i; j <= max_element; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        // if no prime number return length-1
        // if prime number is there, divisibility needs to be checked for forward numbers only  
        // bfs ensures minimum number of steps (optimized path)
        int n = nums.size();
        queue<int>q;
        vector<bool>visited(n, false);
        set<int>seen;
        map<int, vector<int>>m;
        int max_element = INT_MIN;
        int steps = 0;

        for (int i = 0; i < n; i++){
            m[nums[i]].push_back(i);
            max_element = max(max_element, nums[i]);
        }

        sieve(max_element);

        q.push(0);
        visited[0] = true;

        while (!q.empty()){
            int size = q.size();
            
            while (size--){
                int i = q.front();
                q.pop();

                if (i == n-1){
                    return steps;
                }

                // i-1
                if (i-1 >= 0 && !visited[i-1]){
                    q.push(i-1);
                    visited[i-1] = true;
                }
                //i+1
                if (i+1 < n && !visited[i+1]){
                    q.push(i+1);
                    visited[i+1] = true;
                }
                // prime number
                if (isPrime[nums[i]] && !seen.count(nums[i])){
                    for (int multiple = nums[i]; multiple <= max_element;  multiple += nums[i]){
                        if (m.find(multiple) != m.end()){
                            for (auto j:m[multiple]){
                                if (!visited[j]){
                                    q.push(j);
                                    visited[j] = true;
                                }
                            }
                            seen.insert(multiple);
                        }
                    }
                }
            }
            steps++;
        }

        return steps;
    }
};