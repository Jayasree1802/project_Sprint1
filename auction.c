#include<stdio.h>
#include<string.h>
#include"prototype.h"
#include"buyer_prototype.h"

void auction_for_product(product_details *prod_root , seller_Details *seller_root , buyer_Details *buyer_root)
{
	seller_Details *sller_id = NULL;
	int product_amount ; 
	int check_flag = 0;
	char ch ;
	char *transcation = "biding_histry.txt";
	
	FILE *fptr = NULL ;
	
	fptr = fopen(transcation,"a+");
	if(fptr == NULL)
	{	
		printf("%s opening is failed\n",transcation);
		return ;
	}
	
	
	printf("enter the amount \n");
	scanf("%d",&prod_root->product_price);
	
	sller_id = price_check(prod_root->product_id, prod_root->product_price,seller_root );
	
	if((sller_id)!= NULL)
	{
		printf("price is %d\n",prod_root->product_price);
		
		sller_id->buyer_id_request[sller_id->count] = prod_root->product_id;
		
		sller_id->buyer_request_amount[sller_id->count++] = prod_root->product_price ;
		
		strcpy(sller_id->buyer_name , prod_root->product_name);
		
		fprintf(fptr,"%d,%d,%d,%d\n",buyer_root->id ,prod_root->product_id,sller_id->id,prod_root->product_price);
		fclose(fptr);
	}
	else 
	{	
		while(1)
		{
			printf("enter y to continue biding\n");
			printf("enter n to exit the biding\n");
			scanf(" %c",&ch);
			if(ch == 'y' ||ch == 'Y' )
			{
				printf("enter the amount \n");
				scanf("%d",&product_amount);
				sller_id = price_check(prod_root->product_id, prod_root->product_price,seller_root );
				
				if((sller_id)!= NULL)
				{
					sller_id->buyer_id_request[sller_id->count] = prod_root->product_id;
		
					sller_id->buyer_request_amount[sller_id->count++] = prod_root->product_price ;
	
					break;
				}
				else
				{
					sller_id->buyer_id_request[sller_id->count] = prod_root->product_id;
		
					sller_id->buyer_request_amount[sller_id->count++] = prod_root->product_price ;
				}
				
				if(check_flag == 0)
				{
					fprintf(fptr,"%d,%d,%d,%d,",buyer_root->id ,prod_root->product_id,sller_id->id,prod_root->product_price);	
					check_flag = 1;
				}
				else 
					fprintf(fptr,"%d,",prod_root->product_price);
					
			}
			else
			{
				fprintf(fptr,"%c",'\n');
				fclose(fptr);
				break;
			}
		}
	}
	
										
	
}


seller_Details * price_check(int  product_id ,int price ,seller_Details *seller_root)
{
	seller_Details *p = seller_root ;
	
	
	//printf("product id %d\n",product_id);
	
	while(p!=NULL)
	{
		//printf("product is %d and user id %d\n",p->link->product_id ,product_id);
		if(p->link !=NULL)
		{
			if(p->link->product_id == product_id)
			{
				//printf("if :::p-id %d and price :%d\n",p->product_id ,p->base_price );
				if(p->link->product_price <= price )
				{
					return p;
				}
				else
					return NULL;
			}
		}	
		//printf("p-id %d and price :%d\n",p->product_id ,p->base_price );
		
		p = p->next ;
	}
	
	return NULL;
}

