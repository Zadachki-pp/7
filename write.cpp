#include <iostream>


namespace matrix_utils {
    int** write(int** matrix, int n) {
        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < n; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}