#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

struct Transaction
{
	char username[100];
	time_t timestamp;//ʱ��� 
	int type;//�������� 0-ȡǮ��1-��Ǯ
	float amount;//���� 

	struct Transaction* next;
};
typedef struct Transaction TR;

//���׼�¼��Ϣ���� 
TR* tHead = NULL;
TR* tTail = NULL;
TR* Tr = NULL;


struct Account
{
	char password[7];
	char username[19];
	float money;
	struct Account* next;
};
typedef struct Account Account;

int language;
Account a;

typedef struct Account Account;

Account* head = NULL;//ָ��ͷ��� 
Account* tail = NULL;//ָ��β��� 
Account* curAccount = NULL;//��¼��ǰ�˻� 
void homePage();
void transfer();
void esc();
void saveData();
void date() 
{//��ʾ��ǰ����
	printf("��ǰ���ڣ�");
	system("date/t");
	printf("��ǰʱ�䣺");
	system("time/t");

}
//���سɹ�����1�����򷵻�0 
void loadData()
{
	FILE* fp = fopen("D:/demo2/atm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			//�������
			Account* newNode = (Account*)malloc(sizeof(Account));
			if (newNode == NULL) 
			{
				exit(-1);
			}//�ж�malloc����ռ��Ƿ�ɹ�����������

			//����ʼ��
			newNode->next = NULL;
			fscanf_s(fp, "%s %s %f\n", newNode->username,19, newNode->password, 7, &newNode->money);

			//��ӽ�㵽����
			if (head == NULL)
			{
				head = newNode;
				tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
			}
		}
		fclose(fp);
	}
}

void loadDataTR()
{
	FILE* fp = fopen("D:/demo2/Tatm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			//�������
			TR* Node = (TR*)malloc(sizeof(TR));
			if (Node == NULL)
			{
				exit(-1);
			}//�ж�malloc����ռ��Ƿ�ɹ�����������

			//����ʼ��
			Node->next = NULL;
			fscanf_s(fp, "%s %d %f\n", Node->username, 19, & Node->type, &Node->amount);

			//��ӽ�㵽����
			if (tHead == NULL)
			{
				tHead = Node;
				tTail = Node;
			}
			else
			{
				tTail->next = Node;
				tTail =Node;
			}
		}
		fclose(fp);
	}
}




void saveTR()
{
	FILE* fp = fopen("D:/demo2/Tatm.txt", "w");
	TR* curP = tHead;
	while (curP != NULL)
	{
		fprintf(fp, "%s\t\t%d\t %f\n", curP->username,curP->type, curP->amount);
		curP = curP->next;
	}
	fclose(fp);
}

void findeTR(Account *a)
{
	TR* curP = tHead;
	system("cls");
	date();
	printf("\n\n\n");
	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	���׼�¼>1	���ز˵�>2	||\n");
	printf("\t\t||	        		�˳�>3	||\n");
	printf("\t\t||--------------------------------------||\n");
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
			while (curP != NULL)
			{
				if (strcmp(curP->username, a->username) == 0)
				{
					printf("%s\t\t%d\t%f\t", curP->username,curP->type, curP->amount);
					system("date/t");
				}
				curP = curP->next;
			}
			system("pause");
	case 2:homePage(); break;
	default:
		break;
	}
	
}

void drawMoney()
{
	system("cls");
	date();
	printf("\n\n\n");
	printf("**********************************************************************\n");
	printf("*                           ������ȡ��                               *\n");
	printf("**********************************************************************\n\n\n");

	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	ȡ��>1		���ز˵�>2	||\n");
	printf("\t\t||	        		�˳�>3	||\n");
	printf("\t\t||--------------------------------------||\n");
	int n;
	scanf_s("%d",&n);

	switch (n)
	{
	case 1:
			printf("\t\t������ȡ���");
			float money;
			while (1)
			{
				scanf_s("%f", &money);
				if (((int)money % 100) != 0)
					printf("\n\t\t������ȡ��������룺\n");
				else
					break;

			}
			

			//��֤���
			if (curAccount->money >= money)
			{
				printf("\t\tȡ��ɹ���\n");
				curAccount->money -= money;

				//�������׼�¼...	
				TR* newNode = (TR*)malloc(sizeof(TR));
				if (newNode == NULL)
				{
					exit(-1);
				}//�ж�malloc����ռ��Ƿ�ɹ�����������
				newNode->next = NULL;
				strcpy(newNode->username, curAccount->username);
				newNode->type = 0 ;
				newNode->amount = money;
				newNode->timestamp = time(NULL);

				
				//����ʼ��

				//��ӽ�㵽����
				if (tHead == NULL)
				{
					tHead = newNode;
					tTail = newNode;
				}
				else
				{
					tTail->next = newNode;
					tTail = newNode;
				}
				
			}
			else
			{
				printf("\t\t���㣡\n");
			}
			saveTR();
			saveData();
			system("pause");
	case 2: homePage(); break;
	case 3: esc();
	default:
		break;
	}
	
}

