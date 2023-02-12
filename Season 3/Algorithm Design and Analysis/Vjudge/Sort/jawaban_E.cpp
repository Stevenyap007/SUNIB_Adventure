#include <bits/stdc++.h>
using namespace std;

struct Data{
    int num, id;
    char ch;
};

int Partition(Data array[], int p, int r){
    Data x = array[r];
    int i = p-1;

    for (int j = p; j < r; j++)
    {
        if(array[j].num <= x.num){
            i++;
            swap(array[i], array[j]);
        }
    }
    
    swap(array[i+1], array[r]);
    return i+1;
}

void QuickSort(Data array[], int p, int r){
    if(p < r){
        int q = Partition(array, p ,r);
        QuickSort(array, p , q-1);
        QuickSort(array, q+1, r);
    }
}

void check(Data array[], int n){
    for (int i = 1; i < n; i++)
    {
        if(array[i-1].num < array[i].num){
            continue;
        }
        if(array[i-1].id < array[i].id){
            continue;
        }

        cout << "Not stable" << endl;
        return;
    }
    cout << "Stable" << endl;
    
}

int main(){
    int n;
    Data array[100000];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i].ch >> array[i].num;
        array[i].id = i;
    }

    QuickSort(array, 0, n-1);
    check(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i].ch << ' ' << array[i].num << endl;
    }
    
    return 0;
}