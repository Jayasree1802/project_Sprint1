#include<stdio.h>

typedef struct buyer_Details
{
        int id;
        char name[30];
        char emailId[50];
        long int phoneNo;
        char panNo[10];
        int product_id[10];
         char password[20];
        int price[10];
    	int count ;
    	 
        struct buyer_Details *next;
        
}buyer_Details;



buyer_Details *buyer(buyer_Details * , seller_Details *);
buyer_Details *registration_buyer(buyer_Details *);
buyer_Details *buyer_login(buyer_Details *,char * , char *);
seller_Details *price_check(int ,int ,seller_Details *);
void writing_buyer_info_to_file();

buyer_Details data_extraction_from_buyer_file(char * ,buyer_Details);
buyer_Details *create_list_buyer(buyer_Details * , buyer_Details);
void display(seller_Details *);

void auction_for_product(product_details * , seller_Details * , buyer_Details *);

product_details *get_the_product_detail(seller_Details * ,int);
