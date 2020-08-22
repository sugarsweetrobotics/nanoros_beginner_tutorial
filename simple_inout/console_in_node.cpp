#include <iostream>
#include <set>
#include <thread>


#include "nanoros/nanoros.h"
#include "nanoros/rosnode.h"
#include "beginner_tutorial_msgs/msg/Num.h"


int main(const int argc, const char* argv[]) {
    ssr::nanoros::init_nanoros(argc, argv);
    std::cout << "Starting nanoros console_in" << std::endl;

    auto node = ssr::nanoros::registerROSNode("/console_in");
    auto pub =  node->advertise<ssr::nanoros::beginner_tutorial_msgs::Num>("/number");
    if (!pub) {
        std::cout << "Publisher advertise failed." << std::endl;
        return -1;
    }
    
    ssr::nanoros::beginner_tutorial_msgs::Num value;
    value.data = 0;

    const ssr::nanoros::Duration duration(1.0);
    int i = 0;
    while(!ssr::nanoros::is_shutdown()) {
      std::cout << "Input Value:" << std::ends;
      std::string line;
      std::getline(std::cin, line);
      value.data = atoi(line.c_str());
      std::cout << "console_in [" << i << "]: " << value.data << std::endl;
      pub->publish(value);
      node->spinOnce();
      ssr::nanoros::sleep_for(duration);
      i++;
    }
    std::cout << "shutting down node" << std::endl;
    return 0;
}
