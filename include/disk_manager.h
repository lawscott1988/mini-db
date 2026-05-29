#pragma once
#include <fstream>
#include <string>
#include "config.h"

class DiskManager {
public:
    explicit DiskManager(const std::string &db_file);
    // ~DiskManager();

    // void WritePage(page_id_t page_id, const char *data);
    // void ReadPage(page_id_t page_id, char *data);
    // page_id_t AllocatePage();

private:
    std::fstream db_file_;
    std::string db_file_name_;
    page_id_t next_page_id_;
};