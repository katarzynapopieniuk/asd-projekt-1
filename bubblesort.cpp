#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 300000
#define ZIARNO 10
using namespace std;

// ****************** WSPOLNE METODY ******************************

void drukuj(int A[]) {
    for(int i=0; i<N; i++) {
        cout << A[i] << ", ";
    }
    cout << endl;
}

void zamien(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void ustawOdKonca(int A[]) {
    for(int i=0; i < N/2; i++) {
        zamien(A, i, N-i-1);
    }
}

void losuj(int A[]) {
    for(int i=0; i<N; i++) {
        A[i] = rand();
    }
}

// ******************************* BABELKOWE **********************************

void bubbleSort(int A[]){
    bool bylaZmiana = true;
    for (int i=0; i<N-1 && bylaZmiana; i++) {
        bylaZmiana = false;
        for (int j=0; j<N-i-1; j++) {
            if (A[j] > A[j+1]) {
                zamien(A, j, j+1);
                bylaZmiana = true;
            }
        }
    }
}

// ********************************** MAIN ************************************

int main() {
    clock_t timeStart, timeEnd;
    double time_taken;

    srand(ZIARNO);
    int A[N];
    losuj(A);

    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;
    cout << "Rozmiar tablicy: " << N << endl;

    // *********************** SORTOWANIE **************************************************

    timeStart = clock();
    bubbleSort(A);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie babelkowe dla liczb losowych trwalo: " << time_taken << "s" << endl;

    // ************************* SORTOWANIE POSORTOWANYCH *********************************

    timeStart = clock();
    bubbleSort(A);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie babelkowe dla liczb posortowanych trwalo: " << time_taken << "s" << endl;

    // ***************** SORTOWANIE POSORTOWANYCH ODWROTNIE *******************************

    ustawOdKonca(A);
    timeStart = clock();
    bubbleSort(A);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie babelkowe dla liczb posortowanych od konca trwalo: " << time_taken << "s" << endl;

}
