
# Result类型

Result是枚举类型，Result的成员是`Ok`和`Err`。
- `Ok`表示操作成功，并且包含成功时产生的值
- `Err`表示操作失败，并且包含失败时的前因后果

Result有expect方法，如果`Err`，则显示传递给expect的参数，否则会获取`Ok`中的值并返回。

