struct dynamic_connectivity {
    struct euler_tour_tree {
    	struct node_t;
    	using np = node_t*;
    	struct node_t {
    		node_t *lch, *rch, *par;
			int s, t;
    		int sz;
			bool exact;//このノード(辺) のレベル == ettのレベル && s < t   edge_levelup
			bool child_exact;
			bool have_auxedge = false;
			bool child_have_auxedge = false;
    
    		//node_t() : lch(nullptr), rch(nullptr), par(nullptr), sz(0) {}
			node_t(int _s, int _t) : s(_s), t(_t), lch(nullptr), rch(nullptr), par(nullptr), sz(s==t), exact(s<t), child_exact(s<t) {

			}
    	    bool is_root() {
    	    	return !par;
    	    }
    
    		void take_copy(np x) {//xの集約値、作用素を自身にコピー. xはnullptrでは無い。
				sz = x -> sz;
				child_have_auxedge = x -> child_have_auxedge;
				child_exact = x -> child_exact;
    		}
    	};
    
    	
    
    
    	int sz;
    	vector<unordered_map<int, np>> ptr;

    	void push(np t) {}
    
    	void update(np t) {
    	    t -> sz = (t->s == t->t);
			if(t -> lch) t -> sz += t -> lch -> sz;
			if(t -> rch) t -> sz += t -> rch -> sz;
			t -> child_exact = (t -> lch ? t -> lch -> child_exact : 0) | (t -> exact) | (t -> rch ? t -> rch -> child_exact : 0);
			t -> child_have_auxedge = (t -> lch ? t -> lch -> child_have_auxedge : 0) | (t -> have_auxedge) | (t -> rch ? t -> rch -> child_have_auxedge : 0);
    	}
        
		void update_only_child_have_auxedge(np t) {
			t -> child_have_auxedge = (t -> lch ? t -> lch -> child_have_auxedge : 0) | (t -> have_auxedge) | (t -> rch ? t -> rch -> child_have_auxedge : 0);
		}
		void update_only_child_exact(np t) {
			t -> child_exact = (t -> lch ? t -> lch -> child_exact : 0) | (t -> exact) | (t -> rch ? t -> rch -> child_exact : 0);
		}
    
    	void rotR(np t) {//xの作用素、空にしなきゃ遅延伝播おかしくない？TODO
    		np x = t -> par, y = x -> par;
    		push(t);
    		if((x -> lch = t -> rch)) t -> rch -> par = x;
    		t -> rch = x, x -> par = t;
    		if((t -> par = y)) {
    			if(y -> lch == x) y -> lch = t;
    			else y -> rch = t;
    		}
    		t -> take_copy(x);
    		push(x -> lch); push(x -> rch);
    		update(x); 
    	}
    
    	void rotL(np t) {//xの作用素、空にしなきゃ遅延伝播おかしくない？TODO
    		np x = t -> par, y = x -> par;
    		push(t);
    		if((x -> rch = t -> lch)) t -> lch -> par = x;
    		t -> lch = x, x -> par = t;
    		if((t -> par = y)) {
    			if(y -> lch == x) y -> lch = t;
    			else y -> rch = t;
    		}
    	    t -> take_copy(x);
    		push(x -> lch); push(x -> rch);
    		update(x); 
    	}
    
    	void splay(np t) {
    		while(!t -> is_root()) {
    			np x = t -> par;
    			if(x -> is_root()) {
    				if(x -> lch == t) rotR(t);
    				else rotL(t);
    			} else {
    				np y = x -> par;
    				if(y -> lch == x) {
    					if(x -> lch == t) rotR(x), rotR(t);
    					else rotL(t), rotR(t);
    				}
    				else {
    					if(x -> rch == t) rotL(x), rotL(t);
    					else rotR(t), rotL(t);
    				}
    			}
    		}
    		push(t);//tのlazyを恒等作用にしておく
    	}
    
    	np merge(np l, np r) {
    		if(!l) return r;
    		if(!r) return l;
    		while(l -> rch) l = l -> rch;
    		splay(l);
    		if((l -> rch = r)) {
    			push(r);
    			r -> par = l;
    		}
    		update(l);
    		return l;
    	}
    
    
    	pair<np, np> split(np t) {//  t) [t, 
    	    splay(t);
    		np l = t -> lch;
    		if(l) l -> par = nullptr;
    		t -> lch = nullptr;
    		update(t);
    		return make_pair(l, t);
    	}

