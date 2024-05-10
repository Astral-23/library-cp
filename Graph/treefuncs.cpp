struct TreeFuncs {
    using vi = vector<int>;
    using vvi = vector<vector<int>>;
    vvi G;
    int N;
    int MAX_DIST = 1001001001;
    int u = -1; int v = -1; int d = -1;
    TreeFuncs(vvi _G) : G(_G) {N = int(G.size()) - 1;}


    private:

        vi dist__(int s) {
            vi res(N+1, MAX_DIST);
                res[s] = 0;
                queue<int> que;
                que.push(s);
                while(!que.empty()) {
                    int now = que.front();
                    que.pop();
                    for(int to : G[now]) if(res[to] == MAX_DIST) {
                        res[to] = res[now] + 1;
                        que.push(to);
                    }
                }
            return res;
        }

        vi path__(int s, int t) {
            vi res;
            auto dfs = [&](auto f, int now, int prev = -1) -> bool {
                if(now == t) {
                    res.push_back(now);
                    return true;
                }

                for(int to : G[now]) if(to != prev) {
                    if(f(f, to, now)) {
                        res.push_back(now);
                        return true;
                    }
                }
                return false;
            };

            dfs(dfs, s);
            return res;
        }
    
        pair<int, pair<int, int>> diam__() {
            {
                vi ds = dist__(1);
                int tmp = -1;
                for(int i = 1; i <= N; i++) {
                    if(tmp < ds[i]) {
                        u = i;
                        tmp = ds[i];
                    }
                }
            }
            {
                vi ds = dist__(u);
                for(int i = 1; i <= N; i++) {
                    if(d < ds[i]) {
                        v = i;
                        d = ds[i];
                    }
                }
            }

            pair<int, pair<int, int>> res;
            res.first = d;
            res.second.first = u;
            res.second.second = v;
            return res;
        }

        pair<int, int> center__() {
            pair<int, int> res(-1, -1);
            if(d == -1) {
                auto [t, p] = diam__();
                d = t; u = p.first; v = p.second;
            }
            vi ps = path__(u, v);
            res.first = ps[d/2];
            if(d/2+1 < int(ps.size()) && res.first != ps[d/2+1]) res.second = ps[d/2+1];
            return res;
        }
    public:

        void change(vvi _G) { G = _G, N = int(G.size())-1; u = -1; v = -1; d = -1;};

        vi dist(int s) {
            return dist__(s);
        }

        vi path(int s, int t) {
            return path__(s, t);
        }


        pair<int, pair<int, int>> diam() {
            return diam__();
        }

      
        pair<int, int> center() {
            return center__();
        }

        /*  
            TreeFuncs
            @brief 木に関するutility
            コンストラクタ(G)・change(G) ... 扱う木をGに変更
            dist(s) ... sからの距離を入れた配列。
            path(s, t) ... sからtのパス上の頂点を, {s, ....., t}の配列で返す。
            diam() ...pair(直径, pair(直径の端u, 直径の端v))
            center() .... pair(uに近い方の中心、（存在するなら)vに近い方の中心 (存在しない)-1)
        */
};