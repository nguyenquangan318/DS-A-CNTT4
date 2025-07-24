#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc do thi
typedef struct Graph {
    //so dinh trong do thi
    int V;
    //ma tran dai dien cho do thi
    int **matrix;
} Graph;
//Xay dung ham khoi tao do thi
Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    //cap phat bo nho cho mang 2 chieu VxV
    graph->matrix = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        //cap phat bo nho cho tung mang con trong mang 2 chieu
        graph->matrix[i] = (int *) calloc(V, sizeof(int));
    }
    return graph;
}
//Xay dung ham ket noi 2 dinh
void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
//In ma tran
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    //0: 1 3
    //1: 0
    //2:
    //3: 0
}
//Xay dung ham duyet DFS
void DFSUtil(Graph *graph, int src, int *visited) {
    //B1: In ra dinh src va danh dau da di qua
    printf("%d ", src);
    visited[src] = 1;
    //B2: Kiem tra cac duong co the di tu dinh src
    //su dung vong lap voi tat ca dinh trong do thi
    for (int i = 0; i < graph->V; i++) {
        //B3: Neu co duong (matrix[src][i] = 1)
        // va dinh tiep theo chua duoc di qua
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            //B4: Di den dinh tiep theo va thuc hien lai toan bo logic
            DFSUtil(graph, i, visited);
        }
    }
}
void DFS(Graph *graph, int src) {
    int *visited = (int *) calloc(graph->V, sizeof(int));
    printf("bat dau duyet DFS tu dinh %d: ", src);
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);
}
//Xay dung ham duyet BFS
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->arr = (int *) malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue *queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->arr[queue->front++];
    }
    return -1;
}
void BFS(Graph *graph, int src) {
    //B1: Khoi tao va gan gia tri cho mang visited
    int *visited = (int *) calloc(graph->V, sizeof(int));
    //B2: Khoi tao hang doi
    Queue *queue = createQueue(graph->V);
    //B3: Dua dinh src vao dau hang doi va danh dau da di qua
    enqueue(queue, src);
    visited[src] = 1;
    printf("bat dau duyet BFS tu dinh %d: ", src);
    //B4: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B5: Lay dinh o dau hang doi va in ra
        int vertex = dequeue(queue);
        printf("%d ", vertex);
        //B6: Kiem tra toan bo duong co the di tu dinh
        for (int i = 0; i < graph->V; i++) {
            //B7: Neu co duong di va chua tung di qua
            if (graph->matrix[vertex][i] == 1 && visited[i] == 0) {
                //B8: Danh dau da di qua va day vao hang doi
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
    free(queue->arr);
    free(queue);
    free(visited);
}

int main(void) {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 0, 2);
    printGraph(graph);
    DFS(graph, 0);
    BFS(graph, 0);
    return 0;
}