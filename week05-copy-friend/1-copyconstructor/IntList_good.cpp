/**
 * Demonstrates a correct copy constructor.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint newNumInts): 
            numInts(newNumInts), 
            theInts(new int[newNumInts]) 
            {  }

        IntList(const IntList& other): IntList(other.numInts) {
            cout << "copy constructor..." << endl;
            for (uint i=0; i<numInts; ++i)
                theInts[i] = other.theInts[i];
        }

        IntList& operator=(const IntList& other) {
            if (this==&other) 
                return *this;
            cout << "assignment operator..." << endl;
            delete[] theInts;
            theInts = new int[other.numInts]; 
            numInts = other.numInts;
            for (uint i=0; i<numInts; ++i)
                    theInts[i] = other.theInts[i];
            return *this;
        }

        ~IntList() {
             delete[] theInts;
        }

        void operator=(int value) {
            cout << "filling with "<<value<<"..."<<endl;
            for (uint i=0; i<this->numInts; ++i)
                theInts[i] = value;
        }

        int operator[](uint index) const {
            return theInts[index];
        }

        int& operator[](uint index) {
            return theInts[index];
        }
};

int main() {
    IntList list1 {10};
    cout << "list1[5] = " << list1[5] << endl;
    list1 = 1;
    cout << "list1[5] = " << list1[5] << endl << endl;

    IntList list2 {list1};  
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list2[5] = " << list2[5] << endl;
    list2 = 2;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list2[5] = " << list2[5] << endl << endl;

    IntList list3{20};
    list3 = list1;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list3[5] = " << list3[5] << endl;
    list3 = 3;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list3[5] = " << list3[5] << endl << endl;

    return 0;
}