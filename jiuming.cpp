#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000 
#include<conio.h>

struct chuhu
{
	char idnum[9];//�˻� 
	char name[10];//����
	char idnumber[20];//ʡ��֤��
	char password[7];//���� 
	double cunkuan;//��� 
}hu[N]; 

void date();//��ʾ��ǰ����
void dateEnglish(); 
int a,a1;//������ѡ����� 
void Flag0();//ѡ�����Խ��� 
void Flag1();//������
void Flag1enlish();
void Flag2();//�û����� 
void Flag2enlish();
void Flag3();//�û�����ѡ�����
void Flag3enlish();
void zhuce();//ע�� 
void signUp();
int yanzheng();//��֤�浥�Ż����� 
int cheking();
//&&&&&&&&&&&&&&&&&&&&&&&
void qukaun();//ȡ��
void drawMoney(); 
void cunkaun();//���
void saveMoney();
void zhuan();//ת�� 
void transfer();
void xiugai();//�����޸� 
void updatePassword();
void chaxun();//���� 
void enquiry();
//&&&&&&&&&&&&&&&&&&&&&&&&&&
int A,key;//�������� 
int i;//��������ѭ�� 
char ch='y';//�Ƿ����ע�� 
double jin;//���Ǯ 
int t;

char id[11],password[7];

int main()
{
    system("COLOR 0A"); 
	int a,b,t;
	Flag0();
	scanf("%d",&b);
	switch(b)
	{
		case 1:
			{
				Flag1();//����������
				do{
					printf("\n\n\t\t##���������ѡ��\n");
					scanf("%d",&a); 
					switch(a)
					{
							case 1:{
									zhuce();//ע�� 
									Flag1(); 
									break;
						           }
							case 2:{
									t=yanzheng();
									fflush(stdin);///�ö������Է���������
									Flag2();
									break;
							       } 
							case 3:exit(0);
							       break;
							default:printf("\n\n\n\t\t����������ݲ�����Ҫ��!!!\n\n\n\n\n");	
				            }
				   }while(1);
			}
		case 2:
			{
				Flag1enlish();//����������
				do{
					printf("\n\n\t\t##���������ѡ��\n");
					scanf("%d",&a); 
					switch(a)
					{
							case 1:{
									signUp();//ע�� 
									Flag1enlish(); 
									break;
						           }
							case 2:{
									t=cheking();
									fflush(stdin);///�ö������Է���������
									Flag2enlish();
									break;
							       } 
							case 3:exit(0);
							       break;
							default:printf("\n\n\n\t\t����������ݲ�����Ҫ��!!!\n\n\n\n\n");	
				            }
				   }while(1);
			}
		default:printf("\n\n\n\t\t����������ݲ�����Ҫ��!!!\n\n\n\n\n");
	}
	
}

void Flag0()
{
	printf("###########################################################\n");
	printf("|||                      ��ӭʹ��ATM                    |||\n");
	printf("|||                   Welcome to use ATM                |||\n");
	printf("###########################################################\n");
	printf("|||                   ��ѡ������Ҫ������                |||\n");
	printf("|||            please select the language you need      |||\n");
	printf("###########################################################\n");
	printf("|||                    1.  ����                         |||\n");
	printf("|||                    2.  Enlish                       |||\n");
	printf("###########################################################\n");
	
}