void transfer() {
	system("cls");
	date();
	printf("\n\n\n");
	FILE* fp = fopen("D:/demo2/atm.txt", "r+");
	if (fp == NULL)	//�޸������жϽ�����־���Warning C6387
		exit(-1);
	float money;
	char id[9] = {"\0"};
	Account* curp=head;
	

	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	ת��>1		���ز˵�>2	||\n");
	printf("\t\t||	        		�˳�>3	||\n");
	printf("\t\t||--------------------------------------||\n");
	int n;
	scanf_s("%d",&n);
	system("cls");
	switch (n)
	{
	case 1:
		printf("\n\n\t\t������ת���˵��û�����");
		scanf_s("%s", &id, 9);
		while (curp != NULL)
		{


			if (strcmp(id, curp->username) == 0)
			{
				printf("\n\n\t\t������Ҫת�˵Ľ�");
				scanf_s("%f", &money);
				if (curAccount->money >= money)
				{
					printf("\n\n\t\t��ȷ����Ŀ��%f\n", money);
					system("pause");
					curp->money += money;
					curAccount->money -= money;
					printf("\n\n\nת�˳ɹ�!\n");
					fprintf(fp, "%s\t%s\t%f\n", curAccount->username, curAccount->password, curAccount->money);


					//�������
					TR* newNode = (TR*)malloc(sizeof(TR));
					if (newNode == NULL)
					{
						exit(-1);
					}//�ж�malloc����ռ��Ƿ�ɹ�����������
					//����ʼ��
					newNode->next = NULL;
					strcpy(newNode->username, curAccount->username);
					newNode->timestamp = time(NULL);
					newNode->type = 0;
					newNode->amount = money;

					//��ӽ�㵽����
					if (tHead == NULL)
					{
						tHead = newNode;
						tTail = newNode;
					}
					else
					{
						tTail->next = newNode;
						tTail = newNode;
					}

				}
				else
				{
					printf("\t\t���㣡\n\n\n");
					system("pause");
					transfer();
				}


				fclose(fp);
			}
			curp = curp->next;

		}
		saveTR();
		saveData();
		system("pause");
	case 2:homePage();
	case 3:esc();
	default:
		break;
	}
	
	
	
}


void saveMoney()
{
	system("cls");
	date();
	printf("\n\n\n");
	
	printf("**********************************************************************\n");
	printf("*                           �����ٴ��                               *\n");
	printf("**********************************************************************\n\n\n");
	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	���>1		���ز˵�>2	||\n");
	printf("\t\t||	        		�˳�>3	||\n");
	printf("\t\t||--------------------------------------||\n");
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
			printf("\t\t���������");
			float money;
			while (1)
			{
				scanf_s("%f", &money);
				if (((int)money % 100) != 0)
					printf("\t\t�����ٴ��������룺\n\n\n");
				else
					break;

			}
			printf("\t\t���ɹ���\n\n\n");
			curAccount->money += money;

						//�������׼�¼...	
			TR* newNode = (TR*)malloc(sizeof(TR));
			if (newNode == NULL)
			{
				exit(-1);
			}//�ж�malloc����ռ��Ƿ�ɹ�����������
			newNode->next = NULL;
			strcpy(newNode->username, curAccount->username);
			newNode->type = 1;
			newNode->amount = money;
			newNode->timestamp = time(NULL);

			//����ʼ��

			//��ӽ�㵽����
			if (tHead == NULL)
			{
				tHead = newNode;
				tTail = newNode;
			}
			else
			{
				tTail->next = newNode;
				tTail = newNode;
			}
			saveTR();
			saveData();
			system("pause");

	case 2: homePage(); break;
	case 3: esc();
	default:
		break;
	}
	
}

void esc()
{
	void saveData();
	saveData();
	exit(0);
}

void enquiryService()
{
	system("cls");
	date();
	printf("\n\n\n");
	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	����ѯ>1	���ز˵�>2	||\n");
	printf("\t\t||	        		�˳�>3	||\n");
	printf("\t\t||--------------------------------------||\n");
	
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:printf("%s\t\t%f\t\n", curAccount->username,  curAccount->money);
		   system("pause");
	case 2:homePage(); break;
	case 3:esc();
	default:
		break;
	}
	

}

void printLinkedList()
{
	Account* curP = head;
	while (curP != NULL)
	{
		printf("%s\t%s\t%f\t\n", curP->username, curP->password,  curP->money);
		curP = curP->next;
	}
}



void signUp()
{
	void showMenu();
	system("cls");
	date();
	printf("\n\n\n");
	Account* newNode = (Account*)malloc(sizeof(Account));
	if (newNode == NULL)
	{
		exit(-1);
	}//�ж�malloc����ռ��Ƿ�ɹ�����������
	newNode->next = NULL;
	printf("\t\t�������˺ţ�\n");
	scanf_s("%s", newNode->username,19);

	printf("\t\t���������룺\n");
	scanf_s("%s", newNode->password,7);
	newNode->money = 0.0;
	tail->next = newNode;
	tail = newNode;
	printf("\t\tע��ɹ���\n");
	saveData();
	showMenu();

}


