#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/////////////////////STACK////////////////////////////////
typedef struct deque_tag{
    int data;
    struct deque_tag *next, *prev;

}deque;

deque* create(int data)
{
    deque *n = malloc(sizeof(deque));
    n->next = n->prev = n;
    n->data = data;
    return n;
}
deque* last(deque*L)
{
   return L->prev;
}
void push(deque*L, int num)
{
    deque* n = create(num);
    deque* p = last(L);
    if(!(p->next)){
        n->next = L;
        L->prev = n;
        n->prev->next = n;
        p->next = n;
    }
    n->next = p->next; n->prev = p;
    p->next = n;
    n->next->prev = n;
    if(n == last(L)) L->prev = n;
}
deque* print_deque(deque *L){
    //printf("-----------------------\n");
    for(deque* i = L->next; i != L; i=i->next){
        printf("%d ", i->data);
    }
}
deque*search(deque *L, int key)
{
    L = L->next;
    while (L->next){
        if (L->data == key) return L;
        L = L->next;
    }
    return 0;
}
int count(deque *L){
    int count = 0;
    for(deque* i = L->next; i != L; i=i->next) count++;
    return count;
}

////////////////////////////////////////////////////////////////////////////////////////
int N = 8;
int depth_first_search(int A[N][N], int v, int* visited, int N, deque* way){
    //printf("%d", count(way));
    if(visited[v] == 0) push(way, v);
    visited[v] = 1;
    for(int i = 0; i < N; i++){
        if(A[v][i] == 1 && visited[i] == 0){
            return depth_first_search(A, i, visited, N, way);
        }

    } 
    if(count(way) < N) return depth_first_search(A, (search(way, v))->prev->data, visited, N, way);
    return 0;
}
int* create_graph(int A[N][N], int n){
    int *array=(int*)A;
    for(int i = 0; i<n; i++){
        printf("\n");
        for(int j = 0; j<n; j++){
            array[i*n+j] = rand()%2;
            printf("%d", array[i*n+j]);
        }
    }
    return array;
}
int find_vertex_stepen(int arr[N][N], int n){
    int one_count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] == 1){
                one_count+=1;
            }
            //printf("%d", arr[i*n+j]);
        }
    }
    int vertex = one_count/2;
    return vertex;
}
int find_st(int arr[N][N], int n){
    int one_count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j] == 1){
                one_count+=1;
            }
            //printf("%d", arr[i*n+j]);
        }
    }
    return one_count;
}




int main(void){
    int array[8][8] = {0, 1, 0, 0, 1, 0, 0, 0,
                       1, 0, 1, 0, 0, 1, 1, 0,
                       0, 1, 0, 0, 0, 1, 0, 0,
                       0, 0, 0, 0, 1, 0, 1, 0,
                       1, 0, 0, 1, 0, 0, 0, 1,
                       0, 1, 1, 0, 0, 0, 1, 0,
                       0, 1, 0, 1, 0, 1, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 0};
    int* visited = malloc(sizeof(int)*8);
    deque* way = create(0);

    //for(int i = 0; i < sizeof(visited)/sizeof(int); i++) visited[i] = 0;
    visited[0] = 0;
    visited[1] = 0;
    visited[2] = 0;
    visited[3] = 0;
    visited[4] = 0;
    visited[5] = 0;
    visited[6] = 0;
    visited[7] = 0;
    depth_first_search(array, 4, visited, 8, way);
    printf("DFS-way\n");
    print_deque(way);

    return 0;
}

