#include "logger.hpp"

int main(void)
{
    Logger l("INFO");
    l.log("Sistema iniciado");
    l.log("Tudo ok");
    return 0;
}
