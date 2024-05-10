struct Timer {
	chrono::system_clock::time_point s;
	chrono::system_clock::time_point pre;
	bool active = false;

	Timer(){active = false;}

	void start() {
		assert(!active);
		active = true;
		s = chrono::system_clock::now();
	}

	void stop() {
		pre = chrono::system_clock::now();
		assert(active);
		active = false;
	}

	void restart() {//non_activeの時間分、始点をずらす
	    assert(!active);
		active = true;
		s += chrono::system_clock::now() - pre;
	}


	double now() {
		if(active) {
		    chrono::system_clock::time_point t = chrono::system_clock::now();
		    return chrono::duration<double>(t - s).count();
		}
		else {
			return chrono::duration<double>(pre - s).count();
		}
	}

	void out() {
		cout << now() << " sec" << endl;
	}
};
Timer tim;
/*
@brief Timer
*/