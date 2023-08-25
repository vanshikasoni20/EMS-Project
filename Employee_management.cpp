#include<bits/stdc++.h>
using namespace std;
#define limit 15

//structure of Employee
struct Employee{
    string firstName;
    string lastName;
    string kerbID;
    string title;
    int dateOfBirth;
    int joiningDate;
    int endingDate;
};

//declaring the object of Employee class
Employee emp[limit];

//functions used
void menu();
void createTable();
string kerbIDGenerator(string firstName, string lastName);
void addDetails();
void deleteDetails();
void deleteID();
void searchDetails();
void updateDetails();

int n;

void menu(){
    cout<<"\n--------------------------EMPLOYEE MANAGEMENT SYSTEM-----------------------------------\n";
    cout<<"\nPlease Choose an Option";
    cout<<"\n Press 1 Build Table for all Employee Details.";
    cout<<"\n Press 2 Add details of a new Employee.";
    cout<<"\n Press 3 Update details of an existing Employee.";
    cout<<"\n Press 4 Search for an Employee.";
    cout<<"\n Press 5 Delete details of an Employee.";
    cout<<"\n Press 6 Exit the Program.";
    int option;
    cin>>option;

    if(option==1)
        createTable();
    else if(option==2)
        addDetails();
    else if(option==3)
        updateDetails();
    else if(option==4)
        searchDetails();
    else if(option==5)
        deleteDetails();
    else
        cout<<"\nWrong Number Entered. ";
}

//function to create a table of all the details of the empliyee
void createTable(){
    cout<<"\nEnter the number of Employees whose data needs to be entered: (Maximum Employees = 15) ";
    cin>>n;
    if(n>limit)
        cout<<"\nMaximum limit is 15. ";
    
    cout<<"\nEnter the data for "<<n<<" employees: ";

    for(int i=0;i<n;i++){
        cout<<"\nEnter First Name: ";
        cin>>emp[i].firstName;
        cout<<"Enter Last Name: ";
        cin>>emp[i].lastName;
        cout<<"Enter Date of Birth: ";
        cin>>emp[i].dateOfBirth;
        cout<<"Enter Title: ";
        cin>>emp[i].title;
        cout<<"Kerberos ID of Employee: ";
        emp[i].kerbID=kerbIDGenerator(emp[i].firstName, emp[i].lastName);
        cout<<emp[i].kerbID;
        
    }

    menu();
}

//function to generate Kerberos ID for each employee
string kerbIDGenerator(string firstName, string lastName){
    string res= lastName + firstName[0] + firstName[1];
    return res;
}

//function to add details of the employee
void addDetails(){
    if(n<limit){
        int i=n;
        n++;

        cout << "\nEnter information of Employee\n";
        cout << "\nEnter First Name: ";
        cin >> emp[i].firstName;
  
        cout<<"\nEnter Last Name: ";
        cin>>emp[i].lastName;
  
        cout << "\nEnter Title:  ";
        cin >> emp[i].title;
  
        cout << "\nEnter Date of Birth: ";
        cin >> emp[i].dateOfBirth;
  
        cout << "\nKerberos ID: ";
        string ans=kerbIDGenerator(emp[i].firstName, emp[i].lastName);
        cout<<ans;
    }
    else {
        cout << "\nEmployee Table Full\n";
    }
    menu();
}

//function to delete the details
void deleteID(int i)
{
    for (int j = i; j < n - 1; j++) {
        emp[j].firstName = emp[j + 1].firstName;
        emp[j].dateOfBirth = emp[j + 1].dateOfBirth;
        emp[j].title = emp[j + 1].title;
        emp[j].lastName = emp[j + 1].lastName;
        emp[j].kerbID = emp[j + 1].kerbID;
    }
    return;
}

// Function to delete record
void deleteDetails()
{
    cout << "\nEnter the Kerberos ID of the Employee whose details need to be deleted: ";
  
    string kID;
  
    cin >> kID;
    for (int i = 0; i < n; i++) {
        if (emp[i].kerbID == kID) {
            deleteID(i);
            n--;
            break;
        }
    }
    cout<<"\nDetails successfully deleted! ";
    menu();
}

