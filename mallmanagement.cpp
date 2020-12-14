#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class shop
{
	int No;
	char Shopname[20];
	char OwnerName[20];
	int EBbill;
	int WaterBill;
	int Rent;
	public:
		void sgetData()
		{
			cout<<"\nShop No : ";
			cin>>No;
			cout<<"\nShop name : ";
			cin>>Shopname;
			cout<<"\nOwner Name : ";
			cin>>OwnerName;
			cout<<"\nEB bill : ";
			cin>>EBbill;
			cout<<"\nWater Bill : ";
			cin>>WaterBill;
			cout<<"\nRent : ";
			cin>>Rent;
		}
       void sdisplay()
       {
       	cout<<"\nTHE SHOP NUMBER: "<<No;
       	cout<<"\n THE SHOP NAME: "<<Shopname;
       	cout<<"\n THE SHOP OWNER NAME: "<<OwnerName;
       	cout<<"\n THE EB-BILL RATE: "<<EBbill;
       	cout<<"\n THE WATER BILL RATE: "<<WaterBill;
       	cout<<"\n THE RENT RATE : "<<Rent<<"\n\n";
       	cout<<"\n---------------------------------------";
	   }
        char *getm()
        {
            return Shopname;
        }
        int num()
        {
            return No;
        }
        int rent()
        {
            return Rent;
        }

}obj1;
int main()
{
    int option;
    shop e;
    shop b[50];
    fstream fil;
    while(1)
    {
        cout<<"\n--------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\tSHOP DETAILS";
        cout<<"\n--------------------------------------------------------------------------------------------------------";
        cout<<"\n\t1.ADD NEW EMPLOYEE\n\t2.DISPLAY\n\t3.DELETE\n\t4.UPDATE\n\t5.EXIT";
        cout<<"\n--------------------------------------------------------------------------------------------------------";
        cout<<"\nEnter your option.....";
        cin>>option;
        switch(option)
        {
            case 1:
              {

                      fstream f;
                      f.open("s.dat",ios::app|ios::binary);
                      e.sgetData();
                      income=income+e.rent();
                      f.write( (char*)&e, sizeof(shop) );
                      f.close();
                      break;

              }
            case 2:
            {
                ifstream infile("s.dat",ios::in|ios::binary);
                if(!infile)
                {
                    cout<<"\nFile cannot be opened";
                    return 1;
                }
                cout<<"\n\t\t\t\t\tShop details....\n";
                int i=0;
                while(infile)
                {
                    infile.read((char*)&b[i],sizeof(shop));
                    if(infile)
                    b[i].sdisplay();
                    i++;
                }
                infile.close();
                break;
            }
            case 3:
            {
                fstream a;
                int b;
                ofstream c("s1.dat",ios::out|ios::app);
                a.open("s.dat",ios::in|ios::out);
                cout<<"\n\n\t\tWHICH EMPLOYEE YOU WANT TO DELETE(ID) : ";
                cin>>b;
                a.seekg(0,ios::beg);
                while(a.read((char*)&obj1,sizeof(obj1)))
                {
                    if(obj1.num()!=b)
                    {
                        c.write((char*)&obj1,sizeof(obj1));
                    }
                }
                a.close();
                c.close();
                remove("s.dat");
                rename("s1.dat","s.dat");
                break;
            }
            case 4:
                {
                    char m[100];
                    cout<<"Enter Name that should be searched:";
                    cin>>m;
                    fil.open("s.dat",ios::in| ios::out|ios::binary);
                    if(!fil)
                    {
                        cout<<"File not Found";
                        exit(0);
                    }
                    else
                    {
                        fil.read((char*)&obj1, sizeof(obj1));
                        while(!fil.eof())
                        {
                            if(strcmp(m,obj1.getm())==0)
                            {
                                fil.seekg(0,ios::cur);
                                cout<<"Enter New Record.."<<endl;
                                obj1.sgetData();
                                fil.seekp(fil.tellg() - sizeof(obj1));
                            }
                            fil.read((char*)&obj1, sizeof(obj1));
                        }
                    }
                    fil.close();
                    break;
                }
            case 6:
                exit(0);
            default:
                {
                    cout<<"\nEnter correct option....";
                    break;
                }
        }
    }return 0;
    }