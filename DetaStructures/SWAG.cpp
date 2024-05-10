template<typename T>
struct SWAG {
    struct foldable_stack {
        stack<T> data;
        stack<T> res;
        foldable_stack(){}

        void push(T a, int type) {//type == 1 : 配列の右に追加、つまりR  type == 0 : 配列の左に追加、つまりL  なぜこんな事 : 交換法則
            data.push(a);
            if(!res.empty()) {
               if(type == 0) res.push(op(a, res.top()));//resが空ならそれを入れる
               else res.push(op(res.top(), a));
            }
            else res.push(a);
            return;
        }

        void pop() {
            assert(!data.empty());
            data.pop();
            res.pop();
            return;
        }

        T top() const {
            assert(!data.empty());
            return data.top(); 
        }

        T get() const { 
            assert(!data.empty());
            return res.top(); 
        }

        bool empty() {return data.empty();}
        size_t size() {return data.size();}
    };

    
    SWAG() {}
    foldable_stack L, R;
    private:

      void move(foldable_stack& s, foldable_stack& t, int type) {//sの要素を半分tの要素に移す type == 0 : s = L, t = R  type == 1 s = R, t = L
        assert(t.empty());
        int oth = 1 - type;
        stack<T> tmp;
        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()), s.pop();//Rの後半半分を取り出す
        while(!s.empty()) t.push(s.top(), oth), s.pop(); //Rの前半をLに詰める
        while(!tmp.empty()) s.push(tmp.top(), type), tmp.pop(); 
      }
    
    public:
      void push_front(T a) {
          L.push(a, 0);
      }
  
      void push_back(T a) {
          R.push(a, 1);
      }
  
      void pop_front() {
          assert(!L.empty() || !R.empty());
          if(L.empty()) move(R, L, 1);
          L.pop();
      }
  
      void pop_back() {
          assert(!L.empty() || !R.empty());
          if(R.empty()) move(L, R, 0);
          R.pop();
      }
  
      T front() const {
        assert(!L.empty() || !R.empty());
        if(L.empty())move(R, L, 1);
        return L.top();
      }

      
      T back() const {
        assert(!L.empty() || !R.empty());
        if(R.empty())move(L, R, 0);
        return R.top();
      }

      T get()  {
        assert(!L.empty() || !R.empty());
        //if(L.empty() && R.empty()) return T::ide();  //空でも単位元を返して欲しい時コメントアウトを消し、上の行を消す。
        if(L.empty()) return R.get();
        if(R.empty()) return L.get();
        return op(L.get(), R.get());
      }
};


struct Monoid {
    //この辺のスペースに中身を書く
    ll a;
    
	
	Monoid(ll _a) : a(_a) {}

    friend Monoid op(const Monoid& l, const  Monoid& r) {
        return l;
    } 

	static Monoid ide() {
		return 0LL;
	}
};

/*
@brief SWAG

*/