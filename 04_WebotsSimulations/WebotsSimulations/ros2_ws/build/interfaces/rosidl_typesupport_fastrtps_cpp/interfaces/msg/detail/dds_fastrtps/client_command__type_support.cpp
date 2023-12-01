// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/ClientCommand.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/client_command__rosidl_typesupport_fastrtps_cpp.hpp"
#include "interfaces/msg/detail/client_command__struct.hpp"

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
  const interfaces::msg::ClientCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: up
  cdr << (ros_message.up ? true : false);
  // Member: down
  cdr << (ros_message.down ? true : false);
  // Member: right
  cdr << (ros_message.right ? true : false);
  // Member: left
  cdr << (ros_message.left ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  interfaces::msg::ClientCommand & ros_message)
{
  // Member: up
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.up = tmp ? true : false;
  }

  // Member: down
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.down = tmp ? true : false;
  }

  // Member: right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right = tmp ? true : false;
  }

  // Member: left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
get_serialized_size(
  const interfaces::msg::ClientCommand & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: up
  {
    size_t item_size = sizeof(ros_message.up);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: down
  {
    size_t item_size = sizeof(ros_message.down);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right
  {
    size_t item_size = sizeof(ros_message.right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left
  {
    size_t item_size = sizeof(ros_message.left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
max_serialized_size_ClientCommand(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: up
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: down
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ClientCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const interfaces::msg::ClientCommand *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ClientCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<interfaces::msg::ClientCommand *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ClientCommand__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const interfaces::msg::ClientCommand *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ClientCommand__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ClientCommand(full_bounded, 0);
}

static message_type_support_callbacks_t _ClientCommand__callbacks = {
  "interfaces::msg",
  "ClientCommand",
  _ClientCommand__cdr_serialize,
  _ClientCommand__cdr_deserialize,
  _ClientCommand__get_serialized_size,
  _ClientCommand__max_serialized_size
};

static rosidl_message_type_support_t _ClientCommand__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ClientCommand__callbacks,
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
get_message_type_support_handle<interfaces::msg::ClientCommand>()
{
  return &interfaces::msg::typesupport_fastrtps_cpp::_ClientCommand__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, msg, ClientCommand)() {
  return &interfaces::msg::typesupport_fastrtps_cpp::_ClientCommand__handle;
}

#ifdef __cplusplus
}
#endif