//�ҵ�����1�����򷵻�0 
int findAccount(Account a)
{
	Account* curp = head;
	
	while (curp != NULL)
	{
		if ((strcmp(curp->username, a.username) == 0) && (strcmp(curp->password, a.password) == 0))
		{
			curAccount = curp;
		
			return 1;
		}
		curp = curp->next;
	}
	return 0;
}
void updatePassword()
{

	system("cls");
	date();
	printf("\n\n\n");
	printf("**********************************************************************\n");
	printf("*           ������ԭ�����������룬�����벻����ԭ������ͬ��           *\n");
	printf("**********************************************************************\n\n\n");
	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	��������>1	���ز˵�>2	||\n");
	printf("\t\t||	        		�˳�>3	||\n");
	printf("\t\t||--------------------------------------||\n");
	
	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
			printf("\t\t����������룺");
			char oldPassword[7] = { "\0" };
			scanf_s("%s", oldPassword, 7);
			if (strcmp(oldPassword, curAccount->password) == 0)
			{
				printf("\t\t�����������룺");
				while (1)
				{
					scanf_s("%s", curAccount->password, 7);
					if (strcmp(oldPassword, curAccount->password) == 0)
					{
						printf("\t\t�¾����벻��һ��!\n");
						printf("\t\t��������!\n");
					}
					else
						break;
				}
				printf("\t\t�޸ĳɹ���\n");

			}
			else
			{
				printf("\t\t������󣡲����޸ģ�\n");
			}
			system("pause");
			saveData();
	case 2:	homePage(); break;
	case 3: esc();
	default:
		break;
	}
	

}


void signIn()
{
	system("cls");
	date();
	printf("\n\n\n");
	printf("**********************************************************************\n");
	printf("*��������ȷ���˺������룬�������δ���������޷�ʹ�ã�������ٳ��ԣ�*\n");
	printf("**********************************************************************\n\n\n");
	int i;
	for (i = 0; i < 3; i++)
	{
		Account a;
		printf("\t\t\t�������˺ţ�");
		scanf_s("%s", a.username,19);

		printf("\t\t\t���������룺");
		scanf_s("%s", a.password,7);

		if (findAccount(a))
		{
			printf("\t\t\t��¼�ɹ���\n");
			homePage();
		}
		else
		{
			printf("\t\t\t��¼ʧ�ܣ�\n");
		}
	}
	Account* node=head;
	curAccount = node;
	saveData();

}


void showMenu()
{
	system("cls");
	date();
	printf("\n\n\n");
	if (language == 1)
	{
		printf("\t\t||------------------------------||\n");
		printf("\t\t||	    ��¼>1		||\n");
		printf("\t\t||	    ����>2		||\n");
		printf("\t\t||	    �˳�>3		||\n");
		printf("\t\t||------------------------------||\n");
	}
	else if (language == 2)
	{
		esc();
		system("pause");

	}
	int n;
	scanf_s("%d", &n);
	if (n == 1)
	{
		signIn();
	}
	else if (n == 2)
	{
		signUp();
	}
	else if (n == 3)
	{
		esc();
	}
}

//���سɹ�����1�����򷵻�0 

void saveData()
{
	FILE* fp = fopen("D:/demo2/atm.txt", "w");
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%f\n",curP->username, curP->password,  curP->money);
			curP = curP->next;
		}
		fclose(fp);
	}
}

void homePage()
{
	system("cls");
	date();
	printf("\n\n\n");
	printf("**********************************************************************\n");
	printf("*                     �������Ҫѡ��������ķ���                   ��*\n");
	printf("**********************************************************************\n\n\n");
	printf("\t\t||--------------------------------------||\n");
	printf("\t\t||	ȡ��>1		����ѯ>4	||\n");
	printf("\t\t||	���>2		��������>5	||\n");
	printf("\t\t||	ת��>3		���׼�¼>6	||\n");
	printf("\t\t||	        		�˳�>7	||\n");
	printf("\t\t||--------------------------------------||\n");
	
	
	int n;
	scanf_s("%d",&n);
	switch (n)
	{
	case 1: drawMoney(); break;
	case 2: saveMoney(); break;
	case 3:transfer(curAccount); break;
	case 4: enquiryService(); break;
	case 5: updatePassword(); break;
	case 6: findeTR(curAccount); break;
	case 7: esc(); break;
	default:
		break;
	}
}


int main()
{
	loadData();
	loadDataTR();
	date();
	printf("\n\n\n");
	printf("");
	printf("\t\t||-----------ATM����------------||\n");
	printf("\t\t||	   ҵ�����>1		||\n");
	printf("\t\t||	      �˳�>2		||\n");
	printf("\t\t||------------------------------||\n");
	scanf_s("%d", &language);
	showMenu();
	saveTR();
	saveData();
	return 0;
}
