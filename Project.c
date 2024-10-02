#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[100];
int num_items = 0;
int next_item_id = 1;

void add_item() {
	FILE *fp=fopen("file1.txt","a");
	int i,a;
	float value;
    struct Item item;
    item.id = next_item_id++;
    printf("Enter item name: ");
    scanf(" %[^\n]s",item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    if(item.quantity>0)
    {
    	printf("Enter item price for each: ");
       scanf("%f", &item.price);
       if(item.price>0)
       {
       inventory[num_items++] = item;
        printf("Item added successfully.\n");
        a=(float)item.quantity;
         value=a*item.price;
        fprintf(fp,"%s\t\t\t%d\t\t%.3f\t\t%.3f\n", item.name, item.quantity, item.price,value);

       }
       else
       {
		printf("Invalid Price");
	   }
	}
	else
	{
		printf("Invalid Quantity");
	}
    
}

void edit_item() {
    int id, i,found=0;
    printf("Enter item id: ");
    scanf("%d", &id);

    for (i = 0; i < num_items; i++) {
        if (inventory[i].id == id)
		{
            printf("Enter new item name: ");
            scanf(" %[^\n]s", inventory[i].name);
            printf("Enter new item quantity: ");
            scanf("%d", &inventory[i].quantity);
            if(inventory[i].quantity>0)
           {
            	printf("Enter new item price: ");
                scanf("%f", &inventory[i].price);
              if(inventory[i].price>0)
               {
                  printf("Item edited successfully.\n");
                  found=1;
                }
               else
               {
		          printf("Invalid Price");
	           }
	       }
           else
	        {
	        	printf("Invalid Quantity");
	        }
        }
   }
   if (!found)
        {
           printf("Item not found.\n");	
		}
    
    
}

void delete_item() {
    int id, i, j;
    printf("Enter item id: ");
    scanf("%d", &id);
    for (i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            for (j = i + 1; j < num_items; j++) {
                inventory[j - 1] = inventory[j];
            }
            num_items--;
            printf("Item deleted successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void view_inventory() {
    int i;
    printf("Inventory:\n");
    printf("ID\t\tName\t\t\tQuantity\t\tPrice\n");
    for (i = 0; i < num_items; i++) {
        printf("%d\t\t%s\t\t\t%d\t\t%.3f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_item() {
    char name[50];
    int i, found = 0;
    printf("Enter item name to search: ");
    scanf(" %[^\n]s", name);
    printf("Search Results:\n");
    printf("ID\t\tName\t\t\tQuantity\t\tPrice\n");
    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%d\t\t%s\t\t\t%d\t\t%.3f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No items found.\n");
    }
}

void view_report() {
    int i;
    float a,value,total_value = 0;
    printf("Inventory Report:\n");
    printf("ID\t\tName\t\t\tQuantity\t\tPrice\t\t\tValue\n");
    for (i = 0; i < num_items; i++) {
    	 a=(float)inventory[i].quantity;
         value=a*inventory[i].price;
         printf("%d\t\t%s\t\t\t%d\t\t%.3f\t\t\t%.3f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price, value);
         total_value += value;
    }
    printf("------------------------------------\n");
    printf("TotalValue: %.3f\n", total_value);
}

int main() {
FILE *fp=fopen("file1.txt","a");

int choice;
if(fp)
	{
     do {
     printf("Inventory Management System\n");
     printf("1. Add item\n");
    printf("2. Edit item\n");
    printf("3. Delete item\n");
    printf("4. View inventory\n");
    printf("5. Search item\n");
    printf("6. View report\n");
    printf("0. Save and Exit\n");
    printf("Enter your choice(0-6): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            edit_item();
            break;
        case 3:
            delete_item();
            break;
        case 4:
            view_inventory();
            break;
        case 5:
            search_item();
            break;
        case 6:
            view_report();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
     }

        printf("\n");
    } while (choice != 0);
    printf("done");
  }
  else
	{
		printf("failed");
	}
return 0;
}
