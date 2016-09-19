class TwoSum {
public:
    unordered_map<int, int> m;
    
    // Add the number to an internal data structure.
	void add(int number) {
	   m[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto num: m) {
	        int need = value - num.first;
	        if (need == num.first) {
	            if (num.second >= 2) return true;
	        } else if (m.find(need) != m.end()) {
	            return true;
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
