#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Man {
public:
    Man(const string& name, const string& vocation) : Name(name), Vocation(vocation) {}
    virtual void Walk(const string& destination) const {
        cout << Vocation << ": " << Name << " walks to: " << destination << endl;
    };
    string getName() const { return Name; }
    string getVocation() const { return Vocation; }
protected:
    const string Name;
    const string Vocation;
};

class Student : public Man {
public:
    explicit Student(const string& name, const string& favouriteSong) :
            Man(name, "Student"), FavouriteSong(favouriteSong) {
    }
    void Walk(const string& destination) const override {
        cout << Vocation << ": " << Name << " walks to: " << destination << endl;
        SingSong();
    }
    void Learn() const {
        cout << Vocation <<": " << Name << " learns" << endl;
    }
    void SingSong() const {
        cout << Vocation << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};

class Teacher : public Man {
public:
    explicit Teacher(const string& name, const string& subject) : Man(name, "Teacher"), Subject(subject) {}
    void Teach() {
        cout << Vocation << ": " << Name << " teaches: " << Subject << endl;
    }
private:
    const string Subject;
};

class Policeman : public Man{
public:
    explicit Policeman( const string& name) : Man(name, "Policeman") {}
    void Check(Man m){
        cout << Vocation << ": " << Name << " checks " << m.getVocation() << ". " << m.getVocation() << "'s name is: " << m.getName() << endl;
    }
};

void VisitPlaces(const Man& m, const vector<string>& places){
    for(const auto& p : places) {
        m.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}