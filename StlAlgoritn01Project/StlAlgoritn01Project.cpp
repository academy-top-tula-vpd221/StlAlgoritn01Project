#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name = "", int age = 0) : name{ name }, age{ age } {}
    string& Name(){ return name; }
    int& Age() { return age; }
    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << "name: " << user.name << ", age: " << user.age;
        return out;
    }
    friend bool operator==(User u1, User u2)
    {
        return u1.Name() == u2.Name() && u1.Age() == u2.Age();
    }

    friend bool operator<(User u1, User u2)
    {
        return u1.Age() < u2.Age();
    }
};

bool UserCheckAge(User u)
{
    return u.Age() < 22;
}

struct UserComparer
{
public:
    bool operator()(User u1, User u2)
    {
        return u1.Age() < u2.Age();
    }
};


int main()
{
    srand(time(nullptr));
    vector<int> vint; // { 2, 6, 7, 10, 22 };
    for (int i = 0; i < 10; i++)
        vint.push_back(rand() % 100);
    list<int> lint; // { 2, 6, 7, 10 };

    vector<User> vusers{
        User("Bob", 21),
        User("Joe", 25),
        User("Tim", 36),
        User("Sam", 39),
        User("Tim", 42),
    };

    list<User> lusers{
        User("Bob", 32),
        User("Joe", 21),
        User("Tim", 25),
        User("Sam", 29),
    };

    
    for_each(vint.begin(), vint.end(), [](auto item)
        {
            cout << item << " ";
        });
    cout << "\n";

    /*
    for_each(vint.begin(), vint.end(), [](auto item)
        {
            item = item - 10;
        });
    for_each(lint.begin(), lint.end(), [](auto item)
        {
            cout << item << " ";
        });
    cout << "\n";

    cout << boolalpha << all_of(vint.begin(), vint.end(), [](auto item)
        {
            return item % 2 == 0;
        }) << "\n";

    cout << any_of(vint.begin(), vint.end(), [](auto item)
        {
            return item % 2 == 0;
        }) << "\n";

    cout << none_of(vint.begin(), vint.end(), [](auto item)
        {
            return item < 0;
        }) << "\n";

    int n;
    cout << "input n: ";
    cin >> n;
    cout << count(vint.begin(), vint.end(), n) << "\n";
    cout << count_if(vint.begin(), vint.end(), [n](auto item)
        {
            return item > n;
        }) << "\n";

    auto res = mismatch(vint.begin(), vint.end(), lint.begin(), lint.end());
    if (res.first != vint.end())
        cout << "pair: " << *(res.first);
    if(res.second != lint.end())
        cout << " " << *(res.second) << "\n";
   


    auto resUsers = mismatch(vusers.begin(), vusers.end(), lusers.begin(),
        [](User u1, User u2) {
            return u1.Name() == u2.Name() && u1.Age() == u2.Age();
        });

    if (resUsers.first != vusers.end())
        cout << "pair: " << *(resUsers.first) << " | ";
    if (resUsers.second != lusers.end())
        cout << " " << *(resUsers.second) << "\n";

    

    int n;
    cout << "input n: ";
    cin >> n;

    auto result = find(vint.begin(), vint.end(), n);
    if (result != vint.end())
        cout << *result << "\n";
    else
        cout << "not found\n";

    auto result2 = find(vusers.begin(), vusers.end(), User("Tim", 55));
    if (result2 != vusers.end())
        cout << *result2 << "\n";
    else
        cout << "not found\n";

    result2 = find_if(vusers.begin(), vusers.end(), UserCheckAge);
    if (result2 != vusers.end())
        cout << *result2 << "\n";
    else
        cout << "not found\n";

    */

    /*
    vector<int> vect1{ 3, 7, 9, 5, 8, 6, 7, 9, 1 };
    list<int> list1{ 5, 9, 6, 0, 6 };

    auto res1 = find_first_of(vect1.begin(), vect1.end(), list1.begin(), list1.end());
    for_each(res1, vect1.end(), [](auto item) {
        cout << item << " ";
        });

    auto res2 = search(vect1.begin() + 1, vect1.end() - 1, list1.begin(), list1.end());
    if (res2 != vect1.end() - 1)
        cout << *res2 << "\n";
    else
        cout << "not found\n";

    fill(vect1.begin() + 2, vect1.begin() + 5, 0);

    for (auto item : vect1) cout << item << " ";
    cout << "\n";
    for (auto item : list1) cout << item << " ";
    cout << "\n";
    
    transform(vect1.begin() + 1, vect1.end() - 1, vect1.begin(),
        [](auto item) {
            return item * 2;
        });
    move(vect1.begin() + 1, vect1.begin() + 4, ++list1.begin());
    
    for (auto item : vect1) cout << item << " ";
    cout << "\n";
    for (auto item : list1) cout << item << " ";
    cout << "\n";
    */
    //vector<int> vrand(10);
    //int i{ 1 };
    //generate(vrand.begin(), vrand.end(), [&i]() {
    //    return i++; //rand() % 100;
    //    });
    //for (auto item : vrand) cout << item << " ";
    //cout << "\n";
    /*remove_if(vrand.begin(), vrand.end(), [](auto item) {
        return !(item % 2);
        });*/
    /*replace_if(vrand.begin(), vrand.end(), [](auto item) {
        return item < 5;
        }, -1);*/
    //rotate(vrand.begin(), vrand.begin() + 3, vrand.end());
    //random_shuffle(vrand.begin(), vrand.end());

    /*vector<int> hand(5);
    sample(vrand.begin(), vrand.end(), hand.begin(), 5, std::mt19937{ std::random_device{}() });
    for (auto item : vrand) cout << item << " ";
    cout << "\n";
    for (auto item : hand) cout << item << " ";
    cout << "\n";

    string str = "hello     world,     and hello      people";
    cout << str << "\n";
    string str2 = "Wow! ";
    unique_copy(str.begin(), str.end(), back_inserter(str2), [](char a, char b) {
        return a == ' ' && b == ' ';
        });
    cout << str2 << "\n";*/

    //cout << boolalpha << is_sorted(vusers.begin(), vusers.end(), UserComparer());
    vector<int> nums{ 1, 3, 4, 6, 7, 8, 10 };
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << "\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << ": " << *(lower_bound(nums.begin(), nums.end(), i)) << "\n";
        cout << i << ": " << *(upper_bound(nums.begin(), nums.end(), i)) << "\n\n";
    }
        
}
