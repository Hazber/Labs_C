#ifndef h_structures
#define h_structures
/*typedef struct list
{
	int data;
	char stroka[20];
	struct list* next;
} ITEM;*/



struct list
{
	char field[20]; // поле данных
	struct list* ptr; // указатель на следующий элемент
}

struct list* addelem(list* lst, int number);
struct list* init(int a);
void listprint(struct list* lst,FILE* zaebalo);
struct list* swap(struct list* lst1, struct list* lst2, struct list* head)


int GetFileSize(FILE* file);

void orgasm(* head, FILE* fuckingFile);

#endif
