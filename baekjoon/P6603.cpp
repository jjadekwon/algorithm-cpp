#include <iostream>

using namespace std;

int k;
int arr[49];
bool selected[49];

void combination(int idx, int count) {
    if (count == 6) {
        for (int i = 0; i < k; i++) {
            if (selected[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;

        return;
    }

    for (int i = idx; i < k; i++) {
        if (!selected[i]) {
            selected[i] = true;
            combination(i, count + 1);
            selected[i] = false;
        }
    }
}

int main() {
    while (true) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        
        combination(0, 0);

        cout << endl;
    }

    return 0;
}