#include <iostream>
#include "Tests/Tests.h"

#include "Service/Service.h"
#include "UI/UI.h"
int main() {
//    test_all();
    Repo_file_product r("products.txt");
    Repo_file_money rb("currencies.txt");
    clear_file("products.txt");
    clear_file("currencies.txt");
    Service s(r,rb);
    UI ui(s);
    ui.run_menu();
    return 0;
}
