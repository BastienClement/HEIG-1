//
//  merge.cpp
//
//  Created by Olivier Cuisenaire on 25.03.15.
//  Copyright (c) 2015 Olivier Cuisenaire. All rights reserved.
//

#include <iostream>
#include <utility>

using namespace std;

void fusion(string& A, size_t p, size_t q, size_t r) {
    string L = A.substr(p, (q-p)+1);
    string R = A.substr(q+1, r-q);

    L += CHAR_MAX;
    R += CHAR_MAX;

    for (size_t i = 0, j = 0, k = p; k <= r; k++) {
        A[k] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    cout << "[" << p << "," << q << "] + [" << (q+1) << "," << r << "]" << " : " << A << endl;
}

void mergeSort(string& A, size_t lo, size_t hi) {
    if (hi <= lo) return;
    size_t mid = lo + (hi-lo)/2;
    mergeSort(A, lo, mid);
    mergeSort(A, mid+1, hi);
    fusion(A, lo, mid, hi);
}

int main(int argc, const char * argv[]) {

    //string s;
    //cin >> s;

    string s = "EXAMPLE";
    mergeSort(s,0,s.size()-1);

    return 0;
}
