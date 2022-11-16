#define _CRT_SECURE_NO_WARNINGS
#include "public1.H"
#include "P5.h"

// 顺序栈(存储结构由SqStack.h定义)的基本操作(9个)
Status InitStack(SqStack& S)
{   // 构造一个空栈S
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack& S)
{ // 销毁栈S，S不再存在
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack& S)
{ // 把栈S置为空栈
    if (S.base)
    {
        S.top = S.base;
    }
    return OK;
}

Status StackEmpty(SqStack S)
{ // 若栈S为空栈，则返回TRUE；否则返回FALSE
    if (S.base != S.top)
        return FALSE;
    else
        return TRUE;
}

int StackLength(SqStack S)
{ // 返回栈S的元素个数，即栈的长度
    int num = 0;
    while (S.top != S.base)
    {
        --S.top;
        ++num;
    }
    return num;
}

Status GetTop(SqStack S, SElemType& e)
{ // 若栈S不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if (S.top != S.base)
    {
        e = *(--S.top);
        return OK;
    }
    else
        return ERROR;
}

Status Push(SqStack& S, SElemType e)
{ // 插入元素e为栈S新的栈顶元素。
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack& S, SElemType& e)
{ // 若栈S不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if (S.top != S.base)
    {
        e = *(--S.top);
        free(S.top);
        return OK;
    }
    else
        return ERROR;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType))
{ // 从栈底到栈顶依次对栈S中每个元素调用函数visit()
    while (--S.top >= S.base) // S.base指向栈元素
        visit(*S.top); // 对该栈元素调用visit()
    printf("\n");       // 栈底指针上移1个存储单元
    return OK;
}

Status visit(SElemType c)
{
    printf("%d", c);
    return OK;
}

Status StackTraverse_For_0x(SqStack S)//由于十六进制的输出比较特殊，特意为其写了个travel
{
    char num;
    printf("0x");
    while (--S.top >= S.base)
    {
        if (*S.top < 10)
            num = '0' + *S.top;
        else
            num = 'A' + *S.top - 10;
        printf("%c", num);
    }
    printf("\n");
    return OK;
}


SqStack Decimal_to_BOH(unsigned d, int t)
{//十进制转换为二进制/八进制/十进制/十六进制
    SqStack s;
    SElemType e, i = 0;
    InitStack(s); // 初始化栈
    if (d == 0)
        Push(s, 0);
    else
    {
        while (d)//根据对应的权值取模，对余数进行入栈
        {
            e = d % t;
            Push(s, e);
            d /= t;
        }
    }
    return s;
}

int BOH_to_Decimal(char num[], int t)
{//二进制/八进制/十六进制转化为十进制
    SqStack s;
    int d = 0, i = 0, j = 0;
    InitStack(s);
    while (num[i])//将输入的字符型转换为整型
    {
        if (num[i] >= '0' && num[i] <= '9')
            Push(s, (int)(num[i] - '0'));
        if (num[i] >= 'A' && num[i] <= 'F')
            Push(s, (int)(num[i] - 'A') + 10);
        if (num[i] >= 'a' && num[i] <= 'f')
            Push(s, (int)(num[i] - 'a') + 10);
        ++i;
    }
    for (--s.top; s.top >= s.base; --s.top)//根据对应的权值进行转换运算
        d += *s.top * pow(t, j++);
    return d;
}

