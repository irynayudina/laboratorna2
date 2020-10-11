#pragma once
#include "tableBook.h"
#include "ceil_array_2d.h"
class sheet :
	public tableBook
{
protected:
	char* name = NULL;
	int name_length;
	bool protection;
	ceil_array_2d* content = NULL;
	int content_length;
public:
	sheet(void)
	{
		name = new char[5];
		name_length = 5;
		name[0] = 'b';
		name[1] = 'o';
		name[2] = 'o';
		name[3] = 'k';
		name[4] = '1';
		content = new ceil_array_2d[1];
		content_length = 1;
		//for (int i = 0; i < content_length; i++) {
		//	//content[i] = '0';
		//}
		protection = false;
	}
	sheet(char* _name, int _name_length, ceil_array_2d* _content, int _content_length, bool _protection)
	{
		this->name = new char[_name_length];
		for (int i = 0; i < _name_length; i++) {
			this->name[i] = _name[i];
		}
		this->content = new ceil_array_2d[_content_length];
		for (int i = 0; i < _content_length; i++) {
			this->content[i] = _content[i];
		}
		this->protection = _protection;
		this->content_length = _content_length;
		this->name_length = _name_length;
	}
	sheet(const sheet& other)
	{
		this->name = new char[other.name_length];
		for (int i = 0; i < other.name_length; i++) {
			this->name[i] = other.name[i];
		}
		this->content = new ceil_array_2d[other.content_length];
		for (int i = 0; i < other.content_length; i++) {
			this->content[i] = other.content[i];
		}
		this->protection = other.protection;
		this->content_length = other.content_length;
		this->name_length = other.name_length;
	}
	~sheet() { delete[] name; delete[] content; }
	sheet& operator=(const sheet& other)
	{
		this->protection = other.protection;
		this->content_length = other.content_length;
		this->name_length = other.name_length;
		if (this->name != NULL) {
			delete[] this->name;
		}
		this->name = new char[other.name_length];
		for (int i = 0; i < other.name_length; i++) {
			this->name[i] = other.name[i];
		}
		if (this->content != NULL) {
			delete[] this->content;
		}
		this->content = new ceil_array_2d[other.content_length];
		for (int i = 0; i < other.content_length; i++) {
			this->content[i] = other.content[i];
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, const sheet& point);
	friend istream& operator>> (istream& out, sheet& point);

	void save_to_the_disk()
	{
		ofstream writer("theCeil.txt", ofstream::app);
		writer << *this;
		writer.close();
	}
	void get_from_the_disk()
	{
		ifstream reader("theCeil.txt");
		reader >> *this;
		reader.close();
	}
	char* get_name() { return this->name; }
	void set_name(int size, char* value) {
		if (this->name != NULL) {
			delete[] this->name;
		}
		this->name = new char[size];
		for (int i = 0; i < size; i++) {
			this->name[i] = value[i];
		}
	}
	bool get_protection() { return this->protection; }
	void set_protection(bool value) { this->protection = value; }
	ceil_array_2d* get_content() { return this->content; }
	void set_content(int size, ceil_array_2d* value) {
		if (this->content != NULL) {
			delete[] this->content;
		}
		this->content = new ceil_array_2d[size];
		for (int i = 0; i < size; i++) {
			this->content[i] = value[i];
		}
	}
	int get_name_length() { return this->name_length; }
	void set_name_length(int value) { this->name_length = value; }
	int get_content_length() { return this->content_length; }
	void set_content_length(int value) { this->content_length = value; }
};

