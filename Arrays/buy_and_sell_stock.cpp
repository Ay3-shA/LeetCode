#include <iostream>
using namespace std;

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n=6;
    int maxProfit = 0;
    int bestBuy = prices[0];

    for(int i=1; i<n; i++){
        if(prices[i]>bestBuy){
            maxProfit=max(maxProfit, prices[i]-bestBuy);
        }
        bestBuy=min(bestBuy, prices[i]);
    }
    cout<<maxProfit;


    return 0;
}