//14. Сформувати документ, в якому зберігається інформація про
//асортимент продовольчих товарів в магазині : назва магазину, код товару,
//кількість цього товару, ціна за кілограм.Відсортувати магазини для оптової
//закупки заданого товару згідно його ціни
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int n = 3;
struct Product {
    string productName;
    int amount;
    int cost;
};

struct Shop {
    string shopName;
    vector <Product> products;
};

string priceSort(vector <Shop> shopVector, string product) {
    int min = 0;
    string name;
    for (int i = 0; i < shopVector.size(); i++) {
        for (int j = 0; j < shopVector.at(i).products.size(); j++) {
            if (shopVector.at(i).products.at(j).cost < min || min == 0) {
                min = shopVector.at(i).products.at(j).cost;
                name = shopVector.at(i).shopName;
            }
        }
    }
    return name;
}

int main()
{
    vector <Shop> Marketplace = { 
        { "Shop1", { {"Product1", 2, 6}, {"Product2", 2, 6}, {"Product3", 0, 6} } },
        { "Shop2", { {"Product1", 2, 9}, {"Product2", 0, 8}, {"Product3", 2, 7} } },
        { "Shop3", { {"Product1", 0, 8}, {"Product2", 2, 5}, {"Product3", 2, 2} } } };

    cout << priceSort(Marketplace, "Product3");
}