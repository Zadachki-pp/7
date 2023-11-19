#include <iostream>
#include "read.h"
#include "write.h"
#include "process.h"
#include "delete.h"


int main() {
    int n;
    std::cin >> n;

    int** matrix = matrix_utils::read(n);
    matrix_utils::process(matrix, n);
    matrix_utils::write(matrix, n);
    matrix_utils::delete_(matrix, n);

    return 0;
}
