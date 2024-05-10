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
        vector<int> build_scc(int MAX_N, vector<vector<EDGE>>& G, int indexed) {//indexed : 頂点番号は何から始まるか MAX_N : 最大の頂点番号
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

template<typename EDGE>
struct two_sat {
    int N;//命題変数の種類数を表す。
    int N2;//Nの2倍を表す。
    vector<bool> res;//結果。
    bool pre_res;//answer関数で説明。
    vector<vector<EDGE>> G; //i番目の命題変数について、そのままをi番目の頂点、否定をi+N番目の頂点に割り当てることにする。
    two_sat(int _N) : N(_N){
        N2 = N * 2;
        G.resize(N2+1);
        res.resize(N+1, false);
    };
    

    void add_clause(int i, bool f, int j, bool g) {//節を追加する。f, g = trueならば肯定であること、 f, g = falseならば否定がついている事を表す。
        int ni = i, nj = j;
        if(!f) ni += N;
        if(!g) nj += N;
        // not i  → j
        if(!f) G[ni-N].emplace_back(nj);
        else G[ni+N].emplace_back(nj);      
        // not j → i
        if(!g)G[nj-N].emplace_back(ni);
        else G[nj+N].emplace_back(ni);
    }

    bool satisfiable() {//現状の命題論理式を充足する割り振りが存在するかを返す。
        for(int i = 1; i <= N; i++) res[i] = false;//結果を格納する配列の初期化。
        vector<int> scc_res = scc.build_scc(N2, G, 1);
        for(int i = 1; i <= N; i++) {
            //i番目の命題変数についてみる。
            if(scc_res[i] == scc_res[i+N]) {
                pre_res = false;
                return false;//i番目の命題変数について、そのままと否定が同じ強連結成分に存在。この時割り振りは存在しない。
            }
            if(scc_res[i] > scc_res[i+N]) res[i] = true;// P[i] > P[not i]ならtrue。 P[i] < P[not i]ならfalse。
        }
        pre_res = true;
        return true;//全てについて割り振れたなら存在する。
    }

    pair<vector<bool>, bool> answer() {//直近でsatisfiableを呼んだ時の割り当ての結果と、存在したのかを返す。
        return make_pair(res, pre_res);
    }
};

/*
@brief 2sat
*/