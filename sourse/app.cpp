
/*
Приложение для управления персональными финансами
В данном приложении вы можете иметь один кошельк и одну кредитную карту
Вам надо всего один раз зарегестрироваться и войти в коешлек или карту
Также реализованны функции:
Регистрация кошелька;
Регистрация карты;
Вход в кошелек или карту;
Внесение затрат и доходов, каждая из которых относится к определенной категории;
Получение информации о тратах и доходов;
Вывод текущего баланса кошелька;
Возможность оформления кредита;
Вывод текущей задолжности по кредиту;
Просмотр баланса кредитной карты;
Возможность погашения долга;
Просмотр кредитной истрии;
*/




#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>
#include <sstream>
#include <fstream>
using namespace std;

// Шифровка
string encrypt(string input) {
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 3) % 26];

                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}

// Расшифровка
string decrypt(string input) {
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j - 3) % 26];
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}
//класс кредитной карты
class Kredit_Card
{
  private:
    string card_number;
    string card_name;
    string card_surname;
    string card_date;
    string card_cvv;
    string card_password;
  public:
  void set_card_number(string card_number)
  {
      this->card_number=card_number;
  }
    string get_card_number()
  {
    return card_number;
  }
  void set_card_name(string card_name)
  {
    this->card_name=card_name;
  }
  string get_card_name()
  {
    return card_name;
  }
  void set_card_surname(string card_surname)
  {
    this->card_surname=card_surname;
  }
  string get_card_surname()
  {
    return card_surname;
  }
  void set_card_date(string card_date)
  {
      this->card_date=card_date;
  }
  string get_card_date()
  {
    return card_date;
  }
  void set_card_cvv(string card_cvv)
  {
    this->card_cvv=card_cvv;
  }
  string get_card_cvv()
  {
    return card_cvv;
  }
  void set_card_password(string card_password)
  {
    this->card_password=card_password;
  }
  string get_card_password()
  {
    return card_password;
  }
//конструктор по умолчанию
  Kredit_Card()
      {
        card_number = "";
        card_name = "";
        card_surname = "";
        card_date = "";
        card_cvv = "";
      }
//конструктор с параметрами карты
  Kredit_Card(string card_number, string card_name, string card_surname, string card_date, string card_cvv)
  {
    set_card_number(card_number);
    set_card_name(card_name);
    set_card_surname(card_surname);
    set_card_date(card_date);
    set_card_cvv(card_cvv);
  }
//создание номера карты
string card_number_input()
{
  int rand_number = 0;
  string baza = "2200 7009";
  do
  {
    rand_number = rand() % 100000000;
  } while (rand_number < 10000000);
  string str = baza + " " + to_string(rand_number);
  str.insert(14, " "); // добавляем пробел после первых 4 символов
  set_card_number(str);
  return str;
}
//создание даты карты
  string card_date_input()
  {
    time_t now = time(0);
    tm *dt = localtime(&now);
    int year = (1900 + dt->tm_year) + 10;
    int month = 1 + dt->tm_mon;
    string str = to_string(year)+"/"+to_string(month);
    set_card_date(str);
    return str;
  }
//создание cvv карты
  string card_cvv_input()
  {
    int rand_number=0;
    do{
    rand_number=rand()%1000;
    }while(rand_number < 100);
    set_card_cvv(to_string(rand_number));
    return to_string(rand_number);
  }
//вывод информации о карте
  void print_card_info()
  {
    cout<<"\nВаш номер карты: "<< get_card_number() << endl;
    cout << "Ваше имя: " << get_card_name() << endl;
    cout<<"Ваша фамилия: " << get_card_surname() << endl;
    cout<<"Карта действует до " << get_card_date() << endl;
    cout<<"CVV карты: " << get_card_cvv() << endl;
  }
//ввод пароля карты
  string card_password_input()
  {
    int password;
    cout<<"Придумайте и введите 4-ех значный пароль карты(Важно его запомнить!!!)\n";
    do
    {
      cin>>password;
      if(password < 1000 || password > 9999)
      {
        cout<<"Ошибка ввода пароля. Попробуйте еще раз\n";
      }
    }
    while((password < 1000) || (password > 9999));
    set_card_password(to_string(password));
    return to_string(password);
  }
//добавлнеие карты в базу
  void add_card()
  {
      card_number = card_number_input();
      cout<<"Ваш номер карты: "<< card_number << endl;
      cout << "Введите имя: ";
      cin>>card_name;
      set_card_name(card_name);
      cout<<"Введите фамилию: ";
      cin>>card_surname;
      set_card_surname(card_surname);
      card_date = card_date_input();
      card_cvv = card_cvv_input();
      card_password = card_password_input();
      encrypt(card_password);
      card_number.erase(remove(card_number.begin(),card_number.end(),' '),card_number.end());
      set_card_number(card_number);
      ofstream f;
      f.open("regist_card.txt", ios::out);
      f<< "номер карты: " << card_number << " имя: " << card_name << " фамилия: " << card_surname << " дата: " << card_date << " cvv: " << card_cvv << " пароль: " << card_password;
      f.close();

  }

};
//класс кошелька
class Wallet : public Kredit_Card
{
  private:
  int balance;
  public:
  Wallet()
  {
    balance = 0;

  }
  //геттер баланса
  int get_balance()
  {
    return balance;
  }

//Ввод доходов в файл
  void income()
  {
    ofstream f;
    f.open("Doxod.txt", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout<<"\nВВОД ДОХОДОВ!!!\n";
    cout<<"Введите сумму(в рублях): ";
    int income;
    cin>>income;
    cout<<"Выберите категорию для дохода ";
    cout<<"\n1 - Зарплата ";
    cout<<"\n2 - Подарок ";
    cout<<"\n3 - Пенсия ";
    cout<<"\n4 - Другое \n";
    int choice_kategory; cin>>choice_kategory;
    switch(choice_kategory)
      {
        case 1:
          {
            char category[] = "Зарплата";
            f<< "\nСчет увеличен на " << income<< " время записи увеличение баланса: "<< dt << "категория:  "<< category  <<"  "<< income;
          }
        break;
        case 2:
          {
            char category[] = "Подарок";
            f<< "\nСчет увеличен на " << income<< " время записи увеличение баланса: "<< dt << "категория:  "<< category  <<"  "<< income;
          }
        break;
        case 3:
        {
          char category[] = "Пенсия";
          f<< "\nСчет увеличен на " << income<< " время записи увеличение баланса: "<< dt << "категория:  "<< category  <<"  "<< income;

        }
        break;
        case 4:
          {
            char category[] = "Другое";
            f<< "\nСчет увеличен на " << income<< " время записи увеличение баланса: "<< dt << "категория:  "<< category  <<"  "<< income;
          }
      }
    f.close();
    ifstream f1;
    f1.open( "wallet.txt", ios::in );
    f1>>balance;
    f1.close();
    balance+=income;
    ofstream file;
    file.open("wallet.txt", ios::out);
    file << balance << endl;
    file.close();

  }
//вывод доходов из файла
void print_income()
{
  ifstream f;
  f.open("Doxod.txt");
  int col = 0;
  string del;
  char str[25];

  while(!f.eof())
    {
      f>>str;
        cout<<str<<" ";
        col++;
      if(col%15==0)
      {
        f>>del;
        del="";
        cout<<" \n";
      }

    }
  f.close();

}
//вывод баланса кошелька
 void balnce()
  {
     string str_doxod;
     string str_rasxod;
     ifstream filE;
     filE.open("Doxod.txt");
     filE>>str_doxod;
     filE.close();
     ifstream fil;
     fil.open("rasxod.txt");
     fil>>str_rasxod;
     fil.close();
     if((!str_doxod.empty())||(!str_rasxod.empty()))
     {
        ifstream file;
        file.open("wallet.txt", ios::in);
        file >> balance;
        file.close();
        cout<< "Баланс кошелька: "<< balance<<endl;
     }
    else
     {
       balance=0;
       ofstream file;
       file.open("wallet.txt", ios::out);
       file<<balance;
       file.close();
       cout<< "Баланс кошелька: "<< balance<<endl;
     }


  }
//вывод категории, в которую пользователь чаще всего пополял
void kategory_income_col()
{
  map<string,int> mp;
  ifstream f;
  f.open("Doxod.txt", ios::in);
  int col=0;
  int max_kategory = 0;
  string max_kategory_name;
  vector<string> kateg;
  string str;
  string back;
  while(!f.eof())
    {
      col++;
      f>>back;
      if(back=="категория:")
      {
        f>>str;
        mp[str]++;
        kateg.push_back(str);
        if ((mp[str] > max_kategory))
        {
            max_kategory = mp[str];
            max_kategory_name = str;
        }
      }
      }
  cout << "\nЧаще всего пополнения c категории: " << max_kategory_name << " - " << max_kategory << " за все время." << endl;
}
//вывод категории, в которую пользователь больше всего пополнил кошелек
void kategory_income_money()
{
  map<string,int> mp;
  ifstream f;
  f.open("Doxod.txt", ios::in);
  int col=0;
  int max_kategory = 0;
  string max_kategory_money;
  string str;
  string kategor;
  int str_int=0;
  string back;
  while(!f.eof())
    {
      col++;
      f>>back;
      if(back=="категория:")
      {
        f>>kategor;
        f>>str;
        istringstream(str)>>str_int;
        mp[kategor]+=str_int;
        if(mp[kategor]>max_kategory)
        {
          max_kategory=mp[kategor];
          max_kategory_money=kategor;
        }
      }
    }
  cout << "\nБольше всего денег заработанно с категории: " << max_kategory_money << " - " << max_kategory << "р за все время." << endl;
  cout << "Хотите посмотреть все категории ? 1 - да 2 - нет\n";
  int choice;
  cin >> choice;
  if(choice == 1)
  {
    for(auto const& x : mp)
    {
      cout << x.first << " - " << x.second << endl;
    }
  }
  else
  {
    cout << "\n";
  }

  f.close();
}

//ввод расходов
 void expenses( )
 {
     int expense;
     string str;
     int all_dolg=0;
     ifstream f3;
     f3.open("kredit_dolg.txt", ios::in);
     if(f3.is_open())
     {
       while(!f3.eof())
         {
           f3>>str;
           if(str=="Долг:")
           {
             all_dolg+=atoi(str.c_str());
           }
         }
     }
    f3.close();
   cout<<"\nВВОД РАСХОДОВ!!!\n";
   cout<<"Введите сумму(в рублях): ";
    cin>>expense;
    ifstream f1;
    f1.open( "wallet.txt", ios::in );
    f1>>balance;
    f1.close();
    balance-=expense;
    if(balance<0)
    {
     cout<<"\nНедостаточно средств в кошельке. Хотите воспользоваться кредитной картой ?\n1 - да 2 - нет\n";
     int choice; cin>>choice;
     int num_proverka;
     ifstream file_c;
     file_c.open("card_money.txt", ios::in);
     file_c >> num_proverka;
     if(!(num_proverka >= 0))
     {
        cout<<"Вы не вошли в карту!\n";
        cout<<"Кредит не был оформлен!\n";
     }
     else
     {
        if(choice==1)
       {
         int balance = 0;
             int proverka;
             int dolg = 0;
             int credit;
             time_t now = time(0);
             char* dt = ctime(&now);
             tm *gmtm = gmtime(&now);
             dt = asctime(gmtm);

             ifstream f;
               f.open("kredit_dolg.txt", ios::in);
               f>>dolg;
               f.close();

             ifstream f2;
               f2.open("card_money.txt", ios::in);
               f2 >> proverka;
               f2.close();

             ifstream f3;
               f3.open("wallet.txt", ios::in );
               f3>>balance;
               f3.close();
               cout<<"\nВаш баланс: "<<balance<<endl;

              cout<<"\nВведите сумму кредита: ";
              cin>>credit;
              balance+=credit;
              dolg+=credit;
              cout<<"\nТеперь у вас на балансе: "<<balance<<endl;
              cout<<"К вашей задолжности добавленно: "<<credit<<endl;

               ofstream file;
                 file.open("kredit_history.txt", ios::app);
                 file << "\nКредит оформлен "<< dt << "на сумму:  "<< credit << " рублей";
                 file.close();

               ofstream file2;
                 file2.open("kredit_dolg.txt", ios::out);
                 file2 << dolg;
                 file2.close();

               ofstream file3;
                 file3.open("card_money.txt", ios::out);
                 proverka -= credit;
                 file3 << proverka;
                 file3.close();

               ofstream file4;
                 file4.open("wallet.txt", ios::out);
                 file4 << balance;
                 file4.close();

          } //if(choice == 1)
       }//else
     }//if(balance<0)
    else
    {
      ofstream f;
      f.open("rasxod.txt", ios::app);
      time_t now = time(0);
      char* dt = ctime(&now);
      tm *gmtm = gmtime(&now);
      dt = asctime(gmtm);
      cout<<"Выберите категорию для расхода ";
      cout<<"\n1 - Здоровье ";
      cout<<"\n2 - Досуг ";
      cout<<"\n3 - Дом ";
      cout<<"\n4 - Кафе ";
      cout<<"\n5 - Образование ";
      cout<<"\n6 - Подарки ";
      cout<<"\n7 - Продукты ";
      cout<<"\n8 - Спорт ";
      cout<<"\n9 - Транспорт ";
      cout<<"\n10 - Другое \n";
      int choice_kategory; cin>>choice_kategory;
      switch(choice_kategory)
        {
          case 1:
            {
              char category[] = "Здоровье";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;

            }
          break;
          case 2:
            {
              char category[] = "Досуг";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 3:
            {
              char category[] = "Дом";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 4:
            {
              char category[] = "Кафе";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 5:
            {
              char category[] = "Образование";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 6:
            {
              char category[] = "Подарки";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 7:
            {
              char category[] = "Продукты";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 8:
            {
              char category[] = "Спорт";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 9:
            {
              char category[] = "Транспорт";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
          case 10:
            {
              char category[] = "Другое";
              f<< "\nСчет уменьшен на " << expense<< " время записи уменьшения баланса: "<< dt << "категория:  "<< category  <<"  "<< expense;
            }
          break;
        }
    }



 }//expenses
void print_expenses()
{
  ifstream f;
  f.open("rasxod.txt");
  int col = 0;
  char str[256];
  string del;
  while (!f.eof())
    {
      f>>str;
        cout<<str<<" ";
        col++;
      if(col%15==0)
      {
        f>>del;
        del="";
        cout<<" \n";
      }
    }
   f.close();

}
//вывод категории, в которую пользователь чаще всего тратит деньги
void kategory_expenses_col()
{
  map<string,int> mp;
  ifstream f;
  f.open("rasxod.txt", ios::in);
  int col=0;
  int max_kategory = 0;
  string max_kategory_name;
  vector<string> kateg;
  string str;
  string back;
  while(!f.eof())
    {
      col++;
      f>>back;
      if(back=="категория:")
      {
        f>>str;
        mp[str]++;
        kateg.push_back(str);
        if ((mp[str] > max_kategory))
        {
            max_kategory = mp[str];
            max_kategory_name = str;
        }
      }
    }
  cout << "\nЧаще всего тарты на категорию: " << max_kategory_name << " - " << max_kategory << " за все время." << endl;
}
//вывод категории, в которую пользователь больше всего тратит деньги
void kategory_expenses_money()
{
    map<string,int> mp;
    ifstream f;
    f.open("rasxod.txt", ios::in);
    int col=0;
    int max_kategory = 0;
    string max_kategory_money;
    string str;
    string kategor;
    int str_int=0;
    string back;
    while(f >> back)
      {
        col++;
        if(back=="категория:")
        {
          f>>kategor;
          f>>str;
          istringstream(str)>>str_int;
          mp[kategor]+=str_int;

          if(mp[kategor]>max_kategory)
          {
            max_kategory=mp[kategor];
            max_kategory_money=kategor;
          }
        }
      }
    cout << "\nБольше всего денег потрачено на категорию: " << max_kategory_money << " - " << max_kategory<< "р за все время." << endl;
    f.close();
    cout << "Хотите посмотреть все категории ? 1 - да 2 - нет\n";
    int choice;
    cin >> choice;
    if(choice == 1)
    {
      for(auto const& x : mp)
      {
        cout << x.first << " - " << x.second << endl;
      }
    }
    else
    {
      cout << "\n";
    }
  }
};

int main();
//класс пользователя
class Person : public Wallet
{
  private:
    char name[30];
    char password[10];
  public:
//конструктор по умолчанию
    Person()
    {
      strcpy(name,"");
      strcpy(password,"");
    }
//конструктор с параметрами
    Person(string name, string password)
    {
      strcpy(this->name, name.c_str());
      strcpy(this->password, password.c_str());
    }
//проверка пароля
    int check_password_log(string name, string password)
    {
      string n;
      string p;
      int only_n=0;
      int only_p=0;

      ifstream f;
      f.open("regist.txt", ios::in);
      if(f.is_open())
      {
        while(!f.eof())
          {
        f>>n;
        f>>p;
            }
        if(strcmp(n.c_str(), name.c_str())==0)
        {
          only_n++;
          // Расшифровка
              vector<char> word(p.begin(), p.end());
              string alphabet = "abcdefghijklmnopqrstuvwxyz";

              for (int i = 0; i < (int)p.length(); i++) {
                  for (int j = 0; j < (int)alphabet.length(); j++) {
                      if (word[i] == alphabet[j]) {
                          word[i] = alphabet[(j - 3) % 26];
                          break;
                      }
                  }
              }
              string str(word.begin(), word.end());
          if(strcmp(str.c_str(), password.c_str())==0)
          {
            only_p++;
          }
        }

        if((only_n>0)&&(only_p>0))
        {
          return 1;
        }
        if((only_n<1)||(only_p=0))
        {
        return 0;
        }
      }
      return 0;
    }
};

//меню для main()
int menu()
{
  cout<<"\nЧто хотите сделать ?\n";
  cout<<"1. Зарегистрировать кошелёк\n";
  cout<<"2. Зарегистрировать карту\n";
  cout<<"3. Войти в кошелёк или карту\n";
  cout<<"4. Кошелек \n";
  cout<<"5. Карта\n";
  cout<<"6 - RESET ALL\n";
  int choice; cin>>choice;
  return choice;
}

void reset()
{
  ofstream f;
  f.open("regist.txt", ios::out);
  f << "";
  f.close();

  ofstream f2;
  f2.open("regist_card.txt", ios::out);
  f2 << "";
  f2.close();

  ofstream f3;
  f3.open("wallet.txt", ios::out);
  f3 << "";
  f3.close();

  ofstream f4;
  f4.open("rasxod.txt", ios::out);
  f4 << "";
  f4.close();

  ofstream f5;
  f5.open("Doxod.txt", ios::out);
  f5 << "";
  f5.close();

  ofstream f6;
  f6.open("kredit_dolg.txt", ios::out);
  f6 << "";
  f6.close();

  ofstream f7;
  f7.open("card_money.txt", ios::out);
  f7 << "";
  f7.close();

  ofstream f8;
  f8.open("kredit_history.txt", ios::out);
  f8 << "";
  f8.close();
}

//регистрация кошелька
void wallet_registration()
{
  ifstream fiel;
  string str;
  fiel.open("regist.txt", ios::in);
  fiel >> str ;
  fiel.close();
  if(str.empty())
    {
      cout<<"Регистрация нового кошелька\n";
      cout<<"Введите логин: ";
      char login[30]; cin>>login;
      cout<<"Введите пароль: ";
      char password[10]; cin>>password;
      if(login[0]>='a' && login[0]<='z')
      {
        string pass{encrypt(password)};
        strcpy(password,pass.c_str());
        Person p(password,login);
      }
        ofstream f;
        f.open("regist.txt", ios::out);
        if(f.is_open())
        {
          encrypt(password);
          f<<login<<" "<<password;
        }
        f.close();

        ofstream file;
        file.open("wallet.txt", ios::in);
        file << -1;
        file.close();
        cout<<"Кошелек успешно зарегистрирован\n";
      }
    else
    {
      cout<<"Кошелек уже создан\n";
    }
}

//регистрация карты
int kredit_card_registration()
{
  Person p;
  ifstream fil;
  fil.open( "card_money.txt", ios::in);
  string str;
  fil >> str;
  if(str.empty())
  {
    p.add_card();
    int start_balance_card = -1;
    ofstream file;
    file.open("card_money.txt", ios::out);

    if(file.is_open())
    {
      file<<start_balance_card;
    }

    file.close();
    p.print_card_info();
    cout<<endl;
  }
  else
  {
    cout<<"Карта уже зарегистрирована ! \n";
    p.print_card_info();
    return main();
  }
  return 0;
}

//вход в кошелёк
int wallet_enter()
{
  int balance_wallet = -1;
  ifstream f;
  f.open("wallet.txt", ios::in);
  f >> balance_wallet;
  f.close();

  if(balance_wallet == -1)
  {
    cout<<"Вход в кошелёк\n";
    cout<<"Введите логин: ";
    string login; (cin>>login).get();
    cout<<"Введите пароль: ";
    char password[10]; cin>>password;
    Person p(login, password);
    if(p.check_password_log(login,password)==false)
    {
         cout<<"Неверный логин или пароль\n";
         return main();
    }
    else
    {
          balance_wallet++;
          ofstream f;
          f.open("wallet.txt", ios::out);
          f << balance_wallet;
          f.close();
          cout<<"Вход в кошелек выполнен успешно! \n";
    }
  }
  else
  {
    cout<<"Вы уже вошли в кошелек!\n";
    return main();
  }
  return 0;
}

//вход в карту
int card_enter()
{
  ifstream file;
  int proverka=0;
  file.open("card_money.txt", ios::in);
  file>>proverka;
  file.close();

  if(proverka==-1)
  {
    string number_card;
    string date_card;
    string code_card;
    string password_card;
    int count = 0;
    cout<<"Вход в карту\n";
    cout<<"Введите номер карты(без пробелов): ";
    cin>>number_card;
    cout<<"Введите срок истечения карты(гггг/мм): ";
    cin>>date_card;
    cout<<"Введите код(cvv) карты: ";
    cin>>code_card;
    cout<<"Введите пароль от карты: ";
    cin>> password_card;
    string back;
    string str;
    ifstream f;
    f.open("regist_card.txt", ios::in);
    while(!f.eof())
        {
          f>>back;
          if(back == "карты:")
          {
            f>>str;

            if(strcmp(str.c_str(), number_card.c_str()) == 0)
            {
              cout<<"\nНомер карты верный \n";
              count++;
            }
            else
            {
              cout<<"Номер карты не верный\n";
            }
          }

          if(back == "дата:")
          {
            f>>str;
            if(strcmp(str.c_str(), date_card.c_str())==0)
            {
              cout<<"Срок истечения карты верный\n";
              count++;
            }
            else
            {
              cout<<"Срок истечения карты не верный\n";
            }
          }

          if(back == "cvv:")
          {
              f>>str;
              if(strcmp(str.c_str(), code_card.c_str())==0)
              {
                cout<<"Код карты верный\n";
                count++;
              }
              else
              {
                cout<<"Код карты не верный\n";
              }
          }

          if(back == "пароль:")
          {
            f>>str;
            if(strcmp(str.c_str(), password_card.c_str())==0)
            {
              cout<<"Пароль верный\n";
              count++;
            }
            else
            {
              cout<<"Пароль не верный\n";
            }
          }
        }
      if(count == 4)
      {
        cout<<"\nВы успешно вошли в карту\n";
        proverka+=200001;
        ofstream file;
        file.open("card_money.txt", ios::out);
        file<<proverka;
        file.close();
      }
      else
      {
        cout<<"Вы что-то ввели неверно повторите попытку входа \n";
      }

  }//if(proverka==-1))
  else
  {
    cout<<"\nВы не зарегистрировали карту или уже вошли в неё \n";
    return main();
  }
  return 0;
}

//вход в кошелек или карту
int enter()
{
  int choice=0;
  cout<<"Во что хотите войти ?\n";
  cout<<"1 - В кошелек 2 - В карту\n";
  cin>>choice;
  switch(choice)
    {
      //вход в кошелек
      case 1:
      {
        wallet_enter();
      }//case 1:
      return main();
      //вход в карту
      case 2:
        {
          card_enter();
        }//case 2:
      return main();
    }//switch(choice)
  return 0;
}

//функции кошелька
int wallet_functions()
{
  string log;
  string password;

  ifstream f;
  f.open("regist.txt", ios::in);
  while(!f.eof())
    {
      f>>log;
      f>>password;

    }
  Person p(log, decrypt(password));

  int proverka=-1;
  ifstream file;
  file.open("wallet.txt", ios::in);
  file>>proverka;
  file.close();

  if(proverka>=0)
  {
    int choice=0;
    do{
    cout<<"\nЧто хотите сделать ?\n";
    cout<<"1 - Внесение затрат \n";
    cout<<"2 - Внесение доходов\n";
    cout<<"3 - Посмотреть информацию о тратах\n";
    cout<<"4 - Посмотреть информацию о доходах\n";
    cout<<"5 - Вывод баланса\n";
    cout<<"6 - Выход\n";
    cin>>choice;
    switch(choice)
      {
        //внесение затрат
        case 1:
          {
            p.expenses();
          }
        break;
        //внесение доходов
        case 2:
          {
            p.income();
          }
        break;
        //посмотреть информацию о тратах
        case 3:
          {
            p.print_expenses();
            p.kategory_expenses_col();
            p.kategory_expenses_money();
          }
        break;
        //посмотреть информацию о доходах
        case 4:
          {
            p.print_income();
            p.kategory_income_col();
            p.kategory_income_money();
          }
        break;
        //вывод баланса
        case 5:
          {
            p.balnce();
          }
      }
    }while(choice!=6);
  }//if(proverka>=0)
  else
  {
    cout<<"Вы не вошли в кошелек \n";
    return main();
  }
  return 0;
}

//функции карты
int card_functions()
{
  string wal;
    ifstream fil;
    fil.open( "wallet.txt", ios::in);
    fil >> wal;
    fil.close();
    if(!wal.empty())
    {
      int choice_card=0;
      int proverka=-1;
      ifstream file;
      file.open("card_money.txt", ios::in);
      file >> proverka;
      file.close();

      if((proverka<=200000)&&(proverka>=0))
      {
        do{
            cout<<"\nЧто хотите сделать ?\n";
            cout<<"1 - Посмотреть свою задолжность \n";
            cout<<"2 - Посмотреть баланс кредитной карты\n";
            cout<<"3 - Перечислить деньги на счет кошелька\n";
            cout<<"4 - Погасить долг \n";
            cout<<"5 - Посмотреть кредитную историю\n";
            cout<<"6 - Выход\n";
            cin>>choice_card;
            switch(choice_card)
              {
                //посмотреть свою задолжность
                case 1:
                  {
                    ifstream file;
                    file.open("kredit_dolg.txt", ios::in);
                    string proverka;
                    file>>proverka;
                    file.close();
                    if(!proverka.empty())
                    {
                      cout<<"Ваша задолжность: "<<proverka<<endl;
                    }
                    else
                    {
                      cout<<"У вас нет задолжности "<<endl;
                    }

                  }
                break;

                //посмотреть баланс карты
                case 2:
                  {
                    ifstream file;
                    file.open("card_money.txt", ios::in);
                    string proverka;
                    file>>proverka;
                    file.close();
                    if(!proverka.empty())
                    {
                      cout<<"Баланс кредитной карты: "<<proverka<<endl;
                    }
                    else
                    {
                      cout<<"На карте нет денег"<<endl;
                    }
                  }
                break;

                //перечислить деньги на счет кошелька
                case 3:
                  {
                     int balance = 0;
                     int proverka;
                     int dolg = 0;
                     int credit;
                     time_t now = time(0);
                     char* dt = ctime(&now);
                     tm *gmtm = gmtime(&now);
                     dt = asctime(gmtm);

                     ifstream file2;
                     file2.open("kredit_dolg.txt", ios::in);
                     file2>>dolg;
                     file2.close();

                     ifstream f;
                     f.open("card_money.txt", ios::in);
                     f >> proverka;
                     f.close();

                     ifstream file;
                     file.open("wallet.txt", ios::in );
                     file>>balance;
                     file.close();
                    cout<<"\nВаш баланс: "<<balance<<endl;
                     if(proverka!=0)
                     {
                       cout<<"\nВведите сумму кредита: ";
                       cin>>credit;
                       balance+=credit;
                       dolg+=credit;
                       cout<<"\nТеперь у вас на балансе: "<<balance<<endl;
                       cout<<"К вашей задолжности добавленно: "<<credit<<endl;

                       ofstream f2;
                       f2.open("kredit_history.txt", ios::app);
                       f2 << "\nКредит оформлен "<< dt << "на сумму:  "<< credit << " рублей";
                       f2.close();

                       ofstream f;
                       f.open("kredit_dolg.txt", ios::out);
                       f << dolg;
                       f.close();

                       ofstream file;
                       file.open("card_money.txt", ios::out);
                       proverka -= credit;
                       file << proverka;
                       file.close();

                       ofstream f3;
                       f3.open("wallet.txt", ios::out);
                       f3 << balance;
                       f3.close();
                     }
                  }
                break;

                //погасить долг
                case 4:
                  {
                    int dolg;
                    int balance;
                    int kard_money;

                     time_t now = time(0);
                     char* dt = ctime(&now);
                     tm *gmtm = gmtime(&now);
                     dt = asctime(gmtm);

                    ifstream f;
                    f.open("kredit_dolg.txt", ios::in);
                    f >> dolg;
                    f.close();
                    if(dolg>=1)
                    {
                      ifstream file;
                      file.open("card_money.txt", ios::in);
                      file >> kard_money;
                      file.close();

                      ifstream f2;
                      f2.open("wallet.txt", ios::in);
                      f2 >> balance;
                      f2.close();

                      cout<<"Проверьте, чтобы на вашем кошельке хватало средств для погашения долга \n";

                      if(dolg > balance)
                      {
                        cout<<"Недостаточно средств на кашельке для погашения долга \n";
                      }

                      cout<<"Вы хотите погасить весь долг?  ";
                      cout<<"1 - Да  ";
                      cout<<"2 - Нет\n";
                      int choice = 0;
                      cin>>choice;
                      if(choice == 1)
                      {
                         ofstream f2;
                         f2.open("kredit_history.txt", ios::app);
                         f2 << "\nКредит погашен "<< dt << "на сумму:  "<< dolg << " рублей";
                         f2.close();

                        balance -= dolg;
                        kard_money += dolg;
                        dolg = 0;

                        ofstream f;
                        f.open("kredit_dolg.txt", ios::out);
                        f << dolg;
                        f.close();

                        ofstream f5;
                        f5.open("card_money.txt", ios::out);
                        f5 << kard_money;
                        f5.close();

                        ofstream f3;
                        f3.open("wallet.txt", ios::out);
                        f3 << balance;
                        f3.close();
                        cout<<"Весь долг погашен \n";
                      }
                      else
                      {
                        cout<<"Введите сумму погашения долга: ";
                        int minus_dolg;
                        cin>>minus_dolg;

                        ofstream f2;
                        f2.open("kredit_history.txt", ios::app);
                        f2<< "\nКредит погашен "<< dt << "на сумму:  "<< dolg << " рублей";
                        f2.close();

                        balance -= minus_dolg;
                        dolg -= minus_dolg;
                        kard_money += minus_dolg;

                        ofstream f;
                        f.open("kredit_dolg.txt", ios::out);
                        f << dolg;
                        f.close();

                        ofstream f4;
                        f4.open("card_money.txt", ios::out);
                        f4 << kard_money;
                        f4.close();

                        ofstream f3;
                        f3.open("wallet.txt", ios::out);
                        f3 << balance;
                        f3.close();
                       }//else
                    }//if(dolg>=1))
                    else
                    {
                      cout<<"У вас нет задолжности"<<endl;
                    }
                  }//case 4
                break;

                case 5:
                  {
                    string str;
                    ifstream file;
                    file.open("kredit_history.txt", ios::in);
                    file >> str;
                    if(str.empty())
                    {
                      cout<<"У вас нет кредитной истории"<<endl;
                    }
                    while(!file.eof())
                    {
                      if(str == "рублей")
                      {
                        cout<<endl;
                      }
                      file >> str;
                      cout<<str << " ";
                    }
                    file.close();

                  }//case 5:
                }//switch(choice)

            if(choice_card==6)
            {
              return main();
            }

            }while(choice_card!=6);
          }//if(proverka==200001)
          else
          {
            cout<<"Вы не вошли в карту \n";
            return main();
          }
    }//if(wal.empty())
   else
    {
      cout<<"Вы не вошли в кошелёк \n";
      return main();
    }
  return 0;
}

int main()
{

  srand(time(NULL));
  cout<<"\t\t\tФИНАНСЫ\n";
  cout<<"Приложение для управления персональными финансами\n";
  cout<<"В данном приложении вы можете иметь один кошельк и одну кредитную карту\n";
  cout<<"Вам надо всего один раз зарегестрироваться и войти в коешлек или карту\n";
  cout<<"Также реализованны функции:\n";
  cout<<"Регистрация кошелька.\n";
  cout<<"Регистрация карты\n";
  cout<<"Вход в кошелек или карту\n";
  cout<<"Внесение затрат и доходов, каждая из которых относится к определенной категории\n";
  cout<<"Получение информации о тратах и доходов\n";
  cout<<"Вывод текущего баланса кошелька\n";
  cout<<"Возможность оформления кредита\n";
  cout<<"Вывод текущей задолжности по кредиту\n";
  cout<<"Просмотр баланса кредитной карты\n";
  cout<<"Возможность погашения долга\n";
  cout<<"Просмотр кредитной истрии\n\n";
  int choice = menu();
  switch(choice)
    {
      // Регистрация кошелька
      case 1:
        {
          wallet_registration();
        }
        return main();
        break;

      //регистрация карты
      case 2:
        {
          kredit_card_registration();
        }
        return main();
        break;

      //вход в кошелек или карту
      case 3:
        {
          enter();
        }//case 3:
        return main();
        break;

      //функции кошелька
      case 4:
        {
          wallet_functions();
        }//case 4:
      return main();
      break;

      //функции карты
      case 5:
        {
         card_functions();
        }//case 5:
      return main();
      //reset_all
      case 6:
        {
          reset();
          return main();
        }

        }//switch(choice)

   }//main
