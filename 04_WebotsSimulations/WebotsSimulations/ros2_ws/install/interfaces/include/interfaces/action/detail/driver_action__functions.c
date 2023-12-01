// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:action/DriverAction.idl
// generated code does not contain a copyright notice
#include "interfaces/action/detail/driver_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `instruction`
#include "interfaces/msg/detail/driving_instruction__functions.h"

bool
interfaces__action__DriverAction_Goal__init(interfaces__action__DriverAction_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // instruction
  if (!interfaces__msg__DrivingInstruction__init(&msg->instruction)) {
    interfaces__action__DriverAction_Goal__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_Goal__fini(interfaces__action__DriverAction_Goal * msg)
{
  if (!msg) {
    return;
  }
  // instruction
  interfaces__msg__DrivingInstruction__fini(&msg->instruction);
}

bool
interfaces__action__DriverAction_Goal__are_equal(const interfaces__action__DriverAction_Goal * lhs, const interfaces__action__DriverAction_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // instruction
  if (!interfaces__msg__DrivingInstruction__are_equal(
      &(lhs->instruction), &(rhs->instruction)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_Goal__copy(
  const interfaces__action__DriverAction_Goal * input,
  interfaces__action__DriverAction_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // instruction
  if (!interfaces__msg__DrivingInstruction__copy(
      &(input->instruction), &(output->instruction)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_Goal *
interfaces__action__DriverAction_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Goal * msg = (interfaces__action__DriverAction_Goal *)allocator.allocate(sizeof(interfaces__action__DriverAction_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_Goal));
  bool success = interfaces__action__DriverAction_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_Goal__destroy(interfaces__action__DriverAction_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_Goal__Sequence__init(interfaces__action__DriverAction_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Goal * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_Goal *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_Goal__Sequence__fini(interfaces__action__DriverAction_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_Goal__Sequence *
interfaces__action__DriverAction_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Goal__Sequence * array = (interfaces__action__DriverAction_Goal__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_Goal__Sequence__destroy(interfaces__action__DriverAction_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_Goal__Sequence__are_equal(const interfaces__action__DriverAction_Goal__Sequence * lhs, const interfaces__action__DriverAction_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_Goal__Sequence__copy(
  const interfaces__action__DriverAction_Goal__Sequence * input,
  interfaces__action__DriverAction_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_Goal);
    interfaces__action__DriverAction_Goal * data =
      (interfaces__action__DriverAction_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "interfaces/msg/detail/driving_result__functions.h"

bool
interfaces__action__DriverAction_Result__init(interfaces__action__DriverAction_Result * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!interfaces__msg__DrivingResult__init(&msg->result)) {
    interfaces__action__DriverAction_Result__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_Result__fini(interfaces__action__DriverAction_Result * msg)
{
  if (!msg) {
    return;
  }
  // result
  interfaces__msg__DrivingResult__fini(&msg->result);
}

bool
interfaces__action__DriverAction_Result__are_equal(const interfaces__action__DriverAction_Result * lhs, const interfaces__action__DriverAction_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!interfaces__msg__DrivingResult__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_Result__copy(
  const interfaces__action__DriverAction_Result * input,
  interfaces__action__DriverAction_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!interfaces__msg__DrivingResult__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_Result *
interfaces__action__DriverAction_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Result * msg = (interfaces__action__DriverAction_Result *)allocator.allocate(sizeof(interfaces__action__DriverAction_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_Result));
  bool success = interfaces__action__DriverAction_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_Result__destroy(interfaces__action__DriverAction_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_Result__Sequence__init(interfaces__action__DriverAction_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Result * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_Result *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_Result__Sequence__fini(interfaces__action__DriverAction_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_Result__Sequence *
interfaces__action__DriverAction_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Result__Sequence * array = (interfaces__action__DriverAction_Result__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_Result__Sequence__destroy(interfaces__action__DriverAction_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_Result__Sequence__are_equal(const interfaces__action__DriverAction_Result__Sequence * lhs, const interfaces__action__DriverAction_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_Result__Sequence__copy(
  const interfaces__action__DriverAction_Result__Sequence * input,
  interfaces__action__DriverAction_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_Result);
    interfaces__action__DriverAction_Result * data =
      (interfaces__action__DriverAction_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `feedback`
#include "interfaces/msg/detail/driving_feedback__functions.h"

bool
interfaces__action__DriverAction_Feedback__init(interfaces__action__DriverAction_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // feedback
  if (!interfaces__msg__DrivingFeedback__init(&msg->feedback)) {
    interfaces__action__DriverAction_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_Feedback__fini(interfaces__action__DriverAction_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // feedback
  interfaces__msg__DrivingFeedback__fini(&msg->feedback);
}

bool
interfaces__action__DriverAction_Feedback__are_equal(const interfaces__action__DriverAction_Feedback * lhs, const interfaces__action__DriverAction_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // feedback
  if (!interfaces__msg__DrivingFeedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_Feedback__copy(
  const interfaces__action__DriverAction_Feedback * input,
  interfaces__action__DriverAction_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // feedback
  if (!interfaces__msg__DrivingFeedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_Feedback *
interfaces__action__DriverAction_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Feedback * msg = (interfaces__action__DriverAction_Feedback *)allocator.allocate(sizeof(interfaces__action__DriverAction_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_Feedback));
  bool success = interfaces__action__DriverAction_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_Feedback__destroy(interfaces__action__DriverAction_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_Feedback__Sequence__init(interfaces__action__DriverAction_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Feedback * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_Feedback *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_Feedback__Sequence__fini(interfaces__action__DriverAction_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_Feedback__Sequence *
interfaces__action__DriverAction_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_Feedback__Sequence * array = (interfaces__action__DriverAction_Feedback__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_Feedback__Sequence__destroy(interfaces__action__DriverAction_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_Feedback__Sequence__are_equal(const interfaces__action__DriverAction_Feedback__Sequence * lhs, const interfaces__action__DriverAction_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_Feedback__Sequence__copy(
  const interfaces__action__DriverAction_Feedback__Sequence * input,
  interfaces__action__DriverAction_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_Feedback);
    interfaces__action__DriverAction_Feedback * data =
      (interfaces__action__DriverAction_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "interfaces/action/detail/driver_action__functions.h"

bool
interfaces__action__DriverAction_SendGoal_Request__init(interfaces__action__DriverAction_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    interfaces__action__DriverAction_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!interfaces__action__DriverAction_Goal__init(&msg->goal)) {
    interfaces__action__DriverAction_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_SendGoal_Request__fini(interfaces__action__DriverAction_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  interfaces__action__DriverAction_Goal__fini(&msg->goal);
}

bool
interfaces__action__DriverAction_SendGoal_Request__are_equal(const interfaces__action__DriverAction_SendGoal_Request * lhs, const interfaces__action__DriverAction_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!interfaces__action__DriverAction_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_SendGoal_Request__copy(
  const interfaces__action__DriverAction_SendGoal_Request * input,
  interfaces__action__DriverAction_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!interfaces__action__DriverAction_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_SendGoal_Request *
interfaces__action__DriverAction_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_SendGoal_Request * msg = (interfaces__action__DriverAction_SendGoal_Request *)allocator.allocate(sizeof(interfaces__action__DriverAction_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_SendGoal_Request));
  bool success = interfaces__action__DriverAction_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_SendGoal_Request__destroy(interfaces__action__DriverAction_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_SendGoal_Request__Sequence__init(interfaces__action__DriverAction_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_SendGoal_Request * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_SendGoal_Request *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_SendGoal_Request__Sequence__fini(interfaces__action__DriverAction_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_SendGoal_Request__Sequence *
interfaces__action__DriverAction_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_SendGoal_Request__Sequence * array = (interfaces__action__DriverAction_SendGoal_Request__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_SendGoal_Request__Sequence__destroy(interfaces__action__DriverAction_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_SendGoal_Request__Sequence__are_equal(const interfaces__action__DriverAction_SendGoal_Request__Sequence * lhs, const interfaces__action__DriverAction_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_SendGoal_Request__Sequence__copy(
  const interfaces__action__DriverAction_SendGoal_Request__Sequence * input,
  interfaces__action__DriverAction_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_SendGoal_Request);
    interfaces__action__DriverAction_SendGoal_Request * data =
      (interfaces__action__DriverAction_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
interfaces__action__DriverAction_SendGoal_Response__init(interfaces__action__DriverAction_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    interfaces__action__DriverAction_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_SendGoal_Response__fini(interfaces__action__DriverAction_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
interfaces__action__DriverAction_SendGoal_Response__are_equal(const interfaces__action__DriverAction_SendGoal_Response * lhs, const interfaces__action__DriverAction_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_SendGoal_Response__copy(
  const interfaces__action__DriverAction_SendGoal_Response * input,
  interfaces__action__DriverAction_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_SendGoal_Response *
interfaces__action__DriverAction_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_SendGoal_Response * msg = (interfaces__action__DriverAction_SendGoal_Response *)allocator.allocate(sizeof(interfaces__action__DriverAction_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_SendGoal_Response));
  bool success = interfaces__action__DriverAction_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_SendGoal_Response__destroy(interfaces__action__DriverAction_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_SendGoal_Response__Sequence__init(interfaces__action__DriverAction_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_SendGoal_Response * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_SendGoal_Response *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_SendGoal_Response__Sequence__fini(interfaces__action__DriverAction_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_SendGoal_Response__Sequence *
interfaces__action__DriverAction_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_SendGoal_Response__Sequence * array = (interfaces__action__DriverAction_SendGoal_Response__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_SendGoal_Response__Sequence__destroy(interfaces__action__DriverAction_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_SendGoal_Response__Sequence__are_equal(const interfaces__action__DriverAction_SendGoal_Response__Sequence * lhs, const interfaces__action__DriverAction_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_SendGoal_Response__Sequence__copy(
  const interfaces__action__DriverAction_SendGoal_Response__Sequence * input,
  interfaces__action__DriverAction_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_SendGoal_Response);
    interfaces__action__DriverAction_SendGoal_Response * data =
      (interfaces__action__DriverAction_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
interfaces__action__DriverAction_GetResult_Request__init(interfaces__action__DriverAction_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    interfaces__action__DriverAction_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_GetResult_Request__fini(interfaces__action__DriverAction_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
interfaces__action__DriverAction_GetResult_Request__are_equal(const interfaces__action__DriverAction_GetResult_Request * lhs, const interfaces__action__DriverAction_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_GetResult_Request__copy(
  const interfaces__action__DriverAction_GetResult_Request * input,
  interfaces__action__DriverAction_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_GetResult_Request *
interfaces__action__DriverAction_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_GetResult_Request * msg = (interfaces__action__DriverAction_GetResult_Request *)allocator.allocate(sizeof(interfaces__action__DriverAction_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_GetResult_Request));
  bool success = interfaces__action__DriverAction_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_GetResult_Request__destroy(interfaces__action__DriverAction_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_GetResult_Request__Sequence__init(interfaces__action__DriverAction_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_GetResult_Request * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_GetResult_Request *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_GetResult_Request__Sequence__fini(interfaces__action__DriverAction_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_GetResult_Request__Sequence *
interfaces__action__DriverAction_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_GetResult_Request__Sequence * array = (interfaces__action__DriverAction_GetResult_Request__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_GetResult_Request__Sequence__destroy(interfaces__action__DriverAction_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_GetResult_Request__Sequence__are_equal(const interfaces__action__DriverAction_GetResult_Request__Sequence * lhs, const interfaces__action__DriverAction_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_GetResult_Request__Sequence__copy(
  const interfaces__action__DriverAction_GetResult_Request__Sequence * input,
  interfaces__action__DriverAction_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_GetResult_Request);
    interfaces__action__DriverAction_GetResult_Request * data =
      (interfaces__action__DriverAction_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "interfaces/action/detail/driver_action__functions.h"

bool
interfaces__action__DriverAction_GetResult_Response__init(interfaces__action__DriverAction_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!interfaces__action__DriverAction_Result__init(&msg->result)) {
    interfaces__action__DriverAction_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_GetResult_Response__fini(interfaces__action__DriverAction_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  interfaces__action__DriverAction_Result__fini(&msg->result);
}

bool
interfaces__action__DriverAction_GetResult_Response__are_equal(const interfaces__action__DriverAction_GetResult_Response * lhs, const interfaces__action__DriverAction_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!interfaces__action__DriverAction_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_GetResult_Response__copy(
  const interfaces__action__DriverAction_GetResult_Response * input,
  interfaces__action__DriverAction_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!interfaces__action__DriverAction_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_GetResult_Response *
interfaces__action__DriverAction_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_GetResult_Response * msg = (interfaces__action__DriverAction_GetResult_Response *)allocator.allocate(sizeof(interfaces__action__DriverAction_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_GetResult_Response));
  bool success = interfaces__action__DriverAction_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_GetResult_Response__destroy(interfaces__action__DriverAction_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_GetResult_Response__Sequence__init(interfaces__action__DriverAction_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_GetResult_Response * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_GetResult_Response *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_GetResult_Response__Sequence__fini(interfaces__action__DriverAction_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_GetResult_Response__Sequence *
interfaces__action__DriverAction_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_GetResult_Response__Sequence * array = (interfaces__action__DriverAction_GetResult_Response__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_GetResult_Response__Sequence__destroy(interfaces__action__DriverAction_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_GetResult_Response__Sequence__are_equal(const interfaces__action__DriverAction_GetResult_Response__Sequence * lhs, const interfaces__action__DriverAction_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_GetResult_Response__Sequence__copy(
  const interfaces__action__DriverAction_GetResult_Response__Sequence * input,
  interfaces__action__DriverAction_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_GetResult_Response);
    interfaces__action__DriverAction_GetResult_Response * data =
      (interfaces__action__DriverAction_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "interfaces/action/detail/driver_action__functions.h"

bool
interfaces__action__DriverAction_FeedbackMessage__init(interfaces__action__DriverAction_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    interfaces__action__DriverAction_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!interfaces__action__DriverAction_Feedback__init(&msg->feedback)) {
    interfaces__action__DriverAction_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__DriverAction_FeedbackMessage__fini(interfaces__action__DriverAction_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  interfaces__action__DriverAction_Feedback__fini(&msg->feedback);
}

bool
interfaces__action__DriverAction_FeedbackMessage__are_equal(const interfaces__action__DriverAction_FeedbackMessage * lhs, const interfaces__action__DriverAction_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!interfaces__action__DriverAction_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__DriverAction_FeedbackMessage__copy(
  const interfaces__action__DriverAction_FeedbackMessage * input,
  interfaces__action__DriverAction_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!interfaces__action__DriverAction_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

interfaces__action__DriverAction_FeedbackMessage *
interfaces__action__DriverAction_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_FeedbackMessage * msg = (interfaces__action__DriverAction_FeedbackMessage *)allocator.allocate(sizeof(interfaces__action__DriverAction_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__DriverAction_FeedbackMessage));
  bool success = interfaces__action__DriverAction_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__DriverAction_FeedbackMessage__destroy(interfaces__action__DriverAction_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__DriverAction_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__DriverAction_FeedbackMessage__Sequence__init(interfaces__action__DriverAction_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_FeedbackMessage * data = NULL;

  if (size) {
    data = (interfaces__action__DriverAction_FeedbackMessage *)allocator.zero_allocate(size, sizeof(interfaces__action__DriverAction_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__DriverAction_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__DriverAction_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__action__DriverAction_FeedbackMessage__Sequence__fini(interfaces__action__DriverAction_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__action__DriverAction_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__action__DriverAction_FeedbackMessage__Sequence *
interfaces__action__DriverAction_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__DriverAction_FeedbackMessage__Sequence * array = (interfaces__action__DriverAction_FeedbackMessage__Sequence *)allocator.allocate(sizeof(interfaces__action__DriverAction_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__DriverAction_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__DriverAction_FeedbackMessage__Sequence__destroy(interfaces__action__DriverAction_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__DriverAction_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__DriverAction_FeedbackMessage__Sequence__are_equal(const interfaces__action__DriverAction_FeedbackMessage__Sequence * lhs, const interfaces__action__DriverAction_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__DriverAction_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__DriverAction_FeedbackMessage__Sequence__copy(
  const interfaces__action__DriverAction_FeedbackMessage__Sequence * input,
  interfaces__action__DriverAction_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__DriverAction_FeedbackMessage);
    interfaces__action__DriverAction_FeedbackMessage * data =
      (interfaces__action__DriverAction_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__DriverAction_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__action__DriverAction_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__DriverAction_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
