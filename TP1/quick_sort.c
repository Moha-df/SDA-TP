/**
 * \file quick_sort.c
 * \brief Quick sort.
 * \date 2017
 * \author YOU
 * \copyright WTFPLv2
 */

/* Copyright © 2017 YOU <you@etu.unistra.fr>
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar.
 *
 * See http://www.wtfpl.net/ or read below for more details.
 */
/* DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 */
#include "custom_sort.h"

#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////

//  complexité O(NlogN)

void swap(long int* a, long int* b) {
    long int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long int* array, int left, int right) {
    long int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[right]); 
    return i + 1;
}

void quicksort(long int* array, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(array, left, right);
        quicksort(array, left, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, right);
    }
}

long int* custom_sort(size_t size, long int* const array)
{
    quicksort(array, 0, size - 1);
    return array;
}


////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "quick_sort()";
}
