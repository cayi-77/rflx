#pragma once
#include <string_view>
#include <type_traits>
namespace rflx {
template <int N> struct Const_Number_type {
  inline static int Value = N;
};
template <int N> inline constexpr auto Const_Number = Const_Number_type<N>{};

template <typename T>
concept Rflxable = requires(T t) { t.rflx_item_count_; };

template <int Index = 0, Rflxable Rf, typename Callback>
constexpr void rflx_iter(Rf &&item, Callback &&callback) {
  if constexpr (Index < std::remove_reference_t<Rf>::rflx_item_count_) {
    callback(item.rflx_name(Const_Number<Index>),
             item.rflx_item(Const_Number<Index>));
    rflx_iter<Index + 1>(item, callback);
  }
}
} // namespace rflx
#define RFLX_BEGIN                                                             \
private:                                                                       \
  inline static constexpr int rflx_start_line_ = __LINE__ + 1;                 \
                                                                               \
public:

#define RFLX_END                                                               \
private:                                                                       \
  inline static constexpr int rflx_end_line_ = __LINE__;                       \
                                                                               \
public:                                                                        \
  inline static constexpr int rflx_item_count_ =                               \
      rflx_end_line_ - rflx_start_line_;

#define RFLX_ITEM(type, name, default_value)                                   \
  type name{default_value};                                                    \
  constexpr auto &rflx_item(                                                   \
      ::rflx::Const_Number_type<__LINE__ - rflx_start_line_>) {                \
    return name;                                                               \
  }                                                                            \
                                                                               \
  constexpr const auto &rflx_item(                                             \
      ::rflx::Const_Number_type<__LINE__ - rflx_start_line_>) const {          \
    return name;                                                               \
  }                                                                            \
                                                                               \
  static constexpr std::string_view rflx_name(                                 \
      ::rflx::Const_Number_type<__LINE__ - rflx_start_line_>) {                \
    return #name;                                                              \
  }