//This program takes omplex number and performs suitable opertions on them
//using separate class made in header.h file
#include <iostream>
#include<conio.h>
#include"Header.h"
using namespace std;
ComplexNo::ComplexNo()// constructor
{
	real = imaginary = 0;
}


void ComplexNo::setPrint()
{
	cout << real << ", " << imaginary << "i ";
}


void ComplexNo::setNumber(int x, int y)
{
	real = x;
	imaginary = y;
}


void ComplexNo::add(ComplexNo b)
{
	real = real + b.real;
	imaginary = imaginary + b.imaginary;
	cout << "\nAfter Addition of two complex number is as       :   ";
	if (imaginary < 0) {
		cout << real << "-" << imaginary << "i";
	}
	else {
		cout << real << "+" << imaginary << "i";
	}
	//return a;//see this use this
}


void ComplexNo::subtract(ComplexNo b)
{
	
	b.real = b.real*(-1);
	real = real + b.real;
	b.imaginary = b.imaginary*(-1);
	imaginary = imaginary + b.imaginary;
	cout << "\nAfter subtraction of two complex number is as    :   ";
	if (imaginary < 0) {
		cout << real  << imaginary << "i";
	}
	else {
		cout << real << "+" << imaginary << "i";
	}
}


void ComplexNo::multiply(ComplexNo b) {

	real = real*b.real - imaginary*b.imaginary;
	imaginary = imaginary*b.real + real*b.imaginary;
	cout << "\nAfter multiplication of two complex number are    : ";
	if (imaginary < 0) {
		cout << real <<" " << imaginary << "i";
	}
	else {
		cout << real << "+" << imaginary << "i";
	}
}
void ComplexNo::divide(ComplexNo b) {
	
	int temp1,temp2,temp3;
	
	
	if ( b.real == 0 && b.imaginary == 0 )
        printf("Division by 0 + 0i is not allowed.");
      else
      {
        temp1 = real*b.real + imaginary*b.imaginary;
        temp2 = imaginary*b.real - real*b.imaginary;
        temp3 = b.real*b.real + b.imaginary*b.imaginary;
 
        if ( temp1%temp3 == 0 && temp2%temp3 == 0 )
        {
                 if ( temp2/temp3 >= 0)
                                            {
											      cout << "\nsit 1";    printf("\nAfter division of two complex numbers          : %d + %di",temp1/temp3,temp2/temp3);
         } else
                                      {
											       cout << "\nsit 1.2";        printf("\nAfter division of two complex numbers          : %d %di",temp1/temp3,temp2/temp3);
        }
        } else if ( temp1%temp3 == 0 && temp2%temp3 != 0 )
        {
                if ( temp2/temp3 >= 0)
                                                {
													  cout << "\nsit 2.1";printf("\nAfter division of two complex numbers         : %d + %d/%di",temp1/temp3,temp2,temp3);
         }  else
                                      {
											     cout << "\nsit 2.2";         printf("\nAfter division of two complex numbers         : %d %d/%di",temp1/temp3,temp2,temp3);
        }}
        else if ( temp1%temp3 != 0 && temp2%temp3 == 0 )
        {
                  if ( temp2/temp3 >= 0)
                                            {
												      cout << "\nsit 3.1";     printf("\nAfter division of two complex numbers         : %d/%d + %di",temp1,temp3,temp2/temp3);
        }  else
                                                     cout << "\nsit 3.2"; printf("\nAfter division of two complex numbers         : %d %d/%di",temp1,temp3,temp2/temp3);
        }
        else
        {
                   if ( temp2/temp3 >= 0)
                                             {
												    cout << "\nsit 4.1";    printf("\nAfter division of two complex numbers         : %d/%d + %d/%di",temp1,temp3,temp2,temp3);
         } else
                                              {
												   cout << "\nsit 4.2";    printf("\nAfter division of two complex numbers         : %d/%d %d/%di",temp1,temp3,temp2,temp3);
       } } 
      }
}
//r1.r2 + i1.i2 / r12 - i2
//i1.r2 - r1.i2
ComplexNo::~ComplexNo() {
	cout << "";

}
void ComplexNo::conjugate() {
	cout << "\nThe conjugate of complex nmb is         : ";
	imaginary = imaginary*(-1);
	if (imaginary < 0) {
		cout << real << " " << imaginary << "i";
	}
	else {
		cout << real << "+" << imaginary << "i";
	}

}

int main()
{
	ComplexNo c1, c2,*pt1,*pt2;
	pt1=&c1;
	pt2=&c2;
	int r1, i1;
	r1 = i1 = 0;
	cout << "      *****Please give your first complex number***** \n";
	cout << "  Enter a and b where a + ib is the first complex number.\n";
		cout << " a = ";
	cin >> r1;
	cout << " \nb = ";
	cin >> i1;

	c1.setNumber(r1, i1);
	int r2, i2;
	r2 = i2 = 0;
	cout << "       *****Please give your seconed complex number***** \n";
	cout << "    Enter a and b where a + ib is the seconed complex number.\n";
		cout << " a = ";
	cin >> r2;
	cout << " \nb = ";
	cin >> i2;
	c2.setNumber(r2, i2);

	cout << "complex no. 1 is     :";
	c1.setPrint();
	cout << endl;
	cout << "complex no. 2 is     :" ;
	c2.setPrint();
	cout << endl;
	cout<< "\nFor complex nmber Addition Please press              : 1\n";
    cout<< "For complex nmber Subtraction  Please press          : 2\n";
	cout<< "For complex nmber Multiplication  Please press       : 3\n";
	cout<< "For complex nmber Division Please press              : 4\n";
	cout<< "For complex nmber Conjugate Please press             : 5\n";
	int opt;
	cin >> opt;
	 if (opt == 1){
	 	c1.add(c2);
	    cout << endl;
	} else if (opt == 2){
		c1.subtract(c2);
	    cout << endl;
		} else if (opt == 3){
			c1.multiply(c2);
         	cout << endl;
			} else if (opt == 4){
					c1.divide(c2);
                	cout << endl;
				} else if (opt == 5){
						c1.conjugate();
						c2.conjugate();
                      	cout << endl;
						} 
	delete pt1;
	delete pt2;
	_getch();
	return 0;
}
