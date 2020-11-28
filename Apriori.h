#ifndef APRIORI_H
#define APRIORI_H

#include <bitset>
#include <vector>

const int MAX_ITEM_LEN_ = 100;
const int MAX_INPUT_LINE_ = 3200;

using namespace std;
using std::bitset;

class Apriori
{
private:
    bitset<MAX_ITEM_LEN_> data[MAX_INPUT_LINE_];
    vector<bitset<MAX_ITEM_LEN_>> L1_item;
    vector<int> L1_sup;
    double min_sup;
    int ans;
public:
    Apriori(bitset<MAX_ITEM_LEN_> input[], int line_ans, double sup);
    ~Apriori();
    void genL1();
    void genLk(vector<bitset<MAX_ITEM_LEN_>> Lk_1, int num);

    void getResult();
};

#endif