// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/MonAckermannDrive.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/mon_ackermann_drive__rosidl_typesupport_fastrtps_cpp.hpp"
#include "interfaces/msg/detail/mon_ackermann_drive__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_serialize(
  const interfaces::msg::MonAckermannDrive & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: steering_angle
  cdr << ros_message.steering_angle;
  // Member: steering_angle_velocity
  cdr << ros_message.steering_angle_velocity;
  // Member: speed
  cdr << ros_message.speed;
  // Member: acceleration
  cdr << ros_message.acceleration;
  // Member: jerk
  cdr << ros_message.jerk;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  interfaces::msg::MonAckermannDrive & ros_message)
{
  // Member: steering_angle
  cdr >> ros_message.steering_angle;

  // Member: steering_angle_velocity
  cdr >> ros_message.steering_angle_velocity;

  // Member: speed
  cdr >> ros_message.speed;

  // Member: acceleration
  cdr >> ros_message.acceleration;

  // Member: jerk
  cdr >> ros_message.jerk;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
get_serialized_size(
  const interfaces::msg::MonAckermannDrive & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: steering_angle
  {
    size_t item_size = sizeof(ros_message.steering_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steering_angle_velocity
  {
    size_t item_size = sizeof(ros_message.steering_angle_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed
  {
    size_t item_size = sizeof(ros_message.speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acceleration
  {
    size_t item_size = sizeof(ros_message.acceleration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: jerk
  {
    size_t item_size = sizeof(ros_message.jerk);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
max_serialized_size_MonAckermannDrive(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: steering_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: steering_angle_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: acceleration
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: jerk
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MonAckermannDrive__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const interfaces::msg::MonAckermannDrive *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MonAckermannDrive__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<interfaces::msg::MonAckermannDrive *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MonAckermannDrive__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const interfaces::msg::MonAckermannDrive *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MonAckermannDrive__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MonAckermannDrive(full_bounded, 0);
}

static message_type_support_callbacks_t _MonAckermannDrive__callbacks = {
  "interfaces::msg",
  "MonAckermannDrive",
  _MonAckermannDrive__cdr_serialize,
  _MonAckermannDrive__cdr_deserialize,
  _MonAckermannDrive__get_serialized_size,
  _MonAckermannDrive__max_serialized_size
};

static rosidl_message_type_support_t _MonAckermannDrive__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MonAckermannDrive__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::msg::MonAckermannDrive>()
{
  return &interfaces::msg::typesupport_fastrtps_cpp::_MonAckermannDrive__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, msg, MonAckermannDrive)() {
  return &interfaces::msg::typesupport_fastrtps_cpp::_MonAckermannDrive__handle;
}

#ifdef __cplusplus
}
#endif
