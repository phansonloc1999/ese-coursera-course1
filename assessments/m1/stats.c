/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main()
{

  unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                              114, 88, 45, 76, 123, 87, 25, 23,
                              200, 122, 150, 90, 92, 87, 177, 244,
                              201, 6, 12, 60, 8, 2, 5, 67,
                              7, 87, 250, 230, 99, 3, 100, 90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_array(unsigned char *array, int size)
{
  printf("\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void sort_array(unsigned char *array, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] >= array[j+1])
      {
        unsigned char temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;

        swapped = true;
      }
    }

    if (!swapped) break;
  }
}

float find_median(unsigned char *array, int size)
{
  sort_array(array, size);
  if (size % 2 == 0)
  {
    return (float)(array[size / 2 - 1] + array[size / 2]) / 2;
  }
  else
    return (float)array[size / 2];
}

float find_mean(unsigned char *array, int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += array[i];
  }

  return sum / size;
}

unsigned char find_maximum(unsigned char *array, int size)
{
  unsigned char max = array[0];
  for (int i = 1; i < size; i++)
  {
    if (max < array[i]) max = array[i];
  }
  return max;
}

unsigned char find_minimum(unsigned char *array, int size)
{
  unsigned char min = array[0];
  for (int i = 1; i < size; i++)
  {
    if (min > array[i]) min = array[i];
  }
  return min;
}

void print_statistics(unsigned char *array, int size)
{
  printf("Median: %.2f\n", find_median(array, SIZE));
  printf("Mean: %.2f\n", find_mean(array, SIZE));
  printf("Maximum: %u\n", find_maximum(array, SIZE));
  printf("Minimum: %u\n", find_minimum(array, SIZE));
}