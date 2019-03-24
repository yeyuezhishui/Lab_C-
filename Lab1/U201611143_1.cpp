#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


struct STACK {
	int  *elems;	//�����ڴ����ڴ��ջ��Ԫ��
	int   maxNum;	//ջ�ܴ�ŵ����Ԫ�ظ���
	int   pos;	//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
};

void initSTACK(STACK *const p, int m);	//��ʼ��pָ���ջ�����m��Ԫ��
void initSTACK(STACK *const p, STACK * const s); //��ջs��ʼ��pָ���ջ
int  sizeNum(const STACK *const p);		//����pָ���ջ�����Ԫ�ظ���max
int  howMany(const STACK *const p);	//����pָ���ջ��ʵ��Ԫ�ظ���pos
int  getelem(const STACK *const p, int x);	//ȡ�±�x����ջԪ��
STACK *const push(STACK *const p, int e); 	//��e��ջ��������p
STACK *const pop(STACK *const p, int *e); 	//��ջ��e��������p
STACK *const assignValue(STACK*const p, STACK *const s); //��s��pָ��ջ,������p
void print(const STACK*const p);			//��ӡpָ���ջ
void destroySTACK(STACK*const p);		//����pָ���ջ

FILE *fp;


int main(int argc, char * argv[])
{
	int err;
	if ((fp = fopen("U201611143_1.txt","w")) == 0) {
		printf("Cannot open file strike any key exit!");
		getchar();
	}

	if (argc == 1)
	{
		struct STACK *pStack = (struct STACK *)malloc(sizeof(struct STACK));
		struct STACK *sStack = (struct STACK *)malloc(sizeof(struct STACK));
		initSTACK(sStack, 5);
		push(sStack, 4);
		push(sStack, 7);
		push(sStack, 6);
		push(sStack, 1);
		push(sStack, 3);
		push(sStack, 4);

		int operate = 1;  //������� ��0-12֮��
		int isInitial = 0; //�ж�ջ�Ƿ����
		int maxNum;
		int e;
		int temp;
		int input;
		while (operate) {
			system("cls");
			printf("\n\n");
			printf("-------------------Welcome---------------\n");
			printf("1. ��ʼ��ջP         ||7. ��һ������ջ��e\n");
			printf("2. ��ջS��ʼ��ջP    ||8. ��s��pָ���ջ\n");
			printf("3. ջԪ�ص�������  ||9. ��ӡpָ���ջ \n");
			printf("4. ջ��ʵ��Ԫ�ظ���  ||10. ����pָ���ջ\n");
			printf("5. ȡ�±�Ϊx��ջԪ�� ||0. �˳�           \n");
			printf("6.  ����һ��������ջ\n");
			printf("-------------------------------------------------\n");
			printf("��ѡ����Ĳ���:");
			scanf("%d", &operate);
			switch (operate)
			{
			case 1:
				//InitStack
				if (isInitial == 0)
				{
					printf("\n\t������ջ�Ĵ�С:");
					scanf("%d", &maxNum);
					initSTACK(pStack, maxNum);
					isInitial = 1;
					printf("\n\t�½�ջ�ɹ���ջ�Ĵ�СΪ%d\n", maxNum);
				}
				else
				{
					printf("\n\tջ�Ѿ�������\n");
				}

				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 2:
				//initSTACK��S-P
				if (isInitial)printf("\n\tջp�Ѿ���ʼ����");
				else
				{
					initSTACK(pStack, sStack);
					printf("\n\t�ɹ���ջs�½�ջp");
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 3:
				//sizeNum
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					temp = sizeNum(pStack);
					printf("\n\t��ջ�����������%d", temp);
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 4:
				//howMany
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					temp = howMany(pStack);
					printf("\n\t��ջ��Ŀǰ��%d��Ԫ��", temp);
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 5:
				//getelem
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					printf("\n\t��������Ҫ���ҵ������±�:\n");
					scanf("%d", &temp);
					if (temp <= howMany(pStack))
					{
						temp = getelem(pStack, temp);
						printf("\n\t��Ҫ���ҵ�����Ϊ%d\n", temp);
					}
					else
					{
						printf("\n\t������Χ��\n");
					}

				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 6:
				//push
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					printf("\n\t����������Ҫ��ջ��Ԫ��:");
					scanf("%d", &e);
					push(pStack, e);
					printf("\n\t�ɹ���ջ��\n");
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 7:
				//LocateElem
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					pop(pStack, &e);
					printf("\n\t��ջ������Ϊ%d", e);
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 8:
				//PriorElem
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					assignValue(pStack, sStack);
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 9:
				//NextElem
				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					printf("\n\t��ջ������Ϊ��\n");
					print(pStack);
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;
			case 10:

				if (!isInitial)printf("\n\tջp�����ڣ�");
				else
				{
					printf("\n\t�ɹ����ٸ�ջ��\n");
				}
				getchar();
				printf("\n\t\t�������������������\n");
				getchar();
				break;

			case 0:
				break;
			}//end of switch
		}//end of while
		printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
		return 0;
	}
	else {

		struct STACK *pStack = (struct STACK *)malloc(sizeof(struct STACK));
		struct STACK *sStack = (struct STACK *)malloc(sizeof(struct STACK));
		int tempInt; // ��ʱʹ�õ�����

		int ifInit = 0;
		int ifNew = 0; //�ж��Ƿ����ջ����

		int i;
		int e;

		for (i = 1; i<argc; i++)
		{
			//������-S
			if (!strcmp(argv[i], "-S"))
			{
				printf("S  ");
				fputs("S  ", fp);


				if (ifInit == 1)
				{
					printf("E "); //��ô����������ѭ��
					fputs("E  ", fp);
					break;
				}

				//�����һλ�Ǵ���0С��9������
				if (argv[i + 1][0] >= '0' && argv[i + 1][0] <= '9')
				{

					tempInt = atoi(argv[++i]);             //���ַ���ת��������
					initSTACK(pStack, tempInt);            //�½�ջ
					fprintf(fp, "%d  ", tempInt);
					printf("%d  ", tempInt);
					ifInit = 1;  //ջ�½����޸�Ϊ1
				}
				else
				{
					printf("E  ");
					fputs("E  ", fp);
					break;
				}
			}

			//������-I����ʼ����Ԫ��
			if (!strcmp(argv[i], "-I"))
			{
				fputs("I  ", fp);
				printf("I  ");

				int ifLast = 0; // �ж��ǲ������һ����ĸ
				int k = i + 1;
				for (; k < argc; k++)
				{
					ifLast = 1;
					if (!strcmp(argv[k], "-I") || !strcmp(argv[k], "-O") || !strcmp(argv[k], "-N") || !strcmp(argv[k], "-G"))
					{
						ifLast = 0;
						break;
					}
				}


				//�����û���½�����ô�ͱ���
				if (ifInit == 0)
				{
					printf("E  ");
					fputs("E  ", fp);
					exit(1);
				}

				i++;

				for (; (i < argc) && (argv[i][0] >= '0') && (argv[i][0] <= '9'); i++)
				{
					tempInt = atoi(argv[i]);   //���ַ���ת��������'
					int stackNum = howMany(pStack);
					int stackMax = sizeNum(pStack);

					if (stackNum == stackMax)
					{
						printf("E  ");
						fputs("E  ", fp);
						getchar();
						getchar();
						exit(1);
					}

					push(pStack, tempInt);     //��ջ

				}
				print(pStack);
				i--;
			}


			if (i < argc)
			{
				if (!strcmp(argv[i], "-O"))
				{
					fputs("O  ", fp);
					printf("O  ");


					if (ifInit == 0)
					{
						printf("E  "); //��ô����������ѭ��
						fputs("E ", fp);
						break;
					}
					//�����һλ�Ǵ���0С��9������
					if (argv[i + 1][0] >= '0' && argv[i + 1][0] <= '9')
					{
						tempInt = atoi(argv[++i]);
						if (tempInt > howMany(pStack))
						{
							printf("E  ");
							fputs("E  ", fp);
							break;
						}
						int j;
						for (j = 0; j < tempInt; j++)
						{
							pop(pStack, &e);
						}
					
						if(howMany(pStack)) print(pStack);

						i--;
					}
					else
					{
						
						printf("E  ");
						fputs("E ", fp);
						break;
					}
				}

				//��⵽һ����ջ�Ľ���
				if (!strcmp(argv[i], "-A"))
				{
					fputs("A  ", fp);
					printf("A  ");
					//�����һλ�Ǵ���0С��9������
					if (argv[i + 1][0] >= '0' && argv[i + 1][0] <= '9')
					{

						tempInt = atoi(argv[++i]);             //���ַ���ת��������
						initSTACK(sStack, tempInt);            //�½�ջ
						assignValue(sStack, pStack);
						if (howMany(pStack)) print(pStack);
					}
					else
					{
						printf("E  ");
						fputs("E ", fp);
						break;
					}
				}

				//��ȿ���
				if (!strcmp(argv[i], "-C"))
				{
					fputs("C  ", fp);
					printf("C  "); 
					initSTACK(sStack, pStack);            //�½�ջ
					if (howMany(pStack)) print(pStack);

				}


				if (!strcmp(argv[i], "-N"))
				{
					fputs("N  ", fp);
					printf("N  ");
					//�����һλ�Ǵ���0С��9������
					int N = howMany(pStack);//�½�ջ
					fprintf(fp, "%d  ", N);
					printf("%d  ", N);
					getchar();
					getchar();
					fclose(fp);
					return 0;

				}


				if (!strcmp(argv[i], "-G"))
				{
					fputs("G  ", fp);
					printf("G  ", fp);
					//�����һλ�Ǵ���0С��9������
					tempInt = atoi(argv[i + 1]);
					if (tempInt >= howMany(pStack))
					{
						fputs("E  ", fp);
						printf("E  ");
						break;
					}
					else
					{
					int N = getelem(pStack, tempInt);//�½�ջ
					fprintf(fp, "%d  ", N);
					printf("%d  ", N);
					}
					
				}

			}

		}
		fclose(fp);
		getchar();
		getchar();
	}
	return 0;

}

void initSTACK(STACK *const p, int m)
{
	p->elems = (int*)malloc(sizeof(int)*m);
	p->maxNum = m;
	p->pos = 0;
}

void initSTACK(STACK *const p, STACK *const s)
{
	p->elems = (int*)malloc(sizeof(int)*s->maxNum);
	p->maxNum = s->maxNum;
	p->pos = s->pos;
	assignValue(p, s);
}

int  sizeNum(const STACK *const p)
{
	return p->maxNum;
}

int  howMany(const STACK *const p)
{
	return p->pos;
}

int  getelem(const STACK *const p, int x)	//ȡ�±�x����ջԪ��
{
	if (x > p->pos)
	{
		printf("����������±꣡\n");
		fputs("E ", fp);
		return 0;
	}
	return p->elems[x];
}

STACK *const push(STACK *const p, int e)
{
	if (p->pos == p->maxNum)
	{
		printf("��ջ�������޷�������Ԫ��");
		return p;
	}
	p->elems[p->pos] = e;
	p->pos++;
	return p;
}

STACK *const pop(STACK *const p, int *e)
{
	if (p->pos != 0)
	{
		*e = p->elems[p->pos];
		p->pos--;
	}
	else
	{
		printf("E  ");
		fputs("E ", fp);
		return p;
	}
	return p;
}


STACK *const assignValue(STACK*const p, STACK *const s)
{
	int i;
	for (i = 0; i<s->pos && i<p->maxNum; i++)
	{
		p->elems[i] = s->elems[i];
	}
	p->pos = i;
	return p;
}

void print(const STACK*const p)
{
	int i;
	if (p->pos == 0)
	{
		printf("ջ��!\n");
		fputs("E ", fp);
		return;
	}
	for (i = 0; i<p->pos; i++)
	{
		printf("%d  ", p->elems[i]);
		fprintf(fp, "%d  ", p->elems[i]);
	}
}

void destroySTACK(STACK*const p)
{
	free(p->elems);
}

