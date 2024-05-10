template<typename T>
struct sum2D {
    int H; int W;
    vector<vector<T>> table;
	bool inited;

    sum2D(int _H, int _W) : H(_H), W(_W) {
        table = vector<vector<T>>(H+1, vector<T>(W+1, T(0)));
		inited = false;
    }

	sum2D(vector<vector<T>>& A) {
		assert(A.size()>=1);
		H = A.size()-1;
		W = A[0].size()-1;
		table = A;
		init();
	}


    private:
        void init__() {
            for(int i = 0; i <= H; i++) {
                for(int j = 1; j <= W; j++) {
                    table[i][j] += table[i][j-1];
                }
            }

			for(int i = 1; i <= H; i++) {
				for(int j = 0; j <= W; j++) {
					table[i][j] += table[i-1][j];
				}
			}
        }


    public:
        void add(int y, int x, T val) {
            table[y][x] += val;
        }

        void init() {
            init__();
			inited = true;
        }


        T get(int sy, int ty, int sx, int tx) {
			assert(inited);
			assert(0 <= sy && sy <= H && 0 <= sx && tx <= W);
            T res = table[ty][tx];
            if(sy >= 1 && sx >= 1) res += table[sy-1][sx-1];
            if(sy >= 1) res -= table[sy-1][tx];
            if(sx >= 1) res -= table[ty][sx-1];
            return res;
        }

        /*
            sum2D<T> (H, W)   O(HW)
			sum2D<T> (vector<vector<T>> A)   O(HW)    空配列を渡してはいけない。
            @brief : 静的なグリッドの矩形和。

            add(y, x, val) ... (y, x) に valを足す。 O(1)
            init() ... 累積和を計算する。  O(HW)		
			--コンストラクタに配列を渡した場合、上二つを使ってはいけない--
            get(sy, ty, sx, tx) ... [sy, ty] * [sx, tx]の矩形和を取得。 O(1)
        
        */

};
