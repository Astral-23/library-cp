struct Union {   
	private:
	    struct data {
            int a, b;
			int par_b;
			int siz_a;
			int edge_a;

			data(){}
			data(int _a, int _b, int _par_b, int _siz_a, int _edge_a) : a(_a), b(_b), par_b(_par_b), siz_a(_siz_a), edge_a(_edge_a){}
        };

	public:
     	using vi = vector<int>;
		vi par;
		vi size;
		vi edge;
		stack<data> history;
		int cc;

    
        Union(int N) {
            par.resize(N);
            iota(par.begin(), par.end(), 0);
            size.assign(N, 1);
            edge.assign(N, 0);
			cc = N;
        }
      
        int root(int u) {
          while (par[u] != u) {
              u = par[u];
          }    
          return u;
        }
        
        bool same(int a, int b) {
            if (root(a) == root(b)) {
                return true;
            }
            return false;
        }
        
        bool unit(int a, int b) {
            a = root(a), b = root(b);
            if(size[a] < size[b]) swap(a, b);
		    history.push(data(a, b, par[b], size[a], edge[a]));   
			 
		    if(a==b) {
				edge[a]++;
				return false;
		    }

			cc--;
			par[b] = a;
			size[a] += size[b];
			edge[a] += edge[b];
			edge[a]++;
			return true;
        }
      
        void undo() {
			data pre = history.top();
			history.pop();
			par[pre.b] = pre.par_b;
			size[pre.a] = pre.siz_a;
			edge[pre.a] = pre.edge_a;
			if(pre.a != pre.b) cc++;
        }


        int getsize(int u) {
            return size[root(u)];
        }

		int component_count() {
			return cc;
		}

		/*  0-indexed
		    Union(N) O(N)
			@brief : undo可能union_find
			root(u), same(a, b), unit(a, b) ... O(logN)
			undo() ... O(1)
			getsize(u) ... uを含む連結成分のサイズ O(1)
			component_count() ... 連結成分の個数を戻す。ノーを0を含んでいる事に注意。 O(1)。未verified

			注意：undoは、直前のunitを呼ぶ直前の状態に戻すということ。
		    unit(a, b)を呼んだ際にa, bが同じ連結成分かどうかは関係がない。
		*/
      
};