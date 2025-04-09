class Solution {
public:
    string frequencySort(string s) {
    string ans;
	map<char,int>m;

	for (char word:s){
		m[word] += 1;
	}

    // take a max heap
    priority_queue<pair<int,char>>q;
    for (auto key:m){
        q.push({key.second,key.first});
    }

    while(!q.empty()){
        auto [count,ch] = q.top();
        q.pop();
        while (count--){
            ans += ch;
        }
    }

    return ans;
    
    }
};