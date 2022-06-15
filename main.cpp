#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Transaction
{
	char uesrname[100];
	time_t timestamp;
	int type;
	int amount;
	struct Transaction * next;
};
typedef struct Transaction Transaction;

struct Account
{
	char name[100];
	char idCard[19];
	char tel[12];
	char uesrname[100];
	char password[7];
	float money;
	struct Account *next;
};
typedef struct Account Account;

Account * head=NULL;
Account * tail=NULL;
Account * curAccount=NULL;//��¼�����˻�

void Load()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//�������
			Account * newNode=(Account *)malloc(sizeof(Account));
			//����ʼ��
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->uesrname,newNode->password);
			//��ӽ�㵽����
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		printf("���سɹ�!\n");
		fclose(fp);
	}
}

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		curP=curP->next;
	}
}

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s\n",curP->uesrname,curP->password);
			curP=curP->next;
		}
	}
	fclose(fp);
}

void signUp()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("����������:\n");
	scanf("%s",newNodeP->name);

	printf("���������֤��:\n");
	scanf("%s",newNodeP->idCard);

	printf("������绰:\n");
	scanf("%s",newNodeP->tel);

	printf("�������˺�:\n");
	scanf("%s",newNodeP->uesrname);

	printf("����������:\n");
	scanf("%s",newNodeP->password);

	newNodeP->money=0.0f;
	newNodeP->next=NULL;

	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	printf("�����ɹ�!\n");
}

//�ҵ�����1�����򷵻�0
int findAccount(Account a)
{
	Account * curp=head;
	while(curp!=NULL)
	{
		if((strcmp(curp->uesrname,a.uesrname)==0)&&(strcmp(curp->password,a.password)==0))
		{
			curAccount=curp;
			return 1;
		}
		curp=curp->next;
	}
	return 0;
}

void updatePassword()
{
	char formerPassword[100];
	printf("����������룺\n");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("�����������룺\n");
		scanf("%s",curAccount->password);
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("������󣡲����޸ģ�\n");
	}
}

void TheupdatePassword()
{
	char formerPassword[100];
	printf("please enter  your fomer password��");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("please enter your new password��");
		scanf("%s",curAccount->password);
		printf("Changed successfully��\n");
	}
	else
	{
		printf("The former password is wrong ,you can't change it��\n");
	}

}

void saveMoney()
{
	printf("����������:\n");
	int money;
	scanf("%d",&money);
	if(money>=100 && money<=50000)
	{
		curAccount->money+=money;
		printf("���ɹ���\n");
		//��¼������Ϣ
	}
}

void ThesaveMoney()
{
	printf("please enter the deposit amount:\n");
	int money;
	scanf("%d",&money);
	if(money>=100 && money<=50000)
	{
		curAccount->money+=money;
		printf("Deposit succeeded��\n");
		//��¼������Ϣ
	}
}

void drawMoney()
{
	printf("������ȡ����:\n");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money)
	{
		printf("ȡ��ɹ���\n");
		curAccount->money-=money;
		//��¼������Ϣ
	}
	else
	{
		printf("���㣬ȡ��ʧ��\n");
	}
}

void ThedrawMoney()
{
	printf("please enter the withdrawal amount:\n");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money)
	{
		printf("Withdrawal succeeded��\n");
		curAccount->money-=money;
		//��¼������Ϣ
	}
	else
	{
		printf("Insufficient balance,withdrawal failed\n");
	}
}

void signIn()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("�������˺�:");
		scanf("%s",a.uesrname);

		printf("����������:");
		scanf("%s",a.password);

		if(findAccount(a)==1)
		{
			printf("��½�ɹ���\n");
			break;
		}
		else
		{
			printf("��¼ʧ�ܣ�\n");
		}
	}
	printf("�޸�����������1\n");
	printf("���������2\n");
	printf("ȡ��������3\n");
	int o;
	scanf("%d",&o);
	if(o==1)
	{
		updatePassword();
	}
	else if(o==2)
	{
		saveMoney();
	}
	else if(o==3)
	{
		drawMoney();
	}
}

int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
			//�������
			Account * newNode=(Account *)malloc(sizeof(Account));
			//����ʼ��
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->uesrname,newNode->password);
			//��ӽ�㵽����
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		return 1;
	}
}

void signtheUp()
{
    //����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("please input your name:\n");
	scanf("%s",newNodeP->name);

	printf("please input your idCard:\n");
	scanf("%s",newNodeP->idCard);

	printf("please input your telphone:\n");
	scanf("%s",newNodeP->tel);

	printf("please input your username:\n");
	scanf("%s",newNodeP->uesrname);

	printf("please input your password:\n");
	scanf("%s",newNodeP->password);

	newNodeP->money=0.0f;
	newNodeP->next=NULL;

	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	printf("Created Successfully !\n");
}

void signtheIn()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("please input your account:");
		scanf("%s",a.uesrname);

		printf("please input your password:");
		scanf("%s",a.password);

		if(findAccount(a)==1)
		{
			printf("Login successful!\n");
			break;
		}
		else
		{
			printf("Login failed!\n");
		}
	}
	printf("Change the password please enter 1\n");
	printf("Save money please enter 2\n");
	printf("Draw money please enter 3\n");
	int o;
	scanf("%d",&o);
	if(o==1)
	{
		TheupdatePassword();
	}
	else if(o==2)
	{
		ThesaveMoney();
	}
	else if(o==3)
	{
		ThedrawMoney();
	}
}

void showMenu()
{
	printf("��������1\n");
	printf("��¼����2\n");
	int n;
	scanf("%d",&n);

	if(n==1)
	{
		signUp();
	}
	else if(n==2)
	{
		signIn();
	}
}

void showtheMenu()
{
	printf("open an account,please press 1\n");
	printf("signup��please press 2\n");
	int m;
	scanf("%d",&m);

	if(m==1)
	{
		signtheUp();
	}
	else if(m==2)
	{
		signtheIn();
	}
}

int main()
{
	printf("��ӭʹ�û�����������\n");
	printf("welcome to Blossoming wealth bank\n");
	Load();
	int language;
	printf("���ģ��밴1\n");
	printf("English,please press 2\n");
	scanf("%d",&language);
	if(language==1)
	{
		showMenu();
	}
	else if(language==2)
	{
		showtheMenu();
	}

	int i=loadData();
	if(i==0)
	{
		printf("����ʧ�ܣ�\n");
	}
	else
	{
		printf("���سɹ���\n");
	}

	printLinkedList();
	
	time_t timestamp = time(NULL);
	
	char *ct=ctime(&timestamp);
	printf("%s\n",ct);

	saveData();

	return 0;
}