void Flag1()
{
	printf("\n#################################################################################\n");
    printf("\n��                           * �Զ�ȡ���ϵͳ  *                               ��\n");
    printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          |��|******|��|       �� ����ҵ��    �밴 1         |��|******|��|\n"); 
	printf("          |��|******|��|       �� ��¼ϵͳ    �밴 2         |��|******|��|\n");
	printf("          |��|******|��|       �� �˳�        �밴 3         |��|******|��|\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
	
} 

void Flag1enlish()
{
	printf("\n#################################################################################\n");
    printf("\n��                                   * ATM  *                                  ��\n");
    printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          |��|******|��|       ��1. Sign  Up                 |��|******|��|\n"); 
	printf("          |��|******|��|       ��2. Sign  In                 |��|******|��|\n");
	printf("          |��|******|��|       ��3. Sign  Out                |��|******|��|\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
		
}



//********************************************************************************************************************

//�û����� 
void Flag2()
{
       int a;//ѡ���ܵı���
       char ch;
	   do{
	   	printf("\n\n��ENTER�����롢�������˵� \n");
	   	fflush(stdin);
	   	scanf("%c",&ch);
	   	system("cls");//����
		   date(); 
	printf("\n#################################################################################\n");
    printf("\n��                               * ��ӭʹ��  *                                 ��\n");
    printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");	
	printf("          |��|******|��|        �� ���ҵ��       �밴 1        |��|******|��|\n"); 
	printf("          |��|******|��|        �� ȡ��ҵ��       �밴 2        |��|******|��|\n");
	printf("          |��|******|��|        �� ��ѯҵ��       �밴 3        |��|******|��|\n"); 
	printf("          |��|******|��|        �� ת��ҵ��       �밴 4        |��|******|��|\n");
	printf("          |��|******|��|        �� �޸�����       �밴 5        |��|******|��|\n");
	printf("          |��|******|��|        �� �˳�ϵͳ       �밴 6        |��|******|��|\n"); 
	printf("          |��|******|��|                                        |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
    printf("\n#################################################################################\n");
    printf("\n��                          *******************************                    ��\n");
    printf("\n#################################################################################\n");
	printf("\n\n\t\t##���������ѡ��\n");
	fflush(stdin);
	scanf("%d",&a);
	switch(a)
	{//ע��
		case 1: 
		{ 
			system("cls");fflush(stdin);cunkaun();break;//���
		} 
		case 2:  
		{
			system("cls");fflush(stdin);qukaun();break;//ȡ��
		}
		case 3: 
		{
			chaxun();//��ѯҵ��
			break;
		}
		case 4:
		{
			system("cls");fflush(stdin);zhuan();break;//ת�� 
		}
		case 5: 
		{
			system("cls");fflush(stdin);xiugai();break;//�����޸�
		}
		case 6: exit(0);
		default:printf("�������ѡ��������������ȷ��ѡ�\n");
	                                            	         
	}
	 } while(1);
} 

void Flag2enlish()
{
       int a;//ѡ���ܵı���
       char ch;
	   do{
	   	printf("\n\nPress ENTER to ENTER and return to the main menu\n");
	   	fflush(stdin);
	   	scanf("%c",&ch);
	   	system("cls");//����
		   date(); 
	printf("\n#################################################################################\n");
    printf("\n��                               *  Weclome  *                                 ��\n");
    printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");	
	printf("          |��|******|��|      ��1.Deposit    business           |��|******|��|\n"); 
	printf("          |��|******|��|      ��2.Withdrwal  business           |��|******|��|\n");
	printf("          |��|******|��|      ��3.Enquiry    Service            |��|******|��|\n"); 
	printf("          |��|******|��|      ��4.Money Transfer Service        |��|******|��|\n");
	printf("          |��|******|��|      ��5.Change the password           |��|******|��|\n");
	printf("          |��|******|��|      ��6.Exit the system               |��|******|��|\n"); 
	printf("          |��|******|��|                                        |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
    printf("\n#################################################################################\n");
    printf("\n��                          *******************************                    ��\n");
    printf("\n#################################################################################\n");
	printf("\n\n\t\t##���������ѡ��\n");
	fflush(stdin);
	scanf("%d",&a);
	switch(a)
	{//ע��
		case 1: 
		{ 
			system("cls");fflush(stdin);saveMoney();break;//���
		} 
		case 2:  
		{
			system("cls");fflush(stdin);drawMoney();break;//ȡ��
		}
		case 3: 
		{
			enquiry();//��ѯҵ��
			break;
		}
		case 4:
		{
			system("cls");fflush(stdin);transfer();break;//ת�� 
		}
		case 5: 
		{
			system("cls");fflush(stdin);updatePassword();break;//�����޸�
		}
		case 6: exit(0);
		default:printf("You have entered an incorrect selection. Please enter the correct selection:\n");
	                                            	         
	}
	 } while(1);
} 
//********************************************************************************************************************
//�û�����ѡ����� 
void Flag3()
{
	printf("\n\n\t\t##���������ѡ��");
	scanf("%d",&a1);
	switch(a1)
	{
		case 1:printf("���ҵ��");break; 
		case 2:printf("ȡ��ҵ��");break; 
		case 3:printf("��ѯҵ��");break; 
		case 4:printf("ת��ҵ��");break; 
		case 5:printf("�����޸�");break;
		case 6:printf("�˳�");break;  
	} 
}

void Flag3enlish()
{
    printf("\n\n\t\t##Please enter your choice:");
	scanf("%d",&a1);
	switch(a1)
	{
		case 1:printf("Deposit business");break; 
		case 2:printf("Withdrwal business");break; 
		case 3:printf("Enquiry service ");break; 
		case 4:printf("Money Transfer Service");break; 
		case 5:printf("Change the password");break;
		case 6:printf("Exit the system");break;  
	} 
}




//********************************************************************************************************************
//���� 
void zhuce(){
	FILE *nchuhu=fopen("chuh.txt","r");
	FILE *fchuhu=fopen("chuh.txt","a");
	int i;
	if((nchuhu=fopen("chuh.txt","r"))==NULL) printf("�ļ��ޣ�ϵͳ����\n"); 
	do{
	 system("cls");
	date();//��ʾ��ǰ���� 
	printf("\n\n\t\t�������´�������Ϣ��");
	fscanf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,&hu[A].cunkuan); 
	
	printf("\n\n\t\t�����浥��");
	fflush(stdin);
	gets(hu[A].idnum);
	printf("\n\t\t������");
	fflush(stdin);
	gets(hu[A].name);
	printf("\n\t\t�������루6λ����");
	for(i=0;i<6;i++){
		fflush(stdin);
		hu[A].password[i]=getch();
		printf("*");
	//	scanf("%d",&hu[A].password[i]);
	} 
	
	do{
		printf("������ʡ��֤����(18λ)��");
		fflush(stdin);
		gets(hu[A].idnumber);
		if(strlen(hu[A].idnumber)!=18)//strlen �������˼
		printf("\n\t\t�������\n\t\t���֤������18λ���ֻ�����ĸ\n");
		for(i=0;i<A;i++)
		if(strcmp(hu[A].idnumber,hu[i].idnumber)==0&&strcmp(hu[A].name,hu[i].name)==0) 
		break;
		
		if(i<A) 
		  printf("\n\n\t\tǰ���Ѿ������ô����֤ע���\n\n\t\t����������ʡ��֤�ţ�\n");
		  	 
	}while(((strlen(hu[A].idnumber)!=18)||(strcmp(hu[A].idnumber,hu[i].idnumber)==0))&&(strcmp(hu[A].name,hu[i].name)!=0) );
	
	printf("����洢�Ľ�");
	fflush(stdin);
	scanf("%lf",&hu[A].cunkuan);
	
	fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
	A++;
	printf("�Ƿ������(y)/��(n)?");
	fflush(stdin);
	scanf("%c",&ch); 
	}while(ch=='y'||ch=='Y');
	printf("����ɹ���");
//	system("pause");
	system("cls");
	fclose(nchuhu);
	fclose(fchuhu);
}

void signUp()
{
	FILE *nchuhu=fopen("chuh.txt","r");
	FILE *fchuhu=fopen("chuh.txt","a");
	int i;
	if((nchuhu=fopen("chuh.txt","r"))==NULL) printf("No files, system created\n"); 
	do{
	 system("cls");
	date();//��ʾ��ǰ���� 
	printf("\n\n\t\tPlease enter the information of the new depositor��\n");
	fscanf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,&hu[A].cunkuan); 
	printf("\n\n\t\tDepositor's certificate of deposit��\n");
	fflush(stdin);
	gets(hu[A].idnum);
	printf("\n\t\tname��\n");
	fflush(stdin);
	gets(hu[A].name);
	printf("\n\t\tUser Password (6 digits)��\n");
	for(i=0;i<6;i++){
		fflush(stdin);
		hu[A].password[i]=getch();
		printf("*");
	//	scanf("%d",&hu[A].password[i]);
	} 
	
	do{
		printf("Please enter the provincial card number (18 digits)��\n");
		fflush(stdin);
		gets(hu[A].idnumber);
		if(strlen(hu[A].idnumber)!=18)//strlen �������˼
		{
			printf("\n\t\tINPUT ERROR!\n\t\tPlease enter 18 digits or letters for your ID card\n");
			continue;
		}
		for(i=0;i<A;i++)
		if(strcmp(hu[A].idnumber,hu[i].idnumber)==0&&strcmp(hu[A].name,hu[i].name)==0) 
		break;
		
		if(i<A) 
		  printf("\n\n\t\t\n\n\t\tPlease re-enter the provincial card number��\n");
		  	 
	}while(((strlen(hu[A].idnumber)!=18)||(strcmp(hu[A].idnumber,hu[i].idnumber)==0))&&(strcmp(hu[A].name,hu[i].name)!=0) );
	
	printf("Enter the amount saved��");
	fflush(stdin);
	scanf("%lf",&hu[A].cunkuan);
	fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
	A++;
	printf("Is it still (Y)/No (N) ?\n");
	fflush(stdin);
	char ch;
	scanf("%c",&ch); 
	}while(ch=='y'||ch=='Y');
	printf("Deposit successful��\n");
//	system("pause");
	system("cls");
	fclose(nchuhu);
	fclose(fchuhu);	
}




//********************************************************************************************************************
//��֤�浥�Ż����� 
int yanzheng(){
	FILE *fchuhu=fopen("chuh.txt","r");
	int count=0;
	char id[9];
	for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	do{
		system("cls");
			    printf("\n\n\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				printf("\t\t|#|                                                          |#|\n");
				printf("\t\t|#|                    �����������                  |#|\n");
				printf("\t\t|#|                    ��                ��                  |#|\n");
				printf("\t\t|#|             ��   �浥�Ż������������Զ�����   ��         |#|\n");
				printf("\t\t|#|                    ��                ��                  |#|\n");
				printf("\t\t|#|                    �����������                  |#|\n");
				printf("\t\t|#|                                                          |#|\n");
				printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n\n\n\t\t      ���������Ĵ浥�ţ�  ");
		scanf("%s",id);
		printf("\n\n\n\t\t      �������������룺  ");
		for(i=0;i<6;i++){
			fflush(stdin);
		password[i]=getch();
			printf("*");
		} 
		password[6]='\0';
		fflush(stdin);
		scanf("%c",&ch);
		printf("\n\n\t\t");
		for(i=0;i<99;i++){
			if(strcmp(id,hu[i].idnum)==0&&strcmp(password,hu[i].password)==0){
				fclose(fchuhu);
				return 0;
			}
		}
	
		
	}while(count==0);
	fclose(fchuhu);
	//return count;
}

int cheking()
{
	FILE *fchuhu=fopen("chuh.txt","r");
	int count=0;
	char id[9];
	for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	do{
		system("cls");
			    printf("\n\n\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				printf("\t\t|#|                                                                        |#|\n");
				printf("\t\t|#|                            �����������                        |#|\n");
				printf("\t\t|#|                            ��                ��                        |#|\n");
				printf("\t\t|#|The deposit slip number or password is returned automatically in error  |#|\n");
				printf("\t\t|#|                            ��                ��                        |#|\n");
				printf("\t\t|#|                            �����������                        |#|\n");
				printf("\t\t|#|                                                                        |#|\n");
				printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n\n\n\t\t  Please enter your deposit slip number��  \n");
		scanf("%s",id);
		printf("\n\n\n\t\t  Please enter your password��  \n");
		for(i=0;i<6;i++){
			fflush(stdin);
		password[i]=getch();
			printf("*");
		} 
		password[6]='\0';
		fflush(stdin);
		scanf("%c",&ch);
		printf("\n\n\t\t");
		for(i=0;i<99;i++){
			if(strcmp(id,hu[i].idnum)==0&&strcmp(password,hu[i].password)==0){
				fclose(fchuhu);
				return 0;
			}
		}	
	}while(count==0);
	fclose(fchuhu);
	return count;
}



//********************************************************************************************************************
//********************************************************************************************************************
//���
void cunkaun()
{
	FILE *fchuhu=fopen("chuh.txt","r");
	FILE *achuhu=fopen("back.txt","w");
	char id[9];int i;
	if(!fchuhu) printf("���ܴ��ļ���");
	if(!achuhu) printf("���ܴ����ļ�");
	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}	//
	int a;
		date();
		printf("\n\n\t\t##���ٴ����벢ȷ�ϴ浥��");
		scanf("%s",id);
		for(i=0;i<=100;i++){
			if(strcmp(id,hu[i].idnum)==0){		
		   printf("\n\n"); 
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                           *�����*                           ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||         1��200        2��400        3��600        4��800       ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	    	printf("\t\t||         5��1000        6��2000        7��4000        8��6000   ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\n\n\t\t\t���������ȡ���");
	 		scanf("%d",&a);
	 		switch(a){
	 			case 1:{jin=200;
	 				 printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 2:{jin=400;
	 			    printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^");  
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 3:{
				 	jin=600;
				 	 printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^");  
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 4:{
				 		jin=800;
				  printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 	 			case 5:{jin=1000;
	 			 printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 6:{jin=2000;
	 			 printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 7:{
				 	jin=4000;
				  printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 8:{
				 		jin=6000;
				 	 printf("\t\t\t���%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^���ɹ�^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 default:printf("\n\n\n\t\t\t����ѡ����ڷ���Χ�ڣ�����\n\n\n\t\t\t������ѡ��ҵ��"); 
				 
			 }			
				fclose(fchuhu);
	            fclose(achuhu);
            	system("del chuh.txt");
              	rename("back.txt","chuh.txt");//rename(�ɵģ��µģ� 
                break;		
				}
				}
}


void saveMoney()
{
		FILE *fchuhu=fopen("chuh.txt","r");
		FILE *achuhu=fopen("back.txt","w");
		char id[9];int i;
		if(!fchuhu) printf("The file can not be opened��");
		if(!achuhu) printf("The file can not be created");
		for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
		}	//
		int a;
			date();
			printf("\n\n\t\t##Please re-enter and confirm the certificate of deposit��");
			scanf("%s",id);
			for(i=0;i<=100;i++){
				if(strcmp(id,hu[i].idnum)==0){		
			   printf("\n\n"); 
		 		printf("\t\t||================================================================||\n");
		 		printf("\t\t||                       *Amount of deposit*                      ||\n");
		 		printf("\t\t||================================================================||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||         1��200        2��400        3��600        4��800       ||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||                                                                ||\n");
		    	printf("\t\t||         5��1000        6��2000        7��4000        8��6000   ||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||================================================================||\n");
		 		printf("\t\t||================================================================||\n");
		 		printf("\n\n\t\t\tPlease enter your withdrawal amount��");
		 		scanf("%d",&a);
		 		switch(a){
		 			case 1:{jin=200;
		 				 printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^"); 
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 2:{jin=400;
		 			    printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^");  
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
					    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 3:{
					 	jin=600;
					 	 printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^");  
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 4:{
					 		jin=800;
					  printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^"); 
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 	 			case 5:{jin=1000;
		 			 printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^"); 
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 6:{jin=2000;
		 			 printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^"); 
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
					    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 7:{
					 	jin=4000;
					  printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^"); 
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 8:{
					 		jin=6000;
					 	 printf("\t\t\tDeposit %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^Deposit success^^^^"); 
				    	hu[i].cunkuan+=jin;
				    	printf("\n\n\t\t\t$Your balance is:%lf yuan",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 default:printf("\n\n\n\t\t\tYour selection amount is not covered by the service������\n\n\n\t\t\tPlease re-select business��\n"); 
					 
				 }			
					fclose(fchuhu);
		            fclose(achuhu);
	            	system("del chuh.txt");
	              	rename("back.txt","chuh.txt");//rename(�ɵģ��µģ� 
	                break;		
					}
					}
}



//*******************************************************************************************************************
//ȡ�� 
void qukaun()
{
	FILE *fchuhu=fopen("chuh.txt","r");
	FILE *achuhu=fopen("back.txt","w");
	int i,a;
	char id[9];
	if(!fchuhu) printf("���ܴ��ļ���");
	if(!achuhu) printf("���ܴ������ļ���");
	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}

	 	date();
	 	printf("\n\n\t\t���ٴ����벢ȷ�ϴ浥��");
	 	scanf("%s",id);
	 	for(i=0;i<=99;i++){
	 		if(strcmp(id,hu[i].idnum)==0){
	 	    printf("\n\n"); 
	     	printf("\t\t||================================================================||\n");
	 		printf("\t\t||                           *ȡ����*                           ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||         1��200        2��400        3��600        4��800       ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	    	printf("\t\t||         5��1000        6��2000        7��4000        8��6000   ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\n\n\t\t\t���������ȡ���");
	 		scanf("%d",&a);
	 		switch(a){
	 			case 1:{jin=200;
	 				printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 2:{jin=400;
	 				printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 3:{
				 	jin=600;
				 printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^");  
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 4:{
				 		jin=800;
				 printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 	 			case 5:{jin=1000;
	 				printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 6:{jin=2000;
	 			printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 7:{
				 	jin=4000;
				 printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 8:{
				 		jin=6000;
				 printf("\t\t\tȡ��%lfԪ",jin);
			     	printf("\n\n\n\t\t\t^^^^ȡ��ɹ�^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$�������Ϊ��%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 default:printf("\n\n\n\t\t\t����ѡ����ڷ���Χ�ڣ�����\n\n\n\t\t\t������ѡ��ҵ��"); 
				 
			 }
				fclose(fchuhu);
     	        fclose(achuhu);
             	system("del chuh.txt");
             	rename("back.txt","chuh.txt");
				break;
			 }

		 }

}

void drawMoney()
{
	FILE *fchuhu=fopen("chuh.txt","r");
		FILE *achuhu=fopen("back.txt","w");
		int i,a;
		char id[9];
		if(!fchuhu) printf("The file can not be opened��\n");
		if(!achuhu) printf("A new file can not be created��");
		for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
		}
	
		 	date();
		 	printf("\n\n\t\tPlease re-enter and confirm the certificate of deposit��");
		 	scanf("%s",id);
		 	for(i=0;i<=99;i++){
		 		if(strcmp(id,hu[i].idnum)==0){
		 	    printf("\n\n"); 
		     	printf("\t\t||================================================================||\n");
		 		printf("\t\t||                      *Withdrawal Amount*                       ||\n");
		 		printf("\t\t||================================================================||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||         1��200        2��400        3��600        4��800       ||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||                                                                ||\n");
		    	printf("\t\t||         5��1000        6��2000        7��4000        8��6000   ||\n");
		 		printf("\t\t||                                                                ||\n");
		 		printf("\t\t||================================================================||\n");
		 		printf("\t\t||================================================================||\n");
		 		printf("\n\n\t\t\tPlease enter your withdrawal amount��\n");
		 		scanf("%d",&a);
		 		switch(a){
		 			case 1:{jin=200;
		 				printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 2:{jin=400;
		 				printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
					    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 3:{
					 	jin=600;
					 printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^");  
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 4:{
					 		jin=800;
					 printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 	 			case 5:{jin=1000;
		 				printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 6:{jin=2000;
		 			printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
					    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 7:{
					 	jin=4000;
					 printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 case 8:{
					 		jin=6000;
					 printf("\t\t\tGets the %lf yuan",jin);
				     	printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    	hu[i].cunkuan-=jin;
				    	printf("\n\n\t\t\t$Your balance is��%lf",hu[i].cunkuan);
				    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
						break;
					 }
					 default:printf("\n\n\n\t\t\tYour selection amount is not covered by the service������\n\n\n\t\t\tPlease re-select business��\n"); 
					 
				 }
					fclose(fchuhu);
	     	        fclose(achuhu);
	             	system("del chuh.txt");
	             	rename("back.txt","chuh.txt");
					break;
				 }
	
			 }
}



//********************************************************************************************************************
//ת��
void transfer()
{
	FILE *fchuhu=fopen("chuh.txt","r+");
	int i;
	char id[9];
	if(!fchuhu) printf("The file can not be opened��");

	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}

	 	date();
	 	printf("\n\n\t\tPlease enter the deposit slip number of the transferor��");
	 	scanf("%s",id);
	 	for(i=0;i<=99;i++){
	 		if(strcmp(id,hu[i].idnum)==0){
	 	      printf("\n\n\t\tPlease enter the amount to be transferred��");
			   scanf("%lf",&jin);
			   printf("\n\n\t\t  Please confirm the number��%lf",jin); 
				 hu[i].cunkuan+=jin;
				 printf("\n\n\nThe transfer was successful"); 
				 	fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
				 		fclose(fchuhu);
	fclose(fchuhu);

				 break;
			 }

		 }

	
} 

void zhuan()
{
		FILE *fchuhu=fopen("chuh.txt","r+");
		int i;
		char id[9];
		if(!fchuhu) printf("���ܴ��ļ���");
	
		for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
		}
	
		 	date();
		 	printf("\n\n\t\t������ת���˵Ĵ浥�ţ�");
		 	scanf("%s",id);
		 	for(i=0;i<=99;i++){
		 		if(strcmp(id,hu[i].idnum)==0){
		 	      printf("\n\n\t\t������Ҫת�˵Ľ�");
				   scanf("%lf",&jin);
				   printf("\n\n\t\t��ȷ����Ŀ��%lf",jin); 
					 hu[i].cunkuan+=jin;
					 printf("\n\n\nת�˳ɹ�"); 
					 	fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
					 		fclose(fchuhu);
		fclose(fchuhu);
	
					 break;
				 }
	
			 }
}



//********************************************************************************************************************
//�޸� 
void xiugai()
{
	FILE *fchuhu=fopen("chuh.txt","r");
	FILE *achuhu=fopen("back.txt","w");
	int j,i;
	char id[9];
	if(!fchuhu) printf("���ܴ��ļ���");
	if(!achuhu) printf("���ܴ������ļ���");
	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}

	 	date();
	 	printf("\n\n\t\t���ٴ����벢ȷ�ϴ浥��");
	 	scanf("%s",id);
	 	for(i=0;i<=99;i++){
	 		if(strcmp(id,hu[i].idnum)==0){
	 		printf("�������µ����룺\n");
	 			printf("\n\t\t�������루6λ����");
	for(j=0;j<6;j++){
		fflush(stdin);
		hu[i].password[j]=getch();
		printf("*");

	} 
				 printf("\n\n\t\t�µ����룺%s\n",hu[i].password);
			 
				 printf("\n\n\t\t�޸ĳɹ�"); 
				 	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
				 		fclose(fchuhu);
	fclose(achuhu);
	system("del chuh.txt");
	rename("back.txt","chuh.txt");
				 break;
			 }

		 }
}

void updatePassword()
{
		FILE *fchuhu=fopen("chuh.txt","r");
		FILE *achuhu=fopen("back.txt","w");
		int j,i;
		char id[9];
		if(!fchuhu) printf("The file can not be opened��\n");
		if(!achuhu) printf("A new file can not be created��");
		for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
		}
	
		 	date();
		 	printf("\n\n\t\tPlease re-enter and confirm the certificate of deposit��\n");
		 	scanf("%s",id);
		 	for(i=0;i<=99;i++){
		 		if(strcmp(id,hu[i].idnum)==0){
		 		printf("Please enter a new password��\n");
		 			printf("\n\t\tUser Password (6 digits)��");
		for(j=0;j<6;j++){
			fflush(stdin);
			hu[i].password[j]=getch();
			printf("*");
	
		} 
					 printf("\n\n\t\t�µ����룺%s\n",hu[i].password);
				 
					 printf("\n\n\t\tModification successful"); 
					 	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
					 		fclose(fchuhu);
		fclose(achuhu);
		system("del chuh.txt");
		rename("back.txt","chuh.txt");
					 break;
				 }
	
			 }
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//��ѯ��Ϣ 
void chaxun()
{
	FILE *fchuhu=fopen("chuh.txt","r");
	int i,n=0;
	char fnumb[9];
	system("cls");
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	
	printf("\n\n�������������������������������������������������������������\n");
	printf("\n\n              �����������������������������������������������                      \n");
	printf("\n\n                              ���������������������������                                              \n");
	printf("\n\n\n\t\t\t\t\t��������Ĵ浥�ţ�");
	scanf("%s",fnumb);
	printf("\n\n\n");
	printf("\t\t\t\t\t���ĸ�����Ϣ���£�");
	printf("\n\n");
	for(i=0;i<=99;i++)
		if(strcmp(fnumb,hu[i].idnum)==0)
		{
			printf("�浥�ţ�%s\t������%s\t���֤��%s\t���룺%s\t����%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
			n=1;
			fclose(fchuhu);
			system("pause"); 
            break; 
		}
    if(n==0) printf("���˵������ڣ�����\n");
    fclose(fchuhu);
}

void enquiry()
{
		FILE *fchuhu=fopen("chuh.txt","r");
		int i,n=0;
		char fnumb[9];
		system("cls");
		for(i=0;i<=100;i++)
		{
			fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
		}
		
		printf("\n\n�������������������������������������������������������������\n");
		printf("\n\n              �����������������������������������������������                      \n");
		printf("\n\n                              ���������������������������                                              \n");
		printf("\n\n\n\t\t\t\t\t Please enter your deposit slip number��");
		scanf("%s",fnumb);
		printf("\n\n\n");
		printf("\t\t\t\t\tYour personal information is as follows��");
		printf("\n\n");
		for(i=0;i<=99;i++)
			if(strcmp(fnumb,hu[i].idnum)==0)
			{
				printf("Certificate number��%s\tname��%s\tid card��%s\tpassord��%s\tAmount of deposit��%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
				n=1;
				fclose(fchuhu);
				system("pause"); 
	            break; 
			}
	    if(n==0) printf("This bill does not exist������\n");
	    fclose(fchuhu);
}



//********************************************************************************************************************
void date()
{//��ʾ��ǰ����
	printf("��ǰ���ڣ�");
	system("date/t");
	printf("��ǰʱ�䣺");
	system("time/t"); 
}

void dateEnglish()
{
	printf("Current date��");
	system("date/t");
	printf("Current time��");
	system("time/t"); 
}
