class xorshift {
    uint64_t x;
    public:
        xorshift() {
            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
            x = rnd();
            for (int i = 0; i < 100; i++) {
                random();
            }
        }
        uint64_t random() {
            x = x ^ (x << 7);
            return x = x ^ (x >> 9);
    }
}; xorshift rng;
/*
@brief xorshift
*/
