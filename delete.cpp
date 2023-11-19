#include <iostream>


namespace matrix_utils {
    void delete_(int** matrix, int n) {
        for (unsigned i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}