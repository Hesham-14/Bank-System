#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct product		
{
	int Pno;
	string Pname;
	float Pprice, Pq;
};
struct bag
{
	int number;
	string name;
	float price, q, tprice;
};
class Product_x
{
private:
	product pro[5000];		// Products list saved as Array
	bag Purchase[5000];	// 	Purchases list saved as Array

public:
		//Admin Functions
	void storing()		// giving initial Values to the Products info
	{
		for (int i = 0; i < 5000;i++)
		{
			pro[i].Pno = 0;
			pro[i].Pname = "-";
			pro[i].Pprice = 0;
			pro[i].Pq = 0;
		}

	}
	void store() 		// Ready list to use and test code quickly
	{
		pro[0].Pno = 1, pro[0].Pname = "pepsi", pro[0].Pprice = 5, pro[0].Pq = 2500;
		pro[1].Pno = 2, pro[1].Pname = "oreo", pro[1].Pprice = 4, pro[1].Pq = 800;
		pro[2].Pno = 3, pro[2].Pname = "water", pro[2].Pprice = 10, pro[2].Pq = 6900;

	}
	void Add_Product()
	{
		string ans;
		for (int i=0; i < 5000; i++)
		{
			int num;
			cout << "Please enter product number:\t"; cin >> num;
			for (int i = 0; i < 5000; i++)
			{
				if (pro[i].Pno == 0)
				{
					pro[i].Pno = num;
					cout << "Please enter product name:\t"; getline(cin, pro[i].Pname); getline(cin, pro[i].Pname);
					cout << "Please enter product price:\t"; cin >> pro[i].Pprice;
					cout << "Please enter product quantity:\t"; cin >> pro[i].Pq;
					cout << "\n\n The product saved \n\n";
					break;
				}
			}
			cout << "Do You want to add another Product (y/n):\t"; cin >> ans;
			if (ans == "n")
				break;
		}

	}
	void Modify_Product()
	{
		string ans;
		int num = 0;
		do {
			cout << "Please Enter Product number that u want to modify:\t";cin >> num;
			for (int i = 0; i < 5000;i++)
			{
				if (pro[i].Pno == num)
				{
					cout << "Please enter product name:\t"; getline(cin, pro[i].Pname); getline(cin, pro[i].Pname);
					cout << "Please enter product price:\t"; cin >> pro[i].Pprice;
					cout << "Please enter product quantity:\t"; cin >> pro[i].Pq;
					cout << "\n\n The product Updated \n\n";
					break;
				}
			}
			cout << "Do You want to modify another Product (y/n):\t"; cin >> ans;
		} while (ans == "y");

	}
	void Delete_Product()
	{
		string ans;
		int num = 0;
		do {
			cout << "Please Enter Product number that u want to delete:\t";cin >> num;
			for (int i = 0; i < 5000;i++)
			{
				if (pro[i].Pno == num)
				{
					pro[i].Pno = 0;
					pro[i].Pname = "-";
					pro[i].Pprice = 0;
					pro[i].Pq = 0;
					cout << "\n\n The product deleted \n\n";
					break;
				}
			}
			cout << "Do You want to delete another Product (y/n):\t"; cin >> ans;
		} while (ans == "y");
	}
	void Display()		// Display all Product info in table
	{
		cout << "\n\n============================================================================" << endl;
		cout << setw(14) << "Product Number"<< setw(20) << "Product Name"<< setw(22) << "Product Quantity"<< setw(18) << "Product Price" << endl;
		cout << "============================================================================" << endl;
		for (int i = 0; i < 5000;i++)
		{
			if(pro[i].Pno != 0)
			cout << setw(14) << pro[i].Pno << setw(20) << pro[i].Pname << setw(22) << pro[i].Pq << setw(18) << pro[i].Pprice << endl;
		}
	}
	
		//Customer Functions

