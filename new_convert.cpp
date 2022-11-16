#define _CRT_SECURE_NO_WARNINGS
#include "public1.H"
#include "P5.h"

// ˳��ջ(�洢�ṹ��SqStack.h����)�Ļ�������(9��)
Status InitStack(SqStack& S)
{   // ����һ����ջS
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack& S)
{ // ����ջS��S���ٴ���
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack& S)
{ // ��ջS��Ϊ��ջ
    if (S.base)
    {
        S.top = S.base;
    }
    return OK;
}

Status StackEmpty(SqStack S)
{ // ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
    if (S.base != S.top)
        return FALSE;
    else
        return TRUE;
}

int StackLength(SqStack S)
{ // ����ջS��Ԫ�ظ�������ջ�ĳ���
    int num = 0;
    while (S.top != S.base)
    {
        --S.top;
        ++num;
    }
    return num;
}

Status GetTop(SqStack S, SElemType& e)
{ // ��ջS���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if (S.top != S.base)
    {
        e = *(--S.top);
        return OK;
    }
    else
        return ERROR;
}

Status Push(SqStack& S, SElemType e)
{ // ����Ԫ��eΪջS�µ�ջ��Ԫ�ء�
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
{ // ��ջS���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
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
{ // ��ջ�׵�ջ�����ζ�ջS��ÿ��Ԫ�ص��ú���visit()
    while (--S.top >= S.base) // S.baseָ��ջԪ��
        visit(*S.top); // �Ը�ջԪ�ص���visit()
    printf("\n");       // ջ��ָ������1���洢��Ԫ
    return OK;
}

Status visit(SElemType c)
{
    printf("%d", c);
    return OK;
}

Status StackTraverse_For_0x(SqStack S)//����ʮ�����Ƶ�����Ƚ����⣬����Ϊ��д�˸�travel
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
{//ʮ����ת��Ϊ������/�˽���/ʮ����/ʮ������
    SqStack s;
    SElemType e, i = 0;
    InitStack(s); // ��ʼ��ջ
    if (d == 0)
        Push(s, 0);
    else
    {
        while (d)//���ݶ�Ӧ��Ȩֵȡģ��������������ջ
        {
            e = d % t;
            Push(s, e);
            d /= t;
        }
    }
    return s;
}

int BOH_to_Decimal(char num[], int t)
{//������/�˽���/ʮ������ת��Ϊʮ����
    SqStack s;
    int d = 0, i = 0, j = 0;
    InitStack(s);
    while (num[i])//��������ַ���ת��Ϊ����
    {
        if (num[i] >= '0' && num[i] <= '9')
            Push(s, (int)(num[i] - '0'));
        if (num[i] >= 'A' && num[i] <= 'F')
            Push(s, (int)(num[i] - 'A') + 10);
        if (num[i] >= 'a' && num[i] <= 'f')
            Push(s, (int)(num[i] - 'a') + 10);
        ++i;
    }
    for (--s.top; s.top >= s.base; --s.top)//���ݶ�Ӧ��Ȩֵ����ת������
        d += *s.top * pow(t, j++);
    return d;
}

int Check(char num[], int before)//��������/�˽���/ʮ����/ʮ�����Ƶ������ʽ�Ƿ����
{
    int check = 0, i = 0;//ͨ�����int��chenk��ֵ���ж��Ƿ��������
    SetColor(12, 0);
    switch (before)
    {
    case 2:
        while (num[i])
        {
            if (num[i] < '0' || num[i] > '1')
            {
                printf("�����������������������룡\n");
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
                printf("�˽��������������������룡\n");
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
                printf("�����ֵ�ǣ�%c", num[i]);
                printf("ʮ���������������������룡\n");
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
                printf("ʮ�����������������������룡\n");
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
	printf("\n����ת��ǰ�Ľ���[2/8/10/16]:");//��ȡת��ǰ�Ľ�����
    scanf("%d", &before);
    getchar();
	//fflush(stdin);
	printf("��ȡ������ֵΪ��");//չʾ��ȡ������ֵ
	SetColor(9, 0);
	printf("%d\n", before);
	SetColor(7, 0);
	if (before != 2 && before != 8 && before != 10 && before != 16)
	{//�ж������ת��ֵ�Ƿ���2/8/10/16֮��
		SetColor(12, 0);
		printf("ת��ǰ����������������䣡");
		SetColor(7, 0);
		goto input1;//���������󣬽�������
	}


input2:
	printf("������ת����Ľ���[2/8/10/16]:");//��ȡת����Ľ�����
    scanf("%d", &after);
    getchar();
	//fflush(stdin);
	printf("��ȡ������ֵΪ��");//չʾ��ȡ������ֵ
	SetColor(9, 0);
	printf("%d\n", after);
	SetColor(7, 0);
	if (after != 2 && after != 8 && after != 10 && after != 16)
	{//�ж������ת��ֵ�Ƿ���2/8/10/16֮��
		SetColor(12, 0);
		printf("ת���������������������䣡\n");
		SetColor(7, 0);
		goto input2;//���������󣬽�������
	}


input3:
	printf("������Ҫת����%d������:", before);//��ȡҪת������
	if (before == 16)
		printf("0x");//�����ʮ��������������ϲ������ǰ����ϡ�0x��
/*    scanf("%s", &getnum);*///��ȡһ�����飬���س�Ϊֹ
    gets_s(getnum);
    fflush(stdin);
    printf("��ȡ������ֵΪ��");//չʾ��ȡ������ֵ
    SetColor(9,0);
    int i = 0;
    while (getnum[i])
        printf("%c",getnum[i++]);
    printf("\n");
    SetColor(7,0);
    int check = Check(getnum,before);
    if(check)
    {//ͨ��check�������ص�check��ֵ���ж������Ƿ����
        SetColor(7,0);
        goto input3;
    }
    SetColor(7,0);
    printf("\n%d������",before);
    i = 0;
    while (getnum[i])
        printf("%c",getnum[i++]);
    printf("ת��Ϊ%d���ƺ�Ϊ:",after);
    SetColor(3,0);
    if(after == 2 || after == 8 || after == 10)
    {//2/8/10���Ƶ����
        int d = BOH_to_Decimal(getnum,before);
        returned = Decimal_to_BOH(d,after);
        StackTraverse(returned,visit);
    }
    else if(after == 16)
    {//16���Ƶ����
        int d = BOH_to_Decimal(getnum,before);
        returned = Decimal_to_BOH(d,after);
        StackTraverse_For_0x(returned);           
    }
}

int main()
{
    SetColor(12,0);
    printf("Warning������\n");
    SetColor(9,0);
    printf("��淶���룡���������������ֻ����Ԥ��ֵ�ĸ������λ�ȡ�ͷ������");  
    SetColor(7,0);
    input4:
    conversion();//��Ҫ����ֻ����һ��
    SetColor(7,0);
    printf("\n============================[��������]============================");
    SetColor(9,0);
	printf("\n������������밴'Enter',�����˳���������������ֵ��");//�ṩһ�����ô���
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