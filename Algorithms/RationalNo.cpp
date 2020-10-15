//This programm takes two rational nmer stores them in file name input
//and put many opetrations on them and then store in output file
#include<iostream>
#include <fstream>
#include<conio.h>
using namespace std;

class rational
{
	int n,d,n1,d1;
public:
	rational() : n(1), d(1) {};
	~rational(){};
	void getData();
	void reduce(int &n,int &d);
	void operator +(rational);
	void operator -(rational);
	void operator *(rational);
	void operator /(rational);

	//taking GCD(gretest common divisor like HCF)
	int GCD(int n1, int remainder)
     {
	if(remainder==0)
		return(n1);
	else { return(GCD(remainder,n1%remainder)); }
     } 
	
	};
	void rational::getData()
	{
	//storing in file
   ofstream outfile;
    outfile.open("input.txt" ,ios :: out);
    cout << "Writing to the file" << endl;
    cout<<"\nEnter a numerator: "; 
    cin >> n;
    cin.ignore();
    outfile << n << endl;
    cout<<"Enter a denominator: ";
	cin>>d;
	cout<<endl;
	outfile << d << endl;
    outfile.close();

		while(d==0)
		{
			cout<<"Please enter a denominator: ";
			cin>>d;outfile << d << endl;
		}
		while(d<0)
		{
			n *= -1;
			outfile << n << endl;
			d *= -1;
			outfile << d << endl;
		}
	}
void rational::operator +(rational c1)
{
rational temp;
temp.n=(n*c1.d)+(c1.n*d);
temp.d=c1.d*d;
reduce(temp.n,temp.d);
}

void rational::operator -(rational c1)
{
rational temp;
temp.n=(n*c1.d)-(c1.n*c1.d);
temp.d=c1.d*d;
reduce(temp.n,temp.d);
}

void rational::operator *(rational c1)
{
rational temp;
temp.n=n*c1.n;
temp.d=d*c1.d;
reduce(temp.n,temp.d);
}

void rational::operator /(rational c1)
{
rational temp;
temp.n=n*c1.d;
temp.d=d*c1.n;
if(temp.d<0)
{
	temp.n *= -1;
	temp.d *= -1;
}
reduce(temp.n,temp.d);
}




void rational::reduce(int &n,int &d)
{
	int rdc = 0;
	if(d>n)
		rdc = GCD(d,n);
	else if(d<n)
		rdc = GCD(n,d);
	else
		rdc = GCD(n,d);
	n1= (n /= rdc);
	d1= (d /= rdc);
	cout<<"\nAfter operating the rational numbers are: ";
//storing in file and getting output

ofstream outfile;
    outfile.open("output.txt" ,ios :: out);
    outfile << n1 << endl;
    outfile << d1 << endl;
	outfile.close();


	ifstream infile; 
   infile.open("output.txt",ios :: in); 
    infile >> n1; cout << n1 ;
	cout << " / ";
	 infile >> d1;
	  cout << d1 << endl; 
   // close the opened file.
   infile.close();
	
}



int main()
{

	rational c1, c2,*pt1,*pt2;
	pt1=&c1;
	pt2=&c2;
	int n;

	cout<<"Enter the data for the first fraction: ";
	c1.getData();
	cout<<"Enter the data for the second fraction: ";
	c2.getData ();
    cout << "\nChose any option and enter number\n\n";
	cout<<"1 . Addition of the two fractions"<<endl;
	cout<<"2 . Subtraction of the two fractions"<<endl;
	cout<<"3 . Multiplication of the two fractions"<<endl;
	cout<<"4 . Division of the two fractions"<<endl;
	cout << "5 . For all the operations "<< endl;
	cout<<"\nEnter your choice: ";
	cin>>n;
	//applying operations
	switch(n)
	{
		case 1:
			c1+c2;
			getch();
			break;
		case 2:
			c1-c2;
			getch();
			break;
		case 3:
			c1*c2;
			getch();
			break;
		case 4:
			c1/c2;
			getch();
			break;
		case 5:
			c1+c2;
			c1-c2;
			c1*c2;
			c1/c2;
			getch();
			break;
		default:
			cout<<"Invalid choice."<<endl;
		return 0;
	}
	delete pt1;
    delete pt2;
getch();
return 0;
}
