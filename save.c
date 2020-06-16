#include"common.h"

void save_database(hash_table_t t)
{
	node_t *temp;
	Slink *temp1;
	int i;
	FILE *fptr;
	fptr=fopen("file.txt","w");
	for(i=0;i<SIZE;i++)
	{
		if(t.table[i] != NULL)
		{
			fprintf(fptr,"\nindex : [%d]\n",i);
			temp=t.table[i];
			while(temp)
			{
				fprintf(fptr,"\nword : [%s]\n",temp->word);
				fprintf(fptr,"file count :%d\t",temp->file_count);
				//declare pointer for traversing through file table
				temp1=temp->file_table;
				while(temp1)
				{
					fprintf(fptr,"file name : [%s]\t",temp1->file_name);
					fprintf(fptr,"word count : %d\t",temp1->word_count);

					temp1=temp1->link;
				}

				temp=temp->link;
			}
			fprintf(fptr,"\n");
		}
	}
	fclose(fptr);
}


