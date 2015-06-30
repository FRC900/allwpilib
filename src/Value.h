/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2015. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef NT_VALUE_H_
#define NT_VALUE_H_

#include <cassert>
#include <vector>

#include "ntcore.h"

#include "llvm/ArrayRef.h"
#include "llvm/StringRef.h"

namespace ntimpl {

class Storage;
class Value;

/*
 * C++ wrapper class around NT_String.
 */
class StringValue : private NT_String {
  friend class Value;
 public:
  StringValue() { NT_InitString(this); }
  /*implicit*/ StringValue(llvm::StringRef val);
  ~StringValue() { NT_DisposeString(this); }

  operator llvm::StringRef() const { return llvm::StringRef(str, len); }

  StringValue(const StringValue&) = delete;
  StringValue& operator=(const StringValue&) = delete;

  StringValue(StringValue&& other) {
    str = other.str;
    len = other.len;
    other.str = nullptr;
    other.len = 0;
  }

  StringValue& operator=(StringValue&& other) {
    if (this != &other) {
      NT_DisposeString(this);
      str = other.str;
      len = other.len;
      other.str = nullptr;
      other.len = 0;
    }
    return *this;
  }
};

/*
 * C++ wrapper class around NT_Value.
 */
class Value : private NT_Value {
  friend class Storage;
 public:
  Value() { NT_InitValue(this); }
  ~Value() { NT_DisposeValue(this); }

  // A little ugly, as it hides the identically-named NT_Value::type.
  NT_Type type() const { return NT_Value::type; }

  /*
   * Type-Safe Getters
   */
  bool GetBoolean() const {
    assert(NT_Value::type == NT_BOOLEAN);
    return data.v_boolean;
  }
  double GetDouble() const {
    assert(NT_Value::type == NT_DOUBLE);
    return data.v_double;
  }
  llvm::StringRef GetString() const {
    assert(NT_Value::type == NT_STRING);
    return static_cast<const StringValue&>(data.v_string);
  }
  llvm::StringRef GetRaw() const {
    assert(NT_Value::type == NT_RAW);
    return static_cast<const StringValue&>(data.v_raw);
  }
  // Ideally this would return llvm::ArrayRef<bool> but the C headers must
  // use "int" and casting may be very unsafe.
  llvm::ArrayRef<int> GetBooleanArray() const {
    assert(NT_Value::type == NT_BOOLEAN_ARRAY);
    return llvm::ArrayRef<int>(data.arr_boolean.arr, data.arr_boolean.size);
  }
  llvm::ArrayRef<double> GetDoubleArray() const {
    assert(NT_Value::type == NT_DOUBLE_ARRAY);
    return llvm::ArrayRef<double>(data.arr_double.arr, data.arr_double.size);
  }
  llvm::ArrayRef<StringValue> GetStringArray() const {
    assert(NT_Value::type == NT_BOOLEAN_ARRAY);
    return llvm::ArrayRef<StringValue>(
        static_cast<StringValue*>(data.arr_string.arr), data.arr_string.size);
  }

  /*
   * Type-Safe Setters
   */
  void SetBoolean(bool value) {
    if (NT_Value::type != NT_BOOLEAN) {
      NT_DisposeValue(this);
      NT_Value::type = NT_BOOLEAN;
    }
    data.v_boolean = value ? 1 : 0;
  }
  void SetDouble(double value) {
    if (NT_Value::type != NT_DOUBLE) {
      NT_DisposeValue(this);
      NT_Value::type = NT_DOUBLE;
    }
    data.v_double = value;
  }
  void SetString(llvm::StringRef value) { SetString(StringValue(value)); }
  void SetString(StringValue&& value) {
    if (NT_Value::type != NT_STRING) {
      NT_DisposeValue(this);
      data.v_string.str = nullptr;
      data.v_string.len = 0;
      NT_Value::type = NT_STRING;
    }
    data.v_string = value;
  }
  void SetRaw(llvm::StringRef value) { SetRaw(StringValue(value)); }
  void SetRaw(StringValue&& value) {
    if (NT_Value::type != NT_RAW) {
      NT_DisposeValue(this);
      data.v_raw.str = nullptr;
      data.v_raw.len = 0;
      NT_Value::type = NT_RAW;
    }
    data.v_raw = value;
  }

  void SetBooleanArray(llvm::ArrayRef<int> value);
  void SetBooleanArray(llvm::ArrayRef<bool> value);
  void SetDoubleArray(llvm::ArrayRef<double> value);

  // Note: This function moves the values out of the vector.
  void SetStringArray(std::vector<StringValue>& value);

  Value(const Value&) = delete;
  Value& operator=(const Value&) = delete;

  Value(Value&& other) {
    NT_Value::type = static_cast<NT_Value&>(other).type;
    last_change = other.last_change;
    data = other.data;
    static_cast<NT_Value&>(other).type = NT_UNASSIGNED;
    other.last_change = 0;
  }

  Value& operator=(Value&& other) {
    if (this != &other) {
      NT_DisposeValue(this);
      NT_Value::type = static_cast<NT_Value&>(other).type;
      last_change = other.last_change;
      data = other.data;
      static_cast<NT_Value&>(other).type = NT_UNASSIGNED;
      other.last_change = 0;
    }
    return *this;
  }

  friend bool operator==(const Value& lhs, const Value& rhs);
};

bool operator==(const Value& lhs, const Value& rhs);

}  // namespace ntimpl

#endif  // NT_VALUE_H_
