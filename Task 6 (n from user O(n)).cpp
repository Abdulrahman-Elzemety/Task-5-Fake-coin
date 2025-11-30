#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the total number of coins: ";
    cin >> n;

    int* coins = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter weight of coin " << (i + 1) << ": ";
        cin >> coins[i];
    }


    int groupSize = n / 3;

    int totalA = 0, totalB = 0, totalC = 0;

    for (int i = 0; i < groupSize; i++)
        totalA += coins[i];

    for (int i = groupSize; i < 2 * groupSize; i++)
        totalB += coins[i];

    for (int i = 2 * groupSize; i < 3 * groupSize; i++)
        totalC += coins[i];


    if (totalA == totalB) {
        if (totalA > totalC) {
            cout << "The fake coin is lighter.\n";
        }
        else if (totalA < totalC) {
            cout << "The fake coin is heavier.\n";
        }
        else {
            int realCoin = coins[0];

            for (int i = 3 * groupSize; i < n; i++) {
                if (coins[i] < realCoin) {
                    cout << "The fake coin is lighter.\n";
                }
                else if (coins[i] > realCoin) {
                    cout << "The fake coin is heavier.\n";
                }
            }
        }
    }


    else if (totalA > totalB) {
        if (totalC < totalA) {
            cout << "The fake coin is heavier.\n";
        }
        else {
            cout << "The fake coin is lighter.\n";
        }
    }

    else if (totalB > totalA) {
        if (totalC < totalB) {
            cout << "The fake coin is heavier.\n";
        }
        else {
            cout << "The fake coin is lighter.\n";
        }
    }
}
