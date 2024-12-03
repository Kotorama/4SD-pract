//Çíàéòè ø³ñòü íàéìåíøèõ åëåìåíò³â ìàñèâó, êîðèñòóþ÷èñü ôóíêö³ºþ
//ñîðòóâàííÿ åëåìåíò³â
//Ïåðåðîáèòè ç ìàñèâàìè, ñîðòóâàííÿ


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void shiftMatrix(std::vector<std::vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int perimeter = 2 * (rows + cols - 2);

    k = k % perimeter;

    for (int layer = 0; layer < min(M, N) / 2; ++layer) {
        int top = layer, left = layer;
        int bottom = M - layer - 1, right = N - layer - 1;

        vector<int> layer_elements;

        for (int i = left; i <= right; ++i)
            layer_elements.push_back(matrix[top][i]);

        for (int i = top + 1; i <= bottom; ++i)
            layer_elements.push_back(matrix[i][right]);

        for (int i = right - 1; i >= left; --i)
            layer_elements.push_back(matrix[bottom][i]);

        for (int i = bottom - 1; i > top; --i)
            layer_elements.push_back(matrix[i][left]);

        int layer_size = layer_elements.size();

        vector<int> rotated_layer(layer_size);
        for (int i = 0; i < layer_size; ++i) {
            rotated_layer[(i + k) % layer_size] = layer_elements[i];
        }

        int index = 0;

        for (int i = left; i <= right; ++i)
            matrix[top][i] = rotated_layer[index++];

        for (int i = top + 1; i <= bottom; ++i)
            matrix[i][right] = rotated_layer[index++];

        for (int i = right - 1; i >= left; --i)
            matrix[bottom][i] = rotated_layer[index++];

        for (int i = bottom - 1; i > top; --i)
            matrix[i][left] = rotated_layer[index++];
    }
}

int main()
{

    ifstream inputFile("matrix.txt");

    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols;

    inputFile.close();

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i{}; i < cols-1; i++) {
        matrix.[]
    }

    return 0;
}

