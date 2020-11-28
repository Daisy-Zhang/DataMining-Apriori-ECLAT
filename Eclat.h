#ifndef ECLAT_H
#define ECLAT_H

#include <bitset>
#include <unordered_map>
#include <vector>

const int MAX_ITEM_LEN = 100;
const int MAX_INPUT_LINE = 3200;

using namespace std;
using std::bitset;
using std::unordered_map;

class Eclat {
private:
    unordered_map<int, bitset<MAX_INPUT_LINE>> inverted_list;
    vector<bitset<MAX_ITEM_LEN>> L1_item;
    vector<bitset<MAX_INPUT_LINE>> L1_index;
    int ans = 0;
    double min_sup = 0;
public:
    Eclat(bitset<MAX_ITEM_LEN> input[], int line_ans, double sup);
    ~Eclat();
    void genL1();
    void genFreq(vector<bitset<MAX_ITEM_LEN>> Lk_item, vector<bitset<MAX_INPUT_LINE>> Lk_index, int num);

    void getResult();
};

#endif