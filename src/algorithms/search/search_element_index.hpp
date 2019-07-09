#ifndef SEARCHELEMENTINEDEX_H_
#define SEARCHELEMENTINEDEX_H_

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void SearchElementIndex()
{
    vector<signed char> vect;
    vect.push_back(11);
    vect.push_back(22);
    vect.push_back(33);
    vect.push_back(-1);
    vect.push_back(55);

    const signed char* const first = vect.data();
    const signed char* const last = vect.data() + vect.size();

    cout << find(first, last, 33) - first << endl;
}

#endif /* SEARCHELEMENTINEDEX_H_ */
