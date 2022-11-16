//#include"SqStack.cpp"
//
//SqStack Decimal_to_BOH(unsigned d,int t)
//{//十进制转换为二进制/八进制/十进制/十六进制
//	SqStack s;
//	SElemType e,i = 0;
//	InitStack(s); // 初始化栈
//	if(d == 0)
//		Push(s,0);
//	else
//	{
//		while(d)//根据对应的权值取模，对余数进行入栈
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
//{//二进制/八进制/十六进制转化为十进制
//   SqStack s;
//   int d = 0,i = 0,j = 0;
//   InitStack(s);
//   while (num[i])//将输入的字符型转换为整型
//   {
//       if(num[i] >= '0' && num[i] <= '9')
//           Push(s,(int)(num[i] - '0'));
//       if(num[i] >= 'A' && num[i] <= 'F')
//           Push(s,(int)(num[i] - 'A') + 10);
//       if(num[i] >= 'a' && num[i] <= 'f')
//           Push(s,(int)(num[i] - 'a') + 10);
//       ++i;
//   }
//   for(--s.top;s.top >= s.base;--s.top)//根据对应的权值进行转换运算
//       d += *s.top * pow(t,j++);
//   return d;
//}
//
//int Check(char num[],int before)//检查二进制/八进制/十进制/十六进制的输入格式是否出错
//{
//   int check = 0,i = 0;//通过最后int型chenk的值来判断是否输入错误
//   SetColor(12,0);
//   switch (before)
//   {
//   case 2:
//       while (num [i])
//       {
//           if(num[i] < '0' || num[i] > '1')
//           {
//               printf("二进制输入有误，请重新输入！\n");
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
//               printf("八进制输入有误，请重新输入！\n");
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
//               printf("有误的值是：%c",num[i]);
//               printf("十进制输入有误，请重新输入！\n");
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
//               printf("十六进制输入有误，请重新输入！\n");
//               check = 1;
//               break;
//           }
//           ++i;
//       }
//       break;
//   }
//   return check;
//}