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

// ****************** MERGE-SORT **********************************

void mergeA(int A[], int start, int koniec, int indexPodzialu)
{
    if(A[indexPodzialu] <= A[indexPodzialu+1]) {
        return;
    }

    int start2 = indexPodzialu + 1;

    while (start <= indexPodzialu && start2 <= koniec) {
        if (A[start] <= A[start2]) {
            start++;
        } else {
            int val = A[start2];
            int i = start2;
            while(i != start) {
                A[i] = A[i-1];
                i--;
            }
            A[start] = val;
            start++;
            indexPodzialu++;
            start2++;
        }
    }
}

void mergeSort(int A[], int start, int koniec) {
    if(start == koniec) {
        return;
    }

    int indexPodzialu = start + (koniec-start)/2;
    mergeSort(A, start, indexPodzialu);
    mergeSort(A, indexPodzialu+1, koniec);

    if(koniec - start == 1) {
        if(A[start] > A[koniec]) {
            zamien(A, start, koniec);
        }
        return;
    }

    mergeA(A, start, koniec, indexPodzialu);
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
    mergeSort(A, 0, N-1);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie merge-sort dla liczb losowych trwalo: " << time_taken << "s" << endl;

    // ************************* SORTOWANIE POSORTOWANYCH *********************************

    timeStart = clock();
    mergeSort(A, 0, N-1);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie merge-sort dla liczb posortowanych trwalo: " << time_taken << "s" << endl;

    // ***************** SORTOWANIE POSORTOWANYCH ODWROTNIE *******************************

    ustawOdKonca(A);
    timeStart = clock();
    mergeSort(A, 0, N-1);
    timeEnd = clock();
    time_taken = ((double)(timeEnd - timeStart))/CLOCKS_PER_SEC;
    cout << "Sortowanie merge-sort dla liczb posortowanych od konca trwalo: " << time_taken << "s" << endl;

}
