#include <iostream>
#include <string>
using namespace std;
class Student
{
	int no;
	string name;
	float score;
	Student *per;
	Student *next;

public:
	Student();
	Student *find(int i_no);
	void edit(string i_newname, float i_score);
	void erase();
	int add(Student *i_newStudent);
	int getno();
	string getname();
	float getscore();
	static float sum(Student *root);
	static float average(Student *root);
	static int maxno;
	static int count;
	static float total;
};

float Student::sum(Student *root)
{

	return total;
}

float Student::average(Student *root)
{

	return total / count;
}

Student::Student()
{
	score = 0.0;
	per = NULL;
	next = NULL;
}
Student *Student::find(int i_no)
{
	if (i_no == no)
		return this;
	if (next != NULL)
		return next->find(i_no);
	return NULL;
}
void Student::edit(string i_name, float i_score)
{
	if (i_name == "")
		return;
	Student::total += i_score;
	Student::total -= this->getscore();
	name = i_name;
	score = i_score;
}
void Student::erase()
{
	if (no < 0)
		return;
	Student::count--;
	Student::total -= this->score;
	if (per != NULL)
		per->next = next;
	if (next != NULL)
		next->per = per;
	next = NULL;
	per = NULL;
}
int Student::add(Student *i_newStudent)
{
	int no = maxno + 1;
	while (true)
	{
		if (NULL == find(no))
			break;
		no = no + 1;
	}
	Student *tmp = this;
	while (true)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	tmp->next = i_newStudent;
	i_newStudent->next = NULL;
	i_newStudent->per = tmp;
	i_newStudent->no = no;
	Student::count++;
	return no;
}

int Student::getno() { return no; }
string Student::getname() { return name; }
float Student::getscore() { return score; }

int Student::maxno = 1000;
int Student::count = 0;
float Student::total = 0;

int main()
{
	Student *Studentroot = new Student();
	string input1;
	float input2;
	Student *tmp = NULL;
	while (true)
	{
		cout << "Please type ur instruction: Find(F), Add(A), Edit(E), Delete(D), Tatol(T), Averager(V), Exit(Q)" << endl;
		cin >> input1;

		if (("F" == input1) || ("f" == input1))
		{
			cout << "Input Sno:";
			int no = -1;
			cin >> no;
			tmp = Studentroot->find(no);
			if (tmp == NULL)
			{
				cout << "Not find!" << endl;
				continue;
			}
			cout << "Sno:" << tmp->getno();
			cout << "Sname:";
			string name;
			if ((name = tmp->getname()) != "")
				cout << name;
			else
				cout << "No input" << endl;
			cout << "Score: " << tmp->getscore() << endl;
		}
		else if ((input1 == "A") || (input1 == "a"))
		{
			cout << "Input Sname,Score: ";
			cin >> input1 >> input2;
			;
			tmp = new Student();
			tmp->edit(input1, input2);
			cout << "Sno: " << Studentroot->add(tmp) << endl;
		}
		else if ((input1 == "E") || (input1 == "e"))
		{
			cout << "Input Sno: ";
			int no = 0;
			cin >> no;
			tmp = Studentroot->find(no);
			if (tmp == NULL)
			{
				cout << "NULL Sno" << endl;
				continue;
			}
			cout << "New Score, new Name:";
			cin >> input1 >> input2;
			tmp->edit(input1, input2);
			cout << "Change success!" << endl;
		}
		else if ((input1 == "D") || (input1 == "d"))
		{
			cout << "Input Sno:";
			int no = 0;
			cin >> no;
			tmp = Studentroot->find(no);
			tmp->erase();
			cout << "Delete success!" << endl;
			delete tmp;
		}

		else if ((input1 == "T") || (input1 == "t"))
		{
			cout << "Total score:" << Student::total << endl;
		}

		else if ((input1 == "v") || (input1 == "V"))
		{
			cout << "Average:" << Student::total / Student::count << endl;
		}

		else if ((input1 == "Q") || (input1 == "q"))
		{
			break;
		}
		else
		{
			cout << "Input wrong!" << endl;
		}
	}
	delete Studentroot;
	return 0;
}
