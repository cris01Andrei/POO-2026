#include <iostream>


enum class ContactType {
    Friend,
    Acquaintance,
    Colleague
};


class Contact {
protected:
    char name[100];


    void CopyString(char* dest, const char* src, int maxLen) {
        int i = 0;
        while (src[i] != '\0' && i < maxLen - 1) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    bool StringsEqual(const char* s1, const char* s2) const {
        int i = 0;
        while (s1[i] != '\0' && s2[i] != '\0') {
            if (s1[i] != s2[i]) return false;
            i++;
        }
        return s1[i] == s2[i];
    }

public:
    Contact(const char* n) {
        CopyString(name, n, 100);
    }
    
    virtual ~Contact() {} 

    const char* GetName() const {
        return name;
    }


    virtual ContactType GetType() const = 0;
    virtual void Print() const = 0;

    bool HasName(const char* searchName) const {
        return StringsEqual(name, searchName);
    }
};


class Friend : public Contact {
private:
    char dob[20];
    char phone[20];
    char address[100];

public:
    Friend(const char* n, const char* d, const char* p, const char* addr) : Contact(n) {
        CopyString(dob, d, 20);
        CopyString(phone, p, 20);
        CopyString(address, addr, 100);
    }

    ContactType GetType() const override { return ContactType::Friend; }
    
    void Print() const override {
        std::cout << "[Friend] " << name << " | DOB: " << dob 
                  << " | Phone: " << phone << " | Addr: " << address << "\n";
    }
};


class Acquaintance : public Contact {
private:
    char phone[20];

public:
    Acquaintance(const char* n, const char* p) : Contact(n) {
        CopyString(phone, p, 20);
    }

    ContactType GetType() const override { return ContactType::Acquaintance; }
    
    void Print() const override {
        std::cout << "[Acquaintance] " << name << " | Phone: " << phone << "\n";
    }
};


class Colleague : public Contact {
private:
    char phone[20];
    char company[50];
    char address[100];

public:
    Colleague(const char* n, const char* p, const char* comp, const char* addr) : Contact(n) {
        CopyString(phone, p, 20);
        CopyString(company, comp, 50);
        CopyString(address, addr, 100);
    }

    ContactType GetType() const override { return ContactType::Colleague; }
    
    void Print() const override {
        std::cout << "[Colleague] " << name << " | Phone: " << phone 
                  << " | Company: " << company << " | Addr: " << address << "\n";
    }
};


class AddressBook {
private:
    Contact* contacts[100];
    int count;

public:
    AddressBook() : count(0) {}

    ~AddressBook() {
        for (int i = 0; i < count; i++) {
            delete contacts[i];
        }
    }


    bool AddContact(Contact* c) {
        if (count < 100) {
            contacts[count++] = c;
            return true;
        }
        return false;
    }


    Contact* Search(const char* name) const {
        for (int i = 0; i < count; i++) {
            if (contacts[i]->HasName(name)) {
                return contacts[i];
            }
        }
        return nullptr; 
    }


    bool DeleteContact(const char* name) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (contacts[i]->HasName(name)) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            delete contacts[index]; 
                contacts[i] = contacts[i + 1];
            }
            count--;
            return true;
        }
        return false;
    }


    int GetFriends(Friend** friendsList) const {
        int friendsCount = 0;
        for (int i = 0; i < count; i++) {
            if (contacts[i]->GetType() == ContactType::Friend) {
              
                friendsList[friendsCount++] = (Friend*)contacts[i]; 
            }
        }
        return friendsCount;
    }

    void PrintAll() const {
        std::cout << "--- Address Book (" << count << " contacts) ---\n";
        for (int i = 0; i < count; i++) {
            contacts[i]->Print();
        }
        std::cout << "-----------------------------------\n";
    }
};


int main() {
    AddressBook agenda;

   
    agenda.AddContact(new Friend("Alex", "15.05.1995", "0740111222", "Str. Florilor 12"));
    agenda.AddContact(new Acquaintance("Mihai", "0722333444"));
    agenda.AddContact(new Colleague("Diana", "0755666777", "IT Corp", "Bd. Unirii 50"));
    agenda.AddContact(new Friend("Andrei", "20.10.1998", "0770999888", "Str. Libertatii 1"));

    agenda.PrintAll();

 
    std::cout << "\n[Search] Cautam 'Diana':\n";
    Contact* found = agenda.Search("Diana");
    if (found) found->Print();

   
    std::cout << "\n[Friends List]\n";
    Friend* friendsList[100]; 
    int friendsCount = agenda.GetFriends(friendsList);
    for (int i = 0; i < friendsCount; i++) {
        friendsList[i]->Print();
    }

   
    std::cout << "\n[Delete] Stergem 'Mihai'...\n";
    agenda.DeleteContact("Mihai");
    
    agenda.PrintAll();

    return 0;
}