	void storing2()		// giving initial Values to the Purchases info
	{
		for (int i = 0; i < 5000;i++)
		{
			Purchase[i].number = 0;
			Purchase[i].name = "-";
			Purchase[i].price = 0;
			Purchase[i].q = 0;
			Purchase[i].tprice = 0;

		}
	}
	void Buy()
	{
		storing2();		// giving initial Values to the Purchases info
		string ans;
		float sum = 0;		//tatal cash to pay
		do {
			int num = 0;		//product number
			float q = 0;		//product quantity
			float Btotal = 0;
			cout << "Please Enter Product number that u want to buy:\t";cin >> num;
			cout << "Please Enter Product Quantity:\t";cin >> q;
			for (int i = 0; i < 5000;i++)								//loop that search for the Product info in the Products list
			{
				if (pro[i].Pno == num)						//finding product number
				{
					pro[i].Pq -= q;						//decreasing the quantity of product
					Btotal = pro[i].Pprice * q;			// total price for product quantity
					sum += Btotal;						// total cash to pay
					for (int j = 0; j < 5000; j++)
					{
						if (Purchase[j].number == 0)		//making sure that there is no product saved in that place in Purchases list
						{
							Purchase[j].number = num;						//storing product info
							Purchase[j].name = pro[i].Pname;
							Purchase[j].q = q;
							Purchase[j].price = pro[i].Pprice;
							Purchase[j].tprice = Btotal;
							break;
						}
					}
				}

			}
			cout << "Do You want to buy another Product (y/n):\t"; cin >> ans;
		} while (ans == "y");
		receipt(sum);
		
	}
	void receipt(float sum)		//Display Receipt
	{
		cout << "\n\n============================================================================" << endl;
		cout << setw(14) << "Product Number" << setw(20) << "Product Name" << setw(12) << "Quantity" << setw(16) << "Product Price" << setw(14) << "Total Price" << endl;
		cout << "============================================================================" << endl;
		for (int i = 0; i < 5000;i++)
		{
			if (Purchase[i].number != 0)
				cout << setw(14) << Purchase[i].number << setw(20) << Purchase[i].name << setw(12) << Purchase[i].q << setw(16) << Purchase[i].price << setw(14) << Purchase[i].tprice << endl;
		}
		cout << "============================================================================" << endl;
		cout << "\n\t\t\t Total Cash:" << sum << endl;
		cout << "============================================================================" << endl;
	}
	void Return_0()
	{
		storing2();		// giving initial Values to the Purchases info
		string ans;
		float sum = 0;		//tatal cash to take back
		do 
		{
		
			int num, temp;
			do
			{
				temp = 0;
				cout << "Please enter product number:\t"; cin >> num;
				for (int j = 0; j < 5000;j++)
				{
					if (pro[j].Pno == num)
					{
						temp = 1;
						break;
					}
				}
				if (temp == 0)
					cout << "The product is not found" << endl << "\t\t******* try another number ******\t\t\n";
			} while (temp == 0);
			
			float q = 0;		//product quantity
			float Btotal = 0;
			cout << "Please Enter Product Quantity:\t";cin >> q;
			for (int i = 0; i < 5000;i++)								//loop that search for the Product info in the Products list
			{
				if (pro[i].Pno == num)						//finding product number
				{
					pro[i].Pq += q;						//decreasing the quantity of product
					Btotal = pro[i].Pprice * q;			// total price for product quantity
					sum += Btotal;						// total cash to pay
					for (int j = 0; j < 5000; j++)
					{
						if (Purchase[j].number == 0)		//making sure that there is no product saved in that place in Purchases list
						{
							Purchase[j].number = num;						//storing product info
							Purchase[j].name = pro[i].Pname;
							Purchase[j].q = q;
							Purchase[j].price = pro[i].Pprice;
							Purchase[j].tprice = Btotal;
							break;
						}
					}
				}

			}
			cout << "Do You want to return another Product (y/n):\t"; cin >> ans;
		} while (ans == "y");
		receipt(sum);
		
	}
};

void Admin_Menu(Product_x &v)
{
	char x;
	do
	{
		cout << "\n\n\n ADMINISTRATOR MENU:";
		cout << "\n\n\t a. ADD PRODUCT";
		cout << "\n\n\t b. MODIFY PRODUCT";
		cout << "\n\n\t c. DELETE PRODUCT";
		cout << "\n\n\t d. DISPLAY All PRODUCTS";
		cout << "\n\n\t e. RETURN TO MAIN MENU";
		cout << "\n\n\t Please enter your choice (a-d) ";
		cin >> x;
		switch (x)
		{
		case'a':
			v.Add_Product();
			break;
		case'b':
			v.Modify_Product();
			break;
		case'c':
			v.Delete_Product();
			break;
		case'd':
			v.Display();
			break;
		case'e':
			break;
		defult:
			cout << "ERROR\n";
			break;
		}
	} while (x != 'e');

}

void Customer_Menu(Product_x &v)
{
	char x;
	v.storing2();
	do
	{
		cout << "\n\n\n CUSTOMER MENU:";
		cout << "\n\n\t a. BUY";
		cout << "\n\n\t b. RETURN";
		cout << "\n\n\t c. RETURN TO MAIN MENU";
		cout << "\n\n\t Please enter your choice (a-c) ";
		cin >> x;
		switch (x)
		{
		case'a':
			v.Buy();
			break;
		case'b':
			v.Return_0();
			break;
		case'c':
			break;
		defult:
			cout << "ERROR\n";
			break;
		}
	} while (x != 'c');

}

void Main_Menu(Product_x &v)
{
	char x;
	do
	{
		cout << "\n\n\n MAIN MENU:";
		cout << "\n\n\t a. ADMINISTRATOR MENU";
		cout << "\n\n\t b. CUSTOMER MENU";
		cout << "\n\n\t c. EXIT THE PROGRAM";
		cout << "\n\n\t Please enter your choice (a-c) ";
		cin >> x;
		switch (x)
		{
		case'a':
			Admin_Menu(v);
			break;
		case'b':
			Customer_Menu(v);
			break;
		case'c':
			break;
		defult:
			cout << "ERROR\n";
			break;
		}
	} while (x != 'c');

}

void Intro()
{
	cout << "\t**********************************************************" << endl;
	cout << "\t\t\tSuper Market Billing System" << endl;
	cout << "\t**********************************************************" << "\n\n\n";
}

int main()
{
	Intro();
	Product_x v;
	v.storing();
	//v.store();		// Ready list to use and test code quickly
	Main_Menu(v);
	return 0;
}

