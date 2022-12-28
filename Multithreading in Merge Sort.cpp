#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;
// Merge two subarrays L and M into arr
void merge(vector<int>& arr, const vector<int>& L, const vector<int>& M) {
 int i = 0, j = 0, k = 0;
 while (i < L.size() && j < M.size()) {
 if (L[i] < M[j]) {
 arr[k] = L[i];
 i++;
 } else {
 arr[k] = M[j];
 j++;
 }
 k++;
 }
 // Copy remaining elements of L, if there are any
 while (i < L.size()) {
 arr[k] = L[i];
 i++;
 k++;
 }
 // Copy remaining elements of M, if there are any
 while (j < M.size()) {
 arr[k] = M[j];
 j++;
 k++;
 }
}
// Divide the array into two subarrays, sort them, and merge the sorted subarrays
void mergeSort(vector<int>& arr) {
 if (arr.size() <= 1) return;
 int mid = arr.size() / 2;
 vector<int> L(arr.begin(), arr.begin() + mid);
 vector<int> M(arr.begin() + mid, arr.end());
 // Sort the two subarrays in parallel using multithreading
 thread t1([&] { mergeSort(L); });
 thread t2([&] { mergeSort(M); });
 t1.join();
 t2.join();
 // Merge the sorted subarrays
 merge(arr, L, M);
}
int main() {
 vector<int> arr = {5, 2, 4, 7, 1, 3, 2, 6};
 mergeSort(arr);
 // Print the sorted array
 for (int x : arr) {
 cout << x << " ";
 }
 cout << endl;
 return 0;
}
