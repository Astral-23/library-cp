template<typename K, typename X>
struct top2 {
    struct D {
        K key;
        X val;
    
        D(){}
        D(K _key, X _val) : key(_key), val(_val){}
    
        static D ide() {
            //Edit here   return D(-1, -BIG);
        }
    };
    
    D a = D::ide();
    D b = D::ide();
    top2(){}

    void add(K key, X val) {
        if(b.val < val) {
            swap(b.val, val);
            swap(b.key, key);
        }
        if(a.val < b.val) {
            swap(a.val, b.val);
            swap(a.key, b.key);
        }
        if(a.key == b.key) {
            b.val = val;
            b.key = key;
        }
    }

    X get(K key) {
        if(a.key==key) return b.val;
        else return a.val;
    }

    /*
        top2<K, X>() O(1)
        @brief
        add(key, val) KEYとしてkeyが付加された値を追加する.  O(1)
        get(key) 登録された値の中で、付加されたKEYがkeyでないものの最大を取得。 O(1)

        注意：削除不可        
    */
};