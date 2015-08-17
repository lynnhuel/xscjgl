
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>
struct Student_Info
	{
		char NO[13];//学号
		char name[20];//姓名
		char sex[2];//性别
		char classNo[6];//班级
		float grade;//成绩
	};
Student_Info *pstu;
void Input_Info(void);
void Write_Info(void);
void Search_Info();
void WriteTO(Student_Info *pstu,int n);
void ReadFrom(Student_Info *pstu,int n);
void Add_Data(Student_Info *pstu,int n);
void Add_Info();
void ReadFromFile(Student_Info *pstu,int n);
void Info_tj();
void grade_Class();
void paiming();
void change();

void main()
{
	system("cls");
	system ("color 9e");  //设置背景颜色
	
	int mainChoice;			//选择变量
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           这里是学生信息管理系统             |\n");
	printf("          |           1.录入学生信息                     |\n");
	printf("          |           2.查询学生信息                     |\n");
	printf("          |           3.成绩统计系统                     |\n");	
	printf("          |           4.修改学生成绩                     |\n");
	printf("          |           0.退出系统                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          请输入数字选择操作类型：           ");
	scanf("%d",&mainChoice);
	if (mainChoice==0)
	{
		exit(1);
	}
	else if (mainChoice==1)
		{
			Input_Info();
		}
	else if(mainChoice==2)
		{
			Search_Info();
		}
	else if(mainChoice==3)
	{
		grade_Class();
	}
	else if (mainChoice==4)
	{
		change();
	}

}

