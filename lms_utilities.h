// provided. do not change. do not submit.
#ifndef PROVIDED_LMS_UTILITIES_H_
#define PROVIDED_LMS_UTILITIES_H_

#include <string>
#include <vector>
#include "library.h"

/**
 * Load book data from a text file into a Library.
 *
 * @param[out] library
 * @param filename
 * @returns number of books added
 */
int read_list_of_books(Library& library, const std::string& filename);

/**
 * Load member data from a text file into a Library.
 *
 * @param[out] library
 * @param filename
 * @returns number of members added
 */
int read_list_of_members(Library& library, const std::string& filename);

/**
 * Load book borrowing data from a text file into a Library.
 *
 * @param[out] library
 * @param filename
 * @returns number of books borrowed
 */
int read_list_of_borrowed_books(Library& library, const std::string& filename);

/**
 * Load book returning data from a text file into a Library.
 *
 * @param[out] library
 * @param filename
 * @returns number of books returned
 */
int read_list_of_returned_books(Library& library, const std::string& filename);

#endif  // PROVIDED_LMS_UTILITIES_H_
