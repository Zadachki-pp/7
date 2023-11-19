#include <iostream>
#include "delete.h"


namespace matrix_utils {
    void process(int** matrix, int n) {
        bool is_return = false;

        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < n; j++) {
                if (i != j) {
                    continue;
                }
                // Отрицательные
                if (matrix[i][j] <= 0) {
                    is_return = true;
                }
                // Не содержат 3 и 5
                {
                    bool is_exist = false;
                    int N = matrix[i][j];
                    int number;
                    while (N != 0) {
                        number = N % 10;

                        if (number == 3 || number == 5) {
                            is_exist = true;
                        }

                        N /= 10;
                    }
                    if (!is_exist) {
                        is_return = true;
                    }
                }
            }
        }

        if (is_return) {
            return;
        }

        int **transposed_matrix = new int *[n];
        for (unsigned i = 0; i < n; i++) {
            int *array = new int[n];

            for (unsigned j = 0; j < n; j++) {
                array[j] = matrix[j][i];
            }

            transposed_matrix[i] = array;
        }

        for (unsigned i = 0; i < n; i++) {
            unsigned int min_index = 0;
            {
                int min = transposed_matrix[i][min_index];
                for (unsigned j = 0; j < n; j++) {
                    if (transposed_matrix[i][j] >= min) {
                        continue;
                    }
                    min = transposed_matrix[i][j];
                    min_index = j;
                }
            }

            int new_value = 0;
            for (unsigned j = 0; j < n; j++) {
                if (j == min_index) {
                    continue;
                }
                new_value += transposed_matrix[i][j] * transposed_matrix[i][j];
            }

            transposed_matrix[i][min_index] = new_value;
        }

        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < n; j++) {
                matrix[i][j] = transposed_matrix[j][i];
            }
        }

        matrix_utils::delete_(transposed_matrix, n);
    }
}