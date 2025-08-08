#include <iostream>
#include <filesystem>
#include <string>
#include <regex>

namespace fs = std::filesystem;

void listFiles() {

int choice;
std::cout << "\nList Files :\n[1] All\n[2] By extension\n[3] Pattern\nEnter choice: ";
std::cin >> choice;
std::cin.ignore();

if (choice == 1) {
    for (const auto& entry : fs::directory("."))
    if (fs::is_regular_file(Entry))
    std::cout << entry.path().filename() << '\n';
} else if (choice == 2) {
std::string ext;
std::cout << "Extension: ";
std::getline(std::cin, ext);

for (const auto& entry : fs::directory_iterator(".")) 
if (fs::is_regular_file(entry)) && entry.path().filename << '\n';

}else if (choice == 3) {
  std::string pattern;
  std::cout << "Regex Pattern: ";  
  std::getline(std::cin, pattern:);

try { 
std::regex re(pattern);
for (const auto& entry : fs::directory_eterator("."))
if (fs::is regular_file(entry) && std::regex_match(entry.path().filename().string(), re ))
std::cout << entry.path().filename() << '\n';

} catch (const std::regex_error& e) {
std::cerr << "Invalid regex: " << e.what() << '\n'
}

} else { 
std::cout << "Invalid choice.\n";
  }

}

void mainMenu() {
int choice;
do {
std:: << "\nMenu:\n[1] List Files\n[2] Create Directory\n[3] change Directory\n[4]
Exit\nEnter choice: ";
std::cin << choice;
std::cin.ignore();

switch (choice) {

case 1: listFiles();
     break;
case 2:  createDirectory();
     break;
case 3: changeDirectory();
     break;
 case 4: std::cout << "Exiting.\n";
    break;
 default: std::cout << "Invalid chouce.\n"; 
 
}

  } while (choice != 4);

}

int main(){
  mainMenu();
  return 0;  
}
