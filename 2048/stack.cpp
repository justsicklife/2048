#include "stack.h"
#include <stdio.h>

void initStack(Stack* s) {
    s->top = -1;  // 초기 top 값을 -1로 설정 (비어있음)
}

bool isEmpty(Stack* s) {
    return s->top == -1;  // top이 -1이면 비어있음
}

bool isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;  // top이 마지막 인덱스면 가득 참
}

bool push(Stack* s, int value) {
    if (isFull(s)) {
        printf("스택이 가득 찼습니다!\n");
        return false;
    }
    s->data[++(s->top)] = value;  // top을 증가시키고 데이터 삽입
    return true;
}

bool pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다!\n");
        return false;
    }
    *value = s->data[(s->top)--];  // top 위치의 데이터 반환 후 top 감소
    return true;
}

bool peek(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다!\n");
        return false;
    }
    *value = s->data[s->top];  // top 위치의 데이터만 확인 (제거 X)
    return true;
}
