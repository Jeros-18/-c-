#pragma once
#include<iostream>
#include<string>
#include <vector>
#include <conio.h>
using namespace std;

class user {
private:
    string ID;
    string Name;
    string Email;
    string Password;
    
public:
   
    user() {};
    void Register();
    void Enter();
    void Display();
};

vector<user> people;

/*ע��*/
void user::Register()
{
    string pw1;
    string pw2;
    user person;
    cout << "����������ID��";
flag:
    cin >> person.ID;
    for (int i = 0; i < people.size(); i++) {
        if (people.at(i).ID == person.ID) {
            cout << "��ID�Ѵ��ڣ�����������:";
            goto flag;
        }
    }
    cout << "�����������û�����";
    cin >> person.Name;
    cout << "����������䣺";
    cin >> person.Email;
    cout << "�������������룺";
flag0:
    cin >> pw1;
    cout << "���ٴ�ȷ���������룺";
    cin >> pw2;
    if (pw1 != pw2)
    {
        cout << "ǰ�������������벻һ�£���������������:";
        goto flag0;
    }
    cout << "ע��ɹ���" << endl;
    person.Password = pw1;
    people.push_back(person);
    Display();
}
/*��¼*/
void user::Enter()//��¼
{
    cout << "����������ID��";
flag1:
    string id;
    string pwd;
    cin >> id;
    for (int i = 0; i < people.size(); i++) {//��֤ID�Ƿ����
        int tk = 1; tk++;

        if (people.at(i).ID == id) {
            tk = 2;
            cout << "�������������룺";       
            cin >> pwd;
            if (people.at(i).Password != pwd) {
                cout << "�������";               
            }
            cout << "��¼�ɹ���" << endl;
            
            cout << "     (1)Information�鿴��Ϣ\n     (2)���롰��У��Ա��Ϣ����ϵͳ��   (3)�˳�  \n\nChoice:";
            int choice;//ѡ�����
            cin >> choice; switch (choice)
            {
            case 1://�鿴��Ϣ
                cout << "����IDΪ��" << people.at(i).ID << endl;
                cout << "��������Ϊ��" << people.at(i).Password << endl;
                cout << "�����û���Ϊ��" << people.at(i).Name << endl;
                cout << "��������Ϊ��" << people.at(i).Email << endl;
                Display();
            case 2:
               break;
            case 0:
                exit(EXIT_FAILURE);               
            }
            
        }
        else {
            cout << "��ID������";
        }
    }
}
/*����*/
void user::Display()
{
    cout << "     (1)ע��\n     (2)��¼\n     (3)�˳�\n\nChoice:";
    int choice;//ѡ�����
    user u;
    cin >> choice;
    switch (choice)
    {
    case 1://ע��
        u.Register();//���ú���
        break;
    case 2://��¼
        u.Enter();//���ú���
        break;
    case 3://�˳�
        exit(EXIT_FAILURE);
    }
}


