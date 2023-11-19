#include <iostream>


namespace matrix_utils {
    int** read(const int n) {
        int** matrix = new int *[n];

        for (unsigned i = 0; i < n; i++) {
            int* array = new int[n];

            for (unsigned j = 0; j < n; j++) {
                std::cin >> array[j];
            }

            matrix[i] = array;
        }

        return matrix;
    }
}