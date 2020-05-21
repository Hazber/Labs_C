#include "stdio.h"
#include "string.h"



FILE* Fileone, * Filetwo, * Result;
char datastr[20];
struct list* flag;
struct list* root;
struct list* end;
void main()

{
	fopen(Fileone,"text_one", "r");
	fopen(Filetwo,"text_two","r");
	fopen(Result,"result", "w");
	fgets(datastr, 20, Fileone);
	root=end=struct list* init(datastr);

	while (!(feof(Fileone)))
	{
		fgets(datastr, 20, Fileone);
		do 		
		{
			flag = finditem(datastr, root);
			struct list* addelem(flag, datastr);

		} while (flag.ptr != NULL);


	}

	while (!(feof(Filetwo)))
	{
		fgets(datastr, 20, Filetwo);
		do
		{
			flag = finditem(datastr, root);
			struct list* addelem(flag, datastr);

		} while (flag.ptr != NULL);


	}

	void listprint(end, Result);


	
	fclose(Result);
	fclose(Filetwo);
	fclose(Fileone);
	getchar();

}