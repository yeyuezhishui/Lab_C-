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
	int  size() const;		//����ջ�����Ԫ�ظ���max
	int  howMany() const;	//����ջ��ʵ��Ԫ�ظ���pos
	int  getelem(int x) const;	//ȡ�±�x����ջԪ��
	STACK& push(int e); 	//��e��ջ,������ջ
	STACK& pop(int &e); 	//��ջ��e,������ջ
	STACK& assign(const STACK&s); //��s��ջ,�����ر���ֵ��ջ
	void print() const;		//��ӡջ
	~STACK();				//����ջ
};

//��ʼ��ջ
STACK::STACK(int m) :max(m), elems(new int[m]) {
	pos = 0;
}

//��ջs��ʼ��pָ���ջ

STACK::STACK(const STACK &s) : max(s.max), elems(new int[s.max]) {
	pos = s.pos;
	assign(s);
}

//����ջ�����Ԫ�ظ���max
int  STACK::size() const {
	return max;
}

//����ջ��ʵ��Ԫ�ظ���pos
int  STACK::howMany() const
{
	return pos;
}

//ȡ�±�x����ջԪ��
int  STACK::getelem(int x) const
{
	if (x > pos)
	{
		printf("����������±꣡\n");
		fputs("E ", fp);
		return 0;
	}
	return elems[x];
}

//��e��ջ,������ջ
STACK& STACK::push(int e)
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

STACK& STACK::pop(int &e)
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


STACK& STACK::assign(const STACK&s)
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
		printf("ջ��!\n");
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
	if ((fp = fopen("U201611143_2.txt", "w")) == 0) {
		printf("Cannot open file strike any key exit!");
		getchar();
	}

	if (argc == 1)
	{
		class STACK *pStack = (class STACK *)malloc(sizeof(class STACK));
		class STACK *sStack = new STACK(6);
		sStack->push(4);
		sStack->push(7);
		sStack->push(6);
		sStack->push(1);
		sStack->push(3);
		sStack->push(4);

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
					temp = pStack->howMany();
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
					if (temp <= pStack->howMany())
					{
						temp = pStack->getelem(temp);
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
					pStack->push(e);
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
					pStack->pop(e);
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
					pStack->assign(*sStack);
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
					int stackNum = pStack->howMany();
					int stackMax = pStack->size();

					if (stackNum == stackMax)
					{
						printf("E  ");
						fputs("E  ", fp);
						getchar();
						getchar();
						exit(1);
					}

					pStack->push(tempInt);     //��ջ

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
						if (tempInt > pStack->howMany())
						{
							printf("E  ");
							fputs("E  ", fp);
							break;
						}
						int j;
						for (j = 0; j < tempInt; j++)
						{
							pStack->pop(e);
						}

						if (pStack->howMany()) pStack->print();
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
						sStack->assign(*pStack);
						if (ifLast == 0)
						{
							if (sStack->howMany()) sStack->print();
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
					if (sStack->howMany()) sStack->print();

				}


				if (!strcmp(argv[i], "-N"))
				{
					fputs("N  ", fp);
					printf("N  ");
					//�����һλ�Ǵ���0С��9������
					int N = pStack->howMany();//�½�ջ
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
					printf("G  ");
					//�����һλ�Ǵ���0С��9������
					tempInt = atoi(argv[i + 1]);
					if (tempInt >= pStack->howMany())
					{
						fputs("E  ", fp);
						printf("E  ");
						break;
					}
					else
					{
						int N = pStack->getelem(tempInt);//�½�ջ
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

