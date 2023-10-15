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


void print_array(uint8_t *p_array, size_t size) 
{
    for (uint8_t cnt = 0; cnt < size; cnt++) 
    {
        printf("%u ", p_array[cnt]);
    }

    printf("\n");
}

void first_scenario(void)
{
    h_circular_id circ_buff_set_first;

    uint8_t *first_buff;

    size_t size = 50U;

    h_circular_id f_buff = circular_buffer_init(circ_buff_set_first, 
                                                first_buff, 
                                                size);
    if (NULL == f_buff)
    {
        return;
    }

    uint8_t p_data[3U] = {0xAAU, 0xAAU, 0xAAU};        

    bool ret_val = circular_buffer_write(f_buff, p_data, 3U);     

    print_array(f_buff->p_buf, 3U);                              
}


int main()
{
    first_scenario();
}