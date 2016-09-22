class PhoneDirectory {
public:
    vector<int> freeList;
    vector<bool> freeHT;
    int index, count;
    
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : index(0), count(maxNumbers), freeList(maxNumbers), freeHT(maxNumbers, true){
        for (int i = 0; i < maxNumbers; ++i) {
            freeList[i] = i;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int n = -1;
        if (index < count) {
            n = freeList[index++];
            freeHT[n] = false;
        }
        return n;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number >= count) {
            return false;
        }
        return freeHT[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= count || freeHT[number]) {
            return;
        }
        freeList[--index] = number;
        freeHT[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
