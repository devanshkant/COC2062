#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Partition function, parameters = vector, left, right
//partition function  arr[left] ko uski sahi jagah par pahunchata hai, jo sorted array mein hogi 
//aur us sahi jagah ka index return karta h

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (arr[i] <= pivot && i <= right - 1) {
            ++i;
        }
        while (arr[j] > pivot && j >= left + 1) {
            --j;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    return j;
}
// QuickSort function
void qs(vector<int> &arr, int left, int right) {
    if (left < right) {
        int partition_index = partition(arr, left, right);
        qs(arr, left, partition_index - 1);
        qs(arr, partition_index + 1, right);
    }
}


int main() {
    vector<int> arr = {4, 6, 2, 5, 5, 6, 6, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using QuickSort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    qs(arr,0, arr.size());

    cout << "After Using QuickSort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
