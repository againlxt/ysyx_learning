#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Person structure declaration
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// Person structure initialization
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// malloc 函数是 C 语言标准库中的动态内存分配函数之一。它用于在程序运行时动态地分配一块指定大小的内存空间，并返回该内存块的起始地址。该语句为Person类型结构体who申请了一块内存空间。
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
	// 初始化Person类型结构体who中的元素
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

// Person structure memory release
void Person_destroy(struct Person *who)
{
	// 判断传入结构体是否为空，防止错误输入
    assert(who != NULL);

	// 释放申请的内存
    free(who->name);
    free(who);
}

// Person structure traversal
void Person_print(struct Person *who)
{
	// 遍历结构体元素并将其输出终端
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(NULL);

    frank->age += 20;
    frank->weight += 20;
    Person_print(NULL);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
