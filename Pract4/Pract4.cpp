//14. Сформувати документ, в якому зберігається інформація про
//асортимент продовольчих товарів в магазині : назва магазину, код товару,
//кількість цього товару, ціна за кілограм.Відсортувати магазини для оптової
//закупки заданого товару згідно його ціни
#include <iostream>
#include <string>

using std::string;
using std::cout;

const int n = 3;
struct Product {
    string productName;
    int amount;
    int cost;
};

struct Shop {
    string shopName;
    Product products[3];
};

string priceSort(Shop (&shopArray)[3], string product) {
    int min = 0;
    int shopSize = sizeof(shopArray) / sizeof(shopArray[0]);
    string name;
    for (int i = 0; i < shopSize; i++) {
        int productSize = sizeof(shopArray->products) / sizeof(shopArray->products[0]);
        for (int j = 0; j < productSize; j++) {
            if (shopArray[i].products[j].cost < min || min == 0) {
                min = shopArray[i].products[j].cost;
                name = shopArray[i].shopName;
            }
        }
    }
    return name;
}

int main()
{
    Shop Marketplace[] = {
        { "Shop1", { {"Product1", 2, 6}, {"Product2", 2, 6}, {"Product3", 0, 6} } },
        { "Shop2", { {"Product1", 2, 9}, {"Product2", 0, 8}, {"Product3", 2, 7} } },
        { "Shop3", { {"Product1", 0, 8}, {"Product2", 2, 5}, {"Product3", 2, 2} } } };

    cout << priceSort(Marketplace, "Product3");
}