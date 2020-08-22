#include <iostream>
#include <set>
#include <thread>


#include "nanoros/nanoros.h"
#include "nanoros/rosnode.h"
#include "beginner_tutorial_msgs/msg/Num.h"


int main(const int argc, const char* argv[]) {
    ssr::nanoros::init_nanoros(argc, argv);

    const ssr::nanoros::Duration duration(1.0);

    auto node = ssr::nanoros::registerROSNode("/console_out");
    node->subscribe<ssr::nanoros::beginner_tutorial_msgs::Num>("/number", [](const std::shared_ptr<const ssr::nanoros::beginner_tutorial_msgs::Num>& msg) {
        std::cout << "console_out: " << msg->data << std::endl;
    });
    
    while(!ssr::nanoros::is_shutdown()) {
        ssr::nanoros::sleep_for(duration);
        node->spinOnce();
    }

    return 0;
}
