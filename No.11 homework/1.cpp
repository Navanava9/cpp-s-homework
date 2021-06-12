#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

static int n = 0;
class Mytel
{
public:
	void getdata() { cin >> name >> telno; }
	void setname(char a[]) { strcpy(name, a); }
	void settelno(char a[]) { strcpy(telno, a); }
	void disp() { cout << name << setw(12) << telno << endl; }
	char *getname() { return name; }
	char *gettelno() { return telno; }

private:
	char name[12];
	char telno[12];
};

class te1Manager
{
private:
	vector<Mytel> a;

public:
	void loadfile()
	{
		ifstream input("phone.txt");
		if (!input)
		{
			cout << "File cannot be opened．" << endl;
			return;
		}

		Mytel s;
		char name[12], telno[12];
		input >> name >> telno;
		s.setname(name);
		s.settelno(telno);

		while (input)
		{
			a.push_back(s);
			input >> name >> telno;
			s.setname(name);
			s.settelno(telno);
		}
		input.close();
	}

	void display()
	{
		cout << "姓名" << setw(8) << "电话" << endl;
		for (int i = 0; i < a.size(); i++)
			cout << a[i].getname() << setw(12) << a[i].gettelno() << endl;
	}

	void search()
	{
		string sname;

		cout << "输入要查询的姓名（可只输入姓氏）:";
		cin >> sname;
		cout << "输出查询结果:" << endl;
		cout << "姓名" << setw(8) << "电话" << endl;

		for (int i = 0; i < a.size(); i++)
			if (a[i].getname() == sname)
				a[i].disp();
	}

	void add()
	{
		Mytel one;
		cout << "姓名" << setw(8) << "电话" << endl;
		one.getdata();
		a.push_back(one);
	}

	void writefile()
	{
		ofstream file("phone.txt");

		for (int i = 0; i < a.size(); i++)
			file << a[i].getname() << "\t" << a[i].gettelno() << endl;
		file.close();
	}

	void del()
	{
		string sname;
		Mytel one;

		cout << "输入要删除的姓名（可只输入姓氏）:";
		cin >> sname;

		for (int i = 0; i < a.size(); i++)
			if (a[i].getname() == sname)
				a.erase(std::begin(a) + i);
	}

	void change()
	{
		string sname;
		Mytel one;

		cout << "输入要修改的姓名（可只输入姓氏）:";
		cin >> sname;
		cout << "请输入修改之后的姓名，电话:";
		one.getdata();

		for (int i = 0; i < a.size(); i++)
			if (a[i].getname() == sname)
			{
				a[i].setname(one.getname());
				a[i].settelno(one.gettelno());
			}
	}
};

int main()
{
	int sel;
	te1Manager m;
	while (1)
	{
		cout << "***************电话薄管理系统***************";
		cout << endl
			 << endl;
		cout << "1:加载数据      2:输出数据      3:按姓名查询" << endl
			 << "4:添加数据      5:保存数据      6:删除数据" << endl
			 << "7:修改数据      0:退出" << endl;
		cout << "********************************************";
		cout << "\n请选择(0-7)";
		cin >> sel;
		switch (sel)
		{
		case 1:
			m.loadfile();
			break;
		case 2:
			m.display();
			break;
		case 3:
			m.search();
			break;
		case 4:
			m.add();
			break;
		case 5:
			m.writefile();
			break;
		case 6:
			m.del();
			break;
		case 7:
			m.change();
			break;
		case 0:
			exit(1);
		}
	}
	return 0;
}
