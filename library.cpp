#include <iostream>
#include <sstream>
#include <string>
#include "library.h"
#include "lms_utilities.h"

void Library::add_book(Book book) {
    // TODO(student)
    books.push_back(book);
}

void Library::register_member(Member member) {
    // TODO(student)
    members.push_back(member);
}

bool Library::borrow_book(const std::string& isbn, int member_id, std::string& message) {
    // TODO(student)
    int book_index =-1;
    for(size_t i =0;i <books.size();i +=1){
        if(books[i].get_isbn() ==isbn){
            book_index = static_cast<int>(i);
            break;
        }
    }

    if(book_index ==-1||!books[book_index].is_available()){
        message ="Book ISBN: " +isbn+" not available";
        return false;
    }

    int member_index =-1;
    for(size_t i =0; i <members.size();i+=1){
        if(members[i].get_id() ==member_id){
            member_index = static_cast<int>(i);
            break;
        }
    }

    if(member_index ==-1){
        std::stringstream ss;
        ss<<"Member "<< member_id<<" not found";
        message =ss.str();
        return false;
    }

    books[book_index].borrow_book();
    std::stringstream ss;
    ss<<members[member_index]<<" borrowed "<<books[book_index];
    message =ss.str();
    return true;
}

bool Library::return_book(const std::string& isbn, std::string& message) {
    // TODO(student)
    int book_index =-1;
    for(size_t i =0;i<books.size(); i += 1){
        if(books[i].get_isbn() ==isbn){
            book_index = static_cast<int>(i);
            break;
        }
    }

    if(book_index==-1){
        message ="Book ISBN: " +isbn+" not found";
        return false;
    }
    if(books[book_index].is_available()){
        message ="Book ISBN: " +isbn+" still available (cannot be returned)";
        return false;
    }

    books[book_index].return_book();
    message ="Book \""+books[book_index].get_title() +"\" returned";
    return true;
}

void Library::display_available_books(std::ostream& os) {
    // TODO(student)
    // use the ostream parameter, NOT std::cout
    for(size_t i=0;i<books.size(); i+=1){
        if(books[i].is_available()){
            os<<books[i]<<std::endl;
        }
    }
}

void Library::display_library_members(std::ostream& os) {
    // TODO(student)
    // use the ostream parameter, NOT std::cout
    for(size_t i =0;i<members.size();i+=1){
        os<<members[i]<<std::endl;
    }
}

bool Library::is_book_available(const std::string& isbn) {
    // TODO(student)
    for(size_t i=0;i<books.size();i+=1){
        if(books[i].get_isbn()==isbn){
            return books[i].is_available();
        }
    }
    return false;
}
