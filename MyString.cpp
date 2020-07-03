#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
private:
	char *str;
	int length;
public:
	MyString() {
		str = new char[500];
		length = 0;
		str[0] = '\0';
	}
	MyString(const char *c) {
		str = new char[strlen(c)+500];
		length = strlen(c);
		for (int i = 0; i < length; i++)
			str[i] = c[i];
		str[length] = '\0';

	}
	MyString(const MyString& s) {
		str = new char[s.length + 500];
		length = s.length;
		for (int i = 0; i < s.length; i++)
			str[i] = s.str[i];
		str[length] = '\0';
	}
	~MyString() {
		delete[] str;
	}
	MyString& operator=(const MyString& s) {
		if (this != &s)
		{
			length = s.length;
			for (int i = 0; i < s.length; i++)
				str[i] = s.str[i];
			str[length] = '\0';
		}
		return *this;
	}
	void display() const {
		for (int i = 0; i < length; i++)
			cout << str[i];
	}
	int getLength() const {
		return length;
	}
	MyString operator + (const MyString& s) {
		MyString tmp;
		tmp.str = new char[length + s.length + 500];
		tmp.length = length + s.length;
		int j = 0;
		for (int i = 0; i < length; i++, j++)
			tmp.str[j] = str[i];
		for (int i = 0; i < s.length; i++, j++)
			tmp.str[j] = s.str[i];
		tmp.str[tmp.length] = '\0';
		return tmp;
	}
	MyString operator += (const MyString& s) {
		int j = length;
		length += s.length;
		for (int i = 0; i < s.length; i++, j++)
			str[j] = s.str[i];
		str[length] = '\0';
		return *this;
	}
};
int main() {
	char c[] = { 'a','d','e','e','l','\0' };
	MyString s(c);
	MyString t(s);
	MyString r = s + t;
	r += s;
	cout << "Length: " << r.getLength() << endl;
	r.display();
	system("pause");
}