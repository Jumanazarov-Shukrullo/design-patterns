//#include <iostream>
//
//class GameSettings {
//    static GameSettings *_instance;
//    int _brightness;
//    int _width;
//    int _height;
//
//    GameSettings() : _width(0), _height(0), _brightness(0) {}
//
//public:
//    static GameSettings *getInstance() {
//        if (_instance == nullptr) {
//            _instance = new GameSettings();
//        }
//        return _instance;
//    }
//
//    void setWidth(int width) { _width = width; }
//
//    void setHeight(int height) { _height = height; }
//
//    void setBrightness(int brightness) { _brightness = brightness; }
//
//    int getWidth() { return _width; }
//
//    int getHeight() { return _height; }
//
//    int getBrightness() { return _brightness; }
//
//    void displaySetting() {
//        std::cout << "width: " << _width << "\n" <<
//                  "height: " << _height << "\n" <<
//                  "brightness: " << _brightness << "\n\n";
//    }
//};
//
//GameSettings *GameSettings::_instance;
//void someFunction() {
//    GameSettings *settings = GameSettings::getInstance();
//    settings->displaySetting();
//}
//int main() {
//    GameSettings *settings = GameSettings::getInstance();
//    settings->displaySetting();
//    settings->setBrightness(100);
//    someFunction();
//}

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>> &rectangle) : size(rectangle.size()), res(size) {
        for (int i = 0; i < rectangle.size(); ++i) {
            for (int j = 0; j < rectangle[i].size(); ++j) {
                res[i].emplace_back(rectangle[i][j]);
            }
        }
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                res[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return res[row][col];
    }

    void print() {
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < res[i].size(); ++j) {
                std::cout << res[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    size_t size{};
    vector<vector<int>> res;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
int main() {
    std::vector<std::vector<int>> v = {{1, 2, 1},
                                       {4, 3, 4},
                                       {3, 2, 1},
                                       {1, 1, 1}};
    SubrectangleQueries s(v);
    s.print();
    std::cout << s.getValue(0,2) << std::endl;
    s.updateSubrectangle(0,0,3,2,5);
    s.print();
    s.updateSubrectangle(3, 0, 3, 2, 10);
    std::cout << "------\n";
    s.print();
}