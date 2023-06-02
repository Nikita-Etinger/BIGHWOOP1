// OOPWH3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "OOPWH3.h"
using namespace std;
#define random(a,b) a + rand() % (b - a + 1)
const string defaultNames[10] = {
    "Александра",
    "Максим",
    "Елизавета",
    "Даниил",
    "Анна",
    "Артем",
    "София",
    "Иван",
    "Виктория",
    "Никита"
};

const string defaultSurName[10] = {
    "Иванов",
    "Смирнов",
    "Кузнецов",
    "Попов",
    "Соколов",
    "Лебедев",
    "Козлов",
    "Новиков",
    "Морозов",
    "Петров"
};

const string defaultPatronymics[10] = {
    "Александровна",
    "Максимович",
    "Елизаветовна",
    "Даниилович",
    "Андреевна",
    "Артемович",
    "Сергеевна",
    "Ивановна",
    "Викторовна",
    "Никитич"
};
/*

Создайте приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса. Наполните класс переменными-членами, функциями-членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, искать абонентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.


*/
class Abonent {
private:
    string* fios=new string[3]{""};
    string homeNum="";
    string workNum="";
    string selfNum="";
    string info="";
    static int count;


public:
    Abonent(){
        
    }
    Abonent(const Abonent& other) {
        
        fios = new string[3];
        fios[0] = other.fios[0];
        fios[1] = other.fios[1];
        fios[2] = other.fios[2];
        homeNum = other.homeNum;
        workNum = other.workNum;
        selfNum = other.selfNum;
        info = other.info;
    }
    Abonent& operator=(const Abonent& other) {
        
        if (this != &other) {
            delete[] fios;
            fios = new string[3];
            fios[0] = other.fios[0];
            fios[1] = other.fios[1];
            fios[2] = other.fios[2];
            homeNum = other.homeNum;
            workNum = other.workNum;
            selfNum = other.selfNum;
            info = other.info;
            
        }
        return *this;
    }
    Abonent(string fio) {
        for (int i = 0; i < fio.length(); i++) {
            if (fio[i] == ' ') {
                i++;
                for (; i < fio.length(); i++) {
                    if (fio[i] == ' ') {
                        i++;
                        for (; i < fio.length(); i++) {
                            fios[2] += fio[i];
                        }
                        break;
                    }
                    fios[1] += fio[i];
                }
                break;
            }
            fios[0] += fio[i];
        }

    }



    void showFio() {
        cout << fios[0] << " " << fios[1] << " " << fios[2] << endl;
    }
    void showAllData() {
        cout << fios[0] << " " << fios[1] << " " << fios[2] << endl;
        cout << "homeNum: " << " " << homeNum << "| workNum: " << workNum << "| selfNum: " << selfNum << endl;
        cout << info << endl;
    }
    string getFios() {
        return fios[0] + " " + fios[1] + " " + fios[2];
    }
    string getHomeNum() {
        return homeNum;
    }
    string getWorkNum() {
        return workNum;
    }
    string getSelfNum() {
        return selfNum;
    }
    string getInfo() {
        return info;
    }
    void setHomeNum(string homeNum) {
        this->homeNum = homeNum;
    }
    void setWorkNum(string workNum) {
        this->workNum = workNum;
    }
    void setSelfNum(string selfNum) {
        this->selfNum = selfNum;
    }
    void setInfo(string info) {
        this->info = info;
    }
    ~Abonent() {
        count--;
        //cout << "Abonent " << getFios() << " delited" << endl;
        delete[] fios;
    }
    string getName() {
        return fios[0];
    }
    string getSurName() {
        return fios[1];
    }
    string getPatronymics() {
        return fios[2];
    }

};
int Abonent::count = 0;

