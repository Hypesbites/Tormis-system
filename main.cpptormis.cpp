#include <iostream>
#include <filesystem>
#include <string>
#include <regex>

namespace fs = std::filesystem;

void listFiles() {
int choice;
std::cout << "\nList Files:\n[1] All\n[2] By Extension\n[3] By Pattern\nEnter choice: ";
std::cin >> choice;
std::cin.ignore(); // Consume newline
if (choice == 1) {
for (const auto& entry : fs::directory_iterator("."))
if (fs::is_regular_file(entry))
std::cout << entry.path().filename() << '\n';
} else if (choice == 2) {
std::string ext;
std::cout << "Extension: ";
std::getline(std::cin, ext);
for (const auto& entry : fs::directory_iterator("."))
if (fs::is_regular_file(entry) && entry.path().extension() == ext)
std::cout << entry.path().filename() << '\n';
} else if (choice == 3) {
std::string pattern;
std::cout << "Regex Pattern: ";
std::getline(std::cin, pattern);
try {
std::regex re(pattern);
for (const auto& entry : fs::directory_iterator("."))
if (fs::is_regular_file(entry) && std::regex_match(entry.path().filename().string(), re))
std::cout << entry.path().filename() << '\n';
} catch (const std::regex_error& e) {
std::cerr << "Invalid regex: " << e.what() << '\n';
}
} else {
std::cout << "Invalid choice.\n";
}
}
void createDirectory() {
std::string dirName;
std::cout << "Directory name: ";
std::getline(std::cin, dirName);
try {
if (fs::create_directory(dirName))
std::cout << "Directory '" << dirName << "' created.\n";
else
std::cerr << "Failed to create directory.\n";
} catch (const std::exception& e) {
std::cerr << "Error: " << e.what() << '\n';
}
}
void changeDirectory() {
std::string dirPath;
std::cout << "Directory path: ";
std::getline(std::cin, dirPath);
if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
try {
fs::current_path(dirPath);
std::cout << "Working directory changed to: " << fs::current_path() << '\n';
} catch (const std::exception& e) {
std::cerr << "Error changing directory: " << e.what() << '\n';
}
} else {
std::cerr << "Directory not found.\n";
}
}
void mainMenu() {
int choice;
do {
std::cout << "\nMenu:\n[1] List Files\n[2] Create Directory\n[3] Change Directory\n[4] Exit\nEnter
choice: ";
std::cin >> choice;
std::cin.ignore(); // Consume newline
switch (choice) {
case 1: listFiles(); break;
case 2: createDirectory(); break;
case 3: changeDirectory(); break;
case 4: std::cout << "Exiting.\n"; break;
default: std::cout << "Invalid choice.\n";
}
} while (choice != 4);
}
int main() {
mainMenu();
return 0;
