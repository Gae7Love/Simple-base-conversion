//#include"SqStack.cpp"
//
//SqStack Decimal_to_BOH(unsigned d,int t)
//{//ʮ����ת��Ϊ������/�˽���/ʮ����/ʮ������
//	SqStack s;
//	SElemType e,i = 0;
//	InitStack(s); // ��ʼ��ջ
//	if(d == 0)
//		Push(s,0);
//	else
//	{
//		while(d)//���ݶ�Ӧ��Ȩֵȡģ��������������ջ
//		{
//			e = d % t;
//			Push(s,e);
//			d /= t;
//		}
//	}
//   return s;
//}
//
//int BOH_to_Decimal(char num[],int t)
//{//������/�˽���/ʮ������ת��Ϊʮ����
//   SqStack s;
//   int d = 0,i = 0,j = 0;
//   InitStack(s);
//   while (num[i])//��������ַ���ת��Ϊ����
//   {
//       if(num[i] >= '0' && num[i] <= '9')
//           Push(s,(int)(num[i] - '0'));
//       if(num[i] >= 'A' && num[i] <= 'F')
//           Push(s,(int)(num[i] - 'A') + 10);
//       if(num[i] >= 'a' && num[i] <= 'f')
//           Push(s,(int)(num[i] - 'a') + 10);
//       ++i;
//   }
//   for(--s.top;s.top >= s.base;--s.top)//���ݶ�Ӧ��Ȩֵ����ת������
//       d += *s.top * pow(t,j++);
//   return d;
//}
//
//int Check(char num[],int before)//��������/�˽���/ʮ����/ʮ�����Ƶ������ʽ�Ƿ����
//{
//   int check = 0,i = 0;//ͨ�����int��chenk��ֵ���ж��Ƿ��������
//   SetColor(12,0);
//   switch (before)
//   {
//   case 2:
//       while (num [i])
//       {
//           if(num[i] < '0' || num[i] > '1')
//           {
//               printf("�����������������������룡\n");
//               check = 1;
//               break;
//           }
//           ++i;
//       }
//       break;
//   case 8:
//       while (num [i])
//       {
//           if(num[i] < '0' || num[i] > '7')
//           {
//               printf("�˽��������������������룡\n");
//               check = 1;
//               break;
//           }
//           ++i;
//       }
//       break;
//   case 10:
//       while (num [i])
//       {
//           if(num[i] < '0' || num[i] > '9')
//           {
//               printf("�����ֵ�ǣ�%c",num[i]);
//               printf("ʮ���������������������룡\n");
//               check = 1;
//               break;
//           }
//           ++i;
//       }
//       break;
//   case 16:
//       while (num [i])
//       {
//           if((num[i] < '0' || num[i] > '9') && (num[i] < 'a' || num[i] > 'f') && (num[i] < 'A' || num[i] > 'F'))
//           {
//               printf("ʮ�����������������������룡\n");
//               check = 1;
//               break;
//           }
//           ++i;
//       }
//       break;
//   }
//   return check;
//}