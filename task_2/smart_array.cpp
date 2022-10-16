#include "smart_array.h"
#include <exception>

SmartArray::SmartArray(int logicalSize) {
	_Lsize = logicalSize;
	_arr = new int[_Lsize];
}
SmartArray::~SmartArray() {
	delete[] _arr;
}

//Конструктор копирования.
SmartArray::SmartArray(SmartArray& other) {
	_Lsize = other._Lsize;
	_arr = new int[_Lsize];
	for (int i = 0; i < other._size; ++i) {
		add_element(other.get_element(i));
	}
}

void SmartArray::add_element(int newElement) {
	//Если массив заполнен, удвоим его размер (логический).
	if (_size == _Lsize) {
		_Lsize *= 2;
		int* tmp = new int[_Lsize];
		for (int i = 0; i < _size; ++i) {
			tmp[i] = _arr[i];
		}
		delete[] _arr;
		_arr = tmp;
	}
	_arr[_size] = newElement;
	++_size;
}

int SmartArray::get_element(int index) {
	//Если запрашиваемый индекс находится вне массива (заполненного), выбрасываем исключение.
	if (index >= _size) {
		throw std::exception("You ask element out of array range!");
	}
	return _arr[index];
}

int SmartArray::getSize() { return _size; }

SmartArray& SmartArray::operator=(SmartArray& other) {
	if (this != &other) {
		delete[] _arr;
		_size = 0;
		_Lsize = other._Lsize;
		_arr = new int[_Lsize];
		for (int i = 0; i < other._size; ++i) {
			add_element(other.get_element(i));
		}
	}
	return *this;
}