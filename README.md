# rflx
A simple reflection marco on c++20.

## Requires

c++20.

## Usage

- Copy 'include/rflx/rflx' to your include path.
- Or add this dir as a cmake sub dir, then `target_link_libraries(example PRIVATE rflx)`

## Example

```
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
```
