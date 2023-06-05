// OOPWH3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <Windows.h>
using namespace std;
#define random(a,b) a + rand() % (b - a + 1)
const string defaultNames[10] = {
    "Oliver",
    "Emma",
    "Liam",
    "Ava",
    "Noah",
    "Sophia",
    "William",
    "Isabella",
    "James",
    "Mia"
};

const string defaultSurName[10] = {
    "Smith",
    "Johnson",
    "Brown",
    "Taylor",
    "Miller",
    "Wilson",
    "Moore",
    "Anderson",
    "Jackson",
    "Clark"
};

const string defaultPatronymics[10] = {
    "Alexander",
    "David",
    "Michael",
    "Benjamin",
    "William",
    "Nicholas",
    "Christopher",
    "Daniel",
    "Matthew",
    "Anthony"
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
    string* fios = nullptr;
    string homeNum="";
    string workNum="";
    string selfNum="";
    string info="";
    //static int count;//не используется


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

    Abonent(string* fio) {
        delete[] fios;
        fios = fio;
    }
    //Abonent(string fio) {
    //    fios = new string[3];
    //    for (int i = 0; i < fio.length(); i++) {
    //        if (fio[i] == ' ') {
    //            i++;
    //            for (; i < fio.length(); i++) {
    //                if (fio[i] == ' ') {
    //                    i++;
    //                    for (; i < fio.length(); i++) {
    //                        fios[2] += fio[i];
    //                    }
    //                    break;
    //                }
    //                fios[1] += fio[i];
    //            }
    //            break;
    //        }
    //        fios[0] += fio[i];
    //    }
    //}


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
        //count--;
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
//int Abonent::count = 0;

//поиск по фио, номеру телефонов 
//добавление абонентов
//удаление абонентов
//импорт экспорт
class NumBook {
private:
    Abonent* abonents = nullptr;
    int counter = 0;
    inline int searchAbonentNumbers(string number) {
        int index=-1;
        for (int i = 0; i < counter; i++) {
            if (number == abonents[i].getSelfNum()) {
                return i;
            }
            if (number == abonents[i].getWorkNum()) {
                return i;
            }
            if (number == abonents[i].getHomeNum()) {
                return i;
            }
        }
        cout << "Not found" << endl << endl;
        return -1;
    }
    inline int searchAbonentFios(string* fio) {
        
        for (int i = 0; i < counter; i++) {
            if (abonents[i].getName() == fio[0] && abonents[i].getSurName() == fio[1] && abonents[i].getPatronymics() == fio[2]) {
                /*abonents[i].showAllData();*/
                return i;
            }
        }
        
        return -1;
    }
    
    inline void deleteAbonent(int index) {
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
    string* scanDublicate(string* fio) {
        int index = searchAbonentFios(fio);
        if (index == -1) {//дубликат не найден
            return fio;
        }
        return nullptr;
    }
    inline string* stringToStrings(string fio) {
        string* buf = new string[3];
        for (int i = 0; i < fio.length(); i++) {
            if (fio[i] == ' ') {
                i++;
                for (; i < fio.length(); i++) {
                    if (fio[i] == ' ') {
                        i++;
                        for (; i < fio.length(); i++) {
                            buf[2] += fio[i];
                        }
                        break;
                    }
                    buf[1] += fio[i];
                }
                break;
            }
            buf[0] += fio[i];
        }
        return buf;


    }
    bool searchAbonentNumber(string number) {
        int index= searchAbonentNumbers(number);
        if (index != -1) {
            abonents[index].showAllData();
            return 1;
        }
        return 0;
    }
    bool searchAbonentFio(string fio) {
        string* buf= stringToStrings(fio);
        int index = searchAbonentFios(buf);
        if (index != -1) {
            abonents[index].showAllData();
            return 1;
        }
        return 0;
        delete[] buf;
    }

    bool deleteAbonentNumber(string number) {
        int index = searchAbonentNumbers(number);
        if (index != -1) {
            deleteAbonent(index);
            return 1;
        }
        return 0;
    }

    bool deleteAbonentFio(string fio) {
        string* buf = stringToStrings(fio);
        int index = searchAbonentFios(buf);
        delete[]buf;
        if (index != -1) {
            deleteAbonent(index);
            return 1;
        }
        return 0;
    }

    void importData(string path) {

        ifstream out;
        out.open(path);
        if (out.is_open()) {
            string str;
            string bufer = "";
            while (getline(out, str)) {
                string fio = "";
                string homeNum = "";
                string workNum = "";
                string selfNum = "";
                string info = "";

                for (int i = 0; i < str.length(); i++) {

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
                                                for (; i < str.length() - 1; i++) {

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
                Abonent newAbonent(stringToStrings(fio));
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
    inline int getCounter() {
        return counter;
    }

    void addAbonent(const Abonent& newAbonent) {
        Abonent* buf = new Abonent[counter + 1];
        for (int i = 0; i < counter; i++) {
            buf[i] = abonents[i];
        }
        buf[counter] = newAbonent;
        counter++;
        delete[]abonents;
        abonents = buf;

    }
    void addAbonent(string str) {
        string* bufFio = scanDublicate(stringToStrings(str));
        if (bufFio != nullptr) {
            cout << " dublicate"<<endl;
            Abonent* buf = new Abonent[counter + 1];
            for (int i = 0; i < counter; i++) {
                buf[i] = abonents[i];
            }
            buf[counter] = Abonent(bufFio);
            counter++;
            delete[]abonents;
            abonents = buf;
            //cout<<endl << "Add: " << str;
        }
        else {
            delete[]bufFio;
            cout << "Is dublicate"<<endl<<endl;
        }

    }

    void deleteAllAbonents() {
        for (int i = counter-1; i>=0; i--) {
            cout << abonents[i].getFios();
            cout << " deleted" <<endl;
            deleteAbonent(i);
        }
    }

};
inline bool scanFromEmpty(NumBook& nb) {
    if (nb.getCounter() != 0) return 1;
    else return 0;
}
inline string numberGenerator() {
    string newNumber = "";
    for (int i = 0; i < 10; i++) {
        newNumber += to_string(random(0, 9));
    }
    return newNumber;
}
void abonentGenerator(NumBook& nb, int count) {
    for (int i = 0; i < count; i++) {
        string name = defaultNames[random(0, 9)];
        string surname = defaultSurName[random(0, 9)];
        string patronymic = defaultPatronymics[random(0, 9)];
        

        string* buf = nb.stringToStrings(name + " " + surname + " " + patronymic);
        if (nullptr == nb.scanDublicate(buf)) {
            delete[]buf;
            i--;
            continue;
        };
        Abonent newAbonent(buf);
        newAbonent.setHomeNum(numberGenerator());
        newAbonent.setSelfNum(numberGenerator());
        newAbonent.setWorkNum(numberGenerator());
        //cout << "Abonent " << newAbonent.getFios() << " created" << endl;
        nb.addAbonent(newAbonent);
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    NumBook nb;
    while (1) {//тест утечки памяти
        abonentGenerator(nb, random(5,50));
        //nb.importData("Export.txt");
        //nb.exportData("Export.txt");
        
        nb.deleteAllAbonents();

    }
    while (0) {
        int x = 0;
        cout<<endl<<endl << "1-search from number"<<'\n'<<"2-search from Fio" << '\n'  << "3-show all" << '\n' << "4-export data" << '\n' << "5-import data"<<'\n'<<"6-generate abonent" << '\n' << "7-add abonent" << '\n' << "8-delete from fio" << endl;
        cout << "Enter variation" << endl;
        cin >> x;
        string str;
        switch (x) {
        case 1:
            system("cls");
            if (scanFromEmpty(nb)) {
                cout << "Enter number" << endl;
                cin >> str;
                nb.searchAbonentNumber(str);
            }
            else cout << "NumBook is empty" << endl << endl;
            break;
        case 2:
            system("cls");
            if (scanFromEmpty(nb)) {
            cout << "Enter name" << endl;
            cin.ignore();
            getline(cin, str);
            nb.searchAbonentFio(str);
            }
            else cout << "NumBook is empty" << endl << endl;
            break;
        case 3:
            system("cls");
            if (scanFromEmpty(nb)) {
            nb.showAllData();
            }
            else cout << "NumBook is empty" << endl << endl;
            break;
        case 4:
            system("cls");
            if (scanFromEmpty(nb)) {
            nb.exportData("Export.txt");
            cout << "File export complite"<<endl;
            }
            else cout << "NumBook is empty" << endl << endl;
            break;
        case 5:
            system("cls");
            nb.importData("Export.txt");
            cout << "File import complite" << endl;
            break;
        case 6:
            system("cls");
            cout << "How much?" << endl;
            cin >> x;
            abonentGenerator(nb, x);
            cout << "Generate complite" << endl;
            break;
        case 7:
            system("cls");
            cout << "Enter new abonent fio" << endl;
            cin.ignore();
            getline(cin,str);
            nb.addAbonent(str);
            //getchar();
            break;
        case 8:
            system("cls");
            cout << "Enter abonent fio" << endl;
            cin.ignore();
            getline(cin, str);
            if (nb.deleteAbonentFio(str) == 0) {
                cout << "Abonent not found" << endl;
            }
            else cout << str << " delited" << endl;
            break;
        default:
            cout << "Unclorect num. Please try again" << endl;
            break;
        }



    }
}

