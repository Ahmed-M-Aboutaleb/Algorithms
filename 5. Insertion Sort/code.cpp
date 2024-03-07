#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> &array) {
    for (int i = 1; i < array.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j+1] < array[j])
        {
            int temp = array[j+1];
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
    return array;
}