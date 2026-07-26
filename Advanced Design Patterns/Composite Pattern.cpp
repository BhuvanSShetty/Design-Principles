#include <iostream>
#include <vector>
using namespace std;

/*
====================================================
WITHOUT COMPOSITE
====================================================

Problem:

Suppose we have Files and Folders.

A Folder contains multiple Files.

Client code has to separately handle
Files and Folders.

Code:

class File {

public:

    void show() {

        cout << "File\n";

    }

};

class Folder {

public:

    vector<File> files;

    void show() {

        cout << "Folder\n";

        for(auto file : files)

            file.show();

    }

};

int main() {

    File file;

    Folder folder;

    folder.files.push_back(file);

    file.show();

    folder.show();

}

Problems:

- Client treats File and Folder differently.
- Folder cannot contain another Folder.
- Difficult to build tree structures.
- Tight coupling.

====================================================
COMPOSITE PATTERN
====================================================

Solution:

Create a common Component interface.

Both File and Folder implement
the same interface.

Folder can store Components,
not just Files.

Now a Folder can contain:

- Files
- Other Folders

*/

class Component {

public:

    virtual void show() = 0;

};

// Leaf
class File : public Component {

private:

    string name;

public:

    File(string name) {

        this->name = name;

    }

    void show() override {

        cout << "File : " << name << endl;

    }

};

// Composite
class Folder : public Component {

private:

    string name;

    vector<Component*> components;

public:

    Folder(string name) {

        this->name = name;

    }

    void add(Component* component) {

        components.push_back(component);

    }

    void show() override {

        cout << "Folder : " << name << endl;

        for(auto component : components)

            component->show();

    }

};

int main() {

    File file1("Resume.pdf");

    File file2("Notes.txt");

    Folder documents("Documents");

    documents.add(&file1);

    documents.add(&file2);

    Folder root("Root");

    root.add(&documents);

    root.show();

}

/*

Output:

Folder : Root
Folder : Documents
File : Resume.pdf
File : Notes.txt

Notice:

Folder stores Component*

instead of

File

So Folder can now contain

- Files
- Folders

Client treats both exactly the same.

*/