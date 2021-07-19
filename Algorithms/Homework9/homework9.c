#include <stdio.h>
#include <stdlib.h>

#define SZ 10   //Размер очереди
#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;   //Индекс головы очереди
int tail;   //Индекс хвоста очереди
int items;  //Текущее количество элементов

typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void transfer10to2(int num){
    while (num > 0)
    {
        pushStack(num%2);
        num = num /2;
    }
}

void arrstackTest() {
    int a = 123;
    
    printf("%d в двоичной системе будет: ", a);
    transfer10to2(a);
    while (cursor != -1) {
        printf("%d ", popStack());
    }
    printf("\n");
}

void initQueue() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins_queue(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0) {    //Если очередь пуста, ложим элемент в конец очереди и увеличиваем количество элементов
        arr[tail++] = node;
        items++;
    } else if (items == SZ) {   //Если очередь полная, выводим сообщение и выходим из функции
        printf("%s \n", "Queue is full!!!");
        return;
    } else {
        arr[items] = node;
        items++;
        tail++;
    }
}

Node* rem_priority() {

    if (items == 0) {
        return NULL;
    } else {

        int i = 0;  //Счетчик цикла
        int idx = 0;    //Индекс элемента
           
        for (i = 0; i < tail - 1; ++i) {
            if ((arr[idx]->pr) > (arr[i + 1]->pr))
                idx = i+1;
        }
       
        Node *tmp = arr[idx];
        
        for(i = idx; i < tail-1; ++i){
            arr[i] = arr[i+1];
        }
        arr[tail - 1] = NULL;
        items--;
        tail--;
        return tmp;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

void prQueueTest() {
    initQueue();
    ins_queue(3, 200);
    ins_queue(4, 100);
    ins_queue(1, 20);
    ins_queue(3, 250);
    ins_queue(7, 10);
    ins_queue(3, 80);
    ins_queue(5, 2);
    ins_queue(9, 96);
    ins_queue(2, 890);
    ins_queue(3, 90);
    printQueue();
    ins_queue(3, 90);

    printQueue();

    for (int i = 0; i < 7; ++i) {
        Node* n = rem_priority();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
        printQueue();
    }
}

int main(){
    printf("Lesson1:\n");
    prQueueTest();

    printf("Lesson2:\n");
    arrstackTest();

    return 0;

}