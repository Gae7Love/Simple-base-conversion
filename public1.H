 // c1.h (程序名)
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 #include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<Windows.h>
 #include<math.h>
 #include <time.h>
//  #include<iostream.h> // cout,cin
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 //Status 是函数的类型，其值是函数结果状态代码，如OK等
 typedef int Status;
 
 VOID SetColor(UINT uFore, UINT uBack) {
	 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
 }
 
