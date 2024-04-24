#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

int i=0;         //index of the array.

class bankAccount{
string name;
int accNumber;
string rno;
string phoneNumber;
float amount;
float debt;
int loansTaken;
public:
~bankAccount(){
}
bankAccount(){
    accNumber=152437+(3531*i);
    amount=0;
    debt=0;
    loansTaken=0;
}
void getdata(){
cout<<"Enter your name : "<<endl;
cin>>name;
cout<<"Enter your Roll Number :"<<endl;
cin>>rno;
cout<<"Enter your Phone Number : "<<endl;
cin>>phoneNumber;
}
string getrno(){
    return rno;
}
void display(){
    cout<<"Your account details are : "<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Roll Number : "<<rno<<endl;
    cout<<"Account number : "<<accNumber<<endl;
    cout<<"Phone Number : "<<phoneNumber<<endl;
    cout<<"Amount in bank : "<<amount<<endl;
    cout<<"Number of Loans taken : "<<loansTaken<<endl;
    cout<<"Loan repayment amount(debt) : "<<debt<<endl<<endl;
}
int getaccNo(){
 return accNumber;
}
string getName(){
    return name;
}
int deposit(float a){
    if(a>10000){
    cout<<"Cannot deposit more than 10000 rupees at one time."<<endl;
    return 0;    
    }
    amount=amount+a;
    return 1;
}
int repayLoan(float a){
    if(a>debt){
        if(a-debt>10000){
            cout<<"Cannot deposit such a huge amount."<<endl;
            return 0;
        }
        amount=amount+a-debt;
        debt=0;
        return 1;
    }
    else{
    debt=debt-a;
    return 1;
    }
}
int takeLoan(float b){
    if(debt>=10000){
        cout<<"Cannot provide loan due to excessive debt."<<endl
            <<"Kindly re-pay your pending loans first."<<endl;
            return 0;
    }
    if(b>5000){
    cout<<"Cannot take a loan of more than 5000 rupees at one time."<<endl;
    return 0;    
    }    
    loansTaken++;
    amount=amount+b;
    debt=debt+b;
    return 1;
}
void changeData(){
    cout<<"Enter your new name : "<<endl;
    cin>>name;
    cout<<"Enter your new roll number : "<<endl;
    cin>>rno;
    cout<<"Enter your new Phone Number : "<<endl;
    cin>>phoneNumber;
    cout<<endl;
}
int withdraw(float a){
    if(a>amount){
        cout<<endl;
        cout<<"You do not have sufficient balance."<<endl<<endl;
        return 0;
    }
    else{
        amount=amount-a;
        return 1;
    }
}
};



bankAccount customers[100];  //all the accounts are stored in an array.

void functions(int fn);

void disprulesandregu(){
cout<<endl;
cout<<"--------------------------------------------------------------"<<endl<<endl;
cout<<"  RULES AND REGULATIONS    "<<endl<<endl;
cout<<"--> Kindly enter correct details while creating an account."<<endl;
cout<<"--> Every Student is allowed to create only one account."<<endl;
cout<<"--> A unique account number will be issued to every student upon "<<
    "creation of the account."<<endl;
cout<<"--> This account number is not supposed to be shared with anyone, "
    <<"and will act as your passkey to accessing the features of this "
    <<"portal."<<endl;
cout<<"--> A maximum of 10,000 rupees can be deposited into the account "
    <<"at one time."<<endl;
cout<<"--> A maximum loan of 5,000 rupees can be taken at a time."<<endl;
cout<<"--> A student having a debt of more than 10,000 rupees will not be "
    <<"able to take a loan until some of his/her debt is cleared."<<endl;
cout<<"--> If any student is found indulged in any form of fraud, cheating "
    <<"or malpractice including creating a fake account, theft, or falsely "
    <<"logging into others account, his/her account will be permanently disabled."<<endl
    <<endl<<endl
    <<"FOR ANY HELP KINDLY CONTACT :"<<endl
    <<"Phone : 0832-2444397"<<endl
    <<"Mail : bmsnitg@nitgoa.ac.in"<<endl;
cout<<endl;
cout<<"--------------------------------------------------------------"<<endl<<endl;
}

void dispPortal(){
    int fn;
cout<<"**************************************************************"<<endl<<endl;
cout<<"Please choose your functionality : "<<endl
        <<"Press 1 to create an account. "<<endl
        <<"Press 2 to view your account details. "<<endl
        <<"Press 3 to login to your account for further functionalities."<<endl
        <<"Press 4 to view our Rules and Regulations."<<endl
        <<"Press 5 to exit the portal."<<endl<<endl;
        cin>>fn;
        if(fn>5 || fn<1){
            cout<<"Invalid number. Please enter the number again. "<<endl<<endl;
            while(1){
                cin>>fn;
                if(fn<=5 && fn>=1){
                    break;
                }
                else{
                cout<<"Invalid number. Please enter the number again. "<<endl<<endl;
                }
            }
        }
        if(fn==5){
            ofstream file("bank.txt");
            for(int j=0;j<i;j++){
                file.write((char*)&customers[j],sizeof(customers[j]));
            }
            file.close();
            cout<<"Thank you for visiting our portal."<<endl<<endl;
            abort();
        }
        functions(fn);
}

