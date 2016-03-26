#include "stdio.h"
#include "malloc.h"

#define Status int
#define TRUE 1
#define FALSE 0

//�ṹ�嶨��
struct LinkList {
	char elem;
	LinkList *next;
};

//��ʼ������
void InitList(LinkList *L) {
	L->next = NULL;
}

//��ǰ������
void PushFront(LinkList *L,char e) {
	LinkList *t = (LinkList*)malloc(sizeof(LinkList));
	t->elem = e;
	t->next = L->next;
	L->next = t;
}

//�ں󷽲���
void PushBack(LinkList *L,char e) {
	LinkList *t = (LinkList*)malloc(sizeof(LinkList));
	t->elem = e;
	t->next = NULL;
	LinkList *it = L;
	while(it->next != NULL)
		it = it->next;
	it->next = t;
}

//��ӡ
void Print(LinkList *L) {
	LinkList *it = L->next;
	while(it != NULL) {
		printf("%c\n",it->elem);
		it = it->next;
	}
}

//����Ԫ���Ƿ����
Status Find(LinkList *L,char e) {
	LinkList *it = L->next;
	while(it != NULL) {
		if(it->elem == e)
			return TRUE;
		it = it->next;
	}
	return FALSE;
}

//ɾ��Ԫ��
Status Delete(LinkList *L,int k) {
	LinkList *it = L->next;
	for(int i = 0;i < k - 1;i++) {
		if(it->next == NULL)
			return FALSE;
		it = it->next;
	}
	LinkList *t = it->next;
	it->next = t->next;
	free(t);
	return TRUE;
}

//�ݹ�ɾ������
void DFS_Destory(LinkList *L) {
	if(L == NULL)
		return;
	DFS_Destory(L->next);
	free(L);
}

//��ɾ��ͷ�ڵ�
void Destory(LinkList *L) {
	DFS_Destory(L->next);
}

//����������
int Length(LinkList *L) {
	LinkList *it = L->next;
	int len = 0;
	while(it != NULL) {
		len++;
		it = it->next;
	}
	return len;
}

int main() {
	printf("��������\n");
	LinkList L;
	//ͷ�ڵ��Ԫ�ز��ᱻ��ʾ
	L.elem = 'X';

	printf("��ʼ������\n");
	InitList(&L);

	printf("������Ϊ%d\n",Length(&L));

	printf("��ǰ������a\n");
	PushFront(&L,'a');
	printf("��ǰ������b\n");
	PushFront(&L,'b');
	printf("��ǰ������c\n");
	PushFront(&L,'c');

	printf("�����ӡ:\n");
	Print(&L);

	printf("����Ƿ����d\n");
	if(Find(&L,'d') == TRUE)
		printf("����\n");
	else
		printf("������\n");

	printf("�ں󷽲���d\n");
	PushBack(&L,'d');
	printf("�ں󷽲���e\n");
	PushBack(&L,'e');
	printf("�ں󷽲���f\n");
	PushBack(&L,'f');

	printf("�����ӡ:\n");
	Print(&L);

	printf("����Ƿ����d\n");
	if(Find(&L,'d') == TRUE)
		printf("����\n");
	else
		printf("������\n");

	printf("������Ϊ%d\n",Length(&L));

	printf("ɾ���±�Ϊ3��Ԫ��");
	Delete(&L,3);

	printf("�����ӡ:\n");
	Print(&L);


	printf("��������:\n");
	Destory(&L);

	return 0;
}
