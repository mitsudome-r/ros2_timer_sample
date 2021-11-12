#include <ros2_timer_test/generic_timer.hpp>


GenericTimerTestComponent::GenericTimerTestComponent(const rclcpp::NodeOptions & node_options)
: Node("generic_timer_test", node_options)
{
    double update_period = 1.0;

    // Timer
    auto timer_callback = std::bind(&GenericTimerTestComponent::onTimer, this);
    auto period = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::duration<double>(update_period));
    timer_ = std::make_shared<rclcpp::GenericTimer<decltype(timer_callback)>>(
        this->get_clock(), period, std::move(timer_callback),
        this->get_node_base_interface()->get_context());
    this->get_node_timers_interface()->add_timer(timer_, nullptr);

}

void GenericTimerTestComponent::onTimer()
{
    RCLCPP_INFO(get_logger(), "onTimer() called!");
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(GenericTimerTestComponent)
