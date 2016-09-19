class TwoSum {
public:
    set<int> num;
    set<int> res;

    // Add the number to an internal data structure.
	void add(int number) {
	    for (int n: num) {
	        res.insert(n + number);
	    }
	    num.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    return res.find(value) != res.end();
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
