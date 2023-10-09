/*
    #2 Program Bead Sort
    Anggota Kelompok:
    - Yosia Evan (2281020)
    - Deca Caren (2281009)
    - Green Melissa (2281065)
*/

#include <iostream>
using namespace std;

void beadSort(int arr[], int n) {
    // Temukan nilai maksimum dalam array
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    // Inisialisasi array beban
    int* beads = new int[max_num * n];
    for (int i = 0; i < max_num * n; i++) {
        beads[i] = 0;
    }

    // Tempatkan bead pada baris sesuai dengan nilai elemen
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i]; j++) {
            beads[i * max_num + j] = 1;
        }
    }

    // Menampilkan nilai bead sebelum diurutkan
    cout << "Beads sebelum diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < max_num; j++) {
            cout << beads[i * max_num + j] << "\t";
        }
        cout << endl;
    }

    // Biarkan bead jatuh dengan gravitasi
    for (int j = 0; j < max_num; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += beads[i * max_num + j];
            beads[i * max_num + j] = 0;
        }
        for (int i = n - 1; i >= n - sum; i--) {
            beads[i * max_num + j] = 1;
        }
    }

    // Menampilkan bead setelah diurutkan
    cout << "\nBeads setelah diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < max_num; j++) {
            cout << beads[i * max_num + j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Ambil nilai-nilai yang sudah diurutkan dari bawah dan masukkan kembali ke dalam array
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
        for (int j = 0; j < max_num && beads[i * max_num + j]; j++) {
            arr[i]++;
        }
    }

    delete[] beads;
}

int main() {
    int arr[] = {2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diurutkan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << endl;

    beadSort(arr, n);

    cout << "Array setelah diurutkan: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}