#include <iostream>
#include <cstdlib>
using namespace std;

int d[101][100001];
int main(){
    
    int n = 0;
    int k = 0;
    cin >> n >> k;
    int w[101] = {0, };
    int v[101] = {0, };
    int weight = 0;
    int value = 0;
    for (int i =1; i <= n; i++){
        cin >> weight >> value;
        if (k >= weight) {
            w[i] = weight;
            v[i] = value;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            d[i][j] = d[i - 1][j];
            if (j - w[i] >= 0) {
                d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);//계산식
            }
        }
    }
    
    cout << d[n][k] << endl;
    return 0;
}
