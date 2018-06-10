#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<iomanip>

using namespace std;

struct Student
{
	string sex;
	string name;
	double score;
};

Student s[100];
int pos = 0;

bool compare(Student a, Student b)
{
	if (a.score == b.score)
		return a.name.compare(b.name) < 0;
	else
		return a.score > b.score;
}

void Calculate()
{
	int MaleNumber = 0;
	int FemaleNumber = 0;
	double MaleTotal = 0.0;
	double FemaleTotal = 0.0;
	for(int i = 0; i < pos; i++)
	{
		if (strcmp("Female", s[i].sex.c_str()) == 0)
		{
			FemaleNumber++;
			FemaleTotal = s[i].score + FemaleTotal;
		}
		else if (strcmp("Male",s[i].sex.c_str( ))== 0)
		{
			MaleNumber++;
			MaleTotal = s[i].score + MaleTotal;
		}
    }
	cout << "This is a score list of some students." << endl;
	cout << "The average score of Male students is: " << setw(6) << (MaleTotal / MaleNumber) << endl;
	cout << "The average score of Female students is: " << setw(6) << (FemaleTotal / FemaleNumber) << endl;
	cout << "The average score of all the students is: " << setw(6) << ((MaleTotal + FemaleTotal) / (MaleNumber + FemaleNumber)) << endl;
	cout << "Name" << setw(13) << "Sex" << setw(13) << "Score" << endl;
	sort(s, s + pos, compare);
	for (int i = 0; i < pos - 1; i++)
	{
		cout << left << setw(12) << s[i].name << setw(12) << s[i].sex << setw(12) << s[i].score<<endl;
        }
        int p1=0;
        int p2=0;
        int p3=0;
        for(int j=0;j<pos-1;j++)
        {
            if(s[j].score<60)
            {
            cout<<s[j].name<<setw(10)<< "failed the test."<<endl;
            p1++;
            }
            else if(s[j].score==100)
           {
            cout<<s[j].name<<setw(10)<< "got a full score.Great!"<<endl;
            p2++;
           }
            else 
           {
            cout<<s[j].name<<setw(10)<< "passed the test."<<endl;
            p3++;
           }
        }
           cout<<p1<<"student(s) failed the test."<<endl;
           cout<<p2<<"student(s）got a full score in the test."<<endl;
           cout<<p3<<"student(s) passed the test."<<endl;            
}

int main()
{
	ifstream infile("score.csv", ios::in);
	if (!infile)
	{
		cerr << "We can not open this file!" << endl;
		exit(1);
	}
	if (!infile.eof())
	{
		infile.ignore(100, '\n');
		while (!infile.eof())
		{
			getline(infile, s[pos].name, ',');
			getline(infile, s[pos].sex, ',');
			s[pos].sex.erase(0, 1);
			string score1;
			getline(infile, score1, '\n');
			stringstream str;
			str << score1;
			str >> s[pos].score;
			pos++;
		}
	}
	Calculate();
	return 0;
}
