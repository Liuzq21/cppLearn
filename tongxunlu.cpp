#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct Person
{
    string m_Name ;
    int m_Sex; // 1 man 2 woman
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks
{
    Person personArray[MAX];
    int number;
};

void showmenu();
void addPerson(struct AddressBooks *adbs);
void showBooks(AddressBooks adbs);
void delPerson(AddressBooks *adbs, string name);
int findPerson(AddressBooks *abds, string name);
void editPerson(AddressBooks *adbs, string name);
void emptyBooks(AddressBooks *adbs);

int main(){
    int select;
    AddressBooks adbs;
    adbs.number = 0;
    string name_find;
    int flag = 1;
    while (flag)
    {
        showmenu();
        cin >> select;
        switch (select)
        {
        case 1:  // 添加联系人
            addPerson(&adbs);
            break;
        case 2:  // 显示联系人
            showBooks(adbs);
            break;
        case 3: // 删除联系人
            cout<<"输入需要删除的联系人姓名：";
            cin>>name_find;
            delPerson(&adbs, name_find);
            break;
        case 4: // 查找联系人
            cout<<"输入需要查找的联系人姓名：";
            cin>>name_find;
            findPerson(&adbs,name_find);
            break;
        case 5: // 修改联系人
            cout<<"输入需要修改的联系人姓名：";
            cin>>name_find;
            editPerson(&adbs, name_find);
            break;
        case 6: // 清空联系人
            emptyBooks(&adbs);
            break;
        case 0:
            cout<<"欢迎下次使用"<<endl;
            flag = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}


void showmenu(){
    cout<< "******************" <<endl;
    cout<< "1. 添加联系人" <<endl;
    cout<< "2. 显示联系人" <<endl;
    cout<< "3. 删除联系人" <<endl;
    cout<< "4. 查找联系人" <<endl;
    cout<< "5. 修改联系人" <<endl;
    cout<< "6. 清空联系人" <<endl;
    cout<< "0. 退出通讯录" <<endl;
    cout<< "******************" <<endl;
}
void addPerson(AddressBooks *adbs){
    if(adbs->number == MAX) {cout<<"通讯录已经满"<<endl;return;}
    else{
        cout<<"输入联系人的地址:";
        cin>>adbs->personArray[adbs->number].m_Addr;
        cout<<"输入联系人的年龄:";
        cin>>adbs->personArray[adbs->number].m_Age;
        cout<<"输入联系人的姓名:";
        cin>>adbs->personArray[adbs->number].m_Name;
        cout<<"输入联系人的电话:";
        cin>>adbs->personArray[adbs->number].m_Phone;
        cout<<"输入联系人的性别: 1-男 2-女";
        int a;
        cin>>a;
        while(a != 1 && a!=2){
            cout<<"请重新输入：";
            cin>>a;
        }
        adbs->personArray[adbs->number].m_Sex = a;
        adbs->number++;
        return;
    }
}

void showBooks(AddressBooks adbs){
    cout<<"name\tage\tsex\tphone\t\taddr"<<endl;
    for(int i=0;i<adbs.number;i++){
        cout<<adbs.personArray[i].m_Name + "\t" ;
        cout<< adbs.personArray[i].m_Age << "\t" ;
        cout<< adbs.personArray[i].m_Sex << "\t" ;
        cout<< adbs.personArray[i].m_Phone << "\t\t";
        cout<<adbs.personArray[i].m_Addr<<endl;    
        }
    return;
}

void delPerson(AddressBooks *adbs , string name){
    if(adbs->number == 0) {cout<<"通讯录无人可删"<<endl;return;}
    else{
        int sub = findPerson(adbs, name);
        if(sub == -1) {cout<<"查无此人"<<endl; return;}
        else{
            for(int i =sub; i<adbs->number - 1 ; i++){
                adbs->personArray[i] = adbs->personArray[i+1];
            }
            cout<<"删除成功"<<endl;
        }
        adbs->number--;
        return;
    }
}

int findPerson(AddressBooks *adbs , string name){
    for(int i=0;i<adbs->number;i++){
        if(adbs->personArray[i].m_Name == name){
            // success
            cout<<"找到联系人"<<endl;
            cout<<"name\tage\tsex\tphone\t\taddr"<<endl;
            cout<<adbs->personArray[i].m_Name + "\t" ;
            cout<< adbs->personArray[i].m_Age << "\t" ;
            cout<< adbs->personArray[i].m_Sex << "\t" ;
            cout<< adbs->personArray[i].m_Phone << "\t\t";
            cout<<adbs->personArray[i].m_Addr<<endl;
            return i;
        }
    }
    cout<<"未找到联系人"<<endl;
    return -1; // fail
}

void editPerson(AddressBooks *adbs, string name){
    if(adbs->number == 0) {cout<<"通讯录无人可改"<<endl;return;}
    else{
        int sub = findPerson(adbs, name);
        if(sub == -1) {cout<<"查无此人"<<endl; return;}
        else{
            cout<<"请重新输入该联系人的姓别1-男2-女：";
            cin>>adbs->personArray[sub].m_Sex;
            cout<<"请重新输入该联系人的年龄：";
            cin>>adbs->personArray[sub].m_Age;
            cout<<"请重新输入该联系人的电话";
            cin>>adbs->personArray[sub].m_Phone;
            cout<<"请重新输入该联系人的地址";
            cin>>adbs->personArray[sub].m_Addr;
        }
        return;
    }
}

void emptyBooks(AddressBooks *adbs){
    adbs->number = 0;
    cout<<"通讯录已清空"<<endl;
    system("pause");
    system("cls");
    return;
}