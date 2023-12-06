#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <algorithm> // for_each
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define print(x) cout << #x << "=" << x << endl
template <typename T>
static void print_vec(vector<T>& arr) {
    for_each(arr.begin(), arr.end(), [](T v){cout << v << " ";});
    cout << endl;
}
#endif