class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>anagram;
        unordered_map<char, int>anagram2;

        for (int i =0; i < s.size(); i++){
            if (anagram.find(s[i]) != anagram.end()){
                anagram[s[i]] += 1;
            }
            else{
                anagram[s[i]] = 1;
            }
        }

        for (int i =0; i < t.size(); i++){
            if (anagram2.find(t[i]) != anagram2.end()){
                anagram2[t[i]] += 1;
            }
            else{
                anagram2[t[i]] = 1;
            }
        }

        if (anagram == anagram2){
            return true;
        }
        else{
            return false;
        }
    }
};