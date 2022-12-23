#include<stdio.h>
#include<stdlib.h>
#include"prototype.h"
#include"buyer_prototype.h"



void design()
{
	for(int i = 0 ; i <30 ; i++)
		printf("*");
	
	printf("\n");
}

/************************************************************
*FUNCTION NAME         :    main
*DESCRIPTION           :    This function used here is the menu drawn function for admin,seller,buyer
*RETURN                :    No return
**************************************************************/

int main()
{

	seller_Details *seller_root = NULL;
	buyer_Details *buyer_root = NULL;
	product_details *product_root = NULL;
	
	int ch;
	system("clear");
	design() ;
	printf("Welcome To Auction System\n");
	design() ;
	
	while(1)
	{
		design() ;
		printf("1) Admin\n");
		printf("2) Buyer\n");
		printf("3) Seller\n");
		printf("4) Exit\n");
		design() ;
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
				admin();
				break;
			case 2: 
				buyer_root = buyer(buyer_root,seller_root);
				break ;
			case 3: 
				seller_root = seller(seller_root , product_root);
				printf("product add is %p\n",product_root);
				break ;
			case 4:
				exit(0); 
				break ;
		}
		
	
	}
		
}
