#include "disk_manager.h"
#include <iostream>

DiskManager::DiskManager(const std::string &db_file) :
    db_file_name_(db_file)
{
    // Try to open the existing file for reading and writing.
    db_file_.open(db_file_name_, std::ios::in | std::ios::out | std::ios::binary);

    // If that failed, the file doesn't exist yet — so create it.
    if (!db_file_.is_open()) {
        db_file_.clear();                                               // wipe the error flags left by the failed open
        db_file_.open(db_file_name_, std::ios::out | std::ios::binary); // 'out' alone creates the file
        db_file_.close();                                               // close the empty file we just made
        db_file_.open(db_file_name_, std::ios::in | std::ios::out | std::ios::binary); // reopen, now it exists
    }

    db_file_.seekg(0, std::ios::end);
    int64_t file_size = db_file_.tellg();
    next_page_id_ = file_size / PAGE_SIZE;

    std::cout << "next_page_id_ = " << next_page_id_ << "\n";
}