int Check(char num[], int before)//检查二进制/八进制/十进制/十六进制的输入格式是否出错
{
    int check = 0, i = 0;//通过最后int型chenk的值来判断是否输入错误
    SetColor(12, 0);
    switch (before)
    {
    case 2:
        while (num[i])
        {
            if (num[i] < '0' || num[i] > '1')
            {
                printf("二进制输入有误，请重新输入！\n");
                check = 1;
                break;
            }
            ++i;
        }
        break;
    case 8:
        while (num[i])
        {
            if (num[i] < '0' || num[i] > '7')
            {
                printf("八进制输入有误，请重新输入！\n");
                check = 1;
                break;
            }
            ++i;
        }
        break;
    case 10:
        while (num[i])
        {
            if (num[i] < '0' || num[i] > '9')
            {
                printf("有误的值是：%c", num[i]);
                printf("十进制输入有误，请重新输入！\n");
                check = 1;
                break;
            }
            ++i;
        }
        break;
    case 16:
        while (num[i])
        {
            if ((num[i] < '0' || num[i] > '9') && (num[i] < 'a' || num[i] > 'f') && (num[i] < 'A' || num[i] > 'F'))
            {
                printf("十六进制输入有误，请重新输入！\n");
                check = 1;
                break;
            }
            ++i;
        }
        break;
    }
    return check;
}

void conversion()
{
	int before, after;
	char getnum[32];
	SqStack returned;
input1:
	printf("\n输入转换前的进制[2/8/10/16]:");//获取转换前的进制数
    scanf("%d", &before);
    getchar();
	//fflush(stdin);
	printf("获取的输入值为：");//展示获取的输入值
	SetColor(9, 0);
	printf("%d\n", before);
	SetColor(7, 0);
	if (before != 2 && before != 8 && before != 10 && before != 16)
	{//判断输入的转换值是否在2/8/10/16之间
		SetColor(12, 0);
		printf("转换前进制输入错误！请重输！");
		SetColor(7, 0);
		goto input1;//如果输入错误，进行重输
	}


input2:
	printf("请输入转换后的进制[2/8/10/16]:");//获取转换后的进制数
    scanf("%d", &after);
    getchar();
	//fflush(stdin);
	printf("获取的输入值为：");//展示获取的输入值
	SetColor(9, 0);
	printf("%d\n", after);
	SetColor(7, 0);
	if (after != 2 && after != 8 && after != 10 && after != 16)
	{//判断输入的转换值是否在2/8/10/16之间
		SetColor(12, 0);
		printf("转换后进制数输入错误！请重输！\n");
		SetColor(7, 0);
		goto input2;//如果输入错误，进行重输
	}


input3:
	printf("请输入要转换的%d进制数:", before);//获取要转换的数
	if (before == 16)
		printf("0x");//如果是十六进制数，个人喜欢在其前面加上“0x”
/*    scanf("%s", &getnum);*///获取一段数组，到回车为止
    gets_s(getnum);
    fflush(stdin);
    printf("获取的输入值为：");//展示获取的输入值
    SetColor(9,0);
    int i = 0;
    while (getnum[i])
        printf("%c",getnum[i++]);
    printf("\n");
    SetColor(7,0);
    int check = Check(getnum,before);
    if(check)
    {//通过check函数返回的check的值，判断输入是否错误
        SetColor(7,0);
        goto input3;
    }
    SetColor(7,0);
    printf("\n%d进制数",before);
    i = 0;
    while (getnum[i])
        printf("%c",getnum[i++]);
    printf("转换为%d进制后为:",after);
    SetColor(3,0);
    if(after == 2 || after == 8 || after == 10)
    {//2/8/10进制的输出
        int d = BOH_to_Decimal(getnum,before);
        returned = Decimal_to_BOH(d,after);
        StackTraverse(returned,visit);
    }
    else if(after == 16)
    {//16进制的输出
        int d = BOH_to_Decimal(getnum,before);
        returned = Decimal_to_BOH(d,after);
        StackTraverse_For_0x(returned);           
    }
}

int main()
{
    SetColor(12,0);
    printf("Warning！！！\n");
    SetColor(9,0);
    printf("请规范输入！若输入过多数，则只按照预设值的个数依次获取最开头的数！");  
    SetColor(7,0);
    input4:
    conversion();//主要功能只有这一行
    SetColor(7,0);
    printf("\n============================[操作结束]============================");
    SetColor(9,0);
	printf("\n若想继续计算请按'Enter',若想退出请输入其他任意值：");//提供一个复用窗口
    SetColor(7,0);
	char e=getchar();
	switch (e)
	{
		case '\n':
			goto input4;
		default:
			break;
    }
}