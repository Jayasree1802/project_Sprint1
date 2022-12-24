
#include<stdio.h>
#define BUFFER_SIZE 1000

typedef struct seller_Details
{
        int id;
        char name[30];
        char emailId[50];
        long int phoneNo;
        char panNo[10];
        int product_id;
        char product_name[20];
        char product_details[30];
        char category[20];
        char password[20];
        int base_price;
        int sold_price ;
        int product_status ;
        int choice;
        int code;
        int buyer_id_request[10];
        int buyer_request_amount[10];
        char buyer_name[30];
        int count;
        int buyer_id_sell ;

	
	struct product_details *link;
        struct seller_Details *next;
}seller_Details;

typedef struct product_details
{
	int product_id ;
	char product_name[20];
	char product_details[30];
	int product_price;
	int end_date[3];
	int seller_id ;
	
	struct product_details *next;
}product_details;


void admin();

//functions of seller menu

seller_Details *  price_check(int ,int ,seller_Details *);                       
seller_Details *create_lisr_of_seller(seller_Details *,seller_Details);           //function to create list of seller
seller_Details *file_to_list(seller_Details *);                                
seller_Details seller_extraction_from_file(char * , seller_Details );
void design() ;

seller_Details *seller(seller_Details * , product_details *);                    

seller_Details *login_seller(seller_Details *,char * , char *);                 //function to login the seller

void check_the_buyer_request(seller_Details *);

seller_Details * login(seller_Details *);
int new_registration_to_file();

//functions of product menu

product_details *product_registration(product_details *);                        //functions to register the products

product_details data_extraction_from_buffer(char * , product_details);           

product_details *create_list_for_product(product_details * , product_details);    //creating the list for products  

product_details *delete_product(product_details * ,int);

product_details * modify_product_details(product_details * ,int,seller_Details *);   //function to modify details of products
void display_product(product_details *);                                             //function to display products

void adding_produt_into_file();                                                      //function to adding products into file





