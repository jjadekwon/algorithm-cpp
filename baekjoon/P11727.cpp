#include <iostream>

#define MAX 10007

using namespace std;

int dp[1001];
int main() {
    int n;
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MAX;
    }

    cout << dp[n] << endl;
    
    return 0;
}