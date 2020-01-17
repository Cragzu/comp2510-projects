// Created by Chloe Glave (A01166947) on 1/17/2020.

#include <stdio.h>
#include <stdbool.h>
#include "lecture2.h"

void increment(int *number) {
    printf("number: %d, number value: %p\n", *number, number);
    *number += 1;
    printf("number: %d, number value: %p\n", *number, number);
}