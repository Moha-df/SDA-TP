/**
 * \file bubble_sort.c
 * \brief Bubble sort.
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

// Dans le pire des cas la complexité est O(n²) et dans le meilleur cas O(n)

long int* custom_sort(size_t size, long int* const array)
{
  bool trier = false;
  size_t max = size -1;

  while (!trier) {
    trier = true; 

    for (size_t i = 0; i < max; ++i) {
      if (array[i] > array[i + 1]) {
        long int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        trier = false;
      }
    }
    max--;
  }
  
  (void) size; (void) array;
  return array;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "bubble_sort()";
}

