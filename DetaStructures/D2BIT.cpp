template<typename T>
struct D2BIT {
    int H, W;
    vector<vector<T>> dat;

    D2BIT(int _H, int _W) : H(_H), W(_W){
        dat.resize(H+1);
        for(int i = 1; i <= H; i++)dat[i].resize(W+1, 0);
    }
    

    private:

        void change__(int y, int x, T val) {
            while(x <= W) {
                dat[y][x] += val;
                x += (x & -x);
            }
        }

        T get__(int y, int x) {
            T res = 0;
            while(x > 0) {
                res += dat[y][x];
                x -= (x & -x);
            }
            return res;
        }


    public:
        void change(int y, int x, T val) {
            if(1 > y || y > H || 1 > x || x > W) return;
            while(y <= H) {
                change__(y, x, val);
                y += (y & -y);
            }
        }

        T get(int y, int x) {
            if(1 > y || y > H || 1 > x || x > W) return 0;
            T res = 0;
            while(y > 0) {
                res += get__(y, x);
                y -= (y & -y);
            }
            return res;
        }

        T rec(int sy, int ty, int sx, int tx) {
            T res = 0;
            res += get(ty, tx);
            res += get(sy-1, sx-1);
            res -= get(ty, sx-1);
            res -= get(sy-1, tx);
            return res;
        }
};

/*
@brief : 2DBIT

*/