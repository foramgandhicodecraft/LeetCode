class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<map<int, int>>s;

        for (int i = 0; i < 31; i++){
            int num = pow(2, i);
            map<int, int>m;
            while (num){
                m[num%10] += 1;
                num = num/10;
            }
            s.insert(m);
        }

        map<int,int>m1;
        while (n){
            m1[n%10] += 1;
            n = n/10;
        }

        if (s.find(m1) == s.end()) return false;

        return true;


    }
};