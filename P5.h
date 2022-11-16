#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;


//Õ»µÄ¶¨Òå
struct SqStack
{
    SElemType *top;
    SElemType *base;
    int stacksize;
};