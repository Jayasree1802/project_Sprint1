#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototype.h"
#include"buyer_prototype.h"

/****************************************************
*FUNCTION NAME            :     save_to_file
*DISCRIPTION              :     This function used here to save the buyer details into the file 
*RETURN                   :     No return 
***************************************************/
void save_to_file(buyer_Details *source)
{
	FILE *fptr = NULL ;
	char *buyer_file = "buyer_Details.txt" ;
	buyer_Details *p = source ;
	
	fptr = fopen(buyer_file,"w");
	if(fptr == NULL)
	{	
		printf("file open error\n");
	}
	else
	{
		while(p!=NULL)
		{
			for(int i = 0 ; i < p->count ; i++)
				fprintf(fptr,"%d,%s,%s,%ld,%s,%s,%d,%d\n",p->id,p->name,p->emailId ,p->phoneNo , p->panNo,p->password ,p->product_id[i] ,p->price[i] );
			
			p = p->next;
		}
	}
	
	fclose(fptr);
}
/****************************************************
FUNCTION NAME         :   display_buyer
DESCRPTION            :   This function used here to display the seller details 
RETURN                :   No return 
***************************************************/
void display_buyer(buyer_Details *source)
{
	buyer_Details *p = source  ;
	
	while(p!=NULL)
	{
		printf("%d,%s,%s,%ld,%s,%s\n",p->id,p->name,p->emailId ,p->phoneNo , p->panNo,p->password );
		p = p->next;
	}
}
/*******************************************
FUNCTION NAME             :      display_product
DISCRIPTION               :      This function used here to display the details of buyer
RETURN                    :       No return
*******************************************/
void display_productlis(seller_Details *seller_root)
{
	seller_Details *p = seller_root ;
	
	while(p!= NULL)
	{
		if(p->link != NULL)
			printf("seller-id:%d,product-id:%d,product-name:%s,product-product_details :%s,End-date:%d,%d-%d-%d\n",p->link->seller_id,p->link->product_id,p->link->product_name,p->link->product_details ,p->link->product_price,p->link->end_date[0],p->link->end_date[1],p->link->end_date[2]);
			
			p = p->next;
	}
	
}
/****************************************************
FUNCTION NAME       :     buyer
DISCRIPTION         :     This function is used here to show the  menu for the registration and login
RETURN              :     source
******************************************************/

buyer_Details *buyer(buyer_Details *source , seller_Details *seller_root)
{
	int ch , exit_flag = 0 , prod_id = 0 , num = 0; 
	char buyer_name[30] , buyer_pswd[30] ,choice;
	buyer_Details *buyer_id = NULL ;
	seller_Details *sller_id  = NULL ;
	product_details *prod_details = NULL ; 
	design() ;
	printf("well come to buyer\n");
	design() ;
	while(1)
	{
		design() ;
		printf("1) Registration\n");
		printf("2) Login\n");
		printf("3) Disply \n");
		printf("4) exit\n");
		design() ;
		source = registration_buyer(source);
		scanf("%d",&ch);
		
		switch(ch)
		
			case 1: 
				writing_buyer_info_to_file();
				source = registration_buyer(source);
				break ;
				
			case 2: 
				printf("enter the name \n");
				getchar();
				fgets(buyer_name, 30 , stdin);
				buyer_name[strlen(buyer_name)-1] = '\0';
				printf("enter the password \n");
				scanf("%s",buyer_pswd);
				if((buyer_id = buyer_login(source,buyer_name,buyer_pswd)) != NULL)
				{
					printf("%s is loged in succsfully\n",buyer_id->name);
					printf("List of products are shown in below\n");
					design() ;
					
					display_productlis(seller_root);
					
					printf("enter y to buy a product\n");
					scanf(" %c",&choice);
					
					if(choice == 'y' || choice == 'Y')
					{
						printf("plese select the product-id\n");
						scanf("%d",&prod_id);
						prod_details = get_the_product_detail(seller_root ,prod_id);

						auction_for_product(prod_details ,seller_root , buyer_id );
					}
					
					
				}
				else
				{
				 	printf("%s buyer is not found\n",buyer_name);
				}
				break ;
			case 3:
				display_buyer(source);
				break;
			case 4: 
				exit_flag = 1;
				break;
		}
		
		if(exit_flag == 1)
			break;
	}
return source ;
}
/*********************************************
FUNCTION                 :      registration_buyer
DESCRIPTION              :      This function used here  for the registration
RETURN                   :       source
**********************************************/
buyer_Details *registration_buyer(buyer_Details *source)
{
	
	char *str = "buyer_info.txt" ;
	char buffer[BUFFER_SIZE]; 
	FILE *fptr = NULL ;
	buyer_Details buyer_data;
	
	fptr = fopen(str,"r");
	
	if(fptr == NULL)
	{
		printf("file opening is failed\n");
		return NULL;
	}
	else 
	{
		while(!feof(fptr))
		{
		
			if(!(fgets(buffer,BUFFER_SIZE,fptr)))
			{
				//printf("string reading is fail\n");
				break ;
			}
			else 
			{
					buyer_data = data_extraction_from_buyer_file(buffer , buyer_data);
						source = create_list_buyer(source , buyer_data);				
			}
		}
	}
return source;
}

