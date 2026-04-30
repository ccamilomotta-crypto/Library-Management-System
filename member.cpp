#include <string>
#include "member.h"

Member::Member(std::string first_name, std::string last_name, int id) : name{}, id{} {
    // TODO(student)
    auto is_letter =[](char c){
        return(c>='A'&&c<='Z')||(c>='a'&&c<='z');
    };

    if(first_name.empty()){
        throw std::invalid_argument("Invalid name");
    }
    for(size_t i=0;i<first_name.size();i+=1){
        if(!is_letter(first_name[i])){
            throw std::invalid_argument("Invalid name");
        }
    }
    for(size_t i=0; i <last_name.size(); i+=1){
        if(!is_letter(last_name[i])){
            throw std::invalid_argument("Invalid name");
        }
    }
    if(id <1000){
        throw std::invalid_argument("Invalid id");
    }

    name.first_name =first_name;
    name.last_name =last_name;
    this->id =id;
}

Member::Member(MemberName name, int id) : name{}, id{} {
    // TODO(student)
    Member member(name.first_name,name.last_name,id);
    this->name =member.get_name();
    this->id =member.get_id();
}

const MemberName& Member::get_name() const {
    // TODO(student)
    return name;
}

int Member::get_id() const {
    // TODO(student)
    return id;
}

std::ostream& operator<<(std::ostream& os, const Member& member) {
    // TODO(student)
    os<<"Member: "<<member.get_name().first_name;
    if(!member.get_name().last_name.empty()){
        os<<" "<<member.get_name().last_name;
    }
    os<<", id: "<<member.get_id();
    return os;
}
