struct MinCostFlow {
	using ll = long long;
	using pli = pair<long long, int>;
	using vl = vector<ll>;
	using vi = vector<int>;

	struct Edge {
		int to, rev;
		ll cap, cost;
		Edge(){}
		Edge(int _to, int _rev, ll _cap, ll _cost) : to(_to), rev(_rev), cap(_cap), cost(_cost){}
	};

	vector<vector<Edge>> G;
    int N;
	const ll MAX_DIST = 2002002002002002002LL;
    vl h;
    vl dist;
    vi prevV;//ダイクストラは再帰関数的に書けないので、保存する必要がある : 最後に流した分減算するのに使う。
    vi prevE;//同上。
    ll now_ryuuryou = 0;
    ll now_cost = 0;
    vector<pair<int, Edge>> es;//辺の情報 [from, EDGE]
    vector<unordered_map<int, int>> getid;
    
	MinCostFlow(int _N) {
        N = _N;
	    G.resize(N+1);
        h.assign(N+1, 0);
        dist.assign(N+1, MAX_DIST);
        prevV.resize(N+1);
        prevE.resize(N+1);
        es.resize(1);
        getid.resize(N+1);
	}

    private:

        ll Daiku(int s, int t, ll &ryuuryou) {
            ll res = 0;
            while(ryuuryou > 0) {
                priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
                dist.assign(N+1, MAX_DIST);
                dist[s] = 0;
                que.push(pli(0, s));        
                while(!que.empty()) {
                    ll cd = que.top().first;
                    int cp = que.top().second;
                    que.pop();
                    if(dist[cp] < cd) {
                      continue;
                    }
                    for (int i = 0; i < int(G[cp].size()); i++) {
                        Edge e = G[cp][i];
                        if(e.cap > 0 && dist[e.to] > dist[cp] + e.cost - (h[e.to] - h[cp])) {
                            //1集目のダイクストラの時、hの中身は0なので最初からこの書き方で不都合は生じない
                            dist[e.to] = dist[cp] + e.cost - (h[e.to] - h[cp]);
                            prevV.at(e.to) = cp;
                            prevE.at(e.to) = i;
                            que.push(pli(dist[e.to], e.to));
                        }
                    }
                }        
                if(dist[t] == MAX_DIST) {
                  return 1;//辿り着けなかった
                }        
                for (int i = 1; i <= N; i++) {
                  h[i] += dist[i];//ポテンシャルの更新 逆辺を張る前にやる（負の辺を消すのが目的なので）
                }

                ll flow = ryuuryou;
                for (int v = t; v != s; v = prevV[v]) {
					if(G[prevV[v]][prevE[v]].cap < flow) flow = G[prevV[v]][prevE[v]].cap;
                }
                ryuuryou -= flow;
                now_ryuuryou += flow;
                res += h[t] * flow;//大いなる注意点: distに入っているのはポテンシャル付きの距離 hに入っているのは元のグラフでの距離
                now_cost += h[t] * flow;        
                for (int v = t; v != s; v = prevV[v]) {
                    Edge &e = G[prevV[v]][prevE[v]];
                    e.cap -= flow;
                    G[v][e.rev].cap += flow;
                }
            }
            return res;
        }    
  
 public:

	void add_edge(int from, int to, ll cap, ll cost) {
		int Current_Ga_idx = G[from].size(); 
		int Current_Gb_idx = G[to].size(); 
		G[from].emplace_back(Edge(to, Current_Gb_idx, cap, cost));
		G[to].emplace_back(Edge(from, Current_Ga_idx, 0, -1 * cost));
        es.emplace_back(from, Edge(to, Current_Gb_idx, cap, cost));
        getid[from][to] = es.size() - 1;
	}

    void WF(int s) {
        vl d(N+1, MAX_DIST);
        d[s] = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= N; j++) {
                for(auto e : G[j]) {
                    if(e.cap != 0 && d[e.to] > d[j] + e.cost) d[e.to] = d[j] + e.cost;
                }
            }
        }
        for(int i = 1; i <= N; i++) h[i] = d[i];
    }

    int edgesize() {return int(es.size()) - 1;}
    
    int get_id(int s, int t) {return getid[s][t];}
    
  
    ll get_flow(int id) {
        auto [_, e] = es[id];
        return G[e.to][e.rev].cap;
    }
  
    pair<int, int> get_st(int id) {
        auto [s, e] = es[id];
        return make_pair(s, e.to);
    }
  
    void change_edge(int id, ll new_cap, ll new_flow) {//流量変えたくないなら、new_flow = get_flow(id)
        assert(new_cap >= new_flow);
        auto[s, e] = es[id];
        G[s][G[e.to][e.rev].rev] = Edge(e.to,  e.rev, new_cap-new_flow, e.cost);
        G[e.to][e.rev] = Edge(s,G[e.to][e.rev].rev,  new_flow, -e.cost);
    }
  
  
  	pli min_cost(int s, int t, ll target) {
        ll ryuuryou = target - now_ryuuryou;
  	    Daiku(s, t, ryuuryou);
  	  	return pli(now_cost, now_ryuuryou);
  	} 

	/*
	    MinCostFlow(N) 空間O(N)
		@brief Mincostflow

		add_edge(s, t, cap, cost) ... s→t の辺を張る。 辺が追加された順番に応じて、辺には1-indexedの番号がつく。O(1)
		WF(s) ... sからのポテンシャルを計算する。負のコストが含まれる場合に呼ぶ。sには、フローを流す始点を与える。  O(VE)
		edgesize() ... 辺の本数 O(1)
		get_id(s, t) ... s→tの辺の、辺番号を返す。 O(1)
		get_flow(id) ... 辺番号idの辺の現在の流量を返す。 O(1)
		get_st(id) ... 辺番号idの辺の視点と終点を返す。O(1)
		change_edge(id, new_cap, new_flow) ... 辺番号idの辺のcap, flowを変更する。 O(1)
		min_cost(s, t, target) ... 現在のグラフを元に、sからtに、合計流量がtargetになる様に水を流す事を試みる。 {コスト、実際に流れた流量}を返す。 O(FElogV)
		合計流量が減る方向には流れない。
	*/
};
