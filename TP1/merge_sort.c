/**
 * \file merge_sort.c
 * \brief Merge sort.
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

/*  La recombinaison est de complexité O(n) et celle de toute les divisions de O(logn) donc la complexité total est O(nlogn)


                           [8, 3, 5, 4, 7, 2, 6, 1]   // Tableau initial

                           [8, 3, 5, 4] | [7, 2, 6, 1]   // Division en deux sous-tableaux
                          /                              \
           [8, 3] | [5, 4]               [7, 2] | [6, 1]   // Division en sous-tableaux plus petits
          /            \                  /            \
     [8] | [3]     [5] | [4]        [7] | [2]      [6] | [1]   // Sous-tableaux triés (1 élément chacun)
          \            /                  \            /
       [3, 8]       [4, 5]               [2, 7]       [1, 6]   // Fusion des sous-tableaux (2 éléments chacun)
          \          /                    \          /
          [3, 4, 5, 8]                   [1, 2, 6, 7]          // Fusion des sous-tableaux (4 éléments chacun)
                 \                           /
                  [1, 2, 3, 4, 5, 6, 7, 8]                  // Fusion finale des deux moitiés triées




*/

void merge(long int* array, size_t left, size_t middle, size_t right) {
    size_t i, j, k;
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    long int* leftArray = (long int*)malloc(n1 * sizeof(long int));
    long int* rightArray = (long int*)malloc(n2 * sizeof(long int));

    for (i = 0; i < n1; i++){
        leftArray[i] = array[left + i];
    }
    for (j = 0; j < n2; j++){
        rightArray[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}


void merge_sort_recursive(long int* array, size_t left, size_t right) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;

        merge_sort_recursive(array, left, middle);

        merge_sort_recursive(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}


long int* custom_sort(size_t size, long int* const array) {

    merge_sort_recursive(array, 0, size - 1);
    return array;

}


////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "merge_sort()";
}
