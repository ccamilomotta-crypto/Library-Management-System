// provided. do not change. do not submit.
#ifndef PROVIDED_BOOK_H_
#define PROVIDED_BOOK_H_

#include <iostream>
#include <string>

struct AuthorName {
    std::string first_name;
    std::string last_name;
};

class Book {
    std::string title;
    AuthorName author;
    std::string isbn;
    bool available;

 public:
    /**
     * Constructs a new instance of Book.
     *
     * @param title
     * @param author_first_name
     * @param author_last_name
     * @param isbn
     * @param available
     */
    Book(std::string title,
         std::string author_first_name,
         std::string author_last_name,
         std::string isbn,
         bool available = true);

    /**
     * Constructs a new instance of Book.
     *
     * @param title
     * @param author
     * @param isbn
     * @param available
     */
    Book(std::string title,
         AuthorName author,
         std::string isbn,
         bool available = true);

    const std::string& get_title() const;
    const AuthorName& get_author() const;
    const std::string& get_isbn() const;
    bool is_available() const;

    /**
     * Make the book unavailable because it was borrowed.
     *
     * @returns true if the book was available, false otherwise
     */
    bool borrow_book();

    /**
     * Make the book available because it was returned
     *
     * @returns true if the book was not available, false otherwise
     */
    bool return_book();
};

/**
 * Inserts a Book into an output stream
 *
 * @param os the output stream
 * @param book the book
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const Book& book);

#endif  // PROVIDED_BOOK_H_