    	pair<np, np> split2(np t) { //move t to top and detach t
    		splay(t);
    		np l = t -> lch;
    		np r = t -> rch;
    		if(l) l -> par = nullptr;
    		t -> lch = nullptr;
    		if(r) r -> par = nullptr;
    		t -> rch = nullptr;
    		update(t);
    		return make_pair(l, r);
    	}

    	tuple<np, np, np> split(np u, np t) {// u) (u  t) (t    /    t) (t  u) (u
    	    auto v = split2(u);
    		if(same(v.first, t)) {
    			auto r = split2(t);
    			return make_tuple(r.first, r.second, v.second);
    		} else {
    			auto r = split2(t);
    			return make_tuple(v.first, r.first, r.second);
    		}
    	}
    
    	np get_node(int s, int t) {
    		if(ptr[s].find(t) == ptr[s].end())ptr[s][t] = new node_t(s, t);
    		return ptr[s][t];
    	}
    
    	np root(np t) {
    		if(!t) return t;
    		while(t -> par) t = t -> par;
    		return t;
    	}

    	np reroot(np t) {
    		auto[l, r] = split(t);
    		return merge(r, l);
    	}
		int size(np u) { // NEW!
			splay(u);
			return u -> sz;
		}
    
    	bool same(np u, np v) {
    		if(u) splay(u);
    		if(v) splay(v);
    		return root(u) == root(v);
    	}
		euler_tour_tree(){}
    	
    	euler_tour_tree(int _sz) : sz(_sz) {
    	    ptr.resize(sz);
    	}

    	bool same(int u, int v) {
    		return same(get_node(u, u), get_node(v, v));
    	}

    	bool link(int u, int v) {
    		if(same(u, v)) return false;
    		merge(merge(merge(reroot(get_node(u, u)), get_node(u, v)), reroot(get_node(v, v))), get_node(v, u));
    		return true;
    	}

    	bool cut(int u, int v) {
    		if(ptr[u].find(v) == ptr[u].end()) return false;
    		auto [i, j, k] = split(get_node(u, v), get_node(v, u));
    		merge(i, k);
    		np p = ptr[u][v];
    		np q = ptr[v][u];
    		ptr[u].erase(v);
    		ptr[v].erase(u);
    		delete p; delete q;
    		return true;
    	}
		int size(int u) {
			return size(get_node(u, u));
		}
		void have_auxedge_update(int t, bool b) {
			np v = get_node(t, t);
			splay(v);
			v -> have_auxedge = b;
			update_only_child_have_auxedge(v);
		}

		vector<int> vertex_list(int t) {
			np v = get_node(t, t);
			splay(v);
			vector<int> res;

			auto dfs = [&](auto f, np now) -> void {
				if(now -> lch) f(f, now -> lch);
				if(now -> s == now -> t) res.push_back(now -> s);
				if(now -> rch) f(f, now -> rch);
				return;
			};

			dfs(dfs, v);
			return res;
		}

    };
    int cc;
    int sz;
	int dep;
    vector<euler_tour_tree> ett;
	vector<vector<unordered_set<int>>> aux_edges;
    using np = typename euler_tour_tree::node_t*;

	private:
	 

	    void edge_level_increment(int t, int k) {
			np v = ett[k].get_node(t, t);
			ett[k].splay(v);
			auto dfs = [&](auto f, np now) -> void {
				if(now->exact) {
					ett[k].splay(now);
					now -> exact = 0;
					ett[k].update_only_child_exact(now);
					ett[k+1].link(now -> s, now -> t);
					return;
				}
				if(now -> lch && now -> lch -> child_exact) f(f, now -> lch);
				else f(f, now -> rch);
				return;
			};

			while(v && v -> child_exact) {
				dfs(dfs, v);
				ett[k].splay(v);
			}
		}
	    
