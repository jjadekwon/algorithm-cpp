#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int dwarfs[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> dwarfs[i];
        sum += dwarfs[i];
    }

    sort(dwarfs, dwarfs + 9);

    bool found = false;
    int sumOfSeven = sum;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            sumOfSeven -= (dwarfs[i] + dwarfs[j]);
            if (sumOfSeven == 100) {
                dwarfs[i] = dwarfs[j] = -1;
                found = true;
                break;
            }
            sumOfSeven = sum;
        }

        if (found) break;
    }

    for (int i = 0; i < 9; i++) {
        if (dwarfs[i] > 0) cout << dwarfs[i] << endl;
    }

    return 0;
}