#include <rclcpp/rclcpp.hpp>
#include "pub_node.hpp"

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

