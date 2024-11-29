//Знайти шість найменших елементів масиву, користуючись функцією
//сортування елементів
//Переробити з масивами, сортування


#include <iostream>

using namespace std;

int numLength(int num) {
    int length = 1;
    while (num >= 10) {
        num /= 10;
        length++;
    }
    return length;
};

class Address {
private:
    unique_ptr<char[]> city, street, bNum;

    int* defCount() {
        static int defaultnum = 0;

        return &defaultnum;
    }

    int* defCount(int i) {
        *defCount() += i;
        return defCount();
    }

public:

    Address() {
        int nLen, cSize, sSize, bNSize;

        nLen = numLength(*defCount());
        cSize = strlen("City ") + nLen + 1;
        sSize = strlen("Street ") + nLen + 1;
        bNSize = nLen + 1;

        city = make_unique<char[]>(cSize);
        street = make_unique<char[]>(sSize);
        bNum = make_unique<char[]>(bNSize);

        sprintf_s(city.get(), cSize, "%s%d", "City ", *defCount());
        sprintf_s(street.get(), sSize, "%s%d", "Street ", *defCount());
        sprintf_s(bNum.get(), bNSize, "%d", *defCount());

        defCount(1);
    }

    Address(const char* cityName, const char* streetName, const char* buildingNum) {
        int cSize, sSize, bNSize;

        cSize = strlen(cityName) + 1;
        sSize = strlen(streetName) + 1;
        bNSize = strlen(streetName) + 1;

        city = make_unique<char[]>(cSize);
        street = make_unique<char[]>(sSize);
        bNum = make_unique<char[]>(bNSize);

        strcpy_s(city.get(), cSize, cityName);
        strcpy_s(street.get(), sSize, streetName);
        strcpy_s(bNum.get(), bNSize, buildingNum);
    }

    Address(const Address& other) {
        int cSize, sSize, bNSize;

        cSize = strlen(other.city.get()) + 1;
        sSize = strlen(other.street.get()) + 1;
        bNSize = strlen(other.bNum.get()) + 1;

        city = make_unique<char[]>(cSize);
        street = make_unique<char[]>(sSize);
        bNum = make_unique<char[]>(bNSize);

        strcpy_s(city.get(), cSize, other.city.get());
        strcpy_s(street.get(), sSize, other.street.get());
        strcpy_s(bNum.get(), bNSize, other.bNum.get());
    }

    ~Address() {
        cout << "Address deconstructor" << "\n";
    }

    operator const char* () const {
        return city.get();
    }

    Address& operator=(const Address& other) {
        if (this != &other) {
            int cSize, sSize, bNSize;

            cSize = strlen(other.city.get()) + 1;
            sSize = strlen(other.street.get()) + 1;
            bNSize = strlen(other.bNum.get()) + 1;

            city = make_unique<char[]>(cSize);
            street = make_unique<char[]>(sSize);
            bNum = make_unique<char[]>(bNSize);

            strcpy_s(city.get(), cSize, other.city.get());
            strcpy_s(street.get(), sSize, other.street.get());
            strcpy_s(bNum.get(), bNSize, other.bNum.get());
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Address& a) {
        os << "City: " << a.city.get() << ", Street: " << a.street.get() << ", Building number: " << a.bNum.get() << "\n";
        return os;
    }

    void printAddress() const {
        cout << "City: " << city.get() << ", Street: " << street.get() << ", Building number: " << bNum.get() << endl;
    }
};

class Train {
private:
    int num, capacity, occupied;
    bool isExpress;

    int* defCount() {
        static int defaultnum = 0;

        return &defaultnum;
    }

    int* defCount(int i) {
        *defCount() += i;
        return defCount();
    }

public:
    Train() {
        num = *defCount();
        capacity = 40;
        occupied = 0;
        isExpress = false;

        defCount(1);
    }

    Train(int numParam, int capacityParam, int occupiedParam, bool isExpressParam) {
        if (occupiedParam > capacityParam) {
            occupiedParam = capacityParam;
        }
        num = numParam;
        capacity = capacityParam;
        occupied = occupiedParam;
        isExpress = isExpressParam;
    }

    Train(const Train& other) {
        num = other.num;
        capacity = other.capacity;
        occupied = other.occupied;
        isExpress = other.isExpress;
    }

    ~Train() {
        cout << "This is a deconstructor, lol" << '\n';
    }

    Train& operator=(const Train& other) {
        if (this != &other) {
            num = other.num;
            capacity = other.capacity;
            occupied = other.occupied;
            isExpress = other.isExpress;
        }
        return *this;
    }

    operator int() const {
        return num;
    }

    friend ostream& operator<<(ostream& os, const Train& t) {
        os << "Train number: " << t.num << " Maximum capacity: " << t.capacity << " Seats occupied: " << t.occupied << " Express: " << (t.isExpress ? "Yes" : "No") << "\n";
        return os;
    }

    int addPsgr() {
        if (capacity > occupied) {
            occupied++;
            return 1;
        }
        else {
            return 0;
        }
    }

    int emptySeats() const {
        return capacity - occupied;
    }
};

class TrainStation {
private: 
    unique_ptr<char[]> name;
    unique_ptr<Address> address;
    unique_ptr<Train[]> trains;
    int tSize;

    int* defCount() {
        static int defaultnum = 0;

        return &defaultnum;
    }

    int* defCount(int i) {
        *defCount() += i;
        return defCount();
    }

public:
    TrainStation() {
        int dLen = numLength(*defCount());
        int nSize = strlen("Station " + dLen);
        tSize = 0;

        address = make_unique<Address>();
        name = make_unique<char[]>(nSize);
        trains = make_unique<Train[]>(tSize);

        sprintf_s(name.get(), nSize, "%s%d", "Station ", *defCount());

        defCount(1);
    }

    TrainStation(const char* nameParam, Address& addParam, Train* trainsParam,size_t trainsSize) {
        tSize = trainsSize;
        int nSize = strlen(nameParam) + 1;

        name = make_unique<char[]>(nSize);

        strcpy_s(name.get(), nSize, nameParam);
        
        address = make_unique<Address>(addParam);

        trains = make_unique<Train[]>(trainsSize);

        for (size_t i = 0; i < trainsSize; i++) {
            trains[i] = trainsParam[i];
        }

    }

    TrainStation(const TrainStation& other) {
        tSize = other.tSize;

        int nSize = 0;
        while (other.name[nSize] != '/0') nSize++;

        name = make_unique<char[]>(nSize);

        address = make_unique<Address>(*other.address);

        trains = make_unique<Train[]>(tSize);

        for (int i = 0; i < tSize; i++) {
            trains[i] = other.trains[i];
        }
    }

    TrainStation& operator=(const TrainStation& other) {
        if (this != &other) {

        }
        return *this;
    }
};


int main()
{
    Address address1;
    address1.printAddress();
    Address address2;
    address2.printAddress();
    Address address3;
    address3.printAddress();

    Address properAddress("Lviv", "Linkolna str.", "15a");
    properAddress.printAddress();

    address2 = properAddress;
    address2.printAddress();

    cout << address2;

    return 0;
}

