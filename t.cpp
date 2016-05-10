/*
    С���Ա��
        �׳�� P21514131
        ������
        ������
        ����
        ����
        ��Ȫ��
        
    ������ܣ�
        ��ͨѶ¼��ʾ�����ҡ���ӡ��޸ġ�ɾ���������ܵ�ͨѶ¼�������
        ��������Ҫ���д����
            ��1��ͨѶ¼����Ϊ30�� 
            ��2��ͨѶ¼��Ϣ�����������绰�����䡢QQ�š�
            ��3������ʾ������Ϣ��
            ��4�������Ӽ�¼���������Ϣ��¼�롣
            ��5���ɸ����������绰�����Ҽ�¼������������޸ġ�
            ��6���ɸ����������绰�����Ҽ�¼�����ж��������������ļ�¼��
            ��7�������ܣ����Ը���������������
            
        ��������������¹��ܣ�
            ��1�����湦�ܣ������ݴ洢��save.sav�ļ���
            ��2������ԽϵͰ汾C��׼�����µĳɹ�����
            
        ����ʹ���������ַ��������е������루���ļ�����UTF-8���룩����ҪGBK����֧��
        �����������»����ɹ����벢���У�
            Microsoft Visual Studio 2015 + Windows 10
            Sublime Text 3 + MinGW + Window 10
        
        ��������ڲο��������鳭Ϯ��
        ���ϴ�GitHub��֤����Ȩ���У�
      https://github.com/OhYee/ACM.github.io/blob/master/C%E4%BD%9C%E4%B8%9A/Contacts.c
        2016/5/10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==============
�궨�岿��
==============*/
//���ݽϵͰ汾C��׼
#define bool int
#define true 1
#define false 0

//����ϵ��
#define MAXSIZE 30
#define SIZE_NAME 20
#define SIZE_PHONE 15
#define SIZE_EMAIL 30

#define LINE (printf("###########################\n"))

//���ݵͰ汾C��׼����ѭ�����
#define REP(n) for(o=0;o<n;o++)

//�Ƚϴ�С
#define max(a,b) ((a)>(b)?(a):(b))

/*==============
�ṹ�嶨��
==============*/
typedef struct{
  char name[SIZE_NAME];
  char phone[SIZE_PHONE];
  char email[SIZE_EMAIL];
  int QQ;
  void print() {
    printf("����:%s\n",name);
    printf("    �ֻ�����:%s\n",phone);
    printf("    �����ʼ�:%s\n",email);
    printf("    QQ:%d\n",QQ);
  }
  void insert(char a[SIZE_NAME],char b[SIZE_PHONE],char c[SIZE_EMAIL],int d) {
    strcpy(name,a);
    strcpy(phone,b);
    strcpy(email,c);
    QQ = d;
  }
}People;

/*==============
ȫ�ֱ������岿��
==============*/
People p[MAXSIZE];
int num = 0;
int o,i;//ѭ���ã����ݵͰ汾C��׼

/*==============
������������
==============*/
void Do();
void head();
bool menu();
void Read();
void Save();

void Show();
void Search();
void Insert();
void Change();
void Delete();
void Sort();

bool Compare(char a[SIZE_NAME],char b[SIZE_NAME]);
void Swap(People &a,People &b);
int Find(char id[],int type);

/*==============
�������岿��
==============*/

//����_ͷ������
inline void head() {
  system("cls");
  LINE;
  printf("=========ͨѶ¼========\n");
  LINE;
}

//���˵�
bool menu() {
  head();

  printf("1.��ʾͨѶ¼��������\n");
  printf("2.������ϵ��\n");
  printf("3.������ϵ��\n");
  printf("4.�޸���ϵ��\n");
  printf("5.ɾ����ϵ��\n");
  printf("6.ͨѶ¼����\n");
  printf("7.�˳�\n");
  LINE;

  int com = 0;
  while(!(com >= 1 && com <= 7)) {
    printf("�������Ĳ���(1~7):");
    scanf("%d",&com);
  }
  switch(com) {
    case 1:Show();break;
    case 2:Search();break;
    case 3:Insert();break;
    case 4:Change();break;
    case 5:Delete();break;
    case 6:Sort();break;
    case 7:return false;
  }
  system("pause");
  return true;
}