void functions(int fn){
    cout<<endl;
    if(fn==1){
        bankAccount acc1;
        acc1.getdata();
        for(int j=0;j<i;j++){
        if(acc1.getrno()==customers[j].getrno()){
            cout<<endl<<"The Entered Roll Number already has an account. Kindly try again."
                <<endl;
            acc1.~bankAccount();
            functions(1);
        }
        }
        cout<<endl;
        cout<<"------------------------------------------------------------"<<endl<<endl;
        cout<<"Your account has been created."<<endl<<endl;
        acc1.display();
        cout<<endl<<endl;
        customers[i]=acc1;
        i++;
        dispPortal();
    }
    if(fn==2){
        int j=0;
        int accno;
        cout<<"Please enter your account number : "<<endl;
        cin>>accno;
        if(accno==0){
            dispPortal();
        }
        cout<<endl;
        for(j=0;j<i;j++){
            if(customers[j].getaccNo() == accno){
                break;
            }
        }
        if(j>=i){
            cout<<"Invalid account number. Please try again, or enter '0' to go back."<<endl;
            functions(2);
        }
        else{
        cout<<"------------------------------------------------------------"<<endl<<endl;            
        customers[j].display();
        dispPortal();
        }
    }
    if(fn==3){
        string yourName;
        int k=0;
        int temp;
        int accno;
        cout<<"Please enter your name : "<<endl;
        cin>>yourName;
        cout<<"Please enter your account number : "<<endl;
        cin>>accno;
        cout<<endl;
        for(k=0;k<i;k++){
            if(customers[k].getaccNo() == accno){
            break;
            }
        }
        if(k>=i){
            cout<<"Invalid account number. Please enter any other number to"
            " try again, or enter '0' to go back."<<endl;
            int flagback;
            cin>>flagback;
            if(flagback==0){
                dispPortal();
            }
            else{
                functions(3);
            }
        }
        else if(customers[k].getName()!=yourName){
            cout<<"The entered name and account numbers do not match."<<endl
                <<"Please enter any number to try again or enter '0' to go back."<<endl;
            int flagbac;
            cin>>flagbac;
            if(flagbac==0){
                dispPortal();
            }
            else{
                functions(3);
            }
        }
        else{
        int var=1;
        cout<<"------------------------------------------------------------"<<endl<<endl;
        cout<<"You have successfully logged in into your account. "<<endl<<endl;
        customers[k].display();
        cout<<"Choose your functionality : "<<endl
            <<"Press 1 to deposit amount in bank."<<endl
            <<"Press 2 to withdraw amount from bank."<<endl
            <<"Press 3 to take a loan."<<endl
            <<"Press 4 to repay a loan."<<endl
            <<"Press 5 to change your details."<<endl
            <<"Press 6 to log out of your account."<<endl<<endl;
        cin>>temp;
        if(temp>6 || temp<1){
            cout<<"Invalid number. Please enter the number again."<<endl<<endl;
            while(1){
                cin>>temp;
                if(temp<=6 && temp>=1){
                    break;
                }
                else{
                cout<<"Invalid number. Please enter the number again. "<<endl<<endl;
                }
            }
        }
        if(temp==1){
            float c;
            cout<<"Enter the amount you want to deposit : "<<endl;
            cin>>c;
            var=customers[k].deposit(c);
        }
        if(temp==2){
            float c;
            cout<<"Enter the amount you want to withdraw : "<<endl;
            cin>>c;
            var=customers[k].withdraw(c);
        }
        if(temp==3){
            float d;
            cout<<"Enter the amount you want to take a loan : "<<endl;
            cin>>d;
            var=customers[k].takeLoan(d);
        }
        if(temp==4){
            float f;
            cout<<"Enter the amount you want to deposit : "<<endl;
            cin>>f;
            var=customers[k].repayLoan(f);
        }
        if(temp==5){
            customers[k].changeData();
        }
        if(temp==6){
            cout<<"You have logged out of your account."<<endl<<endl;
            dispPortal();
        }
        cout<<endl;
        if(var==1){
        cout<<"Changes made successfully."<<endl<<endl;
        customers[k].display();
        }
        dispPortal();
        }
    }
    if(fn==4){
        disprulesandregu();
        char back;
        cout<<"Enter any key to go back."<<endl<<endl;
        cin>>back;
        dispPortal();
    }       
}


int main(){
    ifstream file("bank.txt");
    while(!file.eof()){
        file.read((char*)&customers[i],sizeof(customers[i]));
        i++;
    }
    file.close();
    cout<<endl;
    cout<<"**************************************************************"<<endl<<endl;
    cout<<"             WELCOME TO THE NITG STUDENTS BANK      "<<endl<<endl;
    dispPortal();
    return 0;
}


