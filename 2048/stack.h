#ifndef STACK_H
#define STACK_H

#include <stdbool.h>  // bool Ÿ�� ����� ���� �߰�

#define STACK_SIZE 100  // ���� ũ�� ����

typedef struct {
    int data[STACK_SIZE];  // ���� �����͸� ������ �迭
    int top;               // ������ top ��ġ
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack* s);

// ������ ��� �ִ��� Ȯ��
bool isEmpty(Stack* s);

// ������ ���� á���� Ȯ��
bool isFull(Stack* s);

// ���ÿ� ������ �߰� (Ǫ��)
bool push(Stack* s, int value);

// ���ÿ��� ������ ���� (��)
bool pop(Stack* s, int* value);

// ������ �ֻ�� ���� Ȯ�� (��ũ)
bool peek(Stack* s, int* value);

#endif // STACK_H
