class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n= t.size();

        if(m<n){
            return "";
        }

        if(m==1 and n==1){
            if(s[0]!=t[0]){
                return "";
            }
        }

        pair<int,int> idx;
        unordered_map<char,int> map,temp;
        for(char c:t){
            map[c]++;
        }

        int l=0,r=0,minlen=INT_MAX;
        temp=map;

        while(r<m){
            
            if(temp.find(s[r])!=temp.end()){
                cout << "earsing : " << s[r] << endl;
                temp.erase(s[r]);
                //r++;
                
            }
            if(temp.empty()==true){
                temp=map;
                
                //minlen=min(minlen,r-l+1);
                cout<< "min len : "<< l << r << endl;
                if(minlen>r-l+1){
                    minlen=r-l+1;
                     cout<< "min len : "<< l << r << endl;
                     cout << minlen << endl;
                    idx={l,r};
                }
                l++;
                    
                while(l<=r and temp.find(s[l])==temp.end()){
                    l++;
                }
                temp.erase(s[l]);
                r=l;
            }
            r++;
        }
        string res="";
        for(int i=idx.first;i<=idx.second;i++){
            res+=s[i];
        }
        
        return res;
    }
};