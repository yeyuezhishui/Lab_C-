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
	virtual  operator int() const	//����ջ��ʵ��Ԫ�ظ���pos
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
		//printf("��ջ�������޷�������Ԫ��");
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
		e = elems[pos - 1];
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


class QUEUE: public STACK {
	STACK s2;
public:
	QUEUE(int m);		//��ʼ��ѭ�����У�elems��m��Ԫ��
	QUEUE(const QUEUE&s); 			//�ö���s������ʼ������
	virtual operator int() const {
		return s2 + STACK::operator int();
	}
	virtual int full() const;		       //���ض����Ƿ�������������1�����򷵻�0
	virtual int operator[ ](int x)const;   //ȡ�±�Ϊx��Ԫ��,��1��Ԫ���±�Ϊ0
	virtual QUEUE& operator<<(int e); 	//��e�����,�����ض���
	virtual QUEUE& operator>>(int &e);	//�����е�e,�����ض���
	virtual QUEUE& operator=(const QUEUE&s); //��s������,�����ر���ֵ�Ķ���
	virtual void print() const;			//��ӡ����
	virtual ~QUEUE();					//���ٶ���
};

//��ʼ������
QUEUE::QUEUE(int m) :STACK(m), s2(m) {
	return;
}

//�ö���s��ʼ��pָ��Ķ���
QUEUE::QUEUE(const QUEUE &s) : STACK(s.STACK::size()), s2(s.s2.size()) {
	*this = s;
}

//�ж϶����Ƿ���
int  QUEUE::full() const {
	if (s2 == s2.size() && STACK::operator int() == STACK::size())
	{
		return 1;
	}
	return 0;
}


//ȡ�±�x���Ķ���Ԫ��
int  QUEUE::operator[](int x) const
{
	if ((this->STACK::operator int() + s2 == 0) || (x > (s2.size() * 2 - 1)) ){
				printf("E  ");
				fputs("E  ",fp);
				exit(1);
	}
	
	if (s2 == 0)
	{
		return this->STACK::operator[](x);
	}
	else
	{
		if (x >= s2)
		{
			return this->STACK::operator[](x - s2);
		}
		else
		{
			return s2[s2 - 1 - x];
		}
	}
}


//��e���,�����ض���
QUEUE& QUEUE::operator<<(int e)
{
	int k;
	//����������ˣ���ô���ش���
	if (full())
	{
		printf("E  ");
		fputs("E  ",fp);
		return *this;
	}

	//�������2��Ϊ0���Ҷ���1������ô����
	if (s2 != 0 && STACK::operator int() == this->STACK::size())
	{
		printf("E  ");
		fputs("E  ",fp);
		getchar();
		getchar();
		exit(1);
	}

	//�������1û��������ô�������1
	if (STACK::operator int() <  this->STACK::size())
	{
		STACK::operator<<(e);
		return *this;
	}
	else
	{
		//�������1���ˣ�������1�����ݵ������2
		while (STACK::operator int() != 0)
		{
			STACK::operator>>(k);
			s2 << k;
		}
		STACK::operator<<(e);
	}

	return *this;
}

QUEUE& QUEUE::operator>> (int &e)
{
	if (STACK::operator int() != 0 || s2 != 0)
	{
		if (s2 != 0)
		{
			s2 >> e;
			return *this;
		}
		else
		{
			int k;
			while (STACK::operator int() != 0)
			{
				STACK::operator>>(k);
				s2 << k;
			}
			s2 >> e;
			return *this;
		}
	}
	else
	{
		printf("E  ");
		fputs("E ", fp);
	}
	return *this;
}


QUEUE& QUEUE::operator=(const QUEUE&s)
{
	if (s.s2 != 0)
	{
		s2 = s.s2;
	}

	if (this->STACK::operator int() != 0)
	{
		STACK::operator=(s);
	}

	return *this;
}


void QUEUE::print() const
{
	int i;
	if (!(STACK::operator int() != 0 || s2 != 0))
	{
		//printf("���п�!\n");
		fputs("E ", fp);
		printf("E  ");
	}

	if (s2 != 0)
	{
		for (i = s2 - 1; i >= 0; i--)
		{
			printf("%d  ", s2[i]);
			fprintf(fp, "%d  ", s2[i]);
		}
	}

	if (STACK::operator int() != 0)
	{
		for (i = 0; i < STACK::operator int(); i++)
		{
			printf("%d  ", STACK::operator[](i));
			fprintf(fp, "%d  ", STACK::operator[](i));
		}
	}

}

