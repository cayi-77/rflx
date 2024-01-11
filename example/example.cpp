#include <rflx/rflx.h>
#include <iostream>

struct Example {
public:
  RFLX_BEGIN;
  RFLX_ITEM(int, x, 42);
  RFLX_ITEM(int, y, 77);
  RFLX_END;
};

int main() {
  Example a;
  rflx::rflx_iter(a, [](auto name, auto value) { std::cout << name << ": " << value << "\n"; });
  return 0;
}
