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

/*******************************************************************************
 * private function definitions
*******************************************************************************/

/**
 * @brief Fill random value to circular buffer
 *  
 */
static uint8_t* random_array_generator(uint8_t* p_array,
                                       size_t size);

/**
 * @brief  Print array to standard output
 *  
 */
static void print_array(uint8_t *p_array, size_t size);

/*******************************************************************************
 * public function definitions
*******************************************************************************/

/**
 * @brief one buffer initialized, filled and 3 timed read.
 * 
 */
void first_scenario(void)
{
    /*init buffer*/
    h_circular_id circ_buff_set_first;

    size_t size = 50U;

    uint8_t first_buff[size];

    memset(first_buff, 0, size* sizeof(uint8_t));

    h_circular_id f_buff = circular_buffer_init(circ_buff_set_first, 
                                                first_buff, 
                                                size);

    if (NULL == f_buff)
    {
        printf("circular_buffer_init return val is NULL\n");

        return;
    }

    /*write buffer*/
    uint8_t p_data[size];

    uint8_t *rand_array = random_array_generator(p_data, size);        

    bool ret_val = circular_buffer_write(f_buff, rand_array, size);  
    
    printf("updated head val = %d\n", f_buff->head);  

    if (true == ret_val)
    {
        printf("successfully written to buffer...\n");
    } 
    
    printf("written buffer = \n");
    print_array(f_buff->p_buf, f_buff->size);  

    /*read buffer*/
    size_t saved_size= 20U;
    uint8_t saved_data[saved_size];

    ret_val = circular_buffer_read(f_buff, saved_data, saved_size);

    if (false == ret_val)
    {
        printf("circular_buffer_read failed\n");
    }

    printf("written buffer = \n");
    print_array(f_buff->p_buf, f_buff->size);  
    printf("taken buffer = \n");
    print_array(saved_data, saved_size); 

    /*read buffer 2*/
    size_t saved_size_2= 10U;
    uint8_t saved_data_2[saved_size_2];


    ret_val = circular_buffer_read(f_buff, saved_data_2, saved_size_2);

    if (false == ret_val)
    {
        printf("circular_buffer_read2 failed\n");
    }

    printf("written buffer2 = \n");
    print_array(f_buff->p_buf, f_buff->size);  
    printf("taken buffer2 = \n");
    print_array(saved_data_2, saved_size_2); 

    /*read buffer 3*/
    size_t saved_size_3= 3U;
    uint8_t saved_data_3[saved_size_3];

    ret_val = circular_buffer_read(f_buff, saved_data_3, saved_size_3);

    if (false == ret_val)
    {
        printf("circular_buffer_rea3 failed\n");
    }

    printf("written buffer3 = \n");
    print_array(f_buff->p_buf, f_buff->size);  
    printf("taken buffer3 = \n");
    print_array(saved_data_3, saved_size_3);  
}

int main()
{
    first_scenario();
}

static uint8_t* random_array_generator(uint8_t* p_array,
                                       size_t size)
{
    for (uint8_t cnt = 0U; cnt < size; cnt++)
    {
        p_array[cnt] = (uint8_t)(rand() % 256);
    }

    return p_array;
}

static void print_array(uint8_t *p_array, size_t size) 
{
    for (uint8_t cnt = 0; cnt < size; cnt++) 
    {
        printf("%u ", p_array[cnt]);
    }

    printf("\n");
}