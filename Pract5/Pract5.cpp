//Знайти шість найменших елементів масиву, користуючись функцією
//сортування елементів
//Переробити з масивами


#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int> const &vect)
{
    if (typeid(vect) != typeid(vector<int>))
    {
        cout << "Bubble sort invalid array!";
        return -100;
    }
    vector<int> vec = vect;

    int size = vec.size();
    if (size == 1) {
        return vec[0];
    }
    for (int i = 0; i < size -1; i++) {
        if (vec[i + 1] < vec[i]) {
            swap(vec[i], vec[i + 1]);
            if (i > 0) {
                i -= 2;
            }
            
        }
    }
    return vec[0];
   
}

int quickMin(vector<int> const& vec)
{
    if (typeid(vec) != typeid(vector<int>))
    {
        cout << "Invalid array!\n";
        return -100;
    }

    int size = vec.size();
    int min = vec[0];
    for (int i = 0; i < size; i++) {
        if (vec[i]<min) {
            min = vec[i];

        }
    }
    return min;
}

int main()
{
    vector<int> vect{ 7, 5, 63, 2, 2 };

    cout << vect[0] << "\n";

    int min = bubbleSort(vect);

    std::cout<< min << "\n";

    min = quickMin(vect);

    std::cout << min << "\n";

    cout << vect[0] << "\n";
}

