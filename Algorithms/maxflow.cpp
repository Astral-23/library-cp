struct Edge {
    int to;
    ll cap;
    int rev;//対応する辺の、G[相手]のインデックス
};

struct Maxflow {

  
	vector<vector<Edge>> G;
   
  int siz;
  vector<pair<int, Edge>> es;//辺の情報 [from, EDGE]
  vector<unordered_map<int, int>> getid;
  vector<int> level;
  vector<int> iter; //dfsにおいて、既に訪れた辺の本数
  
	Maxflow(int N) {
     siz = N;
		 G.resize(N+1);
     level.assign(N+1, -1);
     iter.assign(N+1, 0);
     getid.resize(N+1);
     es.resize(1);
	}
  

  void bfs(int s) {//グラフのレベルを割り振る
    rep(i, 0, siz) level.at(i) = -1;
    queue<int>  que;
    level.at(s) = 0;
    que.push(s);
    while(!que.empty()) {
      int now = que.front(); que.pop();
      for(auto [TO, CAP, REV] : G[now]) {
        if(CAP > 0 && level[TO] < 0) {
          level[TO] = level[now] + 1;
          que.push(TO);
        }
      }
    }
  }
 
	ll dfs(int now, int goal, ll F) {// posからgoalまでの１パス分の最大流量を返す F = 暫定流せる水量 
		if (now == goal) {
          return F;
        }
		for (int &i = iter[now]; i < int(G[now].size()); i++) {//行き先なくなったらここ無視されるようになって、そこがゴールでないならば0が返される。よってflow >= 1を満たさないのでその道筋は無視される。ゴールならばFが帰る。
		  auto &e = G[now][i]; 
			if(e.cap > 0 && level[now] < level[e.to]) {
        ll d = dfs(e.to, goal, min(F, e.cap));
        if(d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
		  }
    }
		return 0;
	}



  void add_edge(int s, int t, ll c) {//有効辺O(1) //無向辺を貼りたい時は2回、aとbを逆に呼ぶ
		int Current_Ga_idx = G.at(s).size(); 
		int Current_Gb_idx = G.at(t).size(); 
		G.at(s).push_back(Edge{t, c, Current_Gb_idx});
		G.at(t).push_back(Edge{s, 0, Current_Ga_idx});//revは、逆向きの辺の添え字　流した時、残余グラフの容量を増やす為
    es.emplace_back(s, Edge{t, c, Current_Gb_idx});
    getid[s][t] = es.size() - 1;
	}

  int get_edgecount() {return es.size() - 1;}
  
  int get_id(int s, int t) {return getid[s][t];}

  ll get_flow(int id) {//現状の流量を返す。O(1)
    auto [_, e] = es[id];
    return G[e.to][e.rev].cap;
  }

  pair<int, int> get_st(int id) {
    auto [s, e] = es[id];
    return make_pair(s, e.to);
  }

  void change_edge(int id, ll new_cap, ll new_flow) {//O(1)//流量変えたくないなら、new_flow = get_flow(id)
    assert(new_cap >= new_flow);
    auto[a, e] = es[id];
    G[a][G[e.to][e.rev].rev] = Edge{e.to, new_cap-new_flow, e.rev};
    G[e.to][e.rev] = Edge{a, new_flow, G[e.to][e.rev].rev};
  }


	ll max_flow(int s, int t) {//1パス分の最大流量を合計する O(辺 * (流量))
		ll Total_Flow = 0;
		while (true) {
            bfs(s);
		    if(level[t] < 0) return Total_Flow;
            rep(i, 0, siz) iter.at(i) = 0;
		    ll F = 0;
            while((F = dfs(s, t, BIG)) > 0) {
              Total_Flow += F;
            }
		}
	}
};


/*
@brief Maxflow
*/