		bool try_reconnect(int u, int v, int k) {
			for(int i=0; i<k;i++) {
				ett[i].cut(u, v);
			}

			for(int i=k; i >=0; i--) {
				if(ett[i].size(u) > ett[i].size(v)) swap(u, v);
				edge_level_increment(u, i);

				np t = ett[i].get_node(u, u);
				ett[i].splay(t);
				auto dfs = [&](auto f, np now) -> bool {
					if(now -> have_auxedge) {
						ett[i].splay(now);
						for(auto itr = aux_edges[i][now->s].begin(); itr != aux_edges[i][now->s].end(); ) {
							auto y = *itr;
							itr = aux_edges[i][now->s].erase(itr);
							aux_edges[i][y].erase(now->s);
							if(aux_edges[i][now->s].size()==0)ett[i].have_auxedge_update(now->s, 0);
							if(aux_edges[i][y].size()==0)ett[i].have_auxedge_update(y, 0);
							if(ett[i].same(now->s, y)) {//辺の先が自分の連結成分
							    aux_edges[i+1][now->s].insert(y);
								aux_edges[i+1][y].insert(now->s);
								if(aux_edges[i+1][now->s].size()==1)ett[i+1].have_auxedge_update(now->s, 1);
								if(aux_edges[i+1][y].size()==1)ett[i+1].have_auxedge_update(y, 1);
							}
							else {
								for(int j = 0; j <= i; j++) {
									ett[j].link(now->s, y);
								}
								return 1;
							}
						}
						return 0;
					}

					if(now -> lch && now -> lch -> child_have_auxedge) return f(f, now -> lch);
					else return f(f, now -> rch);
				};

				while(t -> child_have_auxedge) {
					if(dfs(dfs, t)) return 1;
					ett[i].splay(t);
				}
			}
			return 0;
		}

	public:

	   


	    dynamic_connectivity(int _sz) : sz(_sz) {
			cc = sz;
			dep = 1;
			ett.emplace_back(sz);
			aux_edges.emplace_back(sz);
		}


		bool same(int u, int v) {
			return ett[0].same(u, v);
		}

		bool link(int u, int v) {//連結成分が減ったか
			if(u==v)return false;
			if(ett[0].link(u, v)) {
				cc--;
				return true;
			} 
			aux_edges[0][u].insert(v);
			aux_edges[0][v].insert(u);
			if(aux_edges[0][u].size()==1)ett[0].have_auxedge_update(u, 1);
			if(aux_edges[0][v].size()==1)ett[0].have_auxedge_update(v, 1);
			return false;
		}

		bool cut(int u, int v) {//切った結果、分断されたか？
			for(int i=0; i<dep; i++) {
				aux_edges[i][u].erase(v);
				aux_edges[i][v].erase(u);
				if(aux_edges[i][u].size()==0)ett[i].have_auxedge_update(u, 0);
				if(aux_edges[i][v].size()==0)ett[i].have_auxedge_update(v, 0);
			}

			for(int i=dep-1; i >=0; i--) {
				if(ett[i].cut(u, v)) {
					if(dep-1==i) {
						dep++;
						ett.emplace_back(sz);
						aux_edges.emplace_back(sz);
					}
					bool b = try_reconnect(u, v, i);
					if(!b)cc++;
					return b;
				}
			}
			return false;
		}

		int component_count() {
			return cc;

		}

		int size(int u) {
			np v = ett[0].get_node(u, u);
			ett[0].splay(v);
			return v -> sz;
		}

		vector<int> vertex_list(int u) {
			return ett[0].vertex_list(u);
		}

		/*
		    dynamic_connectivity(sz)   O(sz)  空間O(szlogsz) (重い!)
			@brief dynamic_connectivity
			link(u, v) ... uv間に辺を張る。すでにあったら何もしない。amortized O(log^2N)  らしい？
			cut(u, v) ... uv間の辺を削除する。すでにあったら何もしない。amortized O(log^2N)
			same(u, v) ... uvが同じ連結成分にあるか。 O(logN)
			size(u) ... uが属する連結成分のサイズ 未verify
			component_count()...連結成分の個数 O(1).頂点0を含んでいる事に注意。
			vertex_list(u) ... uが属する連結成分の頂点 O(logN + |SIZE|)  未verify
		*/

};
