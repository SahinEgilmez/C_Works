#include <stdio.h>

#define TRUE 1
#define FALSE 0

void 
read_menu(FILE *fPtr_menu, int *c1, double *p1,
	int *c2, double *p2,int *c3, double *p3)
{
	fscanf(fPtr_menu, "%d", c1);
	fscanf(fPtr_menu, "%lf", p1);
	fscanf(fPtr_menu, "%d", c2);
	fscanf(fPtr_menu, "%lf", p2);
	fscanf(fPtr_menu, "%d", c3);
	fscanf(fPtr_menu, "%lf", p3);
}

void 
read_discounts(FILE *fPtr_discount, int *d1, int *d2, int *d3)
{
	fscanf(fPtr_discount, "%d", d1);
	fscanf(fPtr_discount, "%d", d2);
	fscanf(fPtr_discount, "%d", d3);
}

int
get_menu_choice(int c1, int c2, int c3, double p1, double p2, double p3)
{
	int menu;
	printf("\n\nEnter meal:\n1 - Soup (%d cal) = %.2lf TL\n2 - Beef (%d cal) = %.2lf TL\n3 - Cake(%d cal) = %.2lf TL\n0 - To exit\n", 
		c1, p1, c2, p2, c3, p3);
	printf("Enter your choice : ");
	scanf("%d", &menu);
	return menu;
}

void
print_state(int report, int food, double money, int cal)
{
	if(report == 0)
	{
		printf("Your money is not enough to order that food!\n");
		printf("Cal: %d Money: %.2lf", cal, money);
		return;
	}

	switch(food)
	{
		case 1: printf("You ordered soup.\n"); break;
		case 2: printf("You ordered beef.\n"); break;
		case 3: printf("You ordered cake.\n"); break;
	}
	printf("Cal: %d Money: %.2lf", cal, money);
}

int
order_meal(double price_of_food, int c_of_food, int d_percentage, double *money, int *cal)
{
	price_of_food = price_of_food * (100-d_percentage)/100;
	if(price_of_food<=*money)
	{
		*money -= price_of_food;
		*cal += c_of_food;
		return TRUE;
	}

	return FALSE;
}

int
main(int argc, char* argv[])
{
	FILE *fPtr_menu, *fPtr_discount;
	int c1,c2,c3;
	double money, p1,p2,p3;
	int d1,d2,d3;
	int d_type, disc, menu;
	int cal = 0, report;

	fPtr_menu = fopen("menu.txt","r");
	fPtr_discount = fopen("discount.txt","r");

	if(fPtr_menu == NULL || fPtr_discount == NULL)
	{
		printf("Could not read file!\n");
		return 1;
	}
	read_menu(fPtr_menu, &c1, &p1, &c2, &p2, &c3, &p3);
	read_discounts(fPtr_discount, &d1, &d2, &d3);
	fclose(fPtr_menu);
	fclose(fPtr_discount);

	printf("Enter balance:");
	scanf("%lf", &money);

	printf("Enter discount type:");
	scanf("%d", &d_type);

	switch(d_type)
	{
		case 1: disc = d1; break;
		case 2: disc = d2; break;
		case 3: disc = d3; break;
	}
	
	menu = get_menu_choice(c1, c2, c3, p1, p2, p3);
	while(menu != 0)
	{
		switch(menu)
		{
			case 1: report = order_meal(p1, c1, disc, &money, &cal); break;
			case 2: report = order_meal(p2, c2, disc, &money, &cal); break;
			case 3: report = order_meal(p3, c3, disc, &money, &cal); break;
		}
		print_state(report, menu, money, cal);
		menu = get_menu_choice(c1, c2, c3, p1, p2, p3);
	}


	return 0;
}