
# Rust环境配置

在macOS或Linux系统下安装：
```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

配置环境变量：
在`~/.bashrc`中添加环境变量`~/.cargo/bin`：
```
export PATH=$PATH:/home/lixk28/.cargo/bin
```
这样可以直接使用`rustc`，`cargo`，`rustup`等工具链。

Rust更新和迭代速度非常快，`rustup`用于管理rust版本。

更新：
```
rustup update
```

卸载：
```
rustup self uninstall
```

查看版本：
```
rustc --version
```

Rust源代码后缀`.rs`，编译命令：
```
rustc main.rs
```
Rust是一种预编译静态型语言，可以编译程序。


# Cargo

Cargo是Rust的构建系统和包管理器，可以构建项目，以及下载依赖。

创建项目：
```
cargo new hello
```
将会创建一个名为hello的目录：
```
.
├── - Cargo.toml
└── - src
    └── - main.rs
```

`Cargo.toml`是项目的配置文件，列出了项目名，版本，作者，Rust版本以及项目依赖。

构建项目：
```
cargo build hello
```
将会生成二进制可执行文件，以及在根目录创建`Cargo.lock`，该文件记录项目依赖的实际版本。

运行可执行文件：
```
cargo run
```

检查代码确保可以被编译：
```
cargo check
```


# 基础语法

## 注释

与C相同。

## 函数

```rust
fn main() {
    println!("Hello, Rust!");
}
```

定义函数用`fn`，`main`函数总是最先运行的代码。

`println!`是一个Rust宏，而`println`是一个函数。

`println!`支持格式化字符串，用`{}`作为占位符。

`!`意味着是宏。


## 变量

用`let`声明变量，变量名前加`mut`是可变变量，没有是不可变变量。


## 库

`use std::io`在程序的开头，表示使用`std`标准库中的`io`库。

如果没有用use显式使用，需要在程序中写明`std::io`。

## match








