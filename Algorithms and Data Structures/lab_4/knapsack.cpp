#include <iostream>
#include <vector>
#include <limits>
#include <map>


std::map<int, int> w_p;
int putThings(const std::vector<int> &wight, const std::vector<int> &prise, int C) {
    size_t n = wight.size();
    std::vector<std::vector<int>> dinamo(C + 1,std::vector<int>(n+1,0));
    for (size_t j = 1; j <=n;j++){
        for (int c = 1; c <= C ; c++) {
            if (wight[j-1] <= c){
                w_p[wight[j-1]] = prise[j-1];
                dinamo[c][j] = std::max(dinamo[c][j-1],dinamo[c-wight[j-1]][j-1]+prise[j-1]);
            } else{
                dinamo[c][j] = dinamo[c][j-1];
            }
        }
    }
    return dinamo[C][n];
}


int main(){
    int C = 0;
    int n = 0;
    int w = 0;
    int cost = 0;
    std::cin >> C;
    std::cin >> n;
    std::vector<int> wight;
    std::vector<int> prise;
    for (int i = 0; i < n; ++i) {
        std::cin >> w;
        wight.push_back(w);
        std::cin >> cost;
        prise.push_back(cost);
    }
    int rez = putThings(wight,prise, C);
    std::cout << "Max price " <<  rez;
    for (w_p = w_p.begin(),0; i < w_p.size(); ++i) {
        std::cout << i-
    }
}