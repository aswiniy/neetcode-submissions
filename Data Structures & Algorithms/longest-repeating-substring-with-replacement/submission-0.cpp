class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int n= s.size();
        int l=0;
        int r=0;
        int max_freq=0;
        int res=0;

        for(int r=0;r<n;r++){

           freq[s[r]]++;
           max_freq= max(max_freq,freq[s[r]]);

           while((r-l+1)-max_freq > k){
            freq[s[l]]--;
            l++;
           }

           res=max(res,r-l+1);

        }

        return res;
    }
};
