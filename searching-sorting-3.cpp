/*
    #3 Program Insertion Sort
    Anggota Kelompok:
    - Yosia Evan (2281020)
    - Deca Caren (2281009)
    - Green Melissa (2281065)
*/

#include <iostream>
using namespace std;

int main() {
    // Deklarasi array dengan 10 elemen
    int array[] = {77, 42, 35, 12, 101, 5, 17, 1, 8, 90};
    // Mencari ukuran array
    int size = sizeof(array)/sizeof(array[0]);

    // Menampilkan isi array sebelum diurutkan
    cout << "Elemen sebelum diurutkan:" << endl;
    for(int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;
    cout << endl;

    // Proses insertion sort
    for(int i = 1; i < size; i++) {
        cout << "Perulangan ke-" << i << ": " << endl;
        for(int j = i; j > 0; j--) {
            if(array[j] < array[j-1]) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            } else { 
                break;
            }
            for(int k = 0; k < size; k++) {
                cout << array[k] << "\t";
            }
            cout << endl;
        }
    }

    // Menampilkan isi array setelah diurutkan
    cout << "\nElemen setelah diurutkan:" << endl;
    for(int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }

    return 0;
}