//Çíàéòè ø³ñòü íàéìåíøèõ åëåìåíò³â ìàñèâó, êîðèñòóþ÷èñü ôóíêö³ºþ
//ñîðòóâàííÿ åëåìåíò³â
//Ïåðåðîáèòè ç ìàñèâàìè, ñîðòóâàííÿ


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

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
    string city, street, bNum;

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

        city = "City " + to_string(*defCount());
        street = "Street " + to_string(*defCount());
        bNum = "Building " + to_string(*defCount());

        defCount(1);
    }

    Address(const string cityParam, const string streetParam, const string bParam) {
        city = cityParam;
        street = streetParam;
        bNum = bParam;
    }

    Address(const Address& other) {
        city = other.city;
        street = other.street;
        bNum = other.bNum;
    }

    ~Address() {
        cout << "Address deconstructor" << "\n";
    }

    operator string () const {
        return city;
    }

    Address& operator=(const Address& other) {
        if (this != &other) {
            city = other.city;
            street = other.street;
            bNum = other.bNum;
        }
        return *this;
    }

    friend istream& operator>>(istream& input, Address& a) {
        cout << "Enter city: ";
        input >> a.city;
        cout << "Enter street: ";
        input >> a.street;
        cout << "Enter building number: ";
        input >> a.bNum;

        return input;
    }

    friend ostream& operator<<(ostream& os, const Address& a) {
        os << "City: " << a.city << ", Street: " << a.street << ", Building number: " << a.bNum << "\n";
        return os;
    }

    void printAddress() const {
        cout << "City: " << city << ", Street: " << street << ", Building number: " << bNum << endl;
    }
};

template <typename T>
class DynamicArray {
protected:
    vector<T> array;

public:
    DynamicArray(int size) {
        array.resize(size);
    }

    virtual void input() = 0;
    virtual void output() = 0;
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

    friend istream& operator>>(istream& input, Train& t) {
        string temp;
        cout << "Enter train number: ";
        input >> temp;
        try {
            int num = stoi(temp);
            cout << "The number is: " << num << endl;
            t.num = num;
        }
        catch (const invalid_argument& e) {
            cout << "Invalid train number input: not a number!" << endl;
        }
        catch (const out_of_range& e) {
            cout << "Number is out of range!" << endl;
        }

        cout << "Enter train capacity: ";
        input >> temp;
        try {
            int num = stoi(temp);
            cout << "The number is: " << num << endl;
            t.capacity = num;
        }
        catch (const invalid_argument& e) {
            cout << "Invalid capacity input: not a number!" << endl;
        }
        catch (const out_of_range& e) {
            cout << "Number is out of range!" << endl;
        }

        cout << "Enter number of places occupied: ";
        input >> temp;
        try {
            int num = stoi(temp);
            cout << "The number is: " << num << endl;
            if (num > t.capacity) {
                cout << "Number of occupied places can't be more than train's capacity!";
            }
            t.occupied = num;
        }
        catch (const invalid_argument& e) {
            cout << "Invalid occupied input: not a number!" << endl;
        }
        catch (const out_of_range& e) {
            cout << "Number is out of range!" << endl;
        }

        cout << "Enter if express (true/false): ";
        input >> temp;
        if (temp == "true") {
            t.isExpress == true;
        }
        else if (temp == "false") {
            t.isExpress == false;
        }
        else {
            cout << "Invalid input!";
        }
        return input;
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

    int getNum() const {
        return num;
    }

    int getOcc() const {
        return occupied;
    }

    int getCap() const {
        return capacity;
    }
};

class TrainArray : public DynamicArray<Train> {
public:
    TrainArray(int size) : DynamicArray<Train>(size) {}

    void input() override {
        cout << "Input data for " << array.size() << " trains: \n";
        for (int i = 0; i < array.size(); ++i) {
            cout << "Input data for train " << i << " \n";
            cin >> array[i];
        }
    }

