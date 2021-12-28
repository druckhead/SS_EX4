/**
 * @file nodes.h
 * @author daniel raz (https://github.com/druckhead)
 * @brief
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __NODE_H__

#define __NODE_H__

#include "edges.h"
typedef struct Node
{
    int id;
    edge_list neighbors;
} node, *node_list;

#endif