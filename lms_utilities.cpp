#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "book.h"
#include "member.h"
#include "library.h"
#include "lms_utilities.h"

int read_list_of_books(Library& library, const std::string& filename) {
    // TODO(student)
    std::ifstream input(filename);
    if(!input.is_open()){
        throw std::runtime_error("Cannot open "+filename);
    }

    int count=0;
    std::string title;
    std::string author_line;
    std::string isbn;

    while(std::getline(input,title)){
        if(!std::getline(input,author_line)){
            break;
        }
        if(!std::getline(input,isbn)){
            break;
        }

        std::stringstream author_stream(author_line);
        std::string first_name;
        std::string last_name;
        std::string extra;
        author_stream>>first_name>>last_name>>extra;

        if(!extra.empty()){
            continue;
        }

        try{
            Book book(title,first_name,last_name,isbn);
            library.add_book(book);
            count+=1;
        }catch(const std::invalid_argument&){
        }
    }
    return count;
}

int read_list_of_members(Library& library, const std::string& filename) {
    // TODO(student)
    std::ifstream input(filename);
    if(!input.is_open()){
        throw std::runtime_error("Cannot open "+filename);
    }

    int count =0;
    int next_id =1000;
    std::string line;

    while(std::getline(input, line)){
        std::stringstream member_stream(line);
        std::string first_name;
        std::string last_name;
        std::string extra;
        member_stream>>first_name>>last_name>>extra;

        if(!extra.empty()){
            continue;
        }

        try{
            Member member(first_name,last_name,next_id);
            library.register_member(member);
            count +=1;
            next_id +=1;
        } catch(const std::invalid_argument&){
        }
    }
    return count;
}

int read_list_of_borrowed_books(Library& library, const std::string& filename) {
    // TODO(student)
    std::ifstream input(filename);
    if(!input.is_open()){
        throw std::runtime_error("Cannot open "+filename);
    }

    int count =0;
    std::string line;

    while(std::getline(input,line)){
        std::stringstream line_stream(line);
        std::string isbn;
        int member_id =0;
        std::string extra;

        if(!(line_stream>>isbn>>member_id)){
            continue;
        }
        if(line_stream>>extra){
            continue;
        }

        std::string message;
        if(library.borrow_book(isbn, member_id, message)){
            count+=1;
        }
    }
    return count;
}

int read_list_of_returned_books(Library& library, const std::string& filename) {
    // TODO(student)
    std::ifstream input(filename);
    if(!input.is_open()){
        throw std::runtime_error("Cannot open "+filename);
    }

    int count=0;
    std::string line;

    while(std::getline(input, line)){
        std::stringstream line_stream(line);
        std::string isbn;
        std::string extra;

        if(!(line_stream>>isbn)){
            continue;
        }
        if(line_stream>>extra){
            continue;
        }

        std::string message;
        if(library.return_book(isbn, message)){
            count +=1;
        }
    }
    return count;
}
