#include "graph.h"
#include "heap.h"

char ch =0;
int num_vertex=0;
int num_edges=0;
int *visited;
pnode head = NULL;
pnode tail = NULL;

void free_edges(pnode *head)
{
    if ((*head)->neighbours == NULL)
        return;
    pedge tempEdge = (*head)->neighbours;
    while (tempEdge)
    {
        pedge p_edge_free = tempEdge;
        tempEdge = tempEdge->next;
        num_edges--;
        free(p_edge_free);
    }
    (*head)->neighbours = NULL;
}
void delete_graph(pnode *head)
{
    pnode tempHead = *head;
    while (tempHead)
    {
        free_edges(&tempHead);
        pnode p_node_free = tempHead;
        tempHead = tempHead->next;
        free(p_node_free);
    }
    *head = NULL;
}
void print_graph(pnode *head)
{
    printf("-------------------Graph------------------------\n");
    printf("|V| = %d\n", num_vertex);
    printf("|E| = %d\n", num_edges);

    pnode temp_head = *head;
    while (temp_head)
    {
        printf("src: %d ->", temp_head->id);
        pedge temp_edge = temp_head->neighbours;
        while (temp_edge)
        {
            printf("(%d, w=%d), ", temp_edge->dest->id, temp_edge->weight);
            temp_edge = temp_edge->next;
        }
        printf("\n");
        temp_head = temp_head->next;
    }
    printf("------------------------------------------------\n");
}
void graph_init(pnode *head)
{
    if (*head)
        delete_graph(head);
    if (num_vertex == 0)
        return;
    int i = 0;
    char *buff_in = calloc(i, sizeof(*buff_in));
    for (i = 0; (ch = getchar()) != '\n' && !isupper(ch); i++)
    {
        buff_in = realloc(buff_in, ((i + 1) * sizeof(*buff_in)));
        *(buff_in + i) = ch;
    }

    pnode *vert_created = calloc(num_vertex, sizeof(**vert_created));
    int number = num_vertex;
    int _buff_index_ = 0;
    char ch = ' ';
    while (number && _buff_index_ < i)
    {
        ch = *(buff_in + _buff_index_);
        if (ch == ' ' || ch == 'n')
        {
            _buff_index_++;
            continue;
        }
        int src = 0;
        while (isdigit(*(buff_in + _buff_index_)))
        {
            src *= 10;
            src += *(buff_in + _buff_index_) - '0';
            _buff_index_++;
        }
        ch = *(buff_in + _buff_index_);
        if (vert_created[src % num_vertex] == NULL)
        {
            pnode srcNode = malloc(sizeof(*srcNode));
            srcNode->id = src;
            srcNode->neighbours = NULL;
            srcNode->next = NULL;
            vert_created[src % num_vertex] = srcNode;
        }
        number--;
        if (number == 0 || ch == '\n' || ch == 'n' || *(buff_in + _buff_index_ + 1) == 'n')
            continue;
        _buff_index_++;
        while (1)
        {
            int dest = 0;
            while (isdigit(*(buff_in + _buff_index_)))
            {
                dest *= 10;
                dest += *(buff_in + _buff_index_) - '0';
                _buff_index_++;
            }
            num_edges++;
            _buff_index_++;
            pnode destnode;
            if (vert_created[dest % num_vertex] == NULL)
            {
                destnode = malloc(sizeof(*destnode));
                destnode->id = dest;
                destnode->neighbours = NULL;
                destnode->next = NULL;
                vert_created[dest % num_vertex] = destnode;
            }
            else
                destnode = vert_created[dest % num_vertex];
            pedge e = malloc(sizeof(*e));
            int weight = 0;
            while (isdigit(*(buff_in + _buff_index_)))
            {
                weight *= 10;
                weight += *(buff_in + _buff_index_) - '0';
                _buff_index_++;
            }
            e->weight = weight;
            e->dest = destnode;
            e->next = NULL;
            if (vert_created[src % num_vertex]->neighbours != NULL)
            {
                e->next = vert_created[src % num_vertex]->neighbours;
                vert_created[src % num_vertex]->neighbours = e;
            }
            else
            {
                vert_created[src % num_vertex]->neighbours = e;
            }
            if (ch == '\n' || ch == 'n' || *(buff_in + _buff_index_ + 1) == 'n')
                break;
            _buff_index_++;
        }
    }
    for (int i = 0; i < num_vertex - 1; i++)
        vert_created[i]->next = vert_created[i + 1];
    (*head) = vert_created[0];
    if (*head)
        tail = vert_created[num_vertex - 1];
    free(vert_created);
    free(buff_in);
}
void unlink_neighbors(pnode *head, int nodeId)
{

    pnode temp_head = *head;
    while (temp_head)
    {
        if (temp_head->neighbours == NULL)
        {
            temp_head = temp_head->next;
            continue;
        }
        pedge temp_edge = temp_head->neighbours->next;
        pedge temp_edge_previous = temp_head->neighbours;
        if (temp_edge_previous && temp_edge_previous->dest->id == nodeId)
        {
            temp_head->neighbours = temp_edge_previous->next;
            free(temp_edge_previous);
            temp_head = temp_head->next;
            num_edges--;
            continue;
        }
        while (temp_edge && temp_edge->dest->id != nodeId)
        {
            temp_edge = temp_edge->next;
            temp_edge_previous = temp_edge_previous->next;
        }
        if (temp_edge && temp_edge->dest->id == nodeId)
        {
            temp_edge_previous->next = temp_edge->next;
            num_edges--;
            free(temp_edge);
        }
        temp_head = temp_head->next;
    }
}
void del_node(pnode *head)
{
    if (*head == NULL)
        return;
    int nodeId;
    scanf("%d", &nodeId);
    pnode tempHead = (*head)->next;
    pnode prevNode = *head;
    unlink_neighbors(head, nodeId);
    while (tempHead != NULL && tempHead->id != nodeId && prevNode->id != nodeId)
    {
        tempHead = tempHead->next;
        prevNode = prevNode->next;
    }

    if (prevNode->id == nodeId)
    {
        (*head) = prevNode->next;
        free_edges(&prevNode);
        free(prevNode);
        num_vertex--;
        ch = getchar();
        return;
    }
    if (tempHead != NULL)
    {
        prevNode->next = tempHead->next;
        num_vertex--;
        free_edges(&tempHead);
        free(tempHead);
    }
    ch = getchar();
}
void add_node(pnode *head)
{
    pnode tempHead = *head;
    pnode newNode;
    int nodeId;
    scanf("%d", &nodeId);
    while (tempHead != NULL && tempHead->id != nodeId)
        tempHead = tempHead->next;
    if (tempHead == NULL)
    {
        num_vertex++;
        newNode = malloc(sizeof(*newNode));
        tail->next = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode = tempHead;
        free_edges(&newNode);
    }
    int i = 0;
    char *buff_in = calloc(i, sizeof(*buff_in));
    for (i = 0; (ch = getchar()) != '\n' && !isupper(ch); i++)
    {
        buff_in = realloc(buff_in, ((i + 1) * sizeof(*buff_in)));
        *(buff_in + i) = ch;
    }
    newNode->id = nodeId;
    newNode->neighbours = NULL;
    if (i < 3)
    {
        free(buff_in);
        return;
    }
    tempHead = *head;
    int _buff_index_ = 0;
    char ch = ' ';
    while (_buff_index_ < i)
    {
        ch = *(buff_in + _buff_index_);
        if (ch == ' ' || ch == '\n')
        {
            _buff_index_++;
            continue;
        }

        int dest = 0;
        while (isdigit(*(buff_in + _buff_index_)))
        {
            dest *= 10;
            dest += *(buff_in + _buff_index_) - '0';
            _buff_index_++;
        }
        _buff_index_++;
        num_edges++;
        while (tempHead != NULL && tempHead->id != dest)
            tempHead = tempHead->next;
        if (tempHead == NULL)
            break;

        pedge e = malloc(sizeof(*e));
        int weight = 0;
        while (isdigit(*(buff_in + _buff_index_)))
        {
            weight *= 10;
            weight += *(buff_in + _buff_index_) - '0';
            _buff_index_++;
        }
        e->weight = weight;
        e->dest = tempHead;
        e->next = NULL;
        if (newNode->neighbours != NULL)
        {
            e->next = newNode->neighbours;
            newNode->neighbours = e;
        }
        else
            newNode->neighbours = e;
        tempHead = *head;
        _buff_index_++;
    }
    free(buff_in);
}
int dijkstra(pnode *head, int src, int dest)
{
    visited = NULL;
    pnode tempHead = (*head);
    // Min Heap Memory O(|V|)
    min_heap *heap = create_heap(num_vertex);
    if (heap == NULL)
    {
        printf("__Memory Issue__\n");
        return -1;
    }
    // O(V)
    while (tempHead)
    {
        tempHead->distance = (tempHead->id == src) ? 0 : INFINITY;
        add(heap, &tempHead);
        tempHead = tempHead->next;
    }
    // int i = 0;
    while (heap->size)
    {
        // printf("---%d---\n", i++);
        // print(heap);
        pnode node = pop_min(heap);
        // printf("id -> %d distance -> %d\n", node->id, node->distance);
        pedge edge = node->neighbours;
        while (edge)
        {
            int distance;
            distance = node->distance + edge->weight;
            // printf("%d\n", distance);

            if (distance < edge->dest->distance)
            {
                edge->dest->distance = distance;
                edge->dest->previous = node;
            }
            edge = edge->next;
        }
        heapify_top_bottom(heap, 0);
        // print(heap);
    }
    tempHead = (*head);
    while (tempHead)
    {
        if (tempHead->id == dest)
            break;
        tempHead = tempHead->next;
    }
    int path = tempHead->distance;
    if (path == INFINITY)
    {
        visited = malloc(sizeof(int));
        visited[0] = path;
        free(heap->vert_arr);
        free(heap);
        return 1;
    }
    int size = 0;

    visited = malloc(size * sizeof(int));
    while (tempHead && tempHead->id != src)
    {
        size++;
        visited = realloc(visited, size * sizeof(int));
        visited[size - 1] = tempHead->id;
        tempHead = tempHead->previous;
    }
    size++;
    visited = realloc(visited, size * sizeof(int));
    visited[size - 1] = src;
    size++;
    visited = realloc(visited, size * sizeof(int));
    visited[size - 1] = path;
    tempHead = (*head);
    // while (tempHead)
    // {
    //     printf("id -> %d distance -> %d\n", tempHead->id, tempHead->distance);
    //     tempHead = tempHead->next;
    // }

    free(heap->vert_arr);
    free(heap);
    return size;
}
void shortest_path(pnode *head)
{
    int src, dest;
    scanf("%d %d", &src, &dest);
    // printf("src %d dest %d\n", src, dest);
    int size = dijkstra(head, src, dest);
    // printf("%d", size);
    if (size == -1)
        return;
    pnode tempHead = (*head);
    // printf("\n---------------- visited -------------------\n");

    // while (size--)
    // {
    //     printf("%d ", visited[size]);
    // }
    // printf("\n------------------------------------------------\n");

    while (tempHead)
    {
        if (tempHead->id == dest)
        {
            printf("Dijsktra shortest path: %d \n", (tempHead->distance) < INFINITY ? (tempHead->distance) : -1);
            break;
        }
        tempHead = tempHead->next;
    }
    // printf("[");
    // while (tempHead && tempHead->id != src)
    // {
    //     printf("%d ", tempHead->id);
    //     tempHead = tempHead->previous;
    // }
    // if (tempHead)
    //     printf("%d ", tempHead->id);
    // printf("]\n");
    free(visited);
    ch = getchar();
}
/*
void TSP_cmd(pnode *head)
{
    int count_cities;
    scanf("%d", &count_cities);
    int *cities = malloc(count_cities * sizeof(int));
    int i = 0;
    while ((count_cities - i))
        scanf("%d", &cities[i++]);
    ch = getchar();
    // print cities
    printf("\n------------------cities------------------\n");
    for (int i = 0; i < count_cities; i++)
    {
        printf("%d ", cities[i]);
    }
    printf("| size %d \n", count_cities);
    if (count_cities <= 1)
    {
        free(cities);
        printf("TSP shortest path: 0 ");
        return;
    }
    int count = count_cities - 2;
    int distance = 0;
    int cityPath = dijkstra(head, cities[0], cities[1]);
    // print dijakstra
    printf("\n------------------dijakstra------------------\n");
    for (int i = cityPath - 2; i >= 0; i--)
    {
        printf("%d ", visited[i]);
    }
    printf("| size %d \n", cityPath - 1);

    int *citiesPathList = malloc((cityPath - 1) * sizeof(int));
    int count_citiesPathList = cityPath - 1;
    if (visited[cityPath - 1] == INFINITY)
    {
        printf("TSP shortest path: -1 ");
        free(visited);
        free(cities);
        free(citiesPathList);
        return;
    }
    distance += visited[--cityPath];
    int p = 0;
    while (cityPath)
    {
        cityPath--;
        citiesPathList[p++] = visited[cityPath];
    }
    // print citiesPathList
    printf("\n------------------citiesPathList------------------\n");
    for (int i = 0; i < count_citiesPathList; i++)
    {
        printf("%d ", citiesPathList[i]);
    }
    printf("| size %d \n", count_citiesPathList);
    printf("TSP shortest path: %d \n", distance);
    if(count)
        free(visited);
    p = 2;
    int flag = 0;
    while (count)
    {
        for (int i = 0; i < count_citiesPathList; i++)
        {
            if (cities[p] == citiesPathList[i])
            {
                p++;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            flag = 0;
            count--;
            continue;
        }
        cityPath = dijkstra(head, citiesPathList[count_citiesPathList - 1], cities[p]);
        printf("\n------------------dijakstra------------------\n");
        for (int i = cityPath - 2; i >= 0; i--)
        {
            printf("%d ", visited[i]);
        }
        printf("| size %d \n", cityPath - 1);
        if (visited[--cityPath] == INFINITY)
        {
            printf("TSP shortest path: -1 ");
            free(visited);
            free(cities);
            free(citiesPathList);
            return;
        }
        distance += visited[cityPath];
        int index = count_citiesPathList;
        while (cityPath)
        {
            for (int i = 0; i < count_citiesPathList; i++)
            {
                if (citiesPathList[i] == visited[cityPath - 1])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
            {
                citiesPathList = realloc(citiesPathList, (count_citiesPathList + 1) * sizeof(int));
                citiesPathList[index++] = visited[cityPath - 1];
                count_citiesPathList++;
                flag = !flag;
            }
            flag = 0;
            cityPath--;
        }
        printf("\n------------------citiesPathList------------------\n");
        for (int i = 0; i < count_citiesPathList; i++)
        {
            printf("%d ", citiesPathList[i]);
        }
        printf("| size %d \n", count_citiesPathList);
        printf("TSP shortest path: %d \n", distance);
        p++;
        count--;
        if (count)
            free(visited);
    }
    if (ch == ' ')
        ch = getchar();
    free(cities);
    free(citiesPathList);
    free(visited);
}*/

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void tsp(pnode *head)
{
    int count_cities;
    scanf("%d", &count_cities);
    int *cities = malloc(count_cities * sizeof(int));
    int i = 0;
    while ((count_cities - i))
        scanf("%d", &cities[i++]);
    ch = getchar();
    // print cities
    // printf("\n------------------cities------------------\n");
    // for (int i = 0; i < count_cities; i++)
    // {
    //     printf("%d ", cities[i]);
    // }
    // printf("| size %d \n", count_cities);
    if (count_cities <= 1)
    {
        free(cities);
        cities = NULL;
        printf("TSP shortest path: 0\n");
        return;
    }
    int minDistance = INFINITY;
    int *permute = malloc(count_cities * sizeof(int));
    for (int i = 0; i < count_cities; i++)
        permute[i] = i;
    int *temp_permute = calloc(count_cities, sizeof(int));
    int index_i = 0;
    int h = -1;
    while (index_i < count_cities)
    {
        if (temp_permute[index_i] < index_i)
        {
            if (h >= 0)
            {
                if (index_i % 2 == 0)
                    swap(permute, 0, index_i);
                else
                    swap(permute, temp_permute[index_i], index_i);
            }
            else
            {
                temp_permute[index_i] = 0;
                index_i--;
            }
            h++;
            int count = count_cities - 2;
            int distance = 0;
            int cityPath = dijkstra(head, cities[permute[0]], cities[permute[1]]);
            // print dijakstra
            // printf("\n------------------dijakstra------------------\n");
            // for (int i = cityPath - 2; i >= 0; i--)
            // {
            //     printf("%d ", visited[i]);
            // }
            // printf("| size %d \n", cityPath - 1);

            int *citiesPathList = malloc((cityPath - 1) * sizeof(int));
            int count_citiesPathList = cityPath - 1;
            if (visited[cityPath - 1] == INFINITY)
            {
                // printf("TSP shortest path: -1 ");
                free(visited);
                visited = NULL;
                free(citiesPathList);
                citiesPathList = NULL;
                temp_permute[index_i] += 1;
                index_i = 0;
                continue;
            }
            distance += visited[--cityPath];
            int p = 0;
            while (cityPath)
            {
                cityPath--;
                citiesPathList[p++] = visited[cityPath];
            }
            // print citiesPathList
            // printf("\n------------------citiesPathList------------------\n");
            // for (int i = 0; i < count_citiesPathList; i++)
            // {
            //     printf("%d ", citiesPathList[i]);
            // }
            // printf("| size %d \n", count_citiesPathList);
            // printf("TSP shortest path: %d \n", distance);
            if (count == 0)
            {
                free(visited);
                visited = NULL;
                free(citiesPathList);
                citiesPathList = NULL;
                temp_permute[index_i] += 1;
                minDistance = MIN(distance, minDistance);
                index_i = 0;
                continue;
            }
            p = 2;
            int flag = 0;
            while (count)
            {
                for (int i = 0; i < count_citiesPathList; i++)
                {
                    if (cities[permute[p]] == citiesPathList[i])
                    {
                        p++;
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                {
                    flag = 0;
                    count--;
                    continue;
                }
                free(visited);
                visited = NULL;
                cityPath = dijkstra(head, citiesPathList[count_citiesPathList - 1], cities[permute[p]]);
                // printf("\n------------------dijakstra------------------\n");
                // for (int i = cityPath - 2; i >= 0; i--)
                // {
                //     printf("%d ", visited[i]);
                // }
                // printf("| size %d \n", cityPath - 1);
                if (visited[--cityPath] == INFINITY)
                {
                    // printf("TSP shortest path: -1 ");
                    free(visited);
                    visited = NULL;
                    free(citiesPathList);
                    citiesPathList = NULL;
                    distance = INFINITY;
                    flag = 1;
                    break;
                }
                distance += visited[cityPath];
                int index = count_citiesPathList;
                while (cityPath)
                {
                    for (int i = 0; i < count_citiesPathList; i++)
                    {
                        if (citiesPathList[i] == visited[cityPath - 1])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag != 1)
                    {
                        citiesPathList = realloc(citiesPathList, (count_citiesPathList + 1) * sizeof(int));
                        citiesPathList[index++] = visited[cityPath - 1];
                        count_citiesPathList++;
                        flag = !flag;
                    }
                    flag = 0;
                    cityPath--;
                }
                // printf("\n------------------citiesPathList------------------\n");
                // for (int i = 0; i < count_citiesPathList; i++)
                // {
                //     printf("%d ", citiesPathList[i]);
                // }
                // printf("| size %d \n", count_citiesPathList);
                // printf("TSP shortest path: %d \n", distance);
                p++;
                count--;
                if (count)
                {
                    free(visited);
                    visited = NULL;
                }
            }
            minDistance = MIN(distance, minDistance);
            if (flag != 1)
            {
                free(citiesPathList);
                citiesPathList = NULL;
                free(visited);
                visited = NULL;
            }
            temp_permute[index_i] += 1;
            index_i = 0;
            if (citiesPathList != NULL)
                free(citiesPathList);
            if (visited != NULL)
                free(visited);
        }
        else
        {
            temp_permute[index_i] = 0;
            index_i++;
        }
    }

    free(cities);
    cities = NULL;
    free(permute);
    permute = NULL;

    free(temp_permute);
    temp_permute = NULL;
    // printf("\n___________________________________\n");
    if (minDistance < INFINITY)
        printf("TSP shortest path: %d \n", minDistance);
    else
        printf("TSP shortest path: -1 \n");
    // printf("\n___________________________________\n");

    if (ch == ' ')
        ch = getchar();
}