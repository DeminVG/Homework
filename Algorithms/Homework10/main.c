
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}

void printOneLinkIntNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printOneLinkIntList(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    if (current == NULL) {
        printOneLinkIntNode(current);
    } else {
        do {
            printOneLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

void printOneLinkCharNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}

void printOneLinkCharList(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    } else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

boolean pushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

void printTwoLinkIntNode(TwoLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printTwoLinkIntList(TwoLinkList *lst) {
    TwoLinkNode *current = lst->head;
    if (current == NULL) {
        printTwoLinkIntNode(current);
    } else {
        do {
            printTwoLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

boolean TwoLinkEnqueue(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

T TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}

void printCyclicIntList(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    if (current == NULL) {
        printOneLinkIntNode(current);
    } else {
        do {
            printOneLinkIntNode(current);
            current = current->next;
        } while (current != lst->head);
    }
    printf(" Size: %d \n", lst->size);
}

int bracket_sequence(){
    
    OneLinkList *st = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    
    char *str;
    str = (char*)malloc(100);
    printf("Lesson1:\n");
    printf("Введите скобочную последовательность:\n>");
    scanf("%s", str);
    
    int i = 0;
    if( str[i] == ')' || str[i] == '}' || str[i] == ']'){
            printf("Скобочная последовательность неверная!\n");
            return 0;
    }

    while (str[i] != '\0')
    {
        switch (str[i])
        {
        case '(':
            pushOneLinkStack(st, '(');
            break;
        case '{':
            pushOneLinkStack(st, '{');
            break;
        case '[':
            pushOneLinkStack(st, '[');
            break;
        case ')':
            if(popOneLinkStack(st) == '(')
            break;
            else{
                printf("Скобочная последовательность неверная!\n");
                return 0;
            }
        case '}':
            if(popOneLinkStack(st) == '{')
            break;
            else{
                printf("Скобочная последовательность неверная!\n");
                return 0;
            }
        case ']':
            if(popOneLinkStack(st) == '[')
            break;
            else{
                printf("Скобочная последовательность неверная!\n");
                return 0;
            }

        default:
            break;
        }
         
    i++;
    }
    if(popOneLinkStack(st) == -1){
        printf("Скобочная последовательность верная!\n");
        return 1;
    }
    else{
        printf("Скобочная последовательность неверная!\n");
        return 0;
    }
}


int main(){

    //listStackTest();
    bracket_sequence();
    //OneLinkCopy();
    return 0;
}