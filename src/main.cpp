#include <magic.h>

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <optional>
#include <regex>
#include <sstream>
#include <string>

#define GRAY "\033[90m"
#define WHITE "\033[0m"
namespace fs = std::filesystem;

bool search_file_name(const fs::path &path, const std::string &name) {
    std::string str = path.string();
    return std::regex_match(str, std::regex(name, std::regex_constants::icase));
}

void search_in_path(const fs::path &path, const std::string &name) {
    for (const auto &entry : fs::directory_iterator(path)) {
        fs::path p = entry.path();
        if (fs::is_regular_file(p) && search_file_name(p.filename(), name)) {
            std::cout << p;

            if (fs::is_symlink(p)) {
                std::cout << GRAY << " symlink to " << fs::read_symlink(p) << WHITE << std::endl;
            } else {
                magic_t magic_cookie = magic_open(MAGIC_SYMLINK | MAGIC_MIME_TYPE);
                magic_load(magic_cookie, nullptr);
                std::cout << GRAY << " [" << magic_file(magic_cookie, p.c_str()) << "]" << WHITE
                          << std::endl;
                magic_close(magic_cookie);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "too few arguments" << std::endl;
        return -1;
    }

    std::string path = std::getenv("PATH");
    std::stringstream ss;

    for (char ch : path) {
        if (ch != ':') {
            ss << ch;
        } else {
            search_in_path(ss.str(), argv[1]);
            ss.str("");
        }
    }

    return 0;
}
