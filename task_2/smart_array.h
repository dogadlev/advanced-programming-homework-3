#pragma once

class SmartArray {
public:
	SmartArray(int logicalSize);
	~SmartArray();
	void add_element(int newElement);
	int get_element(int index);
	int getSize();
	SmartArray& operator=(SmartArray& arr);
private:
	int* _arr = nullptr;
	int _Lsize = 0; //Логический размер массива.
	int _size = 0; //Заполненность массива.
};