QUEUE::~QUEUE()
{

}

int isPrime(int num)
{
	int i;
	int flag = 1;
	for (i = 2; i<num/2;i++)
	{
		if (num%i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}


int main(int argc, char * argv[])
{
	int err;
	if ((fp = fopen("U201611143_4.txt", "w")) == 0) {
		printf("Cannot open file");
		getchar();
	}

	if (argc == 1)
	{
		using namespace std;
		int conti = 1;
		cout << "�Ƿ���������ԣ�(����1�ǣ�������������˵���" << endl;
		int  wuban;
		cin >> wuban;
		if (wuban == 1)
		{
			int M, F;
			int m, f;
			cout << "�������������е�����M,ȷ��M������:";
			cin >> M;
			while (!isPrime(M))
			{
				cout << "�����������������е�����M,ȷ��M������:";
				cin >> M;
			}

			cout << "������Ů�����е�����F��ȷ��F�������Ҳ�����M:";
			cin >> F;
			while (!isPrime(F) && F != M)
			{
				cout << "����������Ů�����е�����F,ȷ��F���������Ҳ�����M:";
				cin >> F;
			}

			cout << "���������ʿվ��λ��ȷ��m������M:";
			cin >> m;
			while (m > M)
			{
				cout << "�������������ʿվ��ȷ��m������M:";
				cin >> m;
			}

			cout << "�������Ůʿվ��λ��ȷ��f������F:";
			cin >> f;
			while (f > F)
			{
				cout << "�������������ʿվ��ȷ��f������F:";
				cin >> f;
			}

			class QUEUE *mQueue = new QUEUE(M);
			class QUEUE *fQueue = new QUEUE(F);

			int i;
			for (i = 1; i <= M; i++)
			{
				if (i != m) {
					*mQueue << 1;
				}
				else
				{
					*mQueue << 0;
				}
			}

			for (i = 1; i <= F; i++)
			{
				if (i != f) {
					*fQueue << 1;
				}
				else
				{
					*fQueue << 0;
				}
			}

			int mOut =1, fOut =1;
			int count = 0;
			while (mOut == 1 || fOut ==1) {
				*mQueue >> mOut;
				*mQueue << mOut;
				*fQueue >> fOut;
				*fQueue << fOut;
				count++;
			}
			delete mQueue;
			delete fQueue;

			cout << "�����m��ʿ�ڵڡ�" << count << "��֧��ʱ,���Ժ�fŮʿ���赸" << endl;
			getchar();
			cout << "�˳�����1";
			int out;
			cin >> out;
			if (out == 1)
			{
				return 0;
			}
		}
		else
		{

			class QUEUE *pQueue = (class QUEUE *)malloc(sizeof(class QUEUE));
			class QUEUE *sQueue = new QUEUE(6);
			*sQueue << 4;
			*sQueue << 7;
			*sQueue << 6;
			*sQueue << 1;
			*sQueue << 3;
			*sQueue << 4;

			int operate = 1;  //������� ��0-12֮��
			int isInitial = 0; //�ж϶����Ƿ����
			int maxNum;
			int e;
			int temp;
			//int input;
			while (operate) {
				system("cls");
				printf("\n\n");
				printf("--------------------Welcome------------------\n");
				printf("-------------------------------------------------\n");
				printf("1. ��ʼ������P        ||7. ��һ���������е�e\n");
				printf("2. �Ӷ���S��ʼ������P ||8. ��s��pָ��Ķ���\n");
				printf("3. ����Ԫ�ص������� ||9. ��ӡpָ��Ķ��� \n");
				printf("4. ������ʵ��Ԫ�ظ��� ||10. ����pָ��Ķ���\n");
				printf("5. ȡ�±�Ϊx�Ķ���Ԫ��||6.  ����һ����������� \n");
				printf("0. �˳�        \n");
				printf("-------------------------------------------------\n");
				printf("��ѡ����Ĳ���:");
				scanf("%d", &operate);
				switch (operate)
				{
				case 1:
					//InitQueue
					if (isInitial == 0)
					{
						printf("\n\t��������еĴ�С:");
						scanf("%d", &maxNum);
						pQueue = new QUEUE(maxNum);
						isInitial = 1;
						printf("\n\t�½����гɹ������еĴ�СΪ%d\n", maxNum);
					}
					else
					{
						printf("\n\t�����Ѿ�������\n");
					}

					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 2:
					//initSTACK��S-P
					if (isInitial)printf("\n\t����p�Ѿ���ʼ����");
					else
					{
						pQueue = new QUEUE(*sQueue);
						printf("\n\t�ɹ��Ӷ���s�½�����p");
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 3:
					//sizeNum
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						temp = pQueue->size() ;
						printf("\n\t�ö��е����������%d", temp);
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 4:
					//howMany
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						temp = *pQueue;
						printf("\n\t�ö�����Ŀǰ��%d��Ԫ��", temp);
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 5:
					//getelem
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						printf("\n\t��������Ҫ���ҵ������±�:\n");
						scanf("%d", &temp);
						if (temp <= *pQueue)
						{
							QUEUE aStack = *pQueue;
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
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						printf("\n\t����������Ҫ����е�Ԫ��:");
						scanf("%d", &e);
						*pQueue << e;
						printf("\n\t�ɹ�����У�\n");
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 7:
					//LocateElem
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						*pQueue >> e;
						printf("\n\t�����е�����Ϊ%d", e);
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 8:
					//PriorElem
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						*pQueue = *sQueue;
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 9:
					//NextElem
					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						printf("\n\t�ö��е�����Ϊ��\n");
						pQueue->print();
					}
					getchar();
					printf("\n\t\t�������������������\n");
					getchar();
					break;
				case 10:

					if (!isInitial)printf("\n\t����p�����ڣ�");
					else
					{
						printf("\n\t�ɹ����ٸö��У�\n");
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
		
	}
	else {

		class QUEUE *pQueue = (class QUEUE *)malloc(sizeof(class QUEUE));
		class QUEUE *sQueue = (class QUEUE *)malloc(sizeof(class QUEUE));
		int tempInt; // ��ʱʹ�õ�����

		int ifInit = 0;
		int ifNew = 0; //�ж��Ƿ���¶��в���

		int i;
		int e;
		int m;

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
					pQueue = new QUEUE(tempInt);           //�½�����
					m = tempInt;
					fprintf(fp, "%d  ", tempInt);
					printf("%d  ", tempInt);
					ifInit = 1;                            //�����½����޸�Ϊ1
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

					if (pQueue->full())
					{
						fputs("E  ", fp);
						printf("E  ");	
						getchar();
						getchar();
						exit(1);
					}

					*pQueue << tempInt;     //�����

				}
				pQueue->print();
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
						if (tempInt > *pQueue)
						{
							printf("E  ");
							fputs("E  ", fp);
							return 0;
						}
						int j;

						for (j = 0; j < tempInt; j++)
						{
							*pQueue >> e;
						}

						if (*pQueue) pQueue->print();
						i--;
					}
					else
					{

						printf("E  ");
						fputs("E ", fp);
						return 0;
					}
				}

				//��⵽һ���¶��еĽ���
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
						sQueue = new QUEUE(tempInt);            //�½�����
						*sQueue = *pQueue;
						if (ifLast == 0)
						{
							if (sQueue) sQueue->print();
						}
						else
						{
							pQueue->print();
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

					QUEUE *newQueue;
					newQueue = new QUEUE(*pQueue);
					if (newQueue) newQueue->print();
					delete newQueue;
				}


				if (!strcmp(argv[i], "-N"))
				{
					fputs("N  ", fp);
					printf("N  ");
					//�����һλ�Ǵ���0С��9������
					int N = *pQueue;//�½�����
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
					if (tempInt >= *pQueue)
					{
						fputs("E  ", fp);
						printf("E  ");
						break;
					}
					else
					{
						int N = (*pQueue)[tempInt];
						fprintf(fp, "%d  ", N);
						printf("%d  ", N);
					}

				}

			}

		}
		fclose(fp);
	}
	getchar();
	getchar();
	return 0;

}

