template<typename EDGE>
class SCC {
    private:
        void sDFS(int now, vector<vector<EDGE>>& G, vector<bool>& visited, vector<int>& vs) {
            visited[now] = true;
            for(auto& e : G[now]) {
                if(!visited[e.to]) sDFS(e.to, G, visited, vs);
            }
            vs.push_back(now);
            return;
        }

        void srDFS(int now, vector<vector<EDGE>>& rG, vector<bool>& rvisited, vector<int>& cmp, int k) {
            rvisited[now] = true;
            cmp[now] = k;
            for(EDGE& e : rG[now]) {
                if(!rvisited[e.to]) srDFS(e.to, rG, rvisited, cmp, k);
            }
        }
    
    public:
        SCC(){}
        vector<int> build_scc(int MAX_N, vector<vector<EDGE>>&G, int indexed) {//indexed : 頂点番号は何から始まるか MAX_N : 最大の頂点番号
            int t = indexed;
            int N = MAX_N;
            vector<vector<EDGE>> rG(N+1);
            vector<int> vs;
            vector<bool> visited(N+1, false);

            for(int i = t; i <= N; i++) {
                for(EDGE& e : G[i]) {
                    EDGE ne = e;
                    ne.to = i;
                    rG[e.to].push_back(ne);
                }
            }

            for(int i = t; i <= N; i++) {
                if(!visited[i])sDFS(i, G, visited, vs);
            }
        
            vector<int> cmp(N+1, -1);
            vector<bool> rvisited(N+1, false);
            int k = 1;
            for(int i = vs.size(); i >= 1; i--) {
                if(!rvisited[vs[i-1]]) srDFS(vs[i-1], rG, rvisited, cmp, k++);
            }
            return cmp;
        }
};
struct edge {
    int to;
};
SCC<edge> scc;//1から始まるトポロジカル順序を返す。頂点のindexedをbulid_sccに渡す。

/*
@brief 強連結成分分解
*/