//поиск по имени, фамилии, номеру телефонов 
//добавление абонентов
//удаление абонентов
//импорт экспорт
class NumBook {
private:
    Abonent* abonents = nullptr;
    int counter = 0;
    int searchAbonentNumbers(string number) {
        int index=-1;
        for (int i = 0; i < counter; i++) {
            if (number == abonents[i].getSelfNum()) {
                index = i;
                break;
            }
            if (number == abonents[i].getWorkNum()) {
                index = i;
                break;
            }
            if (number == abonents[i].getHomeNum()) {
                index = i;
                break;
            }
        }
        return index;
    }
public:
    NumBook() {

    }
    ~NumBook() {
        delete[]abonents;
    }
    void showAllNames() {
        for (int i = 0; i < counter; i++) {
            abonents[i].showFio();
        }
    }
    void showAllData() {
        for (int i = 0; i < counter; i++) {
            abonents[i].showAllData();
        }
    }
    void addAbonent(Abonent& newAbonent) {
        Abonent* buf = new Abonent[counter + 1];
        for (int i = 0; i < counter; i++) {
            buf[i] = abonents[i];
        }
        buf[counter] = newAbonent;
        counter++;
        delete[]abonents;
        abonents = buf;

    }
    void searchAbonentName(string name) {
        for (int i = 0; i < counter; i++) {
            if (name == abonents[i].getName()) {
                abonents[i].getInfo();
            }
        }
    }
    void searchSurName(string surName) {
        for (int i = 0; i < counter; i++) {
            if (surName == abonents[i].getSurName()) {
                abonents[i].getInfo();
            }
        }
    }
    void searchAbonentPatronymics(string patronymics) {
        for (int i = 0; i < counter; i++) {
            if (patronymics == abonents[i].getPatronymics()) {
                abonents[i].getInfo();
            }
        }
    }
    void searchAbonentNumber(string number) {
        abonents[searchAbonentNumbers(number)].showAllData();

    }
    void deleteAbonentNumber(string number) {
        int index = searchAbonentNumbers(number);
        if (index != -1) {
            Abonent* buf = new Abonent[counter - 1];
            for (int i = 0; i < index; i++) {
                buf[i] = abonents[i];
            }
            for (int i = index + 1; i < counter; i++) {
                buf[i - 1] = abonents[i];
            }
            counter--;
            delete[] abonents;
            abonents = buf;
        }
    }
    void importData(string path) {

        ifstream out;
        out.open(path);
        if (out.is_open()) {
            string str;
            string bufer = "";
            while (getline(out, str)) {
                string fio="";
                string homeNum = "";
                string workNum = "";
                string selfNum = "";
                string info = "";
                
                for (int i = 0; i < str.length();i++) {
                    
                    if (str[i] == '|') {
                        i++;
                        for (; i < str.length(); i++) {
                            
                            if (str[i] == '|') {
                                i++;
                                for (; i < str.length(); i++) {
                                    
                                    if (str[i] == '|') {
                                        i++;
                                        for (; i < str.length(); i++) {
                                            
                                            if (str[i] == '|') {
                                                i++;
                                                for (; i < str.length()-1; i++) {
                                                    
                                                    if (str[i] == '|') {
                                                        break;
                                                    }
                                                    info += str[i];
                                                }
                                                break;
                                            }
                                            selfNum += str[i];
                                        }
                                        break;
                                    }
                                    workNum += str[i];
                                }
                                break;
                            }
                            homeNum += str[i];
                        }
                        break;
                    }
                    fio += str[i];
                }
                Abonent newAbonent(fio);
                newAbonent.setHomeNum(homeNum);
                newAbonent.setSelfNum(selfNum);
                newAbonent.setWorkNum(workNum);
                newAbonent.setInfo(info);
                addAbonent(newAbonent);
            }
            out.close();
        }
    }
    void exportData(string path) {
        ofstream in;
        in.open(path);
        if (in.is_open()) {
            for (int i = 0; i < counter; i++) {
                in << abonents[i].getFios() << "|"
                    << abonents[i].getHomeNum() << "|"
                    << abonents[i].getWorkNum() << "|"
                    << abonents[i].getSelfNum() << "|"
                    << abonents[i].getInfo() << "|" << endl;
            }
            in.close();
        }
    }





};
string numberGenerator() {
    string newNumber = "";
    for (int i = 0; i < 4; i++) {
        newNumber += to_string(random(0, 9));
    }
    return newNumber;


}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    NumBook nb;
    Abonent newAbonent;
    bool generateData = 0;
    if (generateData == 1) {
        for (int i = 0; i < 10; i++) {
            string name = defaultNames[random(0, 9)];
            string surname = defaultSurName[random(0, 9)];
            string patronymic = defaultPatronymics[random(0, 9)];
            Abonent newAbonent(name + " " + surname + " " + patronymic);
            newAbonent.setHomeNum(numberGenerator());
            newAbonent.setSelfNum(numberGenerator());
            newAbonent.setWorkNum(numberGenerator());
            //cout << "Abonent " << newAbonent.getFios() << " created" << endl;
            nb.addAbonent(newAbonent);
        }
    }

    while (1) {
        int x = 0;
        cout << "1-search from number" << " 2-delete from number"<<" 3-show all"<<" 4-export data"<<" 5-import data" << endl;
        cout << "Enter variation" << endl;
        cin >> x;
        string str;
        switch (x) {
        case 1:
            system("cls");
            cout << "Enter number" << endl;
            cin >> str;
            nb.searchAbonentNumber(str);
            break;
        case 2:
            system("cls");
            cout << "Enter number" << endl;
            cin >> str;
            nb.deleteAbonentNumber(str);
            break;
        case 3:
            system("cls");
            cout << "Enter number" << endl;
            cin >> str;
            nb.showAllData();
            break;
        case 4:
            system("cls");
            nb.exportData("Export.txt");
            cout << "File export complite"<<endl;
            break;
        case 5:
            system("cls");
            nb.importData("Export.txt");
            cout << "File import complite" << endl;
            break;
        }



    }
}