//修改成绩
void change()
{
	char Search_NO[13];int i,n,b=0;
		printf("请输入已录入考生总数");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("请输入考生学号");
		scanf("%s",&Search_NO);
		free (pstu);
		ReadFrom(pstu,n);
		for (i=0;i<n;i++)
		{
		
			if(strcmp(pstu[i].NO,Search_NO)==0)
			{
				b=1;
				printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
				break;
			}
		}
		if (b==0)
		{printf("未找到这个学号");}
		printf("请输入成绩");
		scanf("%f",&pstu[i].grade);
		WriteTO(pstu,n);
		printf("\n%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
		printf("%s %12s       %s     %6s    %4f\n成绩已修改\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
		printf("按1返回上一级菜单,按0退出程序");scanf("%d",&b);
		if (b==1)
		{main();}
}

//成绩分级系统
void grade_Class()
{	
	system("cls");int InputChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           这里是学生信息管理系统             |\n");
	printf("          |           1.按照班级查询学生信息             |\n");	
	printf("          |           2.学生成绩分级统计                 |\n");
	printf("          |           3.成绩排名                         |\n");	
	printf("          |           4.返回上一级菜单                   |\n");
	printf("          |           0.退出系统                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          请输入数字选择操作类型：           ");
	scanf("%d",&InputChoice);
	if(InputChoice==1)
	{
		char Search_class[6];int i,n,b=0;
		printf("请输入已录入考生总数");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("请输入班级代号（六位）");
		scanf("%s",&Search_class);
		free (pstu);
		ReadFrom(pstu,n);
		printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
		for (i=0;i<n;i++)
		{
			if(strcmp(pstu[i].classNo,Search_class)==0)
			{
				b=1;
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
			}
		}
		if (b==0)
		{printf("没有这个班级的数据");}
		printf("按1返回上一级菜单,按0退出程序");scanf("%d",&InputChoice);
		if (InputChoice==1)
		{grade_Class();}
		
	}
	else if(InputChoice==2)
	{
		Info_tj();
	}
	else if(InputChoice==4)
	{
		main();
	}
	else if(InputChoice==3)
	{
		paiming();
	}
}

void paiming()
{
	int i,j,n,S;
	Student_Info t;
	printf("请输入考生数量");
	scanf("%d",&n);
	pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
	free (pstu);
	ReadFrom(pstu,n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i;j++)
		{
			if (pstu[j].grade<pstu[j+1].grade)
			{
				t=pstu[j];
				pstu[j]=pstu[j+1];
				pstu[j+1]=t;
			}
		}
	}
	printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
	for(i=0;i<n;i++)
	{
			printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
	}
	printf("按1返回上一级菜单,按0退出程序");scanf("%d",&S);
		if (S==1)
		{grade_Class();}
}


void Input_Info(void)
{
	system("cls");
	int InputChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           这里是学生信息录入系统             |\n");
	printf("          |           1.开始录入                         |\n");
	printf("          |           2.增加数据                         |\n");
	printf("          |           3.返回上一级菜单                   |\n");
	printf("          |           0.退出系统                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          请输入数字选择操作类型：           ");
	scanf("%d",&InputChoice);
	if (InputChoice==1)
	
		Write_Info();
	
	else if (InputChoice==3)
	
		main();
	
	else if(InputChoice==2)
		Add_Info();
		
}

//查询
void Search_Info()
{
	system("cls");
	int SearchChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           这里是学生信息管理系统             |\n");
	printf("          |           1.按学号查询                       |\n");
	printf("          |           2.按姓名查询                       |\n");
	printf("          |           3.返回上一级菜单                   |\n");
	printf("          |           0.退出系统                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          请输入数字选择操作类型：           ");
	scanf("%d",&SearchChoice);
	if (SearchChoice==1)
	{
		char Search_NO[13];int i,n,b=0;
		printf("请输入已录入考生总数");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("请输入考生学号");
		scanf("%s",&Search_NO);
		free (pstu);
		ReadFrom(pstu,n);
		for (i=0;i<n;i++)
		{
		
			if(strcmp(pstu[i].NO,Search_NO)==0)
			{
				b=1;
				printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
				break;
			}
		}
		if (b==0)
		{printf("未找到这个学号");}
		printf("按1返回上一级菜单,按0退出程序");scanf("%d",&SearchChoice);
		if (SearchChoice==1)
		{Search_Info();}
	}
	else if(SearchChoice==2)
	{
		char Search_name[20];int i,n,b=0;
		printf("请输入已录入考生总数");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("请输入考生姓名");
		scanf("%s",&Search_name);
		free (pstu);
		ReadFrom(pstu,n);
		for (i=0;i<n;i++)
		{
		
			if(strcmp(pstu[i].name,Search_name)==0)
			{
				b=1;
				printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
				break;
			}
		}
		if (b==0)
		{printf("未找到这个名字");}
		printf("按1返回上一级菜单,按0退出程序");scanf("%d",&SearchChoice);
		if (SearchChoice==1)
		{Search_Info();}
	}
	else if(SearchChoice==3)
	{
		main();
	}

}
//数据统计系统
void Info_tj()
{
	system("cls");
	int tjChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           这里是学生信息管理系统             |\n");
	printf("          |           1.查询不及格人数及信息             |\n");
	printf("          |           2.查询80分以上人数及信息           |\n");
	printf("          |           3.返回上一级菜单                   |\n");
	printf("          |           0.退出系统                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          请输入数字选择操作类型：           ");
	scanf("%d",&tjChoice);
		char Search_class[6];int i,n,b=0;
		printf("请输入已录入考生总数");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		free (pstu);
		ReadFrom(pstu,n);
	if(tjChoice==1)
	{
		printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
		for (i=0;i<n;i++)
		{
			if(pstu[i].grade<60)
			{
				b+=1;
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
			}
		}
		if (b==0)
		{printf("没有不及格数据");}
		printf("按1返回上一级菜单,按0退出程序");scanf("%d",&tjChoice);
		if (tjChoice==1)
		{Info_tj();}
	}
	else if(tjChoice==2)
	{
		printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
		for (i=0;i<n;i++)
		{
			if(pstu[i].grade>80)
			{
				b+=1;
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
			}
		}
		if (b==0)
		{printf("没有80分以上数据");}
		printf("按1返回上一级菜单,按0退出程序");scanf("%d",&tjChoice);
		if (tjChoice==1)
		{Info_tj();}
	}
	else if(tjChoice==3)
	{
		Search_Info();
	}

}


//开始录入数据
void Write_Info(void)
{
	int i,n;
	printf("请输入要录入的学生的数量");
	scanf("%d",&n);
	pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
	printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
	for (i=0;i<n;i++)
	{
	scanf("%s",pstu[i].NO);
	scanf("%s",&pstu[i].name);
	scanf("%s",&pstu[i].sex);
	scanf("%s",&pstu[i].classNo);
	scanf("%f",&pstu[i].grade);
	}
	fflush(stdin);
	WriteTO(pstu,n);
	printf("信息已保存\n");
	printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
	for (i=0;i<n;i++)
	{
		printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
	}
	free (pstu);//释放内存
	Sleep(5000);
	Input_Info();
}



//创建文件
void WriteTO(Student_Info *pstu,int n)
{
	FILE *fp;
	fp=fopen("student.dat","wt");
	if(fp==NULL)
	{
		printf("不能创建文件\n");
		free(pstu);
		exit(0);
	}
	fwrite(pstu,sizeof(Student_Info),n,fp);
	fclose (fp);
}

//读文件
void ReadFrom(Student_Info *pstu,int n)
{
	FILE *fp;
	fp=fopen("student.dat","rt");
	fseek(fp,0L,SEEK_SET);
	if (fp==NULL)//打开失败
	{
		printf("不能打开文件\n");
		free(pstu);
		exit(0);
	}
	fread (pstu,sizeof(Student_Info),n,fp);
	fclose(fp);
}


//增加文件数据
void Add_Data(Student_Info *pstu,int n)
{
	FILE *fp;
	fp=fopen("student.dat","r+");
	if(fp==NULL)
	{
		printf("不能打开文件\n");
		free(pstu);
		exit(0);
	}
	fseek(fp,0L,SEEK_END);
	fwrite(pstu,sizeof(Student_Info),n,fp);
	fclose (fp);

}

//增加数据
void Add_Info()
{
	int i,n;
	printf("请输入要录入的学生的数量");
	scanf("%d",&n);
	free (pstu);
	pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
	printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
	for (i=0;i<n;i++)
	{
	scanf("%s",pstu[i].NO);
	scanf("%s",&pstu[i].name);
	scanf("%s",&pstu[i].sex);
	scanf("%s",&pstu[i].classNo);
	scanf("%f",&pstu[i].grade);
	}
	fflush(stdin);
	Add_Data(pstu,n);
	printf("信息已保存\n");
	printf("%12s%12s%10s%10s%10s\n","学号","姓名","性别","班级","成绩");
	for (i=0;i<n;i++)
	{
		printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
	}
	free (pstu);//释放内存
	Sleep(5000);
	Input_Info();
}