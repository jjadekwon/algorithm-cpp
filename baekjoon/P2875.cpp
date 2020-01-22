#include <iostream>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int team = M * 2 <= N ? M : N / 2;
    int rest = (N + M) - team * 3;
    if (rest < K) {
        int p = (K - rest) / 3;
        int q = (K - rest) % 3;
        
        if (q != 0) ++p;
        team -= p;
    }
    
    cout << team << endl;

    return 0;
}