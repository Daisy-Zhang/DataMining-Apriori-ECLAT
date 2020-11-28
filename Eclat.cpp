#include "Eclat.h"

using namespace std;

Eclat::~Eclat() {
}

Eclat::Eclat(bitset<MAX_ITEM_LEN> input[], int line_ans, double sup) {
    min_sup = sup;
    ans = line_ans;
    for(int i = 0; i < line_ans; i ++) {
        for(int j = 0; j < MAX_ITEM_LEN; j ++) {
            if(input[i].test(j)) {
                inverted_list[j].set(i);
            }
        }
    }
    printf("gen inverted list done\n");
}

void Eclat::genL1() {
    for(int i = 0; i < MAX_ITEM_LEN; i ++) {
        if((double)(inverted_list[i].count()) / ans >= min_sup) {
            bitset<MAX_ITEM_LEN> tmp;
            tmp.set(i);
            L1_item.push_back(tmp);
            L1_index.push_back(inverted_list[i]);
        }
    }
    //printf("num: 1 , size: %d\n", L1_item.size());
}

void Eclat::genFreq(vector<bitset<MAX_ITEM_LEN>> L_item, vector<bitset<MAX_INPUT_LINE>> L_index, int num) {
    if(L_item.size() == 0) {
        return;
    }
    
    vector<bitset<MAX_ITEM_LEN>> Lk_item;
    vector<bitset<MAX_INPUT_LINE>> Lk_index;
    int tot = L_item.size();
    printf("num: %d , size: %d\n", num - 1, tot);
    
    vector<bitset<MAX_ITEM_LEN>> freq_exist;

    for (int i = 0; i < tot; i ++) {
        for (int j = i + 1; j < tot; j ++) {
            bitset<MAX_ITEM_LEN> tmp_item;
            bitset<MAX_INPUT_LINE> tmp_index;

            for(int k = 0; k < MAX_ITEM_LEN; k ++) {
                if(L_item[i].test(k) || L_item[j].test(k)) {
                    tmp_item.set(k);
                }
            }
            if (tmp_item.count() != num || find(freq_exist.begin(), freq_exist.end(), tmp_item) != freq_exist.end()) {
                continue;
            }
            freq_exist.push_back(tmp_item);
            
            int sup = 0;
            for(int k = 0; k < MAX_INPUT_LINE; k ++) {
                if(L_index[i].test(k) && L_index[j].test(k)) {
                    sup ++;
                    tmp_index.set(k);
                }
            }

            if((double)(sup) / ans >= min_sup) {
                Lk_item.push_back(tmp_item);
                Lk_index.push_back(tmp_index);
            }
        }
    }
    genFreq(Lk_item, Lk_index, num + 1);
}

void Eclat::getResult() {
    genL1();
    //printf("gen L1 done\n");
    genFreq(L1_item, L1_index, 2);
}