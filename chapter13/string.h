/*Exercise 13.44: Write a class named String that is a simplified version of
the library string class. Your class should have at least a default
constructor and a constructor that takes a pointer to a C-style string. Use an
allocator to allocate memory that your String class uses.*/

#include <iostream>

class String {
public:
  String() = default;
  String(const char *cStr);
  String(const String str&);
  String &operator=(const char *cStr);
  String &operator=(const String str&);
  ~String();
  size_type size() const {return last - first;}
  size_type capacity() const {return capacity - first;}
  std::char *begin() const {return first;}
  std::char *end() const {return last;}
  std::char front() const {return *first;}
  std::char back() const {return *last;}
  void insert();
private:
  std::allocator<std::char> alloc;
  void check_cap() {if (size() == capacity()) reallocate();}
  pair<std::char*, std::char*> alloc_n_copy(std::char* start, size_type length);
  std::char *first;
  std::char *last;
  std::char *capacity;
  void free();
  void reallocate();
}；
