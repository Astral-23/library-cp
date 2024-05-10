struct Union {   
    vector<int> Par;
    vector<int> size;
 

    Union(int N) {
        Par.resize(N+1);
        size.resize(N+1, 1);
        for (int i = 1; i <= N; i++) {
            Par[i] = i;
            
        }
    }
  
    int root(int u) {
        if (Par[u] != u) {
            return Par[u] = root(Par[u]);
        }    
         return u;
    }
    
    bool same(int a, int b) {
        return root(a) == root(b);
    }
    
    bool unit(int a, int b) {
        a = root(a), b = root(b);
        if(size[a] < size[b]) swap(a, b);

        if(a == b) return false;
        else {
            Par[b] = root(a);
            size[a] += size[b];
			return true;
        }

    }
int getsize(int u) {//uが含まれる連結成分のサイズを返す
        return size[root(u)];
    }//O(1)(大体)
};

/*
@brief Union-find
*/

/*
 struct Union {   
	using vi = vector<int>;
	using vvi = vector<vector<int>>;
    vi par;
    vi size;
    vi edge;
	vector<bool> visited;
    vvi G;
    
    Union(int N) {
        par.resize(N+1);
        iota(par.begin(), par.end(), 0);
        size.assign(N+1, 1);
        edge.assign(N+1, 0);
        G.resize(N+1);
		visited.resize(N+1);
    }
  
    int root(int u) {
        if(par[u] != u) return par[u] = root(par[u]);
         return u;
    }
    
    bool same(int a, int b) {
        return root(a) == root(b);
    }
    
    void unit(int a, int b) {
        a = root(a), b = root(b);
        if(size[a] < size[b]) swap(a, b);
 
        if(a == b) {
            ++edge[a];
            return;
        }
        else {
            G[a].push_back(b);
            G[b].push_back(a);
            par[b] = a;
            size[a] += size[b];
            edge[a] += edge[b];
            edge[a]++;
        }
    }
  
    int getsize(int u) {//uが含まれる連結成分のサイズを返す
        return size[root(u)];
    }//O(1)(大体)
  
    vector<int> members(int u) {
        vi res;
        queue<int> que;
        visited[u] = true;
        que.push(u);
        res.push_back(u);
        while(!que.empty()) {
            int now = que.front();
            que.pop();
            for(int to : G[now]) {
                if(!visited[to]) {
                    visited[to] = true;
                    que.push(to);
                    res.push_back(to);
                }
            }
        }
 
		for(auto v : res) visited[v] = false;
        return res;
    }  
};
*/