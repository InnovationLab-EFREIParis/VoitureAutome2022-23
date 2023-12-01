// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Sensors.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SENSORS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__SENSORS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'example_sensor1_name'
// Member 'example_sensor2_name'
// Member 'example_sensor3_name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Sensors in the package interfaces.
typedef struct interfaces__msg__Sensors
{
  rosidl_runtime_c__String example_sensor1_name;
  int64_t example_sensor1_value;
  rosidl_runtime_c__String example_sensor2_name;
  int64_t example_sensor2_value;
  rosidl_runtime_c__String example_sensor3_name;
  int64_t example_sensor3_value;
} interfaces__msg__Sensors;

// Struct for a sequence of interfaces__msg__Sensors.
typedef struct interfaces__msg__Sensors__Sequence
{
  interfaces__msg__Sensors * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Sensors__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__SENSORS__STRUCT_H_
