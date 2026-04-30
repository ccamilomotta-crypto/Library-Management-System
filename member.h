// provided. do not change. do not submit.
#ifndef PROVIDED_MEMBER_H_
#define PROVIDED_MEMBER_H_

#include <iostream>
#include <string>

struct MemberName {
    std::string first_name;
    std::string last_name;
};

class Member {
    MemberName name;
    int id;

 public:
    /**
     * Construct a new instance of Member.
     *
     * @param first_name
     * @param last_name
     * @param id
     */
    Member(std::string first_name, std::string last_name, int id);

    /**
     * Construct a new instance of Member.
     *
     * @param name
     * @param id
     */
    Member(MemberName name, int id);

    const MemberName& get_name() const;
    int get_id() const;
};

/**
 * Inserts a Member into an output stream
 *
 * @param os the output stream
 * @param member the member
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const Member& member);

#endif  // PROVIDED_MEMBER_H_