//function to update details
void updateDetails(){
    cout<<"\nEnter the Kerberos ID of the Employee whose details need to be updated: ";
    string kID;
    cin>>kID;

    string firstName;
    string lastName;
    string kerbID;
    int dateOfBirth;
    string title;
    cout<<"\nEnter the new details: ";
    cout<<"\nFirst Name: ";
    cin>>firstName;

    cout<<"\nLast Name: ";
    cin>>lastName;

    cout<<"\nDate of Birth: ";
    cin>>dateOfBirth;

    cout<<"\nTitle: ";
    cin>>title;

    for(int i=0;i<n;i++){
        if(emp[i].kerbID==kID){
            emp[i].firstName=firstName;
            cout<<"\nNew First Name: "<<emp[i].firstName;

            emp[i].lastName=lastName;
            cout<<"\nNew Last Name: "<<emp[i].lastName;

            emp[i].title=title;
            cout<<"\nNew Title: "<<emp[i].title;

            emp[i].dateOfBirth=dateOfBirth;
            cout<<"\nNew Date of Birth: "<<emp[i].dateOfBirth;

            emp[i].kerbID=kerbIDGenerator(emp[i].firstName, emp[i].lastName);
            cout<<"\nNew Kerberos ID: "<<emp[i].kerbID;
        }
    }
    cout<<"\nDetails successfully updated! ";

    menu();
}

//function to search details of the employee
void searchDetails(){
    cout<<"\nOn what basis do you want to search the Employee Database: ";
    cout<<"\n1. Employee's First Name. ";
    cout<<"\n2. Employee's Last Name. ";
    cout<<"\n3. Employee's Kerberos ID. ";
    cout<<"\n4. Employee's Title. ";
    cout<<"\n";
    int option;
    cin>>option;

    if(option==1){
        //searching on basis of first name
        string fName;
        cout<<"\nEnter the First Name of the Employee: ";
        cin>>fName;
        for(int i=0;i<n;i++){
            if(emp[i].firstName==fName){
                cout<<"\nEmployee's First Name: "<<emp[i].firstName;
                cout<<"\nEmployee's Last Name: "<<emp[i].lastName;
                cout<<"\nEmployee's Date of Birth: "<<emp[i].dateOfBirth;
                cout<<"\nEmployee's Title: "<<emp[i].title;
                cout<<"\nEmployee's Kerberos ID: "<<emp[i].kerbID;
            }
            else{
                cout<<"\nNo such record exists. ";
            }
        }

    }
    else if(option==2){
        //searching on basis of last name
        string lName;
        cout<<"\nEnter the Last Name of the Employee: ";
        cin>>lName;
        for(int i=0;i<n;i++){
            if(emp[i].lastName==lName){
                cout<<"\nEmployee's First Name: "<<emp[i].firstName;
                cout<<"\nEmployee's Last Name: "<<emp[i].lastName;
                cout<<"\nEmployee's Date of Birth: "<<emp[i].dateOfBirth;
                cout<<"\nEmployee's Title: "<<emp[i].title;
                cout<<"\nEmployee's Kerberos ID: "<<emp[i].kerbID;
            }
            else{
                cout<<"\nNo such record exists. ";
            }
        }
    }
    else if(option==3){
        //searching on basis of KID
        string kID;
        cout<<"\nEnter the Kerberos ID of the Employee: ";
        cin>>kID;
        for(int i=0;i<n;i++){
            if(emp[i].kerbID==kID){
                cout<<"\nEmployee's First Name: "<<emp[i].firstName;
                cout<<"\nEmployee's Last Name: "<<emp[i].lastName;
                cout<<"\nEmployee's Date of Birth: "<<emp[i].dateOfBirth;
                cout<<"\nEmployee's Title: "<<emp[i].title;
                cout<<"\nEmployee's Kerberos ID: "<<emp[i].kerbID;
            }
            else{
                cout<<"\nNo such record exists. ";
            }
        }
    }
    else{
        //searching on basis of title
        string title;
        cout<<"\nEnter the title of the Employee: ";
        cin>>title;
        for(int i=0;i<n;i++){
            if(emp[i].title==title){
                cout<<"\nEmployee's First Name: "<<emp[i].firstName;
                cout<<"\nEmployee's Last Name: "<<emp[i].lastName;
                cout<<"\nEmployee's Date of Birth: "<<emp[i].dateOfBirth;
                cout<<"\nEmployee's Title: "<<emp[i].title;
                cout<<"\nEmployee's Kerberos ID: "<<emp[i].kerbID;
            }
            else{
                cout<<"\nNo such record exists. ";
            }
        }
    }

    menu();
}

//driver function
int main(){
    menu();
    return 0;
}