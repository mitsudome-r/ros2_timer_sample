#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/header.hpp>


class CreateTimerTestComponent: public rclcpp::Node
{
public:
  explicit CreateTimerTestComponent(const rclcpp::NodeOptions & node_options);

private:

  // Timer
  rclcpp::TimerBase::SharedPtr timer_;
  void onTimer();
};

