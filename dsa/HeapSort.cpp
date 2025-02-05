#include<iostream>
using namespace std;

void display(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void heapify(int *array, int n) {
   int i, par, l, r, node;
   for(i = 1; i<= n; i++) {
      node = i; par = (int)node/2;
      while(par >= 1) {
         if(array[par] < array[node])
            swap(array[par], array[node]);
         node = par;
         par = (int)node/2;
      }
   }
}

void heapSort(int *array, int n) {
   int i;

   for(i = n; i>= 1; i--) {
      heapify(array, i);
      swap(array[1], array[i]);
   }
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n+1]; 
   cout << "Enter elements:" << endl;

   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }

   cout << "Array before Sorting: ";
   display(arr, n);
   heapSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}