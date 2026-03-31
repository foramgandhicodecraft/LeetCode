class Solution {
public:
    
    bool check(string word, string s2, int N, int m, int i){
        for (int j = 0; j < m; j++){
            if (word[i] != s2[j]){
                return false;
            }
            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int N = m+n-1;
        string word(N,'$');
        vector<bool>added(N, false);

        // fill all the T places
        for (int i = 0; i < n; i++){
            if (str1[i] == 'T'){
                int i_ = i;
                for (int j = 0; j < m; j++){
                    if (word[i_] != '$' && word[i_] != str2[j]){
                        return "";
                    }
                    word[i_] = str2[j];
                    i_++;
                }
            }
        }

        // fill all empty places with a
        for (int i = 0; i < N; i++){
            if (word[i] == '$'){
                word[i] = 'a';
                added[i] = true;
            }
        }

        // remove all the mismatching F
        for (int i = 0; i < n; i++){
            if (str1[i] == 'F'){
                if (check(word, str2, N, m, i)){
                    int k = i + m -1;
                    bool change = false;
                    while (k >= i){
                        if (added[k]){
                            word[k] = 'b';
                            change = true;
                            break;
                        }
                        k--;
                    }

                    if (!change){
                        return "";
                    }
                    
                }
            }
        }

        return word;
    }
};