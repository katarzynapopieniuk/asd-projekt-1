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

// ******************************* HEAP-SORT **********************************

int lewyDzieciak(int rodzic) {
    return 2*rodzic + 1;
}

int prawyDzieciak(int rodzic) {
    return 2*rodzic + 2;
}

void przywrocWlasnoscKopca(int A[], int sizeA, int nrElementu) {
    int l = lewyDzieciak(nrElementu);
    int r = prawyDzieciak(nrElementu);
    int largest;
    if(l < sizeA && A[l] > A[nrElementu]) {
        largest = l;
    } else {
        largest = nrElementu;
    }
    if(r < sizeA && A[r] > A[largest]) {
        largest = r;
    }
    if(largest != nrElementu) {
        zamien(A, largest, nrElementu);
        przywrocWlasnoscKopca(A, sizeA, largest);
    }
}

void zbudujKopiec(int A[], int sizeA) {
    int rozmiarKopca = sizeA;
    for(int i=sizeA/2; i >= 0; i--) {
        przywrocWlasnoscKopca(A, rozmiarKopca, i);
    }
}

void heapSort(int A[]) {
    int sizeA = N;
    zbudujKopiec(A, sizeA);
    for(int i=N-1; i>=1; i--) {
        zamien(A, 0, i);
        sizeA--;
        przywrocWlasnoscKopca(A, sizeA, 0);
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
    heapSort(A);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie heap-sort dla liczb losowych trwalo: " << time_taken << "s" << endl;

    // ************************* SORTOWANIE POSORTOWANYCH *********************************

    timeStart = clock();
    heapSort(A);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie heap-sort dla liczb posortowanych trwalo: " << time_taken << "s" << endl;

    // ***************** SORTOWANIE POSORTOWANYCH ODWROTNIE *******************************

    ustawOdKonca(A);
    timeStart = clock();
    heapSort(A);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie heap-sort dla liczb posortowanych od konca trwalo: " << time_taken << "s" << endl;
}
