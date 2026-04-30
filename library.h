// provided. do not change. do not submit.
#ifndef PROVIDED_LIBRARY_H_
#define PROVIDED_LIBRARY_H_

#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "member.h"

class Library {
    std::vector<Book> books;
    std::vector<Member> members;

 public:
    /**
     * Construct a new instance of Library.
     */
    Library() : books{}, members{} {};

    /**
     * Add a book to the library.
     *
     * @param book the book to add
     */
    void add_book(Book book);

    /**
     * Add a member to the library.
     *
     * @param member the member to add
     */
    void register_member(Member member);

    /**
     * Borrow a book from the library.
     *
     * @param isbn isbn of the book to borrow
     * @param member_id the id of the member borrowing the book
     * @param[out] message a message about the operation
     * @returns true if the operation was successful, false otherwise
     */
    bool borrow_book(const std::string& isbn, int member_id, std::string& message);

    /**
     * Return a book to the library.
     *
     * @param isbn isbn of the book to borrow
     * @param[out] message a message about the operation
     * @returns true if the operation was successful, false otherwise
     */
    bool return_book(const std::string& isbn, std::string& message);

    /**
     * @brief List the available books.
     *
     * Inserts the books, one per line, into the output stream
     *
     * @param os output stream
     */
    void display_available_books(std::ostream& os = std::cout);

    /**
     * @brief List the library members.
     *
     * Inserts the members, one per line, into the output stream
     *
     * @param os output stream
     */
    void display_library_members(std::ostream& os = std::cout);

    /**
     * @returns true if the book is available.
     */
    bool is_book_available(const std::string& isbn);

    /**
     * Get the books in the library.
     *
     * @returns a constant reference to the collection of books
     *
     * @note for testing purposes only
     */
    const std::vector<Book>& get_books() { return books; }

    /**
     * Get the members of the library.
     *
     * @returns a constant reference to the collection of members
     *
     * @note for testing purposes only
     */
    const std::vector<Member>& get_members() { return members; }
};

#endif  // PROVIDED_LIBRARY_H_
