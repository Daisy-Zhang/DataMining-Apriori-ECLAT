#include "Apriori.h"

using namespace std;

Apriori::Apriori(bitset<MAX_ITEM_LEN_> input[], int line_ans, double sup) {
    for(int i = 0; i < MAX_INPUT_LINE_; i ++) {
        data[i] = input[i];
    }
    min_sup = sup;
    ans = line_ans;
}

Apriori::~Apriori() {

}

void Apriori::genL1() {
    for (int i = 0; i < MAX_ITEM_LEN_; i ++) {
        int tmp_sup = 0;
        for (int j = 0; j < ans; j ++) {
            if(data[j].test(i)) {
                tmp_sup ++;
            }
        }
        if(tmp_sup == 0) {
            continue;
        }
        if((double)(tmp_sup) / ans < min_sup) {
            continue;
        }
        bitset<MAX_ITEM_LEN_> tmp;
        tmp.set(i);
        L1_item.push_back(tmp);
        L1_sup.push_back((double)(tmp_sup) / ans);
    }
    //printf("num: 1 , size: %d\n", L1_item.size());
}

void Apriori::genLk(vector<bitset<MAX_ITEM_LEN_>> Lk_1, int num) {
    if(Lk_1.size() == 0) {
        return;
    }

    vector<bitset<MAX_ITEM_LEN_>> Lk;

    vector<int> tmp;
    int tot = Lk_1.size();
    printf("num: %d , size: %d\n", num - 1, tot);

    vector<bitset<MAX_ITEM_LEN_>> freq_exist;

    for(int i = 0; i < tot; i ++) {
        for(int j = i; j < tot; j ++) {
            tmp.clear();
            bitset<MAX_ITEM_LEN_> bitset_tmp;
            for(int k = 0; k < MAX_ITEM_LEN_; k ++) {
                if(Lk_1[i].test(k) || Lk_1[j].test(k)) {
                    bitset_tmp.set(k);
                    tmp.push_back(k);
                }
            }

            if(bitset_tmp.count() != num || find(freq_exist.begin(), freq_exist.end(), bitset_tmp) != freq_exist.end()) {
                continue;
            }
            freq_exist.push_back(bitset_tmp);

            int tmp_sup = 0;
            for(int k = 0; k < ans; k ++) {
                int flag = 1;
                for(int m = 0; m < tmp.size(); m ++) {
                    if(data[k].test(tmp[m])) {
                        continue;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
                tmp_sup += flag;
            }

            if((double)(tmp_sup) / ans >= min_sup) {
                Lk.push_back(bitset_tmp);
            }
        }
    }

    genLk(Lk, num + 1);
}

void Apriori::getResult() {
    genL1();
    //printf("gen L1 done\n");
    genLk(L1_item, 2);
}