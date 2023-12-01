// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from interfaces:msg/Sensors.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/sensors__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interfaces/msg/detail/sensors__struct.h"
#include "interfaces/msg/detail/sensors__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // example_sensor1_name, example_sensor2_name, example_sensor3_name
#include "rosidl_runtime_c/string_functions.h"  // example_sensor1_name, example_sensor2_name, example_sensor3_name

// forward declare type support functions


using _Sensors__ros_msg_type = interfaces__msg__Sensors;

static bool _Sensors__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Sensors__ros_msg_type * ros_message = static_cast<const _Sensors__ros_msg_type *>(untyped_ros_message);
  // Field name: example_sensor1_name
  {
    const rosidl_runtime_c__String * str = &ros_message->example_sensor1_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: example_sensor1_value
  {
    cdr << ros_message->example_sensor1_value;
  }

  // Field name: example_sensor2_name
  {
    const rosidl_runtime_c__String * str = &ros_message->example_sensor2_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: example_sensor2_value
  {
    cdr << ros_message->example_sensor2_value;
  }

  // Field name: example_sensor3_name
  {
    const rosidl_runtime_c__String * str = &ros_message->example_sensor3_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: example_sensor3_value
  {
    cdr << ros_message->example_sensor3_value;
  }

  return true;
}

static bool _Sensors__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Sensors__ros_msg_type * ros_message = static_cast<_Sensors__ros_msg_type *>(untyped_ros_message);
  // Field name: example_sensor1_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->example_sensor1_name.data) {
      rosidl_runtime_c__String__init(&ros_message->example_sensor1_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->example_sensor1_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'example_sensor1_name'\n");
      return false;
    }
  }

  // Field name: example_sensor1_value
  {
    cdr >> ros_message->example_sensor1_value;
  }

  // Field name: example_sensor2_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->example_sensor2_name.data) {
      rosidl_runtime_c__String__init(&ros_message->example_sensor2_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->example_sensor2_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'example_sensor2_name'\n");
      return false;
    }
  }

  // Field name: example_sensor2_value
  {
    cdr >> ros_message->example_sensor2_value;
  }

  // Field name: example_sensor3_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->example_sensor3_name.data) {
      rosidl_runtime_c__String__init(&ros_message->example_sensor3_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->example_sensor3_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'example_sensor3_name'\n");
      return false;
    }
  }

  // Field name: example_sensor3_value
  {
    cdr >> ros_message->example_sensor3_value;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t get_serialized_size_interfaces__msg__Sensors(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Sensors__ros_msg_type * ros_message = static_cast<const _Sensors__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name example_sensor1_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->example_sensor1_name.size + 1);
  // field.name example_sensor1_value
  {
    size_t item_size = sizeof(ros_message->example_sensor1_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name example_sensor2_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->example_sensor2_name.size + 1);
  // field.name example_sensor2_value
  {
    size_t item_size = sizeof(ros_message->example_sensor2_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name example_sensor3_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->example_sensor3_name.size + 1);
  // field.name example_sensor3_value
  {
    size_t item_size = sizeof(ros_message->example_sensor3_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Sensors__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interfaces__msg__Sensors(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t max_serialized_size_interfaces__msg__Sensors(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: example_sensor1_name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: example_sensor1_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: example_sensor2_name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: example_sensor2_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: example_sensor3_name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: example_sensor3_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Sensors__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_interfaces__msg__Sensors(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Sensors = {
  "interfaces::msg",
  "Sensors",
  _Sensors__cdr_serialize,
  _Sensors__cdr_deserialize,
  _Sensors__get_serialized_size,
  _Sensors__max_serialized_size
};

static rosidl_message_type_support_t _Sensors__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Sensors,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, msg, Sensors)() {
  return &_Sensors__type_support;
}

#if defined(__cplusplus)
}
#endif
