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

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

void circular_buffer_init(void);
void circular_buffer_reset(void);
void circular_buffer_add(void);
void circular_buffer_check(void);


uint8_t make_file_test(void);

#endif /* CIRCULAR_BUFFER_H_ */
