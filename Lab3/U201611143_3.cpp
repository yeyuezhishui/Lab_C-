#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

FILE *fp;

class STACK {
	int  *const  elems;	//�����ڴ����ڴ��ջ��Ԫ��
	const  int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
	int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
	STACK(int m);		//��ʼ��ջ�����m��Ԫ��
	STACK(const STACK&s); //��ջs������ʼ��ջ
	virtual int  size() const;		//����ջ�����Ԫ�ظ���max
	virtual  operator int () const	//����ջ��ʵ��Ԫ�ظ���pos
	{
		return pos;
	}
	virtual int operator[] (int x) const;	//ȡ�±�x����ջԪ��
	virtual STACK& operator<<(int e); 	//��e��ջ,������ջ
	virtual STACK& operator>>(int &e); 	//��ջ��e,������ջ
	virtual STACK& operator=(const STACK&s); //��s��ջ,�����ر���ֵ��ջ
	virtual void print() const;		//��ӡջ
	virtual ~STACK();				//����ջ
};

//��ʼ��ջ
STACK::STACK(int m) :max(m), elems(new int[m]) {
	pos = 0;
}

//��ջs��ʼ��pָ���ջ

STACK::STACK(const STACK &s) : max(s.max), elems(new int[s.max]) {
	pos = s.pos;
	*this = s;
}

//����ջ�����Ԫ�ظ���max
int  STACK::size() const {
	return max;
}


//ȡ�±�x����ջԪ��
int  STACK::operator[](int x) const
{
	if (x > pos)
	{
		//printf("����������±꣡\n");
		fputs("E ", fp);
		return 0;
	}
	return elems[x];
}


//��e��ջ,������ջ
STACK& STACK::operator<<(int e)
{
	if (pos == max)
	{
		printf("��ջ�������޷�������Ԫ��");
		return *this;
	}
	elems[pos] = e;
	pos++;
	return *this;
}

STACK& STACK::operator>> (int &e)
{
	if (pos != 0)
	{
		e = elems[pos];
		pos--;
	}
	else
	{
		printf("E  ");
		fputs("E ", fp);
	}
	return *this;
}


STACK& STACK::operator=(const STACK&s)
{
	int i;
	for (i = 0; i<s.pos && i<this->max; i++)
	{
		elems[i] = s.elems[i];
	}
	pos = i;
	return *this;

}


void STACK::print() const
{
	int i;
	if (pos == 0)
	{
		//printf("ջ��!\n");
		fputs("E ", fp);
		return;
	}
	for (i = 0; i < pos; i++)
	{
		printf("%d  ", elems[i]);
		fprintf(fp, "%d  ", elems[i]);
	}

}

STACK::~STACK()
{
	delete elems;
}


int main(int argc, char * argv[])
{
	if ((fp = fopen("U201611143_3.txt", "w")) == 0) {
		printf("Cannot open file strike any key exit!");
		getchar();
	}

	if (argc == 1)
	{
		class STACK *pStack = (class STACK *)malloc(sizeof(class STACK));
		class STACK *sStack = new STACK(6);
		*sStack << 4;
		*sStack << 7;
		*sStack << 6;
		*sStack << 1;
		*sStack << 3;
		*sStack << 4;

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
					pStack = new STACK(maxNum);
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
					pStack = new STACK(*sStack);
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
					temp = pStack->size();
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
					temp = *pStack;
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
					if (temp <= *pStack)
					{
						STACK aStack = *pStack;
						temp = aStack[temp];
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
					*pStack << e;
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
					*pStack>>e;
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
					*pStack = *sStack;
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
					pStack->print();
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

		class STACK *pStack = (class STACK *)malloc(sizeof(class STACK));
		class STACK *sStack = (class STACK *)malloc(sizeof(class STACK));
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
					pStack = new STACK(tempInt);           //�½�ջ
					fprintf(fp, "%d  ", tempInt);
					printf("%d  ", tempInt);
					ifInit = 1;                            //ջ�½����޸�Ϊ1
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
					int stackNum = *pStack;
					int stackMax = pStack->size();

					if (stackNum == stackMax)
					{
						printf("E  ");
						fputs("E  ", fp);
						getchar();
						getchar();
						exit(1);
					}

					*pStack<<tempInt;     //��ջ

				}
				pStack->print();
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
						if (tempInt > *pStack)
						{
							printf("E  ");
							fputs("E  ", fp);
							return 0;
						}
						int j;
						
						for (j = 0; j < tempInt; j++)
						{
							*pStack >> e;
						}

						if (*pStack) pStack->print();
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

					fputs("A  ", fp);
					printf("A  ");
					//�����һλ�Ǵ���0С��9������
					if (argv[i + 1][0] >= '0' && argv[i + 1][0] <= '9')
					{

						tempInt = atoi(argv[++i]);             //���ַ���ת��������
						sStack = new STACK(tempInt);            //�½�ջ
						*sStack = *pStack;
						if (ifLast == 0)
						{
							if (sStack) sStack->print();
						}
						else
						{
							pStack->print();
						}
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
					sStack = new STACK(*pStack);
					if (sStack) sStack->print();

				}


				if (!strcmp(argv[i], "-N"))
				{
					fputs("N  ", fp);
					printf("N  ");
					//�����һλ�Ǵ���0С��9������
					int N = *pStack;//�½�ջ
					fprintf(fp, "%d  ", N);
					printf("%d  ", N);
					fclose(fp);
					return 0;

				}


				if (!strcmp(argv[i], "-G"))
				{
					fputs("G  ", fp);
					printf("G  ");
					//�����һλ�Ǵ���0С��9������
					tempInt = atoi(argv[i + 1]);
					if (tempInt >= *pStack)
					{
						fputs("E  ", fp);
						printf("E  ");
						break;
					}
					else
					{
						STACK aStack = *pStack;
						int N = aStack[tempInt];
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

