#include "stack.h"
#include <stdio.h>

void initStack(Stack* s) {
    s->top = -1;  // �ʱ� top ���� -1�� ���� (�������)
}

bool isEmpty(Stack* s) {
    return s->top == -1;  // top�� -1�̸� �������
}

bool isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;  // top�� ������ �ε����� ���� ��
}

bool push(Stack* s, int value) {
    if (isFull(s)) {
        printf("������ ���� á���ϴ�!\n");
        return false;
    }
    s->data[++(s->top)] = value;  // top�� ������Ű�� ������ ����
    return true;
}

bool pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("������ ��� �ֽ��ϴ�!\n");
        return false;
    }
    *value = s->data[(s->top)--];  // top ��ġ�� ������ ��ȯ �� top ����
    return true;
}

bool peek(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("������ ��� �ֽ��ϴ�!\n");
        return false;
    }
    *value = s->data[s->top];  // top ��ġ�� �����͸� Ȯ�� (���� X)
    return true;
}
