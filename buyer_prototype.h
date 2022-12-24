#include<stdio.h>

//Structure for Buyer Details

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

//functions for buyer login

buyer_Details *buyer(buyer_Details * , seller_Details *);                         
buyer_Details *registration_buyer(buyer_Details *);                       // function for registration of buyer
buyer_Details *buyer_login(buyer_Details *,char * , char *);              //function for buyer login
seller_Details *price_check(int ,int ,seller_Details *);                 //check the price for the seller
void writing_buyer_info_to_file();                                       // Buyer information in file

buyer_Details data_extraction_from_buyer_file(char * ,buyer_Details);     //Extracting data from buyer file
buyer_Details *create_list_buyer(buyer_Details * , buyer_Details);        //create a linked list to the  buyer
void display(seller_Details *);

void auction_for_product(product_details * , seller_Details * , buyer_Details *);    // auction function to make bidding

product_details *get_the_product_detail(seller_Details * ,int);                     // display the product details
