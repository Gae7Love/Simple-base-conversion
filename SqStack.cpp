//#include "public1.H"
//#include "P5.h"
//
//// 顺序栈(存储结构由SqStack.h定义)的基本操作(9个)
//Status InitStack(SqStack &S) 
//{   // 构造一个空栈S
//	S.base = (SElemType*) malloc (STACK_INIT_SIZE*sizeof(SElemType));
//	if(!S.base) exit (OVERFLOW);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
//}
//
//Status DestroyStack(SqStack &S)
//{ // 销毁栈S，S不再存在
//	free(S.base);
//	S.base = NULL;
//	S.top = NULL;
//	S.stacksize = 0;
//	return OK;
//}
//
//Status ClearStack(SqStack &S)
//{ // 把栈S置为空栈
//	if(S.base)
//	{		
//		S.top = S.base;
//	}
//	return OK;
//}
//
//Status StackEmpty(SqStack S)
//{ // 若栈S为空栈，则返回TRUE；否则返回FALSE
//	if(S.base != S.top)
//		return FALSE;
//	else
//		return TRUE;
//}
//
//int StackLength(SqStack S)
//{ // 返回栈S的元素个数，即栈的长度
//	int num = 0;
//	while (S.top != S.base)
//	{
//		--S.top;
//		++num;
//	}
//	return num;
//}
//
//Status GetTop(SqStack S,SElemType &e) 
//{ // 若栈S不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
//	if(S.top != S.base)
//	{
//		e = *(--S.top);
//		return OK;
//	}
//	else
//		return ERROR;
//}
//
//Status Push(SqStack &S,SElemType e)
//{ // 插入元素e为栈S新的栈顶元素。
//	if (S.top - S.base >= S.stacksize)
//	{
//		S.base = (SElemType*) realloc (S.base,(STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
//		if (!S.base) exit (OVERFLOW);
//		S.top = S.base + S.stacksize;
//		S.stacksize += STACKINCREMENT;
//	}
//	*S.top++ = e;
//	return OK;
//}
//
//Status Pop(SqStack &S,SElemType &e) 
//{ // 若栈S不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
//	if(S.top != S.base)
//	{
//		e = *(--S.top);
//		free(S.top);
//		return OK;
//	}
//	else 
//		return ERROR;
//}
//
//Status StackTraverse(SqStack S,Status(*visit)(SElemType))
//{ // 从栈底到栈顶依次对栈S中每个元素调用函数visit()
//	while(--S.top >= S.base) // S.base指向栈元素
//		visit(*S.top); // 对该栈元素调用visit()
//	printf("\n");       // 栈底指针上移1个存储单元
//	return OK;
//}
//
//Status visit(SElemType c)
//{
//	printf("%d",c);
//	return OK;
//}
//
//Status StackTraverse_For_0x(SqStack S)//由于十六进制的输出比较特殊，特意为其写了个travel
//{
//	char num;
//	printf("0x");
//	while (--S.top >= S.base)
//	{
//		if(*S.top < 10 )
//			num = '0' + *S.top;
//		else
//			num = 'A' + *S.top - 10;
//		printf("%c",num);
//	}
//	printf("\n");
//	return OK;
//}
