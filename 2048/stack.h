#ifndef STACK_H
#define STACK_H

#include <stdbool.h>  // bool 타입 사용을 위해 추가

#define STACK_SIZE 100  // 스택 크기 설정

typedef struct {
    int data[STACK_SIZE];  // 스택 데이터를 저장할 배열
    int top;               // 스택의 top 위치
} Stack;

// 스택 초기화 함수
void initStack(Stack* s);

// 스택이 비어 있는지 확인
bool isEmpty(Stack* s);

// 스택이 가득 찼는지 확인
bool isFull(Stack* s);

// 스택에 데이터 추가 (푸시)
bool push(Stack* s, int value);

// 스택에서 데이터 제거 (팝)
bool pop(Stack* s, int* value);

// 스택의 최상단 값을 확인 (피크)
bool peek(Stack* s, int* value);

#endif // STACK_H
