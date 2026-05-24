classDiagram
    direction TB

    class ContactType {
        <<enumeration>>
        Friend
        Acquaintance
        Colleague
    }

    class Contact {
        <<abstract>>
        #name : char[100]
        +Contact(name : const char*)
        +~Contact()
        +GetName() const char*
        +GetType()* ContactType
        +Print()* void
        +HasName(searchName : const char*) bool
    }

    class Friend {
        -dob : char[20]
        -phone : char[20]
        -address : char[100]
        +Friend(n, d, p, addr)
        +GetType() ContactType
        +Print() void
    }

    class Acquaintance {
        -phone : char[20]
        +Acquaintance(n, p)
        +GetType() ContactType
        +Print() void
    }

    class Colleague {
        -phone : char[20]
        -company : char[50]
        -address : char[100]
        +Colleague(n, p, comp, addr)
        +GetType() ContactType
        +Print() void
    }

    class AddressBook {
        -contacts : Contact*[100]
        -count : int
        +AddressBook()
        +~AddressBook()
        +AddContact(c : Contact*) bool
        +Search(name : const char*) Contact*
        +DeleteContact(name : const char*) bool
        +GetFriends(friendsList : Friend**) int
        +PrintAll() void
    }

    %% Relatii de mostenire (Inheritance)
    Contact <|-- Friend : is-a
    Contact <|-- Acquaintance : is-a
    Contact <|-- Colleague : is-a

    %% Relatie de agregare (Aggregation)
    AddressBook o-- Contact : has-many

    %% Dependenta
    Contact ..> ContactType : uses
