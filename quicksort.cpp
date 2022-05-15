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

// ******************************** QUICK-SORT *****************************

int partitio(int A[], int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(A[j] <= x) {
            i++;
            zamien(A, i, j);
        }
    }
    zamien(A, i+1, r);
    return i+1;
}

void quicksort(int A[], int p, int r) {
    if(p<r) {
        int q = partitio(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
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
    quicksort(A, 0, N-1);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie quick-sort dla liczb losowych trwalo: " << time_taken << "s" << endl;


    // ************************* SORTOWANIE POSORTOWANYCH *********************************

    timeStart = clock();
    quicksort(A, 0, N-1);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie quick-sort dla liczb posortowanych trwalo: " << time_taken << "s" << endl;


    // ***************** SORTOWANIE POSORTOWANYCH ODWROTNIE *******************************

    ustawOdKonca(A);
    timeStart = clock();
    quicksort(A, 0, N-1);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie quick-sort dla liczb posortowanych od konca trwalo: " << time_taken << "s" << endl;

}
