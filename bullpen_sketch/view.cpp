#include "view.hpp"

View::View(String SSID, String pwd, const int port,std::vector<Person> inList, std::vector<Person> outList):server(port), isSSIDReconfiged(false), status(WL_IDLE_STATUS){}
