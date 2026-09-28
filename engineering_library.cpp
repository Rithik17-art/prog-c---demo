#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdio>
class engineering_library{
    int book_id;
    string book_name;
    string author_name;
    string to_lower(string text){
        for (char &character : text) {
            character = tolower(character);
        }
        return text;
    }
    void write_book_details(){
        ofstream outfile;
        outfile.open("books.txt", ios::app);
        cout << "Enter book id: ";
        cin >> book_id;
        cout << "Enter book name: ";
        cin.ignore();
        getline(cin, book_name);
        cout << "Enter author name: ";
        getline(cin, author_name);
        outfile << book_id << "|" << book_name << "|" << author_name << "|0" << endl;
        outfile.close();
        cout << "Book details added successfully!" << endl;
    }    
    public:
    void set_book_details(int id, string name, string author){
        book_id = id;
        book_name = name;
        author_name = author;    
    }
    void display_book_details(){
        string searched_name;
        cout << "Enter book name: ";
        getline(cin, searched_name);

        ifstream infile("books.txt");
        string line;
        bool found = false;

        while (getline(infile, line)) {
            string id;
            string name;
            string author;
            string availability;
            stringstream record(line);

            getline(record, id, '|');
            getline(record, name, '|');
            getline(record, author, '|');
            getline(record, availability, '|');

            if (to_lower(name) == to_lower(searched_name)) {
                cout << "Book ID is " << id << endl;
                cout << "Name of the book is " << name << endl;
                cout << "Author of the book is " << author << endl;
                cout << "Available copies: " << 5 - stoi(availability) << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }
    void getwrite_book_details(){
        write_book_details();
    }
    void borrow_book(){
        string borrower_name;
        string borrowing_date;
        string searched_name;
        cout << "Enter borrower name: ";
        getline(cin, borrower_name);
        cout << "Enter borrowing date: ";
        getline(cin, borrowing_date);
        cout << "Enter book name to borrow: ";
        getline(cin, searched_name);

        ifstream infile("books.txt");
        ofstream tempFile("books_temp.txt");
        string line;
        string borrowed_id;
        string borrowed_name;
        string borrowed_author;
        bool found = false;
        bool borrowed = false;

        while (getline(infile, line)) {
            string id;
            string name;
            string author;
            string availability;
            stringstream record(line);

            getline(record, id, '|');
            getline(record, name, '|');
            getline(record, author, '|');
            getline(record, availability, '|');

            if (to_lower(name) == to_lower(searched_name)) {
                int borrowed_count = stoi(availability);
                if (borrowed_count < 5) {
                    availability = to_string(borrowed_count + 1);
                    borrowed_id = id;
                    borrowed_name = name;
                    borrowed_author = author;
                    borrowed = true;
                } else {
                    cout << "All 5 copies of this book are currently borrowed." << endl;
                }
                found = true;
            }
            tempFile << id << "|" << name << "|" << author << "|" << availability << endl;
        }

        infile.close();
        tempFile.close();

        if (!found) {
            cout << "Book not found." << endl;
        } else if (borrowed) {
            ofstream borrow_file("borrow.txt", ios::app);
            if (borrow_file.is_open()) {
                borrow_file << borrower_name << "|" << borrowing_date << "|" << borrowed_id << "|" << borrowed_name << "|" << borrowed_author << "|borrowed" << endl;
                borrow_file.close();
                cout << "Book borrowed successfully!" << endl;

                remove("books.txt");
                rename("books_temp.txt", "books.txt");
            } else {
                cout << "Unable to open borrow.txt." << endl;
                remove("books_temp.txt");
            }
        } else {
            remove("books_temp.txt");
        }
    }
    void renew_book(){
        string borrower_name;
        string book_name;
        string current_date;
        cout << "Enter borrower name: ";
        getline(cin, borrower_name);
        cout << "Enter book name to renew: ";
        getline(cin, book_name);
        cout << "Enter today's date (DD.MM.YYYY): ";
        getline(cin, current_date);

        ifstream infile("borrow.txt");
        ofstream tempFile("borrow_temp.txt");
        string line;
        bool found = false;

        while (getline(infile, line)) {
            string name;
            string date;
            string id;
            string bname;
            string author;
            string status;
            stringstream record(line);

            getline(record, name, '|');
            getline(record, date, '|');
            getline(record, id, '|');
            getline(record, bname, '|');
            getline(record, author, '|');
            getline(record, status, '|');

            if (to_lower(name) == to_lower(borrower_name) && to_lower(bname) == to_lower(book_name) && status == "borrowed") {
                found = true;
                int borrowed_day = stoi(date.substr(0, 2));
                int current_day = stoi(current_date.substr(0, 2));
                if (current_day - borrowed_day >= 7) {
                    cout << "You cannot renew this book,because it has been borrowed for more than 7 days. Please pay the fine." << endl;
                } else {
                    cout << "Book renewed successfully!" << endl;
                    status = "renewed";
                }
            }
            tempFile << name << "|" << date << "|" << id << "|" << bname << "|" << author << "|" << status << endl;
        }

        infile.close();
        tempFile.close();

        if (!found) {
            cout << "No borrowed record found for this book and borrower." << endl;
        } else {
            remove("borrow.txt");
            rename("borrow_temp.txt", "borrow.txt");
        }
    }
    void return_book(){
        string borrower_name;
        string book_name;
        cout << "Enter borrower name: ";
        getline(cin, borrower_name);
        cout << "Enter book name to return: ";
        getline(cin, book_name);

        ifstream infile("borrow.txt");
        ofstream tempFile("borrow_temp.txt");
        string line;
        bool found = false;

        while (getline(infile, line)) {
            string name;
            string date;
            string id;
            string bname;
            string author;
            string status;
            stringstream record(line);

            getline(record, name, '|');
            getline(record, date, '|');
            getline(record, id, '|');
            getline(record, bname, '|');
            getline(record, author, '|');
            getline(record, status, '|');

            if (to_lower(name) == to_lower(borrower_name) && to_lower(bname) == to_lower(book_name) && (status == "borrowed" || status == "renewed")) {
                found = true;
                cout << "Book returned successfully!" << endl;

                // Update the availability in books.txt
                ifstream books_infile("books.txt");
                ofstream books_tempFile("books_temp.txt");
                string book_line;

                while (getline(books_infile, book_line)) {
                    string id;
                    string name;
                    string author;
                    string availability;
                    stringstream book_record(book_line);

                    getline(book_record, id, '|');
                    getline(book_record, name, '|');
                    getline(book_record, author, '|');
                    getline(book_record, availability, '|');

                    if (to_lower(name) == to_lower(book_name)) {
                        int borrowed_count = stoi(availability);
                        availability = to_string(borrowed_count - 1);
                    }
                    books_tempFile << id << "|" << name << "|" << author << "|" << availability << endl;
                }

                books_infile.close();
                books_tempFile.close();

                remove("books.txt");
                rename("books_temp.txt", "books.txt");
            } else {
                tempFile << line << endl; // Keep the record if not returned
            }
        }

        infile.close();
        tempFile.close();

        if (!found) {
            cout << "No borrowed record found for this book and borrower." << endl;
        } else {
            remove("borrow.txt");
            rename("borrow_temp.txt", "borrow.txt");
        }
    }

    

    

};

int main(){
    engineering_library library;
    cout << "welcome to the engineering library" << endl;
    while (true){
        cout << "1. Add book details" << endl;
        cout << "2. Display book details" << endl;
        cout << "3.borrow book"<< endl;
        cout << "4.renew book"<< endl;
        cout << "5. return book"<< endl;
        cout << "6. exit" << endl;
        int choice;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1: {
                library.getwrite_book_details();
                break;
            }
            case 2: {
                library.display_book_details();
                break;
            }
            case 3: {
                cout <<"note that you have to renew book every 7 days and we have only 5 copies of each book"<< endl;
                library.borrow_book();
                break;
            }
            case 4: {
                library.renew_book();
                break;
            }
            case 5: {
                library.return_book();
                break;
            }
            case 6: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
                break;
            }
        }
        
    }

    
    

}