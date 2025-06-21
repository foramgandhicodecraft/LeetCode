class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
          return false;

        // map<char, int>m1;
        // map<char, int>m2;

        // for (auto c:s){
        //     m1[c]++;
        // }
        // for (auto c2:t){
        //     m2[c2]++;
        // }

        // map<int, char>m3;

        // for (auto itr:m2){
        //     m3.insert({itr.first, itr.second});
        // }

        // for (auto itr:m1){
        //     if (m3.find(itr.second) != m3.end()){
        //         m1.erase(itr.first);
        //         m3.erase(itr.second);
        //     }
        // }

        // if (m1.size() == 0)
        //   return true;
        
        // return false;

        map<char, char>st;
        map<char, char>ts;

        for (int i = 0; i < s.size(); i++){
            if (st.find(s[i]) != st.end()){
                if (st[s[i]] != t[i]){
                    return false;
                }
            } else{
                st[s[i]] = t[i];
            }

             if (ts.find(t[i]) != ts.end()){
                if (ts[t[i]] != s[i]){
                    return false;
                }
            } else{
                ts[t[i]] = s[i];
            }
        }

        return true;


    }
};