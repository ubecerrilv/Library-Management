/**
 * Created by ubecerril 2/20/2026
 *
 * This project is for the administration of a library, you can add, remove and read
 * users and books.
 */
#include "Controller/Controller.h"
#include "Model/LibraryDB.h"
#include "View/View.h"

int main() {
    // Create MVC architecture
    const LibraryDB library{};
    constexpr View view{};
    Controller controller(library, view);

    // Init program
    controller.init();

    return 0;
}