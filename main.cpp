#include "Apriori.h"
#include "Eclat.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>
#include <vector>
#include <ctime>

using namespace std;
using std::bitset;

int main() {
    ifstream fin("data.txt");
    string str;
    bitset<100> data[3500];
    int data_index = 0;
    while(getline(fin, str)) {
        vector<int> nums;
        int last_pos = 0;
        for(int i = 0; i < str.length(); i ++) {
            if(str[i] == ' ') {
                string s = str.substr(last_pos, i - last_pos);
                int num = 0;
                if(s.length() == 1) {
                    num = s[0] - '0';
                }
                else {
                    num = (s[0] - '0') * 10 + (s[1] - '0');
                }
                nums.push_back(num);
                last_pos = i + 1;
            }
        }
        for(int i = 0; i < nums.size(); i ++) {
            data[data_index].set(nums[i]);
        }
        data_index ++;
    }
    printf("Transaction read done\n");

    double min_sup = 0;
    scanf("%lf", &min_sup);

    clock_t start = clock();
    Eclat *my_Eclat = new Eclat(data, data_index, min_sup);
    printf("Eclat Algorithm: \n");
    my_Eclat -> getResult();
    clock_t end = clock();
    double time_spend = (double)(end - start)/(double)(CLOCKS_PER_SEC);
    printf("time spend: %.4lf\n", time_spend);

    start = clock();
    Apriori *my_Apriori = new Apriori(data, data_index, min_sup);
    printf("Apriori Algorithm: \n");
    my_Apriori -> getResult();
    end = clock();
    time_spend = (double)(end - start)/(double)(CLOCKS_PER_SEC);
    printf("time spend: %.4lf\n", time_spend);
    return 0;
}