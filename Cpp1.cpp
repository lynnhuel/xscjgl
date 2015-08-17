
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>
struct Student_Info
	{
		char NO[13];//ѧ��
		char name[20];//����
		char sex[2];//�Ա�
		char classNo[6];//�༶
		float grade;//�ɼ�
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
	system ("color 9e");  //���ñ�����ɫ
	
	int mainChoice;			//ѡ�����
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           ������ѧ����Ϣ����ϵͳ             |\n");
	printf("          |           1.¼��ѧ����Ϣ                     |\n");
	printf("          |           2.��ѯѧ����Ϣ                     |\n");
	printf("          |           3.�ɼ�ͳ��ϵͳ                     |\n");	
	printf("          |           4.�޸�ѧ���ɼ�                     |\n");
	printf("          |           0.�˳�ϵͳ                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          ����������ѡ��������ͣ�           ");
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

//�޸ĳɼ�
void change()
{
	char Search_NO[13];int i,n,b=0;
		printf("��������¼�뿼������");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("�����뿼��ѧ��");
		scanf("%s",&Search_NO);
		free (pstu);
		ReadFrom(pstu,n);
		for (i=0;i<n;i++)
		{
		
			if(strcmp(pstu[i].NO,Search_NO)==0)
			{
				b=1;
				printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
				break;
			}
		}
		if (b==0)
		{printf("δ�ҵ����ѧ��");}
		printf("������ɼ�");
		scanf("%f",&pstu[i].grade);
		WriteTO(pstu,n);
		printf("\n%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
		printf("%s %12s       %s     %6s    %4f\n�ɼ����޸�\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
		printf("��1������һ���˵�,��0�˳�����");scanf("%d",&b);
		if (b==1)
		{main();}
}

//�ɼ��ּ�ϵͳ
void grade_Class()
{	
	system("cls");int InputChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           ������ѧ����Ϣ����ϵͳ             |\n");
	printf("          |           1.���հ༶��ѯѧ����Ϣ             |\n");	
	printf("          |           2.ѧ���ɼ��ּ�ͳ��                 |\n");
	printf("          |           3.�ɼ�����                         |\n");	
	printf("          |           4.������һ���˵�                   |\n");
	printf("          |           0.�˳�ϵͳ                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          ����������ѡ��������ͣ�           ");
	scanf("%d",&InputChoice);
	if(InputChoice==1)
	{
		char Search_class[6];int i,n,b=0;
		printf("��������¼�뿼������");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("������༶���ţ���λ��");
		scanf("%s",&Search_class);
		free (pstu);
		ReadFrom(pstu,n);
		printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
		for (i=0;i<n;i++)
		{
			if(strcmp(pstu[i].classNo,Search_class)==0)
			{
				b=1;
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
			}
		}
		if (b==0)
		{printf("û������༶������");}
		printf("��1������һ���˵�,��0�˳�����");scanf("%d",&InputChoice);
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
	printf("�����뿼������");
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
	printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
	for(i=0;i<n;i++)
	{
			printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
	}
	printf("��1������һ���˵�,��0�˳�����");scanf("%d",&S);
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
	printf("          |           ������ѧ����Ϣ¼��ϵͳ             |\n");
	printf("          |           1.��ʼ¼��                         |\n");
	printf("          |           2.��������                         |\n");
	printf("          |           3.������һ���˵�                   |\n");
	printf("          |           0.�˳�ϵͳ                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          ����������ѡ��������ͣ�           ");
	scanf("%d",&InputChoice);
	if (InputChoice==1)
	
		Write_Info();
	
	else if (InputChoice==3)
	
		main();
	
	else if(InputChoice==2)
		Add_Info();
		
}

//��ѯ
void Search_Info()
{
	system("cls");
	int SearchChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           ������ѧ����Ϣ����ϵͳ             |\n");
	printf("          |           1.��ѧ�Ų�ѯ                       |\n");
	printf("          |           2.��������ѯ                       |\n");
	printf("          |           3.������һ���˵�                   |\n");
	printf("          |           0.�˳�ϵͳ                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          ����������ѡ��������ͣ�           ");
	scanf("%d",&SearchChoice);
	if (SearchChoice==1)
	{
		char Search_NO[13];int i,n,b=0;
		printf("��������¼�뿼������");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("�����뿼��ѧ��");
		scanf("%s",&Search_NO);
		free (pstu);
		ReadFrom(pstu,n);
		for (i=0;i<n;i++)
		{
		
			if(strcmp(pstu[i].NO,Search_NO)==0)
			{
				b=1;
				printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
				break;
			}
		}
		if (b==0)
		{printf("δ�ҵ����ѧ��");}
		printf("��1������һ���˵�,��0�˳�����");scanf("%d",&SearchChoice);
		if (SearchChoice==1)
		{Search_Info();}
	}
	else if(SearchChoice==2)
	{
		char Search_name[20];int i,n,b=0;
		printf("��������¼�뿼������");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		printf("�����뿼������");
		scanf("%s",&Search_name);
		free (pstu);
		ReadFrom(pstu,n);
		for (i=0;i<n;i++)
		{
		
			if(strcmp(pstu[i].name,Search_name)==0)
			{
				b=1;
				printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
				break;
			}
		}
		if (b==0)
		{printf("δ�ҵ��������");}
		printf("��1������һ���˵�,��0�˳�����");scanf("%d",&SearchChoice);
		if (SearchChoice==1)
		{Search_Info();}
	}
	else if(SearchChoice==3)
	{
		main();
	}

}
//����ͳ��ϵͳ
void Info_tj()
{
	system("cls");
	int tjChoice;
	printf("\n\n\n\n\n");
	printf("          _______________________________________________\n");
	printf("          |                                              |\n");
	printf("          |           ������ѧ����Ϣ����ϵͳ             |\n");
	printf("          |           1.��ѯ��������������Ϣ             |\n");
	printf("          |           2.��ѯ80��������������Ϣ           |\n");
	printf("          |           3.������һ���˵�                   |\n");
	printf("          |           0.�˳�ϵͳ                         |\n");
	printf("          |______________________________________________|\n\n");
	printf("          ����������ѡ��������ͣ�           ");
	scanf("%d",&tjChoice);
		char Search_class[6];int i,n,b=0;
		printf("��������¼�뿼������");
		scanf("%d",&n);
		pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
		free (pstu);
		ReadFrom(pstu,n);
	if(tjChoice==1)
	{
		printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
		for (i=0;i<n;i++)
		{
			if(pstu[i].grade<60)
			{
				b+=1;
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
			}
		}
		if (b==0)
		{printf("û�в���������");}
		printf("��1������һ���˵�,��0�˳�����");scanf("%d",&tjChoice);
		if (tjChoice==1)
		{Info_tj();}
	}
	else if(tjChoice==2)
	{
		printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
		for (i=0;i<n;i++)
		{
			if(pstu[i].grade>80)
			{
				b+=1;
				printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
			}
		}
		if (b==0)
		{printf("û��80����������");}
		printf("��1������һ���˵�,��0�˳�����");scanf("%d",&tjChoice);
		if (tjChoice==1)
		{Info_tj();}
	}
	else if(tjChoice==3)
	{
		Search_Info();
	}

}


//��ʼ¼������
void Write_Info(void)
{
	int i,n;
	printf("������Ҫ¼���ѧ��������");
	scanf("%d",&n);
	pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
	printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
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
	printf("��Ϣ�ѱ���\n");
	printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
	for (i=0;i<n;i++)
	{
		printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
	}
	free (pstu);//�ͷ��ڴ�
	Sleep(5000);
	Input_Info();
}



//�����ļ�
void WriteTO(Student_Info *pstu,int n)
{
	FILE *fp;
	fp=fopen("student.dat","wt");
	if(fp==NULL)
	{
		printf("���ܴ����ļ�\n");
		free(pstu);
		exit(0);
	}
	fwrite(pstu,sizeof(Student_Info),n,fp);
	fclose (fp);
}

//���ļ�
void ReadFrom(Student_Info *pstu,int n)
{
	FILE *fp;
	fp=fopen("student.dat","rt");
	fseek(fp,0L,SEEK_SET);
	if (fp==NULL)//��ʧ��
	{
		printf("���ܴ��ļ�\n");
		free(pstu);
		exit(0);
	}
	fread (pstu,sizeof(Student_Info),n,fp);
	fclose(fp);
}


//�����ļ�����
void Add_Data(Student_Info *pstu,int n)
{
	FILE *fp;
	fp=fopen("student.dat","r+");
	if(fp==NULL)
	{
		printf("���ܴ��ļ�\n");
		free(pstu);
		exit(0);
	}
	fseek(fp,0L,SEEK_END);
	fwrite(pstu,sizeof(Student_Info),n,fp);
	fclose (fp);

}

//��������
void Add_Info()
{
	int i,n;
	printf("������Ҫ¼���ѧ��������");
	scanf("%d",&n);
	free (pstu);
	pstu=(Student_Info *) malloc (n *sizeof(Student_Info));
	printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
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
	printf("��Ϣ�ѱ���\n");
	printf("%12s%12s%10s%10s%10s\n","ѧ��","����","�Ա�","�༶","�ɼ�");
	for (i=0;i<n;i++)
	{
		printf("%s %12s       %s     %6s    %4f\n",pstu[i].NO,pstu[i].name,pstu[i].sex,pstu[i].classNo,pstu[i].grade);
	}
	free (pstu);//�ͷ��ڴ�
	Sleep(5000);
	Input_Info();
}