    void output() override {
        cout << "Train details: \n";
        for (const auto& train : array) {
            cout << train;
        }
    }
};

class TrainStation {
private:
    string name;
    unique_ptr<Address> address;
    vector<Train> trains;

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

        address = make_unique<Address>();
        name = "Station " + to_string(*defCount());
        trains = {};

        defCount(1);
    }

    TrainStation(const char* nameParam, Address& addParam, vector<Train>& trainsParam) {
        int nSize = strlen(nameParam) + 1;

        name = nameParam;

        if (isUnique(trainsParam)) {
            trains = trainsParam;
        }
        else {
            cout << "Trains must have unique numbers! " << endl;
        }

        address = make_unique<Address>(addParam);
    }

    TrainStation(const TrainStation& other) {

        int nSize = 0;
        while (other.name[nSize] != '/0') nSize++;

        name = other.name;
        address = make_unique<Address>(*other.address);
        trains = other.trains;
    }

    ~TrainStation() {
        cout << "Train deconstructor" << "\n";
    }

    TrainStation& operator=(const TrainStation& other) {
        if (this != &other) {

        }
        return *this;
    }

    bool isUnique(vector<Train>& trainsParam) {
        unordered_set<int> numbers;

        for (const Train& t : trainsParam) {
            if (numbers.find(t.getNum()) != numbers.end()) {
                numbers.insert(t.getNum());
            }
            else {
                return false;
            }
        }
        return true;
    }

    void getAddress() {
        address->printAddress();
        return;
    }

    int getAvgOccupied() {
        if (trains.size() == 0) {
            cout << "There are no trains! " << endl;
            return -1;
        }
        int total = trains[0].getOcc();
        int amt = 1;
        for (const Train& t : trains) {
            total += t.getOcc();
            amt++;
        }
        return total / amt;
    }

    void addTrain(Train& newT) {
        for (const Train& t : trains) {
            if (newT.getNum() == t.getNum()) {
                cout << "This train number already exists in the Train station!" << endl;
                return;
            }
        }
        trains.push_back(newT);
        cout << "Train number " << newT.getNum() << " is added and open for boarding! " << endl;
        return;
    }

    void boardTrain(const int tNum) {
        auto it = std::find_if(trains.begin(), trains.end(), [tNum](const Train& t) {
            return t.getNum() == tNum;
            });

        if (it == trains.end()) {
            cout << "No train with such number is present! " << endl;
            return;
        }

        it->addPsgr();
        return;
    }

    void deleteTrain(const int tNum) {
        auto it = std::find_if(trains.begin(), trains.end(), [tNum](const Train& t) {
            return t.getNum() == tNum;
            });

        if (it == trains.end()) {
            cout << "No train with such number is present! " << endl;
            return;
        }

        trains.erase(it);
        cout << "Train number " << tNum << " was successfuly deleted!" << endl;
        return;
    }

    int getEmpty() {
        if (trains.size() == 0) {
            cout << "No trains on this station." << endl;
        }
        int empty{};
        for (const Train& t : trains) {
            empty += t.emptySeats();
        }
        return empty;
    }

    int getFullPrcnt() {
        if (trains.size() == 0) {
            cout << "No trains on this station." << endl;
        }
        int total{};
        for (const Train& t : trains) {
            if (t.getOcc() == t.getCap()) {
                total++;
            }
        }
        return total / trains.size() * 100;
    }
};


int main()
{
    Address properAddress("Lviv", "Linkolna str.", "15a");
    properAddress.printAddress();

    Train t1(1, 50, 0, false);
    Train t2(2, 50, 50, false);
    Train t3(3, 50, 0, true);

    vector<Train> trains = { t1, t2, t3 };

    TrainStation s1("City 17", properAddress, trains);

    s1.getAvgOccupied();
    s1.getAddress();
    s1.boardTrain(2);

    TrainArray trainArray(3);

    trainArray.input();

    return 0;
}

