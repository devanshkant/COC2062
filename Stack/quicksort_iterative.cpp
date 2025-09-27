#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Partition procedure (Procedure 6.5)
int QUICK(vector<int> &A, int BEG, int END) {
    int LEFT = BEG, RIGHT = END, LOC = BEG;
    while (true) {
        // Scan from right to left
        while (A[LOC] <= A[RIGHT] && LOC != RIGHT)
            RIGHT--;
        if (LOC == RIGHT) break;
        if (A[LOC] > A[RIGHT]) {
            swap(A[LOC], A[RIGHT]);
            LOC = RIGHT;
        }

        // Scan from left to right
        while (A[LEFT] <= A[LOC] && LEFT != LOC)
            LEFT++;
        if (LOC == LEFT) break;
        if (A[LEFT] > A[LOC]) {
            swap(A[LEFT], A[LOC]);
            LOC = LEFT;
        }
    }
    return LOC;
}

// Non-recursive QuickSort (Algorithm 6.6)
void quickSort(vector<int> &A, int N) {
    stack<int> LOWER, UPPER;
    LOWER.push(0);
    UPPER.push(N - 1);

    while (!LOWER.empty()) {
        int BEG = LOWER.top(); LOWER.pop();
        int END = UPPER.top(); UPPER.pop();

        if (BEG < END) {
            int LOC = QUICK(A, BEG, END);

            // Push left sublist
            if (BEG < LOC - 1) {
                LOWER.push(BEG);
                UPPER.push(LOC - 1);
            }
            // Push right sublist
            if (LOC + 1 < END) {
                LOWER.push(LOC + 1);
                UPPER.push(END);
            }
        }
    }
}

int main() {
    vector<int> arr = {34, 7, 23, 32, 5, 62};
    int N = arr.size();

    quickSort(arr, N);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
