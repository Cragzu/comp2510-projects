// Created by Chloe Glave (A01166947) on 1/13/2020.

#include "A01166947_multiplication_table.h"
#include <stdio.h>

void multiplicationTable(int size) {
    /*Given the size, prints a square multiplication table from 1 to n^2.*/

    for(int row = 1; row <= size; row++) {
        for (int column = 1; column <= size; column++) {
            printf("%d ", row*column); /*prints one row of numbers in each inner loop*/
        }
        printf("\n"); /*newline after every row*/
    }
}
