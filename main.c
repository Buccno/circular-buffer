/**
 * @file main.c
 * @author buccno 
 * @brief Implementation of the main function.ç
 * @version 0.1
 * @date 2023-10-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "source/circular_buffer.h"


int main()
{
    uint8_t my_ret_val = make_file_test();

    if (0 <= my_ret_val)
    {
        printf("my_ret_val = %d\n", my_ret_val);
    }
    else
    {
        printf("failed");
    }

    return 0;
}