#include <stdio.h>
#include <stdbool.h>

#ifndef RunTests

bool ValidateBounds(int row, int col, int max_rows, int max_cols);
bool can_travel_to(bool *game_matrix, int rows, int cols, int from_row,
                   int from_column, int to_row, int to_column);
bool ValidateMovement(int fromRow, int fromCol, int toRow, int toCol);

int main() {
    bool game_matrix[6][6] = {
        {false, true,  true,  false, false, false},
        {true,  true,  true,  false, false, false},
        {true,  true,  true,  true,  true,  true},
        {false, true,  true,  false, true,  true},
        {false, true,  true,  true,  false, true},
        {false, false, false, false, false, false},
    };

    printf("%d\n", can_travel_to((bool*) game_matrix, 6, 6, 3, 2, 2, 2)); // true, Valid move
    printf("%d\n", can_travel_to((bool*) game_matrix, 6, 6, 3, 2, 3, 4)); // false, Can't travel through land
    printf("%d\n", can_travel_to((bool*) game_matrix, 6, 6, 3, 2, 6, 2)); // false, Out of bounds
}

bool ValidateBounds(int row, int col, int max_rows, int max_cols) {
    // Ensure indices are within bounds
    return (row >= 0 && row < max_rows && col >= 0 && col < max_cols);
}

bool can_travel_to(bool *game_matrix, int rows, int cols, int from_row,
                   int from_column, int to_row, int to_column) {
    // Validate overall bounds first
    if (!ValidateBounds(from_row, from_column, rows, cols) || 
        !ValidateBounds(to_row, to_column, rows, cols)) {
        return false;
    }

    // Validate movement is possible
    if (!ValidateMovement(from_row, from_column, to_row, to_column)) {
        return false;
    }

    // Check if the path is clear
    if (from_row == to_row) {  // Horizontal move
        int start_col = (from_column < to_column) ? from_column : to_column;
        int end_col = (from_column < to_column) ? to_column : from_column;
        for (int col = start_col; col <= end_col; col++) {
            if (!game_matrix[(from_row * cols) + col]) {
                return false;
            }
        }
    } else if (from_column == to_column) {  // Vertical move
        int start_row = (from_row < to_row) ? from_row : to_row;
        int end_row = (from_row < to_row) ? to_row : from_row;
        for (int row = start_row; row <= end_row; row++) {
            if (!game_matrix[(row * cols) + from_column]) {
                return false;
            }
        }
    }

    return true;  // Path is valid
}

bool ValidateMovement(int fromRow, int fromCol, int toRow, int toCol) {
    // Allow movement in 4 directions: right, left, up, down
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    if (rowDiff == 0 && (colDiff == 1 || colDiff == -1)) { // Horizontal move
        return true;
    } else if (colDiff == 0 && (rowDiff == 1 || rowDiff == -1)) { // Vertical move
        return true;
    }

    // Add additional movement validation if necessary (e.g., two-step moves)
    if (colDiff == 2 || colDiff == -2) {  // Horizontal move by 2
        return true;
    }

    return false;  // Invalid movement
}

#endif
