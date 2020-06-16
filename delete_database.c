#include"common.h"
void delete_database(hash_table_t *t)
{
	node_t *temp,*temp2;
    Slink *temp1,*pre_temp;
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(t->table[i] != NULL)
        {
            temp=t->table[i];
			t->table[i]=NULL;
            while(temp)
            {
                //declare pointer for traversing through file table
                temp1=temp->file_table;
                while(temp1)
                {
					pre_temp=temp1;

                    temp1=temp1->link;
					free(pre_temp);
                }
				temp2=temp;

                temp=temp->link;
				free(temp2);
            }
        }
    }
	printf("database is deleted\n");
}




