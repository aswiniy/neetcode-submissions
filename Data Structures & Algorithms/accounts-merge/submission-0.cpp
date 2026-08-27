class Solution {
public:
    
    struct DSU{

        vector<int> parent;

        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int find(int u){
            if(parent[u]==u)return u;
            return parent[u]=find(parent[u]);
        }

        void join(int u,int v){
            int p_u=find(u);
            int p_v=find(v);
            if(p_v !=p_u) parent[p_v]=parent[p_u];
        }
    };
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map <string, vector <int>> map;
        int n= accounts.size();
        for(int i=0;i<n;i++){
            int l=accounts[i].size();
            for(int j=1;j<l;j++){
                map[accounts[i][j]].push_back(i);
            }
        }

        DSU dsu(n);
        for(auto it:map){
            int root= dsu.find(it.second[0]);
            int l=it.second.size();
            for(int i=1;i<l;i++){
                dsu.join(root,it.second[i]);
            }
        }

        unordered_map<int,vector<string>> merged_account;
        for(auto it:map){
            string email=it.first;
            int root= dsu.find(it.second[0]);
            merged_account[root].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto it:merged_account){
            int root=it.first;
            string name= accounts[root][0];
            vector<string> & emails = it.second;
            sort(emails.begin(),emails.end());
            vector<string> final_account;
            final_account.push_back(name);
            final_account.insert(final_account.end(),emails.begin(),emails.end());
            ans.push_back(final_account);
        }

        return ans;
    }
};