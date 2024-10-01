//14. Сформувати документ, в якому зберігається інформація про
//асортимент продовольчих товарів в магазині : назва магазину, код товару,
//кількість цього товару, ціна за кілограм.Відсортувати магазини для оптової
//закупки заданого товару згідно його ціни.
#include <iostream>

using namespace std;

int main()
{
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

    {
        Shop Marketplace[3] = { 
            { "Shop1", { {"Product1", 2, 6}, {"Product2", 2, 6}, {"Product3", 2, 6} } },
            { "Shop2", { {"Product1", 2, 9}, {"Product2", 2, 8}, {"Product3", 2, 7} } },
            { "Shop3", { {"Product1", 2, 8}, {"Product2", 2, 5}, {"Product3", 2, 2} } } };

}