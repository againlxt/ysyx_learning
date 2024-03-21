#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
	struct Item items[MAX_SIZE];
	int top;
};

struct Item {
	int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

// 初始化栈
void init(struct Stack *stack) {
	stack->top = -1;
}

// 检查栈是否为空
int is_empty(struct Stack *stack) {
	return stack->top == -1;
}

// 检查栈是否已满
int is_full(struct Stack *stack) {
	return stack->top == MAX_SIZE - 1;
}

// 入栈操作
void push(struct Stack *stack, struct Item *item) {
	if(is_full(stack)) {
		printf("Stack overflow\n");
		return;
	}

	stack->items[++stack->top] = item;
}

// 出栈操作
struct Item *pop(struct Stack *stack) {
	if (is_empty(stack)) {
		printf("Stack underflow\n");
		exit(EXIT_FATLURE);
	}
	return stack->items[stack->top--];
}

// 查看栈顶元素
struct Item *peek(struct Stack *stack) {
	if(is_empty(stack)) {
		printf("Stack is empty\n");
        exit(EXIT_FAILURE);
	}
	return stack->items[stack->top];
}

int main() {
    // 创建栈
    struct Stack *stack;
	struct
    initialize(stack);

    // 使用栈进行操作
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    return 0;
}
