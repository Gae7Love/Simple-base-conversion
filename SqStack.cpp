//#include "public1.H"
//#include "P5.h"
//
//// ˳��ջ(�洢�ṹ��SqStack.h����)�Ļ�������(9��)
//Status InitStack(SqStack &S) 
//{   // ����һ����ջS
//	S.base = (SElemType*) malloc (STACK_INIT_SIZE*sizeof(SElemType));
//	if(!S.base) exit (OVERFLOW);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
//}
//
//Status DestroyStack(SqStack &S)
//{ // ����ջS��S���ٴ���
//	free(S.base);
//	S.base = NULL;
//	S.top = NULL;
//	S.stacksize = 0;
//	return OK;
//}
//
//Status ClearStack(SqStack &S)
//{ // ��ջS��Ϊ��ջ
//	if(S.base)
//	{		
//		S.top = S.base;
//	}
//	return OK;
//}
//
//Status StackEmpty(SqStack S)
//{ // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
//	if(S.base != S.top)
//		return FALSE;
//	else
//		return TRUE;
//}
//
//int StackLength(SqStack S)
//{ // ����ջS��Ԫ�ظ�������ջ�ĳ���
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
//{ // ��ջS���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
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
//{ // ����Ԫ��eΪջS�µ�ջ��Ԫ�ء�
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
//{ // ��ջS���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
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
//{ // ��ջ�׵�ջ�����ζ�ջS��ÿ��Ԫ�ص��ú���visit()
//	while(--S.top >= S.base) // S.baseָ��ջԪ��
//		visit(*S.top); // �Ը�ջԪ�ص���visit()
//	printf("\n");       // ջ��ָ������1���洢��Ԫ
//	return OK;
//}
//
//Status visit(SElemType c)
//{
//	printf("%d",c);
//	return OK;
//}
//
//Status StackTraverse_For_0x(SqStack S)//����ʮ�����Ƶ�����Ƚ����⣬����Ϊ��д�˸�travel
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
