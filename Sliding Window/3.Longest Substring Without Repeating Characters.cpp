class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> map;
        int n=s.size();
        // for(char c: s){
        //     map[c]++;
        // }
        int l=0,r=0;
        int maxlen=0;
        while(r<n){
            while(map.find(s[r])!=map.end() and l<=r){
                cout<< "in erase : "<<s[l]<<endl;
                map.erase(s[l]);
                l++;
            }
            if(map.find(s[r])==map.end()){
                map[s[r]]++;
                r++;
                maxlen=max(maxlen,r-l);
                cout<< "len : " << maxlen <<endl;
            }
            //maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};