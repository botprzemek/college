#include <stdlib.h>
#include <printf.h>

#include "Logger.h"

int main() {
    struct Logger* logger = getLogger();

    while (1) {
        logger->title("Basketball Player Manager");

        for (int i = 1; i < 3; i++) { //Constants::OPTIONS.size(); i++) {

            char* message = malloc(32 * sizeof(char));

            sprintf(&message[i], "%d", i);

            printf("Int: %d, element: %c", i, message[i]);

            logger->message(message);

            free(message);
//            logger->message(i + ". " + Constants::OPTIONS.at(i));
        }

        int option = logger->getInt("option: ");

        switch (option) {
            case 1:
//                manager->create();
                break;
            case 2:
//                manager->edit();
                break;
            case 3:
//                manager->view();
                break;
            case 4:
//                manager->save();
                free(logger);
                return 0;
            default:
                break;
        }
    }
}