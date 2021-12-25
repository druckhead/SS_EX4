/**
 * @file edges.h
 * @author daniel raz (https://github.com/druckhead)
 * @brief
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __EDGE_H__

#define __EDGE_H__

typedef struct Edge
{
    int weight;
    int src;
    int dest;
} Edge;

#endif