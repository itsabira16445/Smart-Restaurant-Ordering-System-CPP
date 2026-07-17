#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void showMainMenu()
{
    cout<<"============================================"<<endl;
    cout<<"Smart Restaurant Ordering and Billing System"<<endl;
    cout<<"============================================"<<endl;
    cout<<"1.Start New Order"<<endl;
    cout<<"2.View Menu"<<endl;
    cout<<"3.Exit"<<endl;
}
void ShowRestaurantMenu()
{
    cout<<"====Restaurant Menu===="<<endl;
    cout<<"1.Burger     Rs.500"<<endl;
    cout<<"2.Pizza      Rs.1200"<<endl;
    cout<<"3.Fries      Rs.400"<<endl;
    cout<<"4.Cold Drink Rs.150"<<endl;
    cout<<"===================="<<endl;
}
void printBill(string Customername,string item,int price,int quantity,int total)
{
    cout<<"====Restaurant Bill===="<<endl;
    cout<<"Customer Name  :"<<Customername<<endl;
    cout<<"Item Name      :"<<item<<endl;
    cout<<"Price          :"<<price<<endl;
    cout<<"Quantity       :"<<quantity<<endl;
    cout<<"---------------"<<endl;
    cout<<"Total          :"<<total<<endl;
    cout<<"================"<<endl;
    cout<<"Thank You!"<<endl;
}
void saveOrder(string customerName,string itemName,int price,int quantity,int total)
{
    ofstream fout("orders.txt",ios::out|ios::app);
    fout<<"==============="<<endl;
    fout<<"Restaurant Bill"<<endl;
    fout<<"==============="<<endl;
    fout<<"Customer Name :"<<customerName<<endl;
    fout<<"Item Name     :"<<itemName<<endl;
    fout<<"Price         :"<<price<<endl;
    fout<<"Quantity      :"<<quantity<<endl;
    fout<<"--------------"<<endl;
    fout<<"Total         :"<<total<<endl;
    fout<<"Status        :Confirmed"<<endl;
    fout<<"=============="<<endl;
    fout<<"Thank You!"<<endl;
    fout<<"=============="<<endl;
    fout.close();    
}
void showRestaurantMenuOnly()
{
    cout<<" =====View Menu=====   :"<<endl;
    cout<<"=====Restaurant Menu==="<<endl;
    cout<<"1.Burger     Rs.500"<<endl;
    cout<<"2.Pizza      Rs.1200"<<endl;
    cout<<"3.Fries      Rs.400"<<endl;
    cout<<"4.Cold Drink Rs.150"<<endl;
    cout<<"======================="<<endl;
}

int main()
{
    int choice;
    int item,quantity;
    int price,total=0;
    char ch;
    string itemname;
    int confirmC;
    do{
    showMainMenu();
    cout<<"Enter your choice:"<<endl;
    cin>>choice;
       switch(choice)
    {
        case 1:
        {
        string customername;
        cout<<"Enter Customer Name:"<<endl;
        cin>>customername;
        cout<<"Start Order :"<<endl;
        ShowRestaurantMenu();
        cout<<"Enter Item Number:"<<endl;
        cin>>item;
        cout<<"Enter Quantity:"<<endl;
        cin>>quantity;
        
        if(item>=1&&item<=4 && quantity>0)
        {
            cout<<"Order is being Processed"<<endl;
        }
        else
        {
            cout<<"Invalid Item Number or Quantity"<<endl;
            break;
        }
        
        if(item==1)
        {
        price=500;
        itemname="Burger";
        }
        else if(item==2)
        {
        price=1200;
        itemname="Pizza";
        }
        else if(item==3)
        {
        price=400;
        itemname="Fries";
        }
        else if(item==4)
        {
        price=150;
        itemname="Cold Drink";
        }
        else
        {
        cout<<"Invalid Choice"<<endl;
        }
        total=price*quantity;
        printBill(customername,itemname,price,quantity,total);
        
        cout<<"1.Confirm Order:"<<endl;
        cout<<"2.Cancel Order:"<<endl;
        cout<<"Enter you Choice"<<endl;
        cin>>confirmC;
        if(confirmC==1)
        {
            cout<<"Order Confirmed"<<endl;
           saveOrder(customername,itemname,price,quantity,total);
        }
        else
        {
            cout<<"Order Cancelled Successfully"<<endl;
        }
        break;
    }
        case 2:
        showRestaurantMenuOnly();
        break;
        case 3:
        cout<<"Thank you for visiting our restaurant!"<<endl;
        cout<<"Have a great day!"<<endl;
        break;
        default:
        cout<<"Invalid Case"<<endl;
    }
        cout<<"Do you want to Order again? (Y/N)"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    
}