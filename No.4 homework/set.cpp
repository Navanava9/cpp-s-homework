#include <iostream>
using namespace std;
class set
{
public:
	set() { n = 0; }
	void add(int x);
	void display();
	int find(int x);
	void del(int x);
	set jiaoji(set t);
	set binji(set t);
	set chaji(set t);

private:
	int a[10];
	int n;
};
void set::add(int x)
{

	if (find(x) == -1)
	{
		a[n] = x;
		n++;
	}
}
void set::del(int x)
{
	int pos, i;
	pos = find(x);
	if (pos != -1)
	{
		for (i = pos; i < n - 1; i++)
			a[i] = a[i + 1];

		n--;
	}
}
int set::find(int x)
{
	int pos = -1;
	int i;
	for (i = 0; i < n; i++)
		if (x == a[i])
		{
			pos = i;
			break;
		}
	return pos;
}
void set::display()
{
	int i;
	cout << "{";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "}" << endl;
}

set set::jiaoji(set t)
{
	set s;

	int i;
	for (i = 0; i < n; i++)
		if (t.find(a[i]) != -1)
			s.add(a[i]);

	return s;
}

set set::binji(set t)
{
	set s;
	for (int i = 0; i < n; i++)
		s.add(a[i]);
	for (int j = 0; j < n; j++)
		s.add(t.a[j]);

	return s;
}

set set::chaji(set t)
{
	set s;

	for (int i = 0; i < n; i++)
		s.add(a[i]);
	for (int j = 0; j < n; j++)
		if (t.find(a[j]) != -1)
			s.del(t.a[t.find(a[j])]);
	return s;
}

int main(void)
{
	set s1, s2, s3;
	s1.add(12);
	s1.add(13);
	s1.add(17);
	s2.add(20);
	s2.add(13);
	s2.add(17);

	s3 = s1.binji(s2);

	s3.display();
	return 0;
}