/**
 * @file circular_buffer.h
 * @author buccno
 * @brief 
 * @version 0.1
 * @date 2023-10-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

typedef struct circular_buf_s *h_circular_id;

typedef struct circular_buf_s circular_buf_t;

struct circular_buf_s
{
    uint8_t *p_buf;
    size_t size;
    size_t head;
    size_t tail;
};

h_circular_id circular_buffer_init(circular_buf_t *p_circular,
                                   uint8_t *p_buf, 
                                   size_t size);

void circular_buffer_destroy(h_circular_id h_circ);

bool circular_buffer_write(h_circular_id h_circ,
                           const uint8_t* p_data, 
                           size_t size);

bool circular_buffer_read(h_circular_id h_circ,
                          uint8_t *p_data, 
                          size_t size);


#endif /* CIRCULAR_BUFFER_H_ */
