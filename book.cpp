#include <string>
#include "book.h"

Book::Book(std::string title, std::string author_first_name, std::string author_last_name, std::string isbn, bool available)
: title{}, author{}, isbn{}, available{} {
    // TODO(student)
    auto is_letter =[](char c){
        return(c>='A'&&c<='Z') ||(c>='a'&&c<='z');
    };

    if(title.empty()){throw std::invalid_argument("Invalid title");
    }
    for(size_t i =0; i<title.size();i +=1){
        char c =title[i];
        if(!(is_letter(c) ||c ==':' ||c =='-' ||c ==' '|| c == '\t' || c =='\n' || c =='\r'||c== '\f' || c =='\v')){throw std::invalid_argument("Invalid title");
        }
    }

    if(author_first_name.empty()){throw std::invalid_argument("Invalid author");
    }
    for(size_t i =0;i<author_first_name.size();i +=1){
        if(!is_letter(author_first_name[i])){throw std::invalid_argument("Invalid author");
        }
    }
    for(size_t i =0;i <author_last_name.size(); i +=1){
        if(!is_letter(author_last_name[i])) {throw std::invalid_argument("Invalid author");
        }
    }

    if(!(isbn.size() ==10 ||isbn.size() ==13)){throw std::invalid_argument("Invalid ISBN");
    }
    for(size_t i =0;i<isbn.size();i+=1){
        if(!(isbn[i]>='0'&&isbn[i] <='9')){
            throw std::invalid_argument("Invalid ISBN");
        }
    }

    this->title =title;
    author.first_name =author_first_name;
    author.last_name =author_last_name;
    this->isbn =isbn;
    this->available =available;
}

Book::Book(std::string title, AuthorName author, std::string isbn, bool available)
: title{}, author{}, isbn{}, available{} {
    // TODO(student)
    Book book(title,author.first_name,author.last_name,isbn,available);
    this->title =book.get_title();
    this->author =book.get_author();
    this->isbn =book.get_isbn();
    this->available =book.is_available();
}

const std::string& Book::get_title() const {
    // TODO(student)
    return title;
}

const AuthorName& Book::get_author() const {
    // TODO(student)
    return author;
}

const std::string& Book::get_isbn() const {
    // TODO(student)
    return isbn;
}

bool Book::is_available() const {
    // TODO(student)
    return available;
}

bool Book::borrow_book() {
    // TODO(student)
    if(!available){
        return false;
    }
    available =false;
    return true;
}

bool Book::return_book() {
    // TODO(student)
    if(available){
        return false;
    }
    available =true;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    // TODO(student)
    os<<"title: \""<<book.get_title()<<"\" by "<<book.get_author().first_name;
    if(!book.get_author().last_name.empty()){
        os<<" "<<book.get_author().last_name;
    }
    os<<", isbn: "<<book.get_isbn();
    return os;
}