/***********************************************
FUNCTION NAME             :     buyer_login
DESCRIPTION               :     This function used here compare the user name and password of buyer 
RETURN                    :     buyer details
***********************************************/
buyer_Details *buyer_login(buyer_Details *source,char *user_name , char *pswd)
{
	buyer_Details *p = source ;
	
	if(source == NULL)
	{
		printf("buyer list is empty \n");
		return NULL;
	}
	int flag = 0 ;
	while(p != NULL)
	{
		if(strcmp(p->name ,user_name) == 0 )
		{
			if(strcmp(p->password , pswd )== 0)
			{
				flag = 1;
				return p ;
			}
			
		}
		
		p = p->next ; 
	}
	
	if(flag == 0)
	 return NULL ;
}

/********************************************************
FUNCTION NAME            :        writing_buyer_info_to_file
DISCRIPTION              :        This function used here to save the buyer details into the file 
RETURN                   :         No return
********************************************************/
void writing_buyer_info_to_file()
{
	char *str = "buyer_info.txt" ;
	
	FILE *fptr = NULL ;
	buyer_Details source ;
	
	fptr = fopen(str,"a");
	
	if(fptr == NULL)
	{
		printf("file opening is failed\n");
		return ;
	}
	else 
	{
		printf("enter the name\n");
		getchar();
		fgets(source.name , 10 , stdin);
		source.name[strlen(source.name)]= '\0';
		
		printf("enter the buyer-id\n");
		scanf("%d",&source.id);
		
		printf("enter the email-id\n");
		getchar();
		fgets(source.emailId , 20 , stdin);
		source.emailId[strlen(source.emailId)-1] = '\0';
		
		printf("enter the password\n");
		getchar();
		scanf("%s",source.password);
		printf("enter the phone number\n");
		scanf("%ld",&source.phoneNo);
		
		printf("enter the pan card number\n");
		getchar();
		fgets(source.panNo , 10 , stdin);
		source.panNo[strlen(source.panNo)-1] = '\0';	
		
		fprintf(fptr,"%d,%s,%ld,%s,%s,%s\n",source.id,source.name,source.phoneNo,source.panNo,source.emailId,source.password);
	}
	
	fclose(fptr);
}

/******************************************************************
FUNCTION NAME             :         data_extraction_from_buyer_file
DISCRIPRION               :         This function is used here to extraction of buyer details tofrom file 
RETURN                    :         DATA
******************************************************************/

buyer_Details data_extraction_from_buyer_file(char *str ,buyer_Details DATA)
{
	
	//printf("str :%s\n",str);
	
	int index = 0;
	char *piece = NULL;
		piece = strtok(str,",");
		while(piece !=NULL)
		{
			//printf("%s\n",piece);
			if(index == 0)
			{
				DATA.id = atoi(piece);
				index =1;
			}
			else if(index == 1)
			{
				strcpy(DATA.name ,piece);
				DATA.name[strlen(DATA.name)] = '\0';
				index =2;
			}
			else if(index == 2)
			{
				DATA.phoneNo = atoi(piece);
				index =3;
			}
			else if(index == 3)
			{
				strcpy(DATA.panNo ,piece);
				DATA.name[strlen(DATA.panNo)-1] = '\0';
				index = 4;
			}
			else if(index == 4)
			{
				strcpy(DATA.emailId ,piece);
				DATA.name[strlen(DATA.emailId)-1] = '\0';
				index = 5;
			}
			else if(index == 5)
			{
				strcpy(DATA.password ,piece);
				DATA.password[strlen(DATA.password)-1] = '\0';
				
			}	
			piece = strtok(NULL,",");
		}
		
	return DATA;
}


/******************************************************************
FUNCTION NAME             :         create_list_buyer
DISCRIPRION               :         This function is used here to create a linked list for buyer
RETURN                    :         DATA
******************************************************************/
buyer_Details *create_list_buyer(buyer_Details *source , buyer_Details DATA) 
{
	if(source == NULL)
	{
		source  = (buyer_Details *)malloc(sizeof(buyer_Details));
		source->id = DATA.id;
		strcpy(source->name ,DATA.name);
		source->phoneNo = DATA.phoneNo ;
		strcpy(source->panNo ,DATA.panNo);
		strcpy(source->emailId ,DATA.emailId);
		strcpy(source->password ,DATA.password );	
		source->next = NULL;
	}
	else 
	{
		buyer_Details *p = source ;	
		buyer_Details *temp = (buyer_Details *) malloc(sizeof(buyer_Details));
		
		 
		strcpy(temp->name ,DATA.name);
		temp->phoneNo = DATA.phoneNo ;
		strcpy(temp->panNo ,DATA.panNo);
		strcpy(temp->emailId ,DATA.emailId);
		strcpy(temp->password ,DATA.password );
		
		while(p->next != NULL)
		 {
		 	p = p->next ;
				 	
		 }
		  
		p->next = temp ;
		temp->next = NULL ;
	}

return source;
}

/******************************************************************
FUNCTION NAME             :         get_the_product_detail
DISCRIPRION               :         This function is used here to get the product details
RETURN                    :         product id with seller details
******************************************************************/

product_details *get_the_product_detail(seller_Details * p ,int prod_id)
{
	
		if(p==NULL)
		{
			printf("product list is empty\n");
			return NULL;
		}
		
		while(p!=NULL)
		{
			if(p->link != NULL)
			{
				if(p->link->product_id == prod_id)
				{
					printf("product id %d",p->link->product_id);
					return p->link;
				}
			}
			
			p = p->next;	
		}		
			
		
		return NULL;	
}
