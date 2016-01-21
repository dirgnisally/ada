#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
int  merge(int list1[ ] , int tam1 , int list2[ ] , int tam2 , int list3[ ], int tam)
{
    int i1, i2, i3;
    if (tam1+tam2 > tam) {
        return false;
    }
    i1 = 0; i2 = 0; i3 = 0;
    
    while (i1 < tam1 && i2 < tam2) {
        if (list1[i1] < list2[i2]) {
            list3[i3++] = list1[i1++];
        } 
        else {
            list3[i3++] = list2[i2++];
        }
    }
    while (i1 < tam1) {   
        
        list3[i3++] = list1[i1++];
    }
    while (i2 < tam2) { 
        
        list3[i3++] = list2[i2++];
    }
    return true;
}

void merge_sort (int A[], int tam)
{
    int temp[tam];
    int mid, i;
    if (tam < 2) {
        return;
    } 
    else {
        mid = tam / 2;
        merge_sort(A, mid);
        merge_sort(A + mid, tam - mid);
        merge (A, mid, A + mid, tam - mid, temp, tam);
        for (i = 0; i < tam; i++) {
            A[i] = temp[i];
        }
    }
}

void insert(int A[], int tam){
     int key;
     int i;
     for (int j = 1; j < tam; j++) {
            key = A[j];
            i = j-1;
            while ((i > -1)&& (A[i] > key))
            {    A[i+1] = A[i];
                 i = i-1;
            }

            A[i+1] = key;
     }
}

int main() 
{
    int a[] = {2, 42, 3, 7, 1};
    merge_sort(a,5);
    //insert(a,5);
    for (int i = 0; i<= 4 ; ++i)
        cout << a[i] << endl;
    return (0);

}
