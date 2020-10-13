#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 0) {
            return 0;
        }
        int min_price = prices[0];
        int max_profix = 0;

        for ( int i = 1; i < prices.size(); i++) {
            printf("[%d] ", i);
            if (prices[i] < min_price) {
                printf("prices[%d]:%d < min_price:%d, update min_price:%d \n", i, prices[i], min_price, prices[i]);
                min_price = prices[i];
            } else {
                if(prices[i] - min_price > 0) {
                    printf("prices[%d]:%d, old min_price:%d, ", i , prices[i], min_price);
                    max_profix += (prices[i] - min_price);
                    min_price = prices[i]; // the original min_price can not be used again
                    
                    printf("max_profix:%d, new min_price:%d\n", max_profix, min_price);
                }
            }
        }

        return max_profix;
    }

};


int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> prices{ 7,1,5,3,6,4 };
    printf("output:%d\n", s -> maxProfit(prices));
}
