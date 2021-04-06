template <class T>
int index_of_largest(T a[], int sze) {
    T max = a[0];
    int index_of_max = 0;
    for (int index = 1; index < sze; index++) {
        if (a[index] > max) {
            max = a[index];
            index_of_max = index;
        }
    }
    return index_of_max;
}