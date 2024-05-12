template<typename T1, typename T2>
struct MYPAIR {
	T1 FIRST_V; 
	T2 SECOND_V;
	MYPAIR () {}
	MYPAIR (T1 _FIRST_V, T2 _SECOND_V) : FIRST_V(_FIRST_V), SECOND_V(_SECOND_V) {}
	bool operator<(const MYPAIR& a) {
		if(FIRST_V != a.FIRST_V) return FIRST_V < a.FIRST_V;
		else return SECOND_V < a.SECOND_V;
	}
	bool operator>(const MYPAIR& a) {
		if(FIRST_V != a.FIRST_V) return FIRST_V > a.FIRST_V;
		else return SECOND_V > a.SECOND_V;
	}
	bool operator==(const MYPAIR& a) {
		return (FIRST_V==a.FIRST_V) && (SECOND_V == a.SECOND_V);
	}
	bool operator!=(const MYPAIR& a) {
		return !(*this == a);
	}
};

/*
@brief 自作のpair
*/
