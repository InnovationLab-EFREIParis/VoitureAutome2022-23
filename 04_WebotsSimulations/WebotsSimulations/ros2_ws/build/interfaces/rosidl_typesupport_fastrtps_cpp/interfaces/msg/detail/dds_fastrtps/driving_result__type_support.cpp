// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/DrivingResult.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/driving_result__rosidl_typesupport_fastrtps_cpp.hpp"
#include "interfaces/msg/detail/driving_result__struct.hpp"

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
bool cdr_serialize(
  const interfaces::msg::MonAckermannDrive &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  interfaces::msg::MonAckermannDrive &);
size_t get_serialized_size(
  const interfaces::msg::MonAckermannDrive &,
  size_t current_alignment);
size_t
max_serialized_size_MonAckermannDrive(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace interfaces


namespace interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_serialize(
  const interfaces::msg::DrivingResult & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: instruction
  interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.instruction,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  interfaces::msg::DrivingResult & ros_message)
{
  // Member: instruction
  interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.instruction);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
get_serialized_size(
  const interfaces::msg::DrivingResult & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: instruction

  current_alignment +=
    interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.instruction, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
max_serialized_size_DrivingResult(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: instruction
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_MonAckermannDrive(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _DrivingResult__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const interfaces::msg::DrivingResult *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DrivingResult__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<interfaces::msg::DrivingResult *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DrivingResult__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const interfaces::msg::DrivingResult *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DrivingResult__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_DrivingResult(full_bounded, 0);
}

static message_type_support_callbacks_t _DrivingResult__callbacks = {
  "interfaces::msg",
  "DrivingResult",
  _DrivingResult__cdr_serialize,
  _DrivingResult__cdr_deserialize,
  _DrivingResult__get_serialized_size,
  _DrivingResult__max_serialized_size
};

static rosidl_message_type_support_t _DrivingResult__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DrivingResult__callbacks,
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
get_message_type_support_handle<interfaces::msg::DrivingResult>()
{
  return &interfaces::msg::typesupport_fastrtps_cpp::_DrivingResult__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, msg, DrivingResult)() {
  return &interfaces::msg::typesupport_fastrtps_cpp::_DrivingResult__handle;
}

#ifdef __cplusplus
}
#endif
