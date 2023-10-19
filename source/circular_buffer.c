/**
 * @file circular_buffer.c
 * @author buccno 
 * @brief Implementation of the circular buffer source code.
 * @version 0.1
 * @date 2023-10-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "circular_buffer.h"

/*******************************************************************************
 * Macros
*******************************************************************************/

/*******************************************************************************
 * Structs
*******************************************************************************/

// typedef struct circular_buff_config_s
// {
//     uint8_t *p_buffer;
//     uint8_t empty_size;
//     uint8_t max_buff_size;
//     uint8_t head;
//     uint8_t tail;
//     bool buff_full; //is it necessary?

// }circular_buff_config_t;

/*******************************************************************************
 * Private Variables
*******************************************************************************/

// static circular_buff_config_t m_buffer;

static bool m_circ_buffer_initialized = false;

/*******************************************************************************
 * Function Definitions
*******************************************************************************/

// static bool circ_buffer_initialization(circular_buff_config_t* p_buffer);

/*******************************************************************************
 * Function Definitions
*******************************************************************************/

/**
 * @brief 
 * 
 */
h_circular_id circular_buffer_init(circular_buf_t *p_circular,
                                   uint8_t *p_buf, 
                                   size_t size)
{
    if (NULL == p_circular || NULL == p_buf || 0U == size)
    {
        
        printf("circular_buffer_init NULL VALUE ENTERED\n");

        return NULL;
    }

    p_circular->p_buf = p_buf;
    p_circular->size = size;
    p_circular->head = 0U;
    p_circular->tail = 0U;

    printf("buffer successfully initialized...\n");

    return p_circular;
}

bool circular_buffer_write(h_circular_id h_circ, 
                           const uint8_t* p_data, 
                           size_t size)
{
    if (NULL == h_circ)
    {
        printf("circular_buffer_write NULL VALUE ENTERED\n");

        return false;
    }

    circular_buf_t *p_circ = h_circ;

    // calc empty size
    size_t usage;
    size_t diff = 0U;

    if (p_circ->head >= p_circ->tail)
    {
        usage = p_circ->head - p_circ->tail;
    }
    else
    {
        diff = (p_circ->size - p_circ->head);
        usage = diff - p_circ->tail;
    }

    size_t empty = p_circ->size - usage;

    if (empty < size)
    {
        return false;
    }
    
    if (0U != diff)
    {
        (void)memcpy(&p_circ->p_buf[p_circ->head], p_data, diff);

        (void)memcpy(p_circ->p_buf, (p_data + diff), (size - diff));
    
        p_circ->head = (p_circ->head + size) % p_circ->size;
    }
    else
    {
        (void)memcpy(p_circ->p_buf, p_data, size);

        p_circ->head = (p_circ->head + size);
    }

    return true;
}


bool circular_buffer_read(h_circular_id h_circ,
                          uint8_t *p_data, 
                          size_t size)
{
    if ((NULL == p_data) || (0U == size) || (NULL == h_circ))
    {
        return false;
    }

    circular_buf_t *p_circ = h_circ;

    size_t usage = 0U;
    size_t diff = 0U;

    if (p_circ->head >= p_circ->tail)
    {
        usage = p_circ->head - p_circ->tail;
    }
    else
    {
        diff = (p_circ->tail - p_circ->head);
        usage = p_circ->size - diff;
    }

    if (size > usage)
    {
        return false;
    }
    
    if (0U != diff)
    {
        (void)memcpy(p_data, &p_circ->p_buf[p_circ->tail], p_circ->size - p_circ->tail);

        (void)memcpy(p_data, &p_circ->p_buf[0], size - (p_circ->size - p_circ->tail));
        
        memset(&p_circ->p_buf[p_circ->tail], 0, size);

        p_circ->tail = ((p_circ->tail + size) % p_circ->size);

    }
    else
    {
        (void)memcpy(p_data, &p_circ->p_buf[p_circ->tail], size);

        memset(&p_circ->p_buf[p_circ->tail], 0, size);

        p_circ->tail = (p_circ->tail + size);
    }
}




// void circular_buffer_reset(void)
// {
//     if (false == m_buffer.buff_full)
//     {
//         return;
//     }

//     memset(m_buffer.p_buffer, 0, MAX_BUFF_SIZE);

//     m_buffer.buff_full = false;
// }

// void circular_buffer_write(const uint8_t* p_data, uint8_t size)
// {
//     if ((true != m_circ_buffer_initialized) &&
//         (NULL != p_data))
//     {
//         return;
//     }

//     /*check buffer consistency with written data's size*/
//     if (m_buffer.empty_size > size)
//     {
//         (void)memcpy((uint8_t*)&m_buffer.p_buffer[m_buffer.head], 
//                      p_data,
//                      size);
        
//         /*update buffer's started position*/
//         m_buffer.head += size;

//         /*decrease empty size according to written size*/
//         m_buffer.empty_size -= size; 
//     }
//     else
//     {
//         (void)memcpy((uint8_t*)&m_buffer.p_buffer[m_buffer.head], 
//                      p_data,
//                      m_buffer.empty_size);
        
//         /*reset started pos, because buff is full*/
//         m_buffer.head = 0U;

//         (void)memcpy((uint8_t*)&m_buffer.p_buffer[m_buffer.head], 
//                      p_data,
//                      (size - m_buffer.empty_size));

//         m_buffer.head = size - m_buffer.empty_size;
//     }
// }

// void circular_buffer_read(uint8_t *p_data,
//                           const uint8_t size, 
//                           uint8_t head)
// {
//     if ((true != m_circ_buffer_initialized) &&
//         (NULL != p_data))
//     {
//         return;
//     }

//     if (((MAX_BUFF_SIZE - head) + size) < size)
//     {
//         (void)memcpy(p_data, (uint8_t*)&m_buffer.p_buffer[head], size);
//     }
//     else
//     {
//         (void)memcpy(p_data,
//                     (uint8_t*)&m_buffer.p_buffer[head], 
//                     (MAX_BUFF_SIZE - head));

//         (void)memcpy(p_data, 
//                      (uint8_t*)&m_buffer.p_buffer[0U], 
//                      (size - (MAX_BUFF_SIZE - head)));
//     }
// }

// static bool circ_buffer_initialization(circular_buff_config_t* p_buffer)
// {
//     if (NULL == p_buffer)
//     {
//         return false;
//     }

//     uint8_t test_array[MAX_BUFF_SIZE] = {0U};

//     m_buffer.p_buffer = test_array;
    
//     for (uint8_t cnt = 0U; cnt < MAX_BUFF_SIZE; cnt++)
//     {
//         m_buffer.p_buffer[cnt] = 0U;
//     }

//     m_buffer.empty_size = MAX_BUFF_SIZE;
//     m_buffer.head = 0U;
//     m_buffer.buff_full = false;

//     return true;
// }

//end file