void Show() {
  head();
  REP(num)
    p[o].print();
}
void Search() {
  head();
  int com = 0;
  while(!(com >= 1 && com <= 2)) {
    printf("ʹ������Ϊ����ֵ����(1.���� 2.�ֻ� -1.����������):");
    scanf("%d",&com);
    if(com == -1)
      return;
  }
  char f[max(SIZE_NAME,SIZE_PHONE)];
  printf("����Ҫ���ҵ�ֵ:");
  scanf("%s",f);
  int it = Find(f,com);
  if(it == -1) {
    printf("δ�ҵ�������\n");
  } else {
    printf("�ҵ����ݣ�����ֵΪ:%d\n",o);
    p[o].print();
  }
}
void Insert() {
  head();
  if(num == MAXSIZE) {
    printf("�ڴ�����\n");
  } else {
    char name[SIZE_NAME];
    char phone[SIZE_PHONE];
    char email[SIZE_EMAIL];
    int QQ;
    printf("�������ݣ�\n");
    printf("����������");
    scanf("%s",name);
    printf("�����ֻ��ţ�");
    scanf("%s",phone);
    printf("�����ʼ���");
    scanf("%s",email);
    printf("����QQ��");
    scanf("%d",&QQ);
    p[num++].insert(name,phone,email,QQ);
    printf("�޸����\n");
  }
}
void Change() {
  head();
  printf("�ı��������ݣ�\n");
  int index = -2;
  while(!(index >= 0 && index < num)) {
    printf("����������ֵ(��ͨ�����ҹ��ܻ�ȡ����ֵ������-1����������):\n");
    scanf("%d",&index);
    if(index == -1)
      return;
  }
  printf("����������");
  scanf("%s",p[index].name);
  printf("�����ֻ��ţ�");
  scanf("%s",p[index].phone);
  printf("�����ʼ���");
  scanf("%s",p[index].email);
  printf("����QQ��");
  scanf("%d",&p[index].QQ);
  printf("�޸����\n");
}
void Delete() {
  head();
  printf("ɾ���������ݣ�\n");
  int index = -2;
  while(!(index >= 0 && index < num)) {
    printf("����������ֵ(��ͨ�����ҹ��ܻ�ȡ����ֵ������-1����������):\n");
    scanf("%d",&index);
    if(index == -1)
      return;
  }
  for(i = index;i < num;i++)
    memcpy(&p[i],&p[i + 1],sizeof(p[i + 1]));
  num--;
  printf("ɾ�����\n");
}
void Sort() {
  //ʹ��ð�������������
  int j,k;
  bool flag;

  k = num;
  flag = true;
  while(flag) {
    flag = false;
    for(j = 1; j < k; j++)
      if(Compare(p[j - 1].name,p[j].name)) {
        Swap(p[j - 1],p[j]);
        flag = true;
      }
    k--;
  }
  printf("�������\n");
}

//���ļ���ȡ����
void Read() {
  FILE * f;
  f = fopen("save.sav","r");
  if(f) {
    char name[SIZE_NAME];
    char phone[SIZE_PHONE];
    char email[SIZE_EMAIL];
    int QQ;
    while(fscanf(f,"%s%s%s%d",name,phone,email,&QQ) != EOF)
      p[num++].insert(name,phone,email,QQ);
    fclose(f);
  }
}
//д�����ݵ��ļ�
void Save() {
  FILE * f;
  f = fopen("save.sav","w");
  REP(num)
    fprintf(f,"%s %s %s %d\n",p[o].name,p[o].phone,p[o].email,p[o].QQ);
  fclose(f);
}

//�Ƚ������ַ����Ĵ�С�������ֵ���Ƚϣ���a>b����true
bool Compare(char a[SIZE_NAME],char b[SIZE_NAME]) {
  int it1 = strlen(a) - 1;
  int it2 = strlen(b) - 1;
  while(1) {
    if(a[it1] != b[it2]) {
      if(a[it1] > b[it2])
        return true;
      else
        return false;
    }
    it1--;it2--;
    if(it1 == -1 || it2 == -1)
      return it1 < it2;
  }
}

//����
void Swap(People &a,People &b) {
  People temp;
  memcpy(&temp,&a,sizeof(a));
  memcpy(&a,&b,sizeof(b));
  memcpy(&b,&temp,sizeof(temp));
}

//����ָ������ֵ�ļ�¼��type 1 ������������ 2 �����ֻ����� ���������±�
int Find(char id[],int type) {
  int it = -1;
  if(type == 1)
    REP(num)
    if(strcmp(id,p[o].name) == 0) {
      it = o;
      break;
    } else
      REP(num)
      if(strcmp(id,p[o].phone) == 0) {
        it = o;
        break;
      }
    return it;
}

//ѭ������
void Do() {
  Read();
  while(menu());
  Save();
}

//�������
int main() {
  Do();
  